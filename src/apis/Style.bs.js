'use strict';


function pct(num) {
  return num + "%";
}

function deg(num) {
  return num + "deg";
}

function rad(num) {
  return num + "rad";
}

exports.pct = pct;
exports.deg = deg;
exports.rad = rad;
/* No side effect */
