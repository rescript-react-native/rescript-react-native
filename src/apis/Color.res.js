


function rgb(r, g, b) {
  return `rgb(` + r.toString() + `, ` + g.toString() + `, ` + b.toString() + `)`;
}

function rgba(r, g, b, a) {
  return `rgba(` + r.toString() + `, ` + g.toString() + `, ` + b.toString() + `, ` + a.toString() + `)`;
}

function hsl(h, s, l) {
  return `hsl(` + h.toString() + `, ` + s.toString() + `%, ` + l.toString() + `%)`;
}

function hsla(h, s, l, a) {
  return `hsl(` + h.toString() + `, ` + s.toString() + `%, ` + l.toString() + `%, ` + a.toString() + `)`;
}

export {
  rgb,
  rgba,
  hsl,
  hsla,
}
/* No side effect */
