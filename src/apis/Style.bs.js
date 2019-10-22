'use strict';


var GetProp = { };

function pct(num) {
  return num.toString() + "%";
}

function deg(num) {
  return num.toString() + "deg";
}

function rad(num) {
  return num.toString() + "rad";
}

exports.GetProp = GetProp;
exports.pct = pct;
exports.deg = deg;
exports.rad = rad;
/* No side effect */
