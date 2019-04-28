'use strict';


function deg(num) {
  return num.toString() + "deg";
}

function rad(num) {
  return num.toString() + "rad";
}

exports.deg = deg;
exports.rad = rad;
/* No side effect */
