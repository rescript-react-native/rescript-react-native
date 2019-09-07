'use strict';

var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReactNative = require("react-native");
var Text$ReactNative = require("../components/Text.bs.js");
var View$ReactNative = require("../components/View.bs.js");
var Image$ReactNative = require("../components/Image.bs.js");
var FlatList$ReactNative = require("../components/FlatList.bs.js");
var ScrollView$ReactNative = require("../components/ScrollView.bs.js");
var SectionList$ReactNative = require("../components/SectionList.bs.js");

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

function ValueMethods(Val) {
  var Decay = /* module */[];
  var Spring = /* module */[];
  var Timing = /* module */[];
  return /* module */[
          /* Decay */Decay,
          /* Spring */Spring,
          /* Timing */Timing
        ];
}

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

var StyleProp = /* module */[];

function make(props) {
  return React.createElement(ReactNative.Animated.createAnimatedComponent(ReactNative.FlatList), props);
}

var FlatList = /* module */[/* make */make];

var make$1 = ReactNative.Animated.createAnimatedComponent(ReactNative.Image);

var $$Image = /* module */[
  /* Source */Image$ReactNative.Source,
  /* DefaultSource */Image$ReactNative.DefaultSource,
  /* make */make$1
];

var make$2 = ReactNative.Animated.createAnimatedComponent(ReactNative.ScrollView);

var ScrollView = /* module */[/* make */make$2];

function make$3(props) {
  return React.createElement(ReactNative.Animated.createAnimatedComponent(ReactNative.SectionList), props);
}

var SectionList = /* module */[/* make */make$3];

var make$4 = ReactNative.Animated.createAnimatedComponent(ReactNative.Text);

var $$Text = /* module */[/* make */make$4];

var make$5 = ReactNative.Animated.createAnimatedComponent(ReactNative.View);

var View = /* module */[/* make */make$5];

exports.Animation = Animation;
exports.ValueAnimations = ValueAnimations;
exports.Interpolation = Interpolation;
exports.ValueOperations = ValueOperations;
exports.ValueMethods = ValueMethods;
exports.Value = Value;
exports.ValueXY = ValueXY;
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
/* make Not a pure module */
