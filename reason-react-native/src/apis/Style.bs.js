'use strict';


function unsafeAddProp(style, property, value) {
  var o = Object.assign({ }, style);
  o[property] = value;
  return o;
}

function pct(num) {
  return num.toString() + "%";
}

function deg(num) {
  return num.toString() + "deg";
}

function rad(num) {
  return num.toString() + "rad";
}

function unsafeTransform(prop, value) {
  var tf = { };
  tf[prop] = value;
  return tf;
}

exports.unsafeAddProp = unsafeAddProp;
exports.pct = pct;
exports.deg = deg;
exports.rad = rad;
exports.unsafeTransform = unsafeTransform;
/* No side effect */
