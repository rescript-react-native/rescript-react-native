@@warning("-30")

type nodeList<'node> = {length: int}
type htmlCollection<'element> = {length: int}

type readOnlyNode<'node, 'document, 'element> = {
  // Node
  childNodes: nodeList<'node>,
  firstChild: Js.Null.t<'node>,
  isConnected: bool,
  lastChild: Js.Null.t<'node>,
  nextSibling: Js.Null.t<'node>,
  nodeType: int,
  nodeName: string,
  nodeValue: Js.Null.t<string>,
  ownerDocument: Js.Null.t<'document>,
  parentElement: Js.Null.t<'element>,
  parentNode: Js.Null.t<'node>,
  previousSibling: Js.Null.t<'node>,
  textContent: string,
}

type rec node = {
  ...readOnlyNode<node, document, element>,
}

and element = {
  // Node
  ...readOnlyNode<node, document, element>,
  // Element
  childElementCount: int,
  children: htmlCollection<element>,
  clientHeight: int,
  clientLeft: int,
  clientTop: int,
  clientWidth: int,
  firstElementChild: Js.Null.t<element>,
  id: string,
  lastElementChild: Js.Null.t<element>,
  nextElementSibling: Js.Null.t<element>,
  previousElementSibling: Js.Null.t<element>,
  scrollHeight: int,
  scrollLeft: int,
  scrollTop: int,
  scrollWidth: int,
  tagName: string,
  // HTMLElement
  offsetHeight: int,
  offsetLeft: int,
  offsetTop: int,
  offsetWidth: int,
  offsetParent: Js.Null.t<element>,
}

and text = {
  // Node
  ...readOnlyNode<node, document, element>,
  // CharacterData
  data: string,
  length: int,
  nextElementSibling: Js.Null.t<element>,
  previousElementSibling: Js.Null.t<element>,
}

and document = {
  ...readOnlyNode<node, document, element>,
  childElementCount: int,
  children: htmlCollection<element>,
  documentElement: element,
  firstElementChild: Js.Null.t<element>,
  lastElementChild: Js.Null.t<element>,
}

module NodeList = {
  @send
  external item: (nodeList<'node>, int) => Js.Null.t<'node> = "item"
}

module HTMLCollection = {
  @send
  external item: (htmlCollection<'element>, int) => Js.Null.t<'element> = "item"

  @send
  external namedItem: (htmlCollection<'element>, string) => Js.Null.t<'element> = "namedItem"
}

module Node = {
  module Impl = (
    T: {
      type t
    },
  ) => {
    external asNode: T.t => node = "%identity"

    @send
    external compareDocumentPosition: (T.t, node) => int = "compareDocumentPosition"
    @send external contains: (T.t, node) => bool = "contains"
    @send external getRootNode: T.t => node = "getRootNode"
    @send external hasChildNodes: T.t => bool = "hasChildNodes"
  }

  include Impl({
    type t = node
  })
}

module Element = {
  module Impl = (
    T: {
      type t
    },
  ) => {
    include Node.Impl({
      type t = T.t
    })

    @send
    external getBoundingClientRect: T.t => Rect.t = "getBoundingClientRect"
    @send
    external hasPointerCapture: (T.t, int) => bool = "hasPointerCapture"
    @send
    external releasePointerCapture: (T.t, int) => unit = "releasePointerCapture"
    @send
    external setPointerCapture: (T.t, int) => unit = "setPointerCapture"
    @send external focus: T.t => unit = "focus"
    @send external blur: T.t => unit = "blur"

    @send external setNativeProps: (T.t, {..}) => unit = "setNativeProps"
  }

  include Impl({
    type t = element
  })
}

module Document = {
  include Node.Impl({
    type t = document
  })

  @send external getElementById: (document, string) => Js.Null.t<element> = "getElementById"
}

module Text = {
  include Node.Impl({
    type t = text
  })

  @send external substringData: (text, ~offset: int, ~count: int) => string = "substringData"
}

module NodeType = {
  /*
  Helper for handle NodeType
  Waiting for this issue :
  https://github.com/rescript-lang/rescript/issues/8280
  to use this type for node instead

  @tag("nodeType")
  type rec node =
    | @as(1) Element(element)
    | @as(3) Text(text)
    | @as(9) Document(document)

  and remove this helper
 */
  type t =
    | Element(element)
    | Text(text)
    | Document(document)
    | Unknown

  let classify = (node: node) =>
    switch node {
    | {nodeType: 1} => Element(node->Obj.magic)
    | {nodeType: 3} => Text(node->Obj.magic)
    | {nodeType: 9} => Document(node->Obj.magic)
    | _ => Unknown
    }
}
