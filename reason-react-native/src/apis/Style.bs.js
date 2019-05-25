'use strict';


function unsafeAddStyle(style, styles) {
  return Object.assign({ }, style, styles);
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

exports.unsafeAddStyle = unsafeAddStyle;
exports.pct = pct;
exports.deg = deg;
exports.rad = rad;
/* No side effect */
