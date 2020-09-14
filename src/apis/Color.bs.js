'use strict';


function rgb(r, g, b) {
  return "rgb(" + r + ", " + g + ", " + b + ")";
}

function rgba(r, g, b, a) {
  return "rgba(" + r + ", " + g + ", " + b + ", " + a + ")";
}

function hsl(h, s, l) {
  return "hsl(" + h + ", " + s + "%, " + l + "%)";
}

function hsla(h, s, l, a) {
  return "hsl(" + h + ", " + s + "%, " + l + "%, " + a + ")";
}

exports.rgb = rgb;
exports.rgba = rgba;
exports.hsl = hsl;
exports.hsla = hsla;
/* No side effect */
