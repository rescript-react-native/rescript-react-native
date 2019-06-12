

import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Printf from "bs-platform/lib/es6/printf.js";

function pct(f) {
  return Curry._1(Printf.sprintf(/* Format */[
                  /* Float */Block.__(8, [
                      /* Float_f */0,
                      /* No_padding */0,
                      /* Lit_precision */[2],
                      /* Char_literal */Block.__(12, [
                          /* "%" */37,
                          /* End_of_format */0
                        ])
                    ]),
                  "%.2f%%"
                ]), f);
}

function deg(f) {
  return Curry._1(Printf.sprintf(/* Format */[
                  /* Float */Block.__(8, [
                      /* Float_f */0,
                      /* No_padding */0,
                      /* Lit_precision */[2],
                      /* End_of_format */0
                    ]),
                  "%.2f"
                ]), f) + "deg";
}

var Encoder = /* module */[
  /* pct */pct,
  /* deg */deg
];

export {
  Encoder ,
  
}
/* No side effect */
