'use strict';


function compose(a, b) {
  return [
          a,
          b
        ];
}

var Infix;

exports.compose = compose;
exports.Infix = Infix;
/* No side effect */
