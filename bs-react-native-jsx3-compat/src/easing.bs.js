

import * as ReactNative from "react-native";

var bounce = ReactNative.Easing.bounce;

var circle = ReactNative.Easing.circle;

var cubic = ReactNative.Easing.cubic;

var ease = ReactNative.Easing.ease;

var exp = ReactNative.Easing.exp;

var linear = ReactNative.Easing.linear;

function poly(prim) {
  return ReactNative.Easing.poly(prim);
}

var quad = ReactNative.Easing.quad;

var sin = ReactNative.Easing.sin;

function step0(prim) {
  return ReactNative.Easing.step0(prim);
}

function step1(prim) {
  return ReactNative.Easing.step1(prim);
}

function back(prim) {
  return ReactNative.Easing.back(prim);
}

function elastic(prim) {
  return ReactNative.Easing.elastic(prim);
}

function in_(prim) {
  return ReactNative.Easing.in(prim);
}

function inOut(prim) {
  return ReactNative.Easing.inOut(prim);
}

function out(prim) {
  return ReactNative.Easing.out(prim);
}

function bezier(prim, prim$1, prim$2, prim$3) {
  return ReactNative.Easing.bezier(prim, prim$1, prim$2, prim$3);
}

export {
  bounce ,
  circle ,
  cubic ,
  ease ,
  exp ,
  linear ,
  poly ,
  quad ,
  sin ,
  step0 ,
  step1 ,
  back ,
  elastic ,
  in_ ,
  inOut ,
  out ,
  bezier ,
  
}
/* bounce Not a pure module */
