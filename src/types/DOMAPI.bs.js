'use strict';


let NodeList = {};

let HTMLCollection = {};

function Impl(T) {
  return {};
}

let Node = {
  Impl: Impl
};

function Impl$1(T) {
  return {};
}

let Element = {
  Impl: Impl$1
};

let Document = {};

let Text = {};

function classify(node) {
  switch (node.nodeType) {
    case 1 :
      return {
        TAG: "Element",
        _0: node
      };
    case 3 :
      return {
        TAG: "Text",
        _0: node
      };
    case 9 :
      return {
        TAG: "Document",
        _0: node
      };
    default:
      return "Unknown";
  }
}

let NodeType = {
  classify: classify
};

exports.NodeList = NodeList;
exports.HTMLCollection = HTMLCollection;
exports.Node = Node;
exports.Element = Element;
exports.Document = Document;
exports.Text = Text;
exports.NodeType = NodeType;
/* No side effect */
