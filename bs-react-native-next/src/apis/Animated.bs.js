'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReactNative = require("react-native");

var Animation = /* module */[];

function ValueAnimations(Val) {
  var Decay = /* module */[];
  var Spring = /* module */[];
  var Timing = /* module */[];
  return /* module */[
          /* Decay */Decay,
          /* Spring */Spring,
          /* Timing */Timing
        ];
}

var Interpolation = /* module */[];

function interpolate(prim, prim$1) {
  return prim.interpolate(prim$1);
}

var ValueOperations = /* module */[/* interpolate */interpolate];

var Decay = /* module */[];

var Spring = /* module */[];

var Timing = /* module */[];

var Value = /* module */[
  /* Decay */Decay,
  /* Spring */Spring,
  /* Timing */Timing,
  /* interpolate */interpolate
];

var Decay$1 = /* module */[];

var Spring$1 = /* module */[];

var Timing$1 = /* module */[];

var ValueXY = /* module */[
  /* Decay */Decay$1,
  /* Spring */Spring$1,
  /* Timing */Timing$1
];

function loop($staropt$star, animation, param) {
  var iterations = $staropt$star !== undefined ? $staropt$star : -1;
  return ReactNative.Animated.loop(animation, {
              iterations: iterations
            });
}

function timing(prim, prim$1) {
  return ReactNative.Animated.timing(prim, prim$1);
}

function spring(prim, prim$1) {
  return ReactNative.Animated.spring(prim, prim$1);
}

function decay(prim, prim$1) {
  return ReactNative.Animated.decay(prim, prim$1);
}

function start(prim, prim$1, prim$2) {
  prim.start(prim$1 !== undefined ? Caml_option.valFromOption(prim$1) : undefined);
  return /* () */0;
}

function stop(prim) {
  prim.stop();
  return /* () */0;
}

function reset(prim) {
  prim.reset();
  return /* () */0;
}

exports.Animation = Animation;
exports.ValueAnimations = ValueAnimations;
exports.Interpolation = Interpolation;
exports.ValueOperations = ValueOperations;
exports.Value = Value;
exports.ValueXY = ValueXY;
exports.loop = loop;
exports.timing = timing;
exports.spring = spring;
exports.decay = decay;
exports.start = start;
exports.stop = stop;
exports.reset = reset;
/* react-native Not a pure module */
