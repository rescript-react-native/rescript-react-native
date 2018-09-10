const Colors = (function() {
  const O = Object

/*  See https://misc.flogisoft.com/bash/tip_colors_and_formatting
    ------------------------------------------------------------------------ */

const colorCodes      = [   'black',      'red',      'green',      'yellow',      'blue',      'magenta',      'cyan', 'lightGray', '', 'default']
    , colorCodesLight = ['darkGray', 'lightRed', 'lightGreen', 'lightYellow', 'lightBlue', 'lightMagenta', 'lightCyan', 'white', '']

    , styleCodes = ['', 'bright', 'dim', 'italic', 'underline', '', '', 'inverse']

    , asBright = { 'red':       'lightRed',
                   'green':     'lightGreen',
                   'yellow':    'lightYellow',
                   'blue':      'lightBlue',
                   'magenta':   'lightMagenta',
                   'cyan':      'lightCyan',
                   'black':     'darkGray',
                   'lightGray': 'white' }

    , types = { 0:  'style',
                2:  'unstyle',
                3:  'color',
                9:  'colorLight',
                4:  'bgColor',
                10: 'bgColorLight' }

    , subtypes = {  color:         colorCodes,
                    colorLight:    colorCodesLight,
                    bgColor:       colorCodes,
                    bgColorLight:  colorCodesLight,
                    style:         styleCodes,
                    unstyle:       styleCodes    }

/*  ------------------------------------------------------------------------ */

const clean = obj => {
                for (const k in obj) { if (!obj[k]) { delete obj[k] } }
                return (O.keys (obj).length === 0) ? undefined : obj
            }

/*  ------------------------------------------------------------------------ */

class Color {

    constructor (background, name, brightness) {

        this.background = background
        this.name       = name
        this.brightness = brightness
    }

    get inverse () {
        return new Color (!this.background, this.name || (this.background ? 'black' : 'white'), this.brightness)
    }

    get clean () {
        return clean ({ name:   this.name === 'default' ? '' : this.name,
                        bright: this.brightness === Code.bright,
                        dim:    this.brightness === Code.dim })
    }

    defaultBrightness (value) {

        return new Color (this.background, this.name, this.brightness || value)
    }

    css (inverted) {

        const color = inverted ? this.inverse : this

        const rgbName = ((color.brightness === Code.bright) && asBright[color.name]) || color.name

        const prop = (color.background ? 'background:' : 'color:')
            , rgb  = Colors.rgb[rgbName]
            , alpha = (this.brightness === Code.dim) ? 0.5 : 1

        return rgb
                ? (prop + 'rgba(' + [...rgb, alpha].join (',') + ');')
                : ((!color.background && (alpha < 1)) ? 'color:rgba(0,0,0,0.5);' : '') // Chrome does not support 'opacity' property...
    }
}

/*  ------------------------------------------------------------------------ */

class Code {

    constructor (n) {
        if (n !== undefined) { this.value = Number (n) } }

    get type () {
       return types[Math.floor (this.value / 10)] }

    get subtype () {
        return subtypes[this.type][this.value % 10] }

    get str () {
        return (this.value ? ('\u001b\[' + this.value + 'm') : '') }

    static str (x) {
        return new Code (x).str }

    get isBrightness () {
        return (this.value === Code.noBrightness) || (this.value === Code.bright) || (this.value === Code.dim) }
}

/*  ------------------------------------------------------------------------ */

O.assign (Code, {

    bright:       1,
    dim:          2,
    inverse:      7,
    noBrightness: 22,
    noItalic:     23,
    noUnderline:  24,
    noInverse:    27,
    noColor:      39,
    noBgColor:    49
})

/*  ------------------------------------------------------------------------ */

const replaceAll = (str, a, b) => str.split (a).join (b)

/*  ANSI brightness codes do not overlap, e.g. "{bright}{dim}foo" will be rendered bright (not dim).
    So we fix it by adding brightness canceling before each brightness code, so the former example gets
    converted to "{noBrightness}{bright}{noBrightness}{dim}foo" – this way it gets rendered as expected.
 */

const denormalizeBrightness = s => s.replace (/(\u001b\[(1|2)m)/g, '\u001b[22m$1')
const normalizeBrightness = s => s.replace (/\u001b\[22m(\u001b\[(1|2)m)/g, '$1')

const wrap = (x, openCode, closeCode) => {

    const open  = Code.str (openCode),
          close = Code.str (closeCode)

    return String (x)
                .split ('\n')
                .map (line => denormalizeBrightness (open + replaceAll (normalizeBrightness (line), close, open) + close))
                .join ('\n')
}

/*  ------------------------------------------------------------------------ */

const camel = (a, b) => a + b.charAt (0).toUpperCase () + b.slice (1)


const stringWrappingMethods = (() => [

        ...colorCodes.map ((k, i) => !k ? [] : [ // color methods

            [k,               30 + i, Code.noColor],
            [camel ('bg', k), 40 + i, Code.noBgColor],
        ]),

        ...colorCodesLight.map ((k, i) => !k ? [] : [ // light color methods

            [k,                90 + i, Code.noColor],
            [camel ('bg', k), 100 + i, Code.noBgColor],
        ]),

        /* THIS ONE IS FOR BACKWARDS COMPATIBILITY WITH PREVIOUS VERSIONS (had 'bright' instead of 'light' for backgrounds)
         */
        ...['', 'BrightRed', 'BrightGreen', 'BrightYellow', 'BrightBlue', 'BrightMagenta', 'BrightCyan'].map ((k, i) => !k ? [] : [

            ['bg' + k, 100 + i, Code.noBgColor],
        ]),

        ...styleCodes.map ((k, i) => !k ? [] : [ // style methods

            [k, i, ((k === 'bright') || (k === 'dim')) ? Code.noBrightness : (20 + i)]
        ])
    ]
    .reduce ((a, b) => a.concat (b))

) ();

/*  ------------------------------------------------------------------------ */

const assignStringWrappingAPI = (target, wrapBefore = target) =>

    stringWrappingMethods.reduce ((memo, [k, open, close]) =>
                                        O.defineProperty (memo, k, {
                                            get: () => assignStringWrappingAPI (str => wrapBefore (wrap (str, open, close)))
                                        }),

                                  target)

/*  ------------------------------------------------------------------------ */

/**
 * Represents an ANSI-escaped string.
 */
class Colors {

    /**
     * @param {string} s a string containing ANSI escape codes.
     */
    constructor (s) {

        if (s) {

            const r = /\u001b\[(\d+)m/g

            const spans = s.split (/\u001b\[\d+m/)
            const codes = []

            for (let match; match = r.exec (s);) codes.push (match[1])

            this.spans = spans.map ((s, i) => ({ text: s, code: new Code (codes[i]) }))
        }

        else {
            this.spans = []
        }
    }

    get str () {
        return this.spans.reduce ((str, p) => str + p.text + p.code.str, '')
    }

    get parsed () {

        var color      = new Color (),
            bgColor    = new Color (true /* background */),
            brightness = undefined,
            styles     = new Set ()

        return O.assign (new Colors (), {

            spans: this.spans.map (span => {

                const c = span.code

                const inverted  = styles.has ('inverse'),
                      underline = styles.has ('underline')   ? 'text-decoration: underline;' : '',
                      italic    = styles.has ('italic')      ? 'font-style: italic;' : '',
                      bold      = brightness === Code.bright ? 'font-weight: bold;' : ''

                const foreColor = color.defaultBrightness (brightness)

                const styledSpan = O.assign (
                                        { css: bold + italic + underline + foreColor.css (inverted) + bgColor.css (inverted) },
                                        clean ({ bold: !!bold, color: foreColor.clean, bgColor: bgColor.clean }),
                                        span)

                for (const k of styles) { styledSpan[k] = true }

                if (c.isBrightness) {

                    brightness = c.value

                } else {

                    switch (span.code.type) {

                        case 'color'        :
                        case 'colorLight'   : color   = new Color (false, c.subtype); break

                        case 'bgColor'      :
                        case 'bgColorLight' : bgColor = new Color (true,  c.subtype); break

                        case 'style'  : styles.add    (c.subtype); break
                        case 'unstyle': styles.delete (c.subtype); break
                    }
                }

                return styledSpan

            }).filter (s => s.text.length > 0)
        })
    }

/*  Outputs with Chrome DevTools-compatible format     */

    get asChromeConsoleLogArguments () {

        const spans = this.parsed.spans

        return [spans.map (s => ('%c' + s.text)).join (''),
             ...spans.map (s => s.css)]
    }

    get browserConsoleArguments () /* LEGACY, DEPRECATED */ { return this.asChromeConsoleLogArguments }

    /**
     * @desc installs String prototype extensions
     * @example
     * require ('ansicolor').nice
     * console.log ('foo'.bright.red)
     */
    static get nice () {

        Colors.names.forEach (k => {
            if (!(k in String.prototype)) {
                O.defineProperty (String.prototype, k, { get: function () { return Colors[k] (this) } })
            }
        })

        return Colors
    }

    /**
     * @desc parses a string containing ANSI escape codes
     * @return {Colors} parsed representation.
     */
    static parse (s) {
        return new Colors (s).parsed
    }

    /**
     * @desc strips ANSI codes from a string
     * @param {string} s a string containing ANSI escape codes.
     * @return {string} clean string.
     */
    static strip (s) {
        return s.replace (/[\u001b\u009b][[()#;?]*(?:[0-9]{1,4}(?:;[0-9]{0,4})*)?[0-9A-PRZcf-nqry=><]/g, '') // hope V8 caches the regexp
    }

    /**
     * @example
     * const spans = [...ansi.parse ('\u001b[7m\u001b[7mfoo\u001b[7mbar\u001b[27m')]
     */
    [Symbol.iterator] () {
        return this.spans[Symbol.iterator] ()
    }
}

/*  ------------------------------------------------------------------------ */

assignStringWrappingAPI (Colors, str => str)

/*  ------------------------------------------------------------------------ */

Colors.names = stringWrappingMethods.map (([k]) => k)

/*  ------------------------------------------------------------------------ */

Colors.rgb = {

    black:        [0,     0,   0],
    darkGray:     [100, 100, 100],
    lightGray:    [200, 200, 200],
    white:        [255, 255, 255],

    red:          [204,   0,   0],
    lightRed:     [255,  51,   0],

    green:        [0,   204,   0],
    lightGreen:   [51,  204,  51],

    yellow:       [204, 102,   0],
    lightYellow:  [255, 153,  51],

    blue:         [0,     0, 255],
    lightBlue:    [26,  140, 255],

    magenta:      [204,   0, 204],
    lightMagenta: [255,   0, 255],

    cyan:         [0,   153, 255],
    lightCyan:    [0,   204, 255],
}

/*  ------------------------------------------------------------------------ */

return Colors

/*  ------------------------------------------------------------------------ */
})();










(function() {

  var node = (tag, attrs, children) => {
    var node = document.createElement(tag)
    for (var attr in attrs) {
      if (attr === 'style') {
        Object.assign(node.style, attrs[attr])
      } else if (attr === 'onclick') {
        node.onclick = attrs[attr]
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


const loadScript = absPath => {
  return new Promise((res, rej) => {
    const src = window.relativeToRoot + '/' + absPath;
    const script = node('script', {src});
    script.onload = () => res();
    script.onerror = e => rej(e);
    document.body.appendChild(script)
  })
}

const loadCss = absPath => {
  return new Promise((res, rej) => {
    const href = window.relativeToRoot + '/' + absPath;
    const link = node('link', {href, rel: 'stylesheet'});
    link.onload = () => res();
    link.onerror = e => rej(e);
    document.head.appendChild(link)
  })
}

const memoCss = absPath => {
  let promise = null
  return () => (promise || (promise = loadCss(absPath)))
};

const memoLoad = absPath => {
  let promise = null
  return () => (promise || (promise = loadScript(absPath)))
};

const loadDeps = memoLoad('all-deps.js');
const loadJsx = memoLoad('jsx-ppx.js');
const loadRefmt = memoLoad('refmt.js');
const loadOcaml = memoLoad('bucklescript.js');
const loadOcamlDeps = memoLoad('bucklescript-deps.js');
const loadCodeMirror = memoLoad('codemirror.js');
const loadRust = memoLoad('rust.js');
const loadSimple = memoLoad('simple.js');
const loadCodeMirrorCss = memoCss('codemirror.css');
const loadAll = () => Promise.all([loadJsx(), loadRefmt(), loadDeps(), loadOcaml().then(() => loadOcamlDeps())])

const runSandboxed = (script, logs, context) => {
  const addLog = (level, items) => {
    var text = ''
    if (items.length === 1 && typeof items[0] === 'string') {
      text = items[0]
    } else {
      text = items.map(item => JSON.stringify(item)).join(' ')
    }
    logs.appendChild(div({class: 'block-log level-' + level}, [text]))
  };

  const oldConsole = window.console
  window.console = Object.assign({}, window.console, {
    log: (...items) => {oldConsole.log(...items); addLog('log', items)},
    warn: (...items) => {oldConsole.warn(...items); addLog('warn', items)},
    error: (...items) => {oldConsole.error(...items); addLog('error', items)},
  });
  Object.assign(window, context)
  // ok folks we're done
  const exports = {}
  const module = {exports}
  const require = name => {
    return bsRequirePaths[name] ? window.packRequire(bsRequirePaths[name]) : window.packRequire(name)
  }
  try {
    // TODO check if it's a promise or something... and maybe wait?
    eval(script);
  } catch (error) {
    oldConsole.error(error)
    addLog('error', [error && error.message || error])
  }
  window.console = oldConsole
  for (let name in context) {
    window[name] = null
  }
};

var initBlocks = () => {
  ;[].forEach.call(document.querySelectorAll('div.block-target'), el => {
    const viewContext = el.getAttribute('data-context');
    const id = el.getAttribute('data-block-id');
    const parent = el.parentNode;
    const syntax = el.getAttribute('data-block-syntax');

    const logs = div({class: 'block-logs'}, []);

    const bundleScript = document.querySelector('script[type=redoc-bundle][data-block-id="' + id + '"]')
    const sourceScript = document.querySelector('script[type=redoc-source][data-block-id="' + id + '"]')

    if (!bundleScript) {
      // not runnable, not editable
      return
    }

    let ran = false

    window.process = {env: {NODE_ENV: 'production'}}

    const runBlock = (context) => {
      if (ran) {
        return Promise.resolve()
      }
      ran = true
      return loadDeps().then(() => {
        console.log(id)
        if (!bundleScript) {
          console.error('bundle not found')
          return
        }
        runSandboxed(bundleScript.textContent, logs, context);
      })
    }
    let context = {}

    const betterShiftTab = /*onInfo => */cm => {
      var cursor = cm.getCursor()
        , line = cm.getLine(cursor.line)
        , pos = {line: cursor.line, ch: cursor.ch}
      cm.execCommand('indentLess')
    }

    const betterTab = /*onComplete => */cm => {
      if (cm.somethingSelected()) {
        return cm.indentSelection("add");
      }
      const cursor = cm.getCursor()
      const line = cm.getLine(cursor.line)
      const pos = {line: cursor.line, ch: cursor.ch}
      cm.replaceSelection(Array(cm.getOption("indentUnit") + 1).join(" "), "end", "+input");
    }

    const htmlEscape = message => message
      .replace('&', '&amp;')
      .replace('<', '&lt;')
      .replace('>', '&gt;');

    const fixEscapes = message => {
      return Colors.parse(message
        .replace(new RegExp('\u001b\\[1;', 'g'), '\u001b[')
        .replace(new RegExp('\u001b\\[0m', 'g'), '\u001b[39m')
      ).spans.map(span => `<span style="${span.css}">${htmlEscape(span.text)}</span>`).join('')
    };

    const getJs = (result, showError) => {
      if (!result) return
      try {
        if (typeof result === 'string') {
          // bs 2.2.3
          result = JSON.parse(result)
        }
        const {js_code, js_error_msg, row, column, endRow, endColumn} = result
        if (!js_code && js_error_msg) {
          // TODO: just compile the straight reason, so these numbers mean something
          if (showError) {
            showError(row, column, endRow, endColumn)
          }
          error.innerHTML = fixEscapes(js_error_msg)
          error.style.display = 'block'
          console.log(result)
          return
        }
        return js_code
      } catch (e) {
        console.error(e)
        error.textContent = e.message
        error.style.display = 'block'
        return
      }
    }

    const preprocessReason = code => {
      let ocaml
      try {
        ocaml = window.printML(window.parseRE(code))
      } catch (e) {
        if (e.location) {
          showError(e.location.startLine - 1, e.location.startLineStartChar - 1, e.location.endLine - 1, e.location.endLineEndChar - 1)
        }
        console.error(e)
        error.textContent = e.message
        error.style.display = 'block'
        return
      }
      let ppxed
      try {
        const {ppx_error_msg, js_error_msg, ocaml_code} = window.jsxv2.rewrite(ocaml)
        if (ppx_error_msg || js_error_msg) {
          console.error(ppx_error_msg, js_error_msg)
          error.textContent = (ppx_error_msg || '') + ' ' + (js_error_msg || '')
          error.style.display = 'block'
          return
        }
        return ocaml_code
      } catch (e) {
        console.error(e)
        error.textContent = e.message
        error.style.display = 'block'
        return
      }
    }

    const execute = (cm, code, before) => {
      logs.innerHTML = ''
      cm.getAllMarks().forEach(mark => {
        cm.removeLineWidget(mark)
      })
      const showError = (l1, c1, l2, c2) => {
        c2 = l1 === l2 && c1 === c2 ? c2 + 1 : c2;
        console.log('showing', l1, c1, l2, c2)
        cm.markText({line: l1 - before, ch: c1}, {line: l2 - before, ch: c2}, {
          className: 'CodeMirror-error-mark',
        })
      }
      return loadAll().then(() => {
        const js = syntax == 'ml'
        ? getJs(window.ocaml.compile(code), showError)
        : (window.ocaml.reason_compile_super_errors
          ? getJs(window.ocaml.reason_compile_super_errors(code), showError)
          : getJs(window.ocaml.compile(preprocessReason(code))))
        if (js) {
          error.style.display = 'none'
          runSandboxed(js, logs, Object.assign({}, context))
        }
      })
    }

    const pre = document.querySelector('pre.code[data-block-id="' + id + '"]')
    const error = div({class: 'code-block-error', style: {display: 'none'}})
    pre.insertAdjacentElement('afterend', error)

    const processHashes = code => {
      const lines = code.split('\n')
      let before = 0
      let after = 0
      for (let i=0; i<lines.length; i++) {
        let line = lines[i]
        if (line[0] == '#' || (line[0] == '!' && line[1] == '#')) {
          before = i + 1
        } else {
          break
        }
      }

      for (let i=1; i<=lines.length; i++) {
        let line = lines[lines.length - i]
        if (line[0] == '#' || (line[0] == '!' && line[1] == '#')) {
          after = i
        } else {
          break
        }
      }
      return {
        before,
        prefix: lines.slice(0, before).map(m => m.replace(/^!?#/, '')).join('\n') + (before > 0 ? '\n' : ''),
        mainCode: lines.slice(before, lines.length - after).join('\n'),
        suffix: (after > 0 ? '\n' : '') + lines.slice(lines.length - after).map(m => m.replace(/^!?#/, '')).join('\n'),
      }
    }

    let onEditRun = () => {};

    let loadingIcon = "⋯";
    let playIcon = "▶";

    let playButton
    if (viewContext === 'canvas') {
      playButton = div({class: 'block-canvas-play'}, ["▶"])
      const canvas = node('canvas', {id: 'block-canvas-' + id})
      canvas.width = 200
      canvas.height = 200
      context = {sandboxCanvas: canvas, sandboxCanvasId: canvas.id, containerDiv: parent}
      playButton.onclick = () => {
        playButton.textContent = loadingIcon
        runBlock(context).then(() => {
          playButton.style.display = 'none'
        })
      }
      const canvasBlock = div({class: 'block-canvas-container'}, [
        canvas,
        playButton
      ]);
      parent.appendChild(canvasBlock)
    } else if (viewContext === 'div') {
      const target = div({id: 'block-target-div-' + id})
      const container = div({class: 'block-target-container'}, [target])
      parent.appendChild(container)
      playButton = div({class: 'block-target-right'}, [playIcon])
      context = {sandboxDiv: target, sandboxDivId: target.id, containerDiv: parent}
      onEditRun = () => container.classList.add('active')
      playButton.onclick = () => {
        playButton.textContent = loadingIcon
        runBlock(context).then(() => {
          playButton.style.display = 'none'
          container.classList.add('active')
        })
      }
      parent.appendChild(playButton)
    } else {
      playButton = div({class: 'block-target-right'}, [playIcon])
      playButton.onclick = () => {
        playButton.textContent = loadingIcon
        runBlock({containerDiv: parent}).then(() => {
          playButton.style.display = 'none'
        })
      }
      parent.appendChild(playButton)
    }

    parent.appendChild(logs)

    if (!sourceScript) {
      // not editable
      return
    }
    const editButton = node('button', {class: 'code-edit-button'}, ["Edit"]);
    pre.appendChild(editButton)

    const startEditing = () => {
      editButton.textContent = loadingIcon
      if (playButton && playButton.parentNode) {
        playButton.parentNode.removeChild(playButton)
        playButton = null
      }
      // const code = sourceScript.textContent
      const {before, prefix, mainCode, suffix} = processHashes(sourceScript.textContent)
      console.log([prefix, mainCode, suffix])


      Promise.all([loadCodeMirror().then(() => loadSimple()).then(() => loadRust()), loadCodeMirrorCss()]).then(() => {
        const textarea = node('textarea', {class: 'code-block-editor', style: {width: '100%'}})
        pre.replaceWith(textarea)
        textarea.value = mainCode
        let playButton

        const run = (cm) => {
          onEditRun();
          playButton.textContent = loadingIcon
          execute(cm, prefix + '#1 ""\n' + cm.getValue() + suffix, 0).then(() => {
            playButton.textContent = playIcon
          })
        }

        const cm = CodeMirror.fromTextArea(textarea, {
          lineNumbers: true,
          lineWrapping: true,
          viewportMargin: Infinity,
          extraKeys: {
            'Cmd-Enter': (cm) => run(cm),
            'Ctrl-Enter': (cm) => run(cm),
            Tab: betterTab,
            'Shift-Tab': betterShiftTab,
          },
          mode: 'rust',
        })

        playButton = node('button', {class: 'code-edit-run'}, ["▶"])
        playButton.onclick = () => run(cm)
        parent.appendChild(playButton)
      })
    }
    editButton.addEventListener('click', startEditing)

  })

  var style = document.createElement('style')
  document.head.appendChild(style)
  var show = lang => {
    localStorage.preferredSyntax = lang
    style.innerText = `
    .syntax-buttons {
      position: fixed;
      top: 0;
      right: 0;
      padding: 4px 8px;
      z-index: 1000;
      background: rgba(255,255,255,0.8);
      border-bottom-left-radius: 4px;
    }
    @media (max-width: 1000px) {
      .syntax-buttons {
        position: absolute;
      }
    }

    .syntax-buttons button {
      background: white;
      border: none;
      border-radius: 3px;
      padding: 4px 8px;
      margin: 0 4px;
    }
    .button-picker-${lang} {
      background-color: #eee;
      font-weight: bold;
    }
    div.code-block { display: none } div.code-block[data-block-syntax=${lang}] { display: block }
    .code-block[data-block-syntax=ml] pre > code::after {
      content: 'ml';
      position: absolute;
      bottom: 0;
      right: 4px;
      color: #999;
      pointer-events: none;
    }
    .code-block[data-block-syntax=re] pre > code::after {
      content: 're';
      position: absolute;
      bottom: 0;
      right: 4px;
      color: #999;
      pointer-events: none;
    }
    .code-block pre {
      position: relative;
    }
    `
  }
  let lang = localStorage.preferredSyntax || 're'
  show(lang)
  var buttons = div({class: 'syntax-buttons', style: {
  }}, [
    'Syntax: ',
    node('button', {class: 'button-picker-ml', onclick: () => show('ml')}, ['ocaml']),
    node('button', {class: 'button-picker-re', onclick: () => show('re')}, ['reason']),
  ]);
  document.body.appendChild(buttons)
}

window.addEventListener('load', () => {
  initBlocks();
})

})();
