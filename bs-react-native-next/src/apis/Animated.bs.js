'use strict';

var Js_undefined = require("bs-platform/lib/js/js_undefined.js");
var ReactNative = require("react-native");

function start(t, callback, param) {
  t.start(Js_undefined.fromOption(callback));
  return /* () */0;
}

var Animation = /* module */[/* start */start];

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

function resetAnimation(value, callback, param) {
  value.resetAnimation(Js_undefined.fromOption(callback));
  return /* () */0;
}

function stopAnimation(value, callback, param) {
  value.stopAnimation(Js_undefined.fromOption(callback));
  return /* () */0;
}

var Decay = /* module */[];

var Spring = /* module */[];

var Timing = /* module */[];

var Value = /* module */[
  /* resetAnimation */resetAnimation,
  /* stopAnimation */stopAnimation,
  /* Decay */Decay,
  /* Spring */Spring,
  /* Timing */Timing,
  /* interpolate */interpolate
];

function create(x, y) {
  return new (ReactNative.Animated.ValueXY)({
              x: x,
              y: y
            });
}

function setValue(t, x, y) {
  t.setValue({
        x: x,
        y: y
      });
  return /* () */0;
}

function setOffset(t, x, y) {
  t.setOffset({
        x: x,
        y: y
      });
  return /* () */0;
}

var Decay$1 = /* module */[];

var Spring$1 = /* module */[];

var Timing$1 = /* module */[];

var ValueXY = /* module */[
  /* create */create,
  /* setValue */setValue,
  /* setOffset */setOffset,
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
