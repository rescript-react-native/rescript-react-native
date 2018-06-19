
(function() {
  
  var node = (tag, attrs, children) => {
    var node = document.createElement(tag)
    for (var attr in attrs) {
      if (attr === 'style') {
        Object.assign(node.style, attrs[attr])
      } else {
        node.setAttribute(attr, attrs[attr])
      }
    }
    children && children.forEach(child => node.appendChild(typeof child === 'string' ? document.createTextNode(child) : child))
    return node
  }
  var named = tag => (attrs, children) => node(tag, attrs, children)
  var div = named('div')
  var span = named('span')
  var a = named('a')
  var raw = text => {
    var node = document.createElement('div')
    node.innerHTML = text
    return node
  };

  var render = (target, node) => {
    target.innerHTML = ''
    target.appendChild(node)
  };


  var input = document.getElementById('search-input');
  var index = elasticlunr.Index.load(window.searchindex);
  var config = {bool: 'AND', fields: {title: {boost: 2}, contents: {boost: 1}}, expand: true};

  function escapeRegExp(string) {
    return string.replace(/[.*+?^${}()|[\]\\]/g, '\\$&'); // $& means the whole matched string
  }

  var walk = (node, fn) => {
    var nodes = [].slice.call(node.childNodes)
    nodes.forEach(child => {
      if (false === fn(child)) return;
      if (child.parentNode === node) {
        walk(child, fn)
      }
    })
  }

  var highlightNode = (node, token) => {
    walk(node, node => {
      if (node.nodeName === '#text') {
        let at = 0;
        let pieces = [];
        node.textContent.replace(new RegExp(escapeRegExp(token), 'gi'), (matched, pos, full) => {
          pieces.push(document.createTextNode(full.slice(at, pos)))
          pieces.push(span({class: 'result-highlighted'}, [matched]))
          at = pos + matched.length
        })
        if (pieces.length === 0) {
          return
        }
        if (at < node.textContent.length) {
          pieces.push(document.createTextNode(node.textContent.slice(at)))
        }
        node.replaceWith(...pieces)
      }
    })
  }

  var highlightingNode = (text, tokens) => {
    var node = raw(text);
    tokens.forEach(token => highlightNode(node, token))
    return node
  };

  window.highlightNode = highlightNode

  var search = text => {
    var results = index.search(text, config).slice(0, 30);
    render(document.getElementById('search-results'), div(
      {},
      results.map(({ref, score, doc: {href, title, contents, rendered, breadcrumb}}) => div(
        {class: 'result'},
        [
          div({style: {display: 'flex', justifyContent: 'space-between'}}, [
            a({href, class: 'title'}, [title]),
            span({class: 'breadcrumb'}, [breadcrumb])
          ]),
          div({}, [
            highlightingNode(rendered, text.split(/\s+/g))
            // raw(text.split(/\s+/g).reduce(
            //   (text, item) => text.replace(new RegExp(escapeRegExp(item), 'ig'), "<span class='result-highlighted'>$&</span>"), rendered
            // ))
          ])
        ]
      ))
    ))
  }

  if (location.search.match(/^\?search=/)) {
    var query = location.search.slice('?search='.length)
    search(query)
    input.value = query
  }

  input.addEventListener('keyup', evt => {
    var text = evt.target.value
    window.history.replaceState({}, '', '?search=' + encodeURIComponent(text))
    search(text)
  })
})();
