'use strict';


var $$NodeList = {};

var $$HTMLCollection = {};

function Impl(T) {
  return {};
}

var $$Node = {
  Impl: Impl
};

function Impl$1(T) {
  return {};
}

var $$Element = {
  Impl: Impl$1
};

var $$Document = {};

var $$Text = {};

function findNodeType(node) {
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

var NodeTypeHelper = {
  findNodeType: findNodeType
};

exports.$$NodeList = $$NodeList;
exports.$$HTMLCollection = $$HTMLCollection;
exports.$$Node = $$Node;
exports.$$Element = $$Element;
exports.$$Document = $$Document;
exports.$$Text = $$Text;
exports.NodeTypeHelper = NodeTypeHelper;
/* No side effect */
