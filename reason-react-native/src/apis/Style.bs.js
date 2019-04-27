'use strict';


function deg(num) {
  return num.toString() + "deg";
}

function rad(num) {
  return num.toString() + "rad";
}

var Transform = /* module */[
  /* deg */deg,
  /* rad */rad
];

exports.Transform = Transform;
/* No side effect */
