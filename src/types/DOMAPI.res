@@warning("-30")

type nodeList<'node> = {length: int}
type htmlCollection<'element> = {length: int}

type readOnlyNode<'node, 'document, 'element> = {
  // Node
  childNodes: nodeList<'node>,
  firstChild: null<'node>,
  isConnected: bool,
  lastChild: null<'node>,
  nextSibling: null<'node>,
  nodeType: int,
  nodeName: string,
  nodeValue: null<string>,
  ownerDocument: null<'document>,
  parentElement: null<'element>,
  parentNode: null<'node>,
  previousSibling: null<'node>,
  textContent: null<string>,
}

type unknownNativeElement

type rec node = {
  ...readOnlyNode<node, document, anyElement>,
}

and element<'nativeElement> = {
  // Node
  ...readOnlyNode<node, document, anyElement>,
  // Element
  childElementCount: int,
  children: htmlCollection<anyElement>,
  clientHeight: int,
  clientLeft: int,
  clientTop: int,
  clientWidth: int,
  firstElementChild: null<anyElement>,
  id: string,
  lastElementChild: null<anyElement>,
  nextElementSibling: null<anyElement>,
  previousElementSibling: null<anyElement>,
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
  offsetParent: null<anyElement>,
}

and text = {
  // Node
  ...readOnlyNode<node, document, anyElement>,
  // CharacterData
  data: string,
  length: int,
  nextElementSibling: null<anyElement>,
  previousElementSibling: null<anyElement>,
}

and document = {
  ...readOnlyNode<node, document, anyElement>,
  childElementCount: int,
  children: htmlCollection<anyElement>,
  documentElement: anyElement,
  firstElementChild: null<anyElement>,
  lastElementChild: null<anyElement>,
}

and anyElement = element<unknownNativeElement>

module NodeList = {
  @send
  external item: (nodeList<'node>, int) => null<'node> = "item"
}

module HTMLCollection = {
  @send
  external item: (htmlCollection<'element>, int) => null<'element> = "item"

  @send
  external namedItem: (htmlCollection<'element>, string) => null<'element> = "namedItem"
}

module Node = {
  // Methods of every node-like type. `T.t` takes a type parameter so that the
  // methods stay generic over the native element type of `element<'nativeElement>`.
  module Impl = (
    T: {
      type t<'a>
    },
  ) => {
    external asNode: T.t<'a> => node = "%identity"

    @send
    external compareDocumentPosition: (T.t<'a>, node) => int = "compareDocumentPosition"
    @send external contains: (T.t<'a>, node) => bool = "contains"
    @send external getRootNode: T.t<'a> => node = "getRootNode"
    @send external hasChildNodes: T.t<'a> => bool = "hasChildNodes"
  }

  include Impl({type t<'a> = node})
}

// Methods of every element, generic over the native element type
module Element = {
  include Node.Impl({type t<'nativeElement> = element<'nativeElement>})

  @send
  external getBoundingClientRect: element<'nativeElement> => Rect.t = "getBoundingClientRect"
  @send
  external hasPointerCapture: (element<'nativeElement>, int) => bool = "hasPointerCapture"
  @send
  external releasePointerCapture: (element<'nativeElement>, int) => unit = "releasePointerCapture"
  @send
  external setPointerCapture: (element<'nativeElement>, int) => unit = "setPointerCapture"
  @send external focus: element<'nativeElement> => unit = "focus"
  @send external blur: element<'nativeElement> => unit = "blur"

  @send external setNativeProps: (element<'nativeElement>, {..}) => unit = "setNativeProps"
}

module Document = {
  include Node.Impl({type t<'a> = document})

  @send
  external getElementById: (document, string) => null<anyElement> = "getElementById"
}

module Text = {
  include Node.Impl({type t<'a> = text})

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
    | Element(element<unknownNativeElement>)
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
