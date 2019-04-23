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

  [@bs.send] external stop: t => unit = "";
  [@bs.send] external reset: t => unit = "";
};

module type Value = {
  type t;
  type rawJsType;
};

type calculated;

type regular;

type value('a);

type valueXY;

module ValueAnimations = (Val: Value) => {
  module Decay = {
    type config;

    [@bs.obj]
    external config:
      (
        ~velocity: Val.rawJsType,
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
    external decay: (Val.t, config) => Animation.t = "";
  };

  module Spring = {
    type toValue;
    external fromRawValue: Val.rawJsType => toValue = "%identity";
    external fromAnimatedValue: Val.t => toValue = "%identity";

    type config;

    [@bs.obj]
    external config:
      (
        ~toValue: toValue,
        ~restDisplacementThreshold: float=?,
        ~overshootClamping: bool=?,
        ~restSpeedThreshold: float=?,
        ~velocity: Val.rawJsType=?,
        ~bounciness: float=?,
        ~speed: float=?,
        ~tension: float=?,
        ~friction: float=?,
        ~stiffness: float=?,
        ~mass: float=?,
        ~damping: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      config =
      "";

    [@bs.module "react-native"] [@bs.scope "Animated"]
    external spring: (Val.t, config) => Animation.t = "";
  };

  module Timing = {
    type toValue;

    external fromRawValue: Val.rawJsType => toValue = "%identity";
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
    external timing: (Val.t, config) => Animation.t = "";
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
  external add: (value('a), value('b)) => value(calculated) = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external divide: (value('a), value('b)) => value(calculated) = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external multiply: (value('a), value('b)) => value(calculated) = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external modulo: (value('a), float) => value(calculated) = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external subtract: (value('a), value('b)) => value(calculated) = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external diffClamp: (value('a), float, float) => value(calculated) = "";
  let interpolate = Interpolation.interpolate;
};

module Value = {
  type t = value(regular);
  type jsValue = {. "value": float};
  type callback = jsValue => unit;
  [@bs.new] [@bs.scope "Animated"] [@bs.module "react-native"]
  external create: float => t = "Value";
  [@bs.send] external setValue: (t, float) => unit = "setValue";
  [@bs.send] external setOffset: (t, float) => unit = "setOffset";
  [@bs.send] external flattenOffset: t => unit = "flattenOffset";
  [@bs.send] external extractOffset: t => unit = "extractOffset";
  [@bs.send] external addListener: (t, callback) => string = "addListener";
  [@bs.send] external removeListener: (t, string) => unit = "removeListener";
  [@bs.send] external removeAllListeners: t => unit = "removeAllListeners";

  [@bs.send]
  external resetAnimation: (t, ~callback: callback=?, unit) => unit =
    "resetAnimation";

  [@bs.send]
  external stopAnimation: (t, ~callback: callback=?, unit) => unit =
    "stopAnimation";

  include ValueAnimations({
    type t = value(regular);
    type rawJsType = float;
  });
  include ValueOperations;
};

module ValueXY = {
  type t = valueXY;
  type jsValue = {
    .
    "x": float,
    "y": float,
  };
  type callback = jsValue => unit;
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

  [@bs.send] external setValue: (t, jsValue) => unit = "";
  [@bs.send] external setOffset: (t, jsValue) => unit = "";
  [@bs.send] external flattenOffset: t => unit = "flattenOffset";
  [@bs.send] external extractOffset: t => unit = "extractOffset";
  [@bs.send]
  external resetAnimation: (t, ~callback: callback=?, unit) => unit =
    "resetAnimation";

  [@bs.send]
  external stopAnimation: (t, ~callback: callback=?, unit) => unit =
    "stopAnimation";
  [@bs.send] external addListener: (t, callback) => string = "addListener";
  [@bs.send] external removeListener: (t, string) => unit = "removeListener";
  [@bs.send] external removeAllListeners: t => unit = "removeAllListeners";
  [@bs.send] external getLayout: t => layout = "getLayout";
  [@bs.send]
  external getTranslateTransform: t => translateTransform =
    "getTranslateTransform";
  [@bs.get] external getX: t => Value.t = "x";
  [@bs.get] external getY: t => Value.t = "y";
  include ValueAnimations({
    type t = valueXY;
    type rawJsType = jsValue;
  });
};

[@bs.module "react-native"] [@bs.scope "Animated"]
external delay: float => Animation.t = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external sequence: array(Animation.t) => Animation.t = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external parallel:
  (array(Animation.t), {. "stopTogether": bool}) => Animation.t =
  "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external stagger: (float, array(Animation.t)) => Animation.t = "";

type loopConfig;

[@bs.obj] external loopConfig: (~iterations: int) => loopConfig = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external loop: Animation.t => Animation.t = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external loopWithConfig: (Animation.t, loopConfig) => Animation.t = "";

type animatedEvent;

[@bs.module "react-native"] [@bs.scope "Animated"]
external event: (array('a), 'b) => animatedEvent = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external createAnimatedComponent:
  React.component('props) => React.component('props) =
  "";

let timing = Value.Timing.timing;

let spring = Value.Spring.spring;

let decay = Value.Decay.decay;

let start = Animation.start;

let stop = Animation.stop;

let reset = Animation.reset;

// Unsafe, unfortunately, but allows us to pass animated values everywhere.
// May be refined later.
external animatedStyle: value('a) => 'b = "%identity";

module Image = {
  include Image;

  let make = createAnimatedComponent(make);
};

module ScrollView = {
  include ScrollView;

  let make = createAnimatedComponent(make);
};

module Text = {
  include Text;

  let make = createAnimatedComponent(make);
};

module View = {
  include View;

  let make = createAnimatedComponent(View.make);
};

```
