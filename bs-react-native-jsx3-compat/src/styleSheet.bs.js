

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as ReactNative from "react-native";

function create(a) {
  return ReactNative.StyleSheet.create(a);
}

var hairlineWidth = ReactNative.StyleSheet.hairlineWidth;

var absoluteFill = ReactNative.StyleSheet.absoluteFill;

var absoluteFillObject = ReactNative.StyleSheet.absoluteFillObject;

function flatten(styles) {
  return ReactNative.StyleSheet.flatten($$Array.of_list(styles));
}

function processColor(prim) {
  return ReactNative.processColor(prim[1]);
}

export {
  create ,
  hairlineWidth ,
  absoluteFill ,
  absoluteFillObject ,
  flatten ,
  processColor ,
  
}
/* hairlineWidth Not a pure module */
