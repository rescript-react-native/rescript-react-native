'use strict';


function pct(num) {
  return num.toString() + "%";
}

var AspectRatio = {};

function deg(num) {
  return num.toString() + "deg";
}

function rad(num) {
  return num.toString() + "rad";
}

var FontWeight = {};

var empty = {};

exports.pct = pct;
exports.AspectRatio = AspectRatio;
exports.deg = deg;
exports.rad = rad;
exports.FontWeight = FontWeight;
exports.empty = empty;
/* No side effect */
