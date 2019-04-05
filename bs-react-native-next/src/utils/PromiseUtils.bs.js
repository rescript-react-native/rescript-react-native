'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");

function nullableToOption(stringOrNull) {
  return Promise.resolve(stringOrNull === null ? undefined : Caml_option.some(stringOrNull));
}

exports.nullableToOption = nullableToOption;
/* No side effect */
