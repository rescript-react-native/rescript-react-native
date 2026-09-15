

import * as ReactNative from "react-native";
import * as Primitive_option from "@rescript/runtime/lib/es6/Primitive_option.js";

let Animation = {};

function ValueAnimations(Val) {
  let Decay = {};
  let Spring = {};
  let Timing = {};
  return {
    Decay: Decay,
    Spring: Spring,
    Timing: Timing
  };
}

let Interpolation = {};

function interpolate(prim0, prim1) {
  return prim0.interpolate(prim1);
}

let ValueOperations = {
  interpolate: interpolate
};

function ValueMethods(Val) {
  let Decay = {};
  let Spring = {};
  let Timing = {};
  return {
    Decay: Decay,
    Spring: Spring,
    Timing: Timing
  };
}

let Decay = {};

let Spring = {};

let Timing = {};

let Value = {
  Decay: Decay,
  Spring: Spring,
  Timing: Timing,
  interpolate: interpolate
};

let Decay$1 = {};

let Spring$1 = {};

let Timing$1 = {};

let ValueXY = {
  Decay: Decay$1,
  Spring: Spring$1,
  Timing: Timing$1
};

let Decay$2 = {};

let Spring$2 = {};

let Timing$2 = {};

let Color = {
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
  prim0.start(prim1 !== undefined ? Primitive_option.valFromOption(prim1) : undefined);
}

function stop(prim) {
  prim.stop();
}

function reset(prim) {
  prim.reset();
}

let StyleProp = {};

let FlatList = {};

let Image = {};

let ScrollView = {};

let SectionList = {};

let Text = {};

let View = {};

export {
  Animation,
  ValueAnimations,
  Interpolation,
  ValueOperations,
  ValueMethods,
  Value,
  ValueXY,
  Color,
  timing,
  spring,
  decay,
  start,
  stop,
  reset,
  StyleProp,
  FlatList,
  Image,
  ScrollView,
  SectionList,
  Text,
  View,
}
/* react-native Not a pure module */
