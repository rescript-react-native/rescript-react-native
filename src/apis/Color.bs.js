'use strict';


function rgb(r, g, b) {
  return "rgb(" + r.toString() + ", " + g.toString() + ", " + b.toString() + ")";
}

function rgba(r, g, b, a) {
  return "rgba(" + r.toString() + ", " + g.toString() + ", " + b.toString() + ", " + a.toString() + ")";
}

function hsl(h, s, l) {
  return "hsl(" + h.toString() + ", " + s.toString() + "%, " + l.toString() + "%)";
}

function hsla(h, s, l, a) {
  return "hsl(" + h.toString() + ", " + s.toString() + "%, " + l.toString() + "%, " + a.toString() + ")";
}

exports.rgb = rgb;
exports.rgba = rgba;
exports.hsl = hsl;
exports.hsla = hsla;
/* No side effect */
