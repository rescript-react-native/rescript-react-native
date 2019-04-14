'use strict';


function pct(num) {
  return num.toString() + "%";
}

var Margin = /* module */[
  /* pct */pct,
  /* auto */"auto"
];

var Size = /* module */[/* pct */pct];

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

var FontVariant = /* module */[];

exports.pct = pct;
exports.Margin = Margin;
exports.Size = Size;
exports.Transform = Transform;
exports.FontVariant = FontVariant;
/* No side effect */
