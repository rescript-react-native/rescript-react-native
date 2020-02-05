---
id: apis/Animated
title: Animated
wip: true
---

```reason
module Animation = {
  type t;
  type endResult = {. "finished": bool};
  type endCallback = endResult => unit;
  [@bs.send]
  external start: (t, ~endCallback: endCallback=?, unit) => unit = "start";

  [@bs.send] external stop: t => unit = "stop";
  [@bs.send] external reset: t => unit = "reset";
};

module type Value = {
  type t;
  type jsValue;
  type addListenerCallback;
};

type calculated;

type regular;

type value('a);

module ValueAnimations = (Val: Value) => {
  module Decay = {
    type config;

    [@bs.obj]
    external config:
      (
        ~velocity: Val.jsValue,
        ~deceleration: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      config =
      "";

    [@bs.module "react-native"] [@bs.scope "Animated"]
    external decay: (Val.t, config) => Animation.t = "decay";
  };

  module Spring = {
    type toValue;
    external fromRawValue: Val.jsValue => toValue = "%identity";
    external fromAnimatedValue: Val.t => toValue = "%identity";

    type config;

    [@bs.obj]
    external config:
      (
        ~toValue: toValue,
        ~restDisplacementThreshold: float=?,
        ~overshootClamping: bool=?,
        ~restSpeedThreshold: float=?,
        ~velocity: Val.jsValue=?,
        ~bounciness: float=?,
        ~speed: float=?,
        ~tension: float=?,
        ~friction: float=?,
        ~stiffness: float=?,
        ~mass: float=?,
        ~damping: float=?,
        ~delay: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      config =
      "";

    [@bs.module "react-native"] [@bs.scope "Animated"]
    external spring: (Val.t, config) => Animation.t = "spring";
  };

  module Timing = {
    type toValue;

    external fromRawValue: Val.jsValue => toValue = "%identity";
    external fromAnimatedValue: Val.t => toValue = "%identity";

    type config;

    [@bs.obj]
    external config:
      (
        ~toValue: toValue,
        ~easing: Easing.t=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      config =
      "";

    [@bs.module "react-native"] [@bs.scope "Animated"]
    external timing: (Val.t, config) => Animation.t = "timing";
  };
};

module Interpolation = {
  type t = value(calculated);
  type outputRange;
  external fromStringArray: array(string) => outputRange = "%identity";
  external fromFloatArray: array(float) => outputRange = "%identity";

  type config;
  [@bs.obj]
  external config:
    (
      ~inputRange: array(float),
      ~outputRange: outputRange,
      ~easing: Easing.t=?,
      ~extrapolate: [@bs.string] [ | `extend | `clamp | `identity]=?,
      ~extrapolateLeft: [@bs.string] [ | `extend | `clamp | `identity]=?,
      ~extrapolateRight: [@bs.string] [ | `extend | `clamp | `identity]=?,
      unit
    ) =>
    config =
    "";
  [@bs.send] external interpolate: (value('a), config) => t = "interpolate";
};

module ValueOperations = {
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external add: (value('a), value('b)) => value(calculated) = "add";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external divide: (value('a), value('b)) => value(calculated) = "divide";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external multiply: (value('a), value('b)) => value(calculated) =
    "multiply";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external modulo: (value('a), float) => value(calculated) = "modulo";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external subtract: (value('a), value('b)) => value(calculated) =
    "subtract";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external diffClamp: (value('a), float, float) => value(calculated) =
    "diffClamp";
  let interpolate = Interpolation.interpolate;
};

module ValueMethods = (Val: Value) => {
  type t = Val.t;
  type jsValue = Val.jsValue;
  type addListenerCallback = Val.addListenerCallback;
  type callback = jsValue => unit;

  [@bs.send] external setValue: (t, jsValue) => unit = "setValue";
  [@bs.send] external setOffset: (t, jsValue) => unit = "setOffset";
  [@bs.send] external flattenOffset: t => unit = "flattenOffset";
  [@bs.send] external extractOffset: t => unit = "extractOffset";
  [@bs.send]
  external addListener: (t, addListenerCallback) => string = "addListener";
  [@bs.send] external removeListener: (t, string) => unit = "removeListener";
  [@bs.send] external removeAllListeners: t => unit = "removeAllListeners";

  [@bs.send]
  external resetAnimation: (t, ~callback: callback=?, unit) => unit =
    "resetAnimation";

  [@bs.send]
  external stopAnimation: (t, ~callback: callback=?, unit) => unit =
    "stopAnimation";

  include ValueAnimations(Val);
};

module Value = {
  include ValueMethods({
    type t = value(regular);
    type jsValue = float;
    type addListenerCallback = {. "value": jsValue} => unit;
  });

  [@bs.new] [@bs.scope "Animated"] [@bs.module "react-native"]
  external create: float => t = "Value";

  include ValueOperations;
};

module ValueXY = {
  include ValueMethods({
    type t = {
      .
      "x": Value.t,
      "y": Value.t,
    };
    type jsValue = {
      .
      "x": float,
      "y": float,
    };
    type addListenerCallback = jsValue => unit;
  });

  [@bs.obj] external jsValue: (~x: float, ~y: float) => jsValue = "";

  type translateTransform = {
    .
    "translateX": Value.t,
    "translateY": Value.t,
  };
  type layout = {
    .
    "left": Value.t,
    "top": Value.t,
  };
  [@bs.new] [@bs.scope "Animated"] [@bs.module "react-native"]
  external create: jsValue => t = "ValueXY";
  [@bs.send] external getLayout: t => layout = "getLayout";
  [@bs.send]
  external getTranslateTransform: t => translateTransform =
    "getTranslateTransform";
};

[@bs.module "react-native"] [@bs.scope "Animated"]
external delay: float => Animation.t = "delay";

[@bs.module "react-native"] [@bs.scope "Animated"]
external sequence: array(Animation.t) => Animation.t = "sequence";

[@bs.module "react-native"] [@bs.scope "Animated"]
external parallel:
  (array(Animation.t), {. "stopTogether": bool}) => Animation.t =
  "parallel";

[@bs.module "react-native"] [@bs.scope "Animated"]
external stagger: (float, array(Animation.t)) => Animation.t = "stagger";

type loopConfig;

[@bs.obj] external loopConfig: (~iterations: int) => loopConfig = "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "Animated"]
external loop: Animation.t => Animation.t = "loop";

// multiple externals
[@bs.module "react-native"] [@bs.scope "Animated"]
external loopWithConfig: (Animation.t, loopConfig) => Animation.t = "loop";

type eventOptions('a);
[@bs.obj]
external eventOptions:
  (~listener: 'a=?, ~useNativeDriver: bool=?, unit) => eventOptions('a) =
  "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "Animated"]
external event1: (array('mapping), eventOptions('a)) => 'a = "event";

// multiple externals
[@bs.module "react-native"] [@bs.scope "Animated"]
external event2: (('mapping1, 'mapping2), eventOptions('a)) => 'a = "event";

[@bs.module "react-native"] [@bs.scope "Animated"]
external createAnimatedComponent:
  React.component('props) => React.component('props) =
  "createAnimatedComponent";

let timing = Value.Timing.timing;

let spring = Value.Spring.spring;

let decay = Value.Decay.decay;

let start = Animation.start;

let stop = Animation.stop;

let reset = Animation.reset;

module StyleProp = {
  // methods to allow use of Animated values with Style props

  // these methods should not be used to get the current value

  // for angle, Color.t, and size expressed as percentage,
  // interpolated values are needed where the outputRange is
  // an appropriate array of strings

  external float: value('a) => float = "%identity";
  external angle: value(calculated) => Style.angle = "%identity";
  external size: value('a) => Style.size = "%identity";
  external margin: value('a) => Style.margin = "%identity";
  external color: value(calculated) => Color.t = "%identity";

  // UNSAFE: allows to pass animated values everywhere,
  // use of more precise methods above is recommended
  external unsafeAny: value('a) => 'b = "%identity";
};

type animatedRef('ref);

external createAnimatedRef: React.Ref.t(Js.nullable('ref)) => animatedRef(React.Ref.t(Js.nullable('ref))) = "%identity";
[@bs.send] external getNode: (animatedRef(React.Ref.t(Js.nullable('ref))), unit) => React.Ref.t(Js.nullable('ref)) = "getNode";

module FlatList = {
  include FlatList.Make({
    type t = animatedRef(FlatList.ref);
  });

  let make = Obj.magic(createAnimatedComponent(make));
};

module Image = {
  include Image.Make({
    type t = animatedRef(Image.ref);
  });

  let make = createAnimatedComponent(make);
};

module ScrollView = {
  include ScrollView.Make({
    type t = animatedRef(ScrollView.ref);
  });

  let make = createAnimatedComponent(make);
};

module SectionList = {
  include SectionList.Make({
    type t = animatedRef(SectionList.ref);
  });

  let make = Obj.magic(createAnimatedComponent(make));
};

module Text = {
  include Text.Make({
    type t = animatedRef(Text.ref);
  });

  let make = createAnimatedComponent(make);
};

module View = {
  include View.Make({
    type t = animatedRef(View.ref);
  });

  let make = createAnimatedComponent(make);
};

```
