'use strict';

let DOMAPI$ReactNative = require("../types/DOMAPI.bs.js");
let NativeMethods$ReactNative = require("./NativeMethods.bs.js");

function Impl(T) {
  NativeMethods$ReactNative.Make({});
  DOMAPI$ReactNative.Element.Impl({});
  return {};
}

NativeMethods$ReactNative.Make({});

exports.Impl = Impl;
/*  Not a pure module */
