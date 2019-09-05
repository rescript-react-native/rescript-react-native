'use strict';


function rgb(r, g, b) {
  return "rgb(" + (String(r) + (", " + (String(g) + (", " + (String(b) + ")")))));
}

function rgba(r, g, b, a) {
  return "rgba(" + (String(r) + (", " + (String(g) + (", " + (String(b) + (", " + (String(a) + ")")))))));
}

function hsl(h, s, l) {
  return "hsl(" + (String(h) + (", " + (String(s) + ("%, " + (String(l) + "%)")))));
}

function hsla(h, s, l, a) {
  return "hsl(" + (String(h) + (", " + (String(s) + ("%, " + (String(l) + ("%, " + (String(a) + ")")))))));
}

exports.rgb = rgb;
exports.rgba = rgba;
exports.hsl = hsl;
exports.hsla = hsla;
/* No side effect */
