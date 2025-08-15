'use strict';

var Caml_option = require("rescript/lib/js/caml_option.js");
var ReactNative = require("react-native");

var $$Animation = {};

function ValueAnimations(Val) {
  var Decay = {};
  var Spring = {};
  var Timing = {};
  return {
          Decay: Decay,
          Spring: Spring,
          Timing: Timing
        };
}

var Interpolation = {};

function interpolate(prim0, prim1) {
  return prim0.interpolate(prim1);
}

var ValueOperations = {
  interpolate: interpolate
};

function ValueMethods(Val) {
  var Decay = {};
  var Spring = {};
  var Timing = {};
  return {
          Decay: Decay,
          Spring: Spring,
          Timing: Timing
        };
}

var Decay = {};

var Spring = {};

var Timing = {};

var Value = {
  Decay: Decay,
  Spring: Spring,
  Timing: Timing,
  interpolate: interpolate
};

var Decay$1 = {};

var Spring$1 = {};

var Timing$1 = {};

var ValueXY = {
  Decay: Decay$1,
  Spring: Spring$1,
  Timing: Timing$1
};

var Decay$2 = {};

var Spring$2 = {};

var Timing$2 = {};

var Color = {
  Decay: Decay$2,
  Spring: Spring$2,
  Timing: Timing$2
};

function timing(prim0, prim1) {
  return ReactNative.Animated.timing(prim0, prim1);
}

function spring(prim0, prim1) {
  return ReactNative.Animated.spring(prim0, prim1);
}

function decay(prim0, prim1) {
  return ReactNative.Animated.decay(prim0, prim1);
}

function start(prim0, prim1) {
  prim0.start(prim1 !== undefined ? Caml_option.valFromOption(prim1) : undefined);
}

function stop(prim) {
  prim.stop();
}

function reset(prim) {
  prim.reset();
}

var StyleProp = {};

var FlatList = {};

var $$Image = {};

var ScrollView = {};

var SectionList = {};

var $$Text = {};

var View = {};

exports.$$Animation = $$Animation;
exports.ValueAnimations = ValueAnimations;
exports.Interpolation = Interpolation;
exports.ValueOperations = ValueOperations;
exports.ValueMethods = ValueMethods;
exports.Value = Value;
exports.ValueXY = ValueXY;
exports.Color = Color;
exports.timing = timing;
exports.spring = spring;
exports.decay = decay;
exports.start = start;
exports.stop = stop;
exports.reset = reset;
exports.StyleProp = StyleProp;
exports.FlatList = FlatList;
exports.$$Image = $$Image;
exports.ScrollView = ScrollView;
exports.SectionList = SectionList;
exports.$$Text = $$Text;
exports.View = View;
/* react-native Not a pure module */
