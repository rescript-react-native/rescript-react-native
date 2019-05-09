module Animation = {
  type t;
  type endResult = {. "finished": bool};
  type endCallback = endResult => unit;
  [@bs.send]
  external start: (t, ~endCallback: endCallback=?, unit) => unit = "";

  [@bs.send] external stop: t => unit = "";
  [@bs.send] external reset: t => unit = "";
};

module type Value = {
  type t;
  type jsValue;
  type rawJsType;
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
  [@bs.send] external interpolate: (value('a), config) => t = "";
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

module ValueMethods = (Val: Value) => {
  type t = Val.t;
  type jsValue = Val.jsValue;
  type rawJsType = Val.rawJsType;

  type callback = jsValue => unit;

  [@bs.send] external setValue: (t, rawJsType) => unit = "";
  [@bs.send] external setOffset: (t, rawJsType) => unit = "";
  [@bs.send] external flattenOffset: t => unit = "";
  [@bs.send] external extractOffset: t => unit = "";
  [@bs.send] external addListener: (t, callback) => string = "";
  [@bs.send] external removeListener: (t, string) => unit = "";
  [@bs.send] external removeAllListeners: t => unit = "";

  [@bs.send]
  external resetAnimation: (t, ~callback: callback=?, unit) => unit = "";

  [@bs.send]
  external stopAnimation: (t, ~callback: callback=?, unit) => unit = "";

  include ValueAnimations(Val);
};

module Value = {
  include ValueMethods({
    type t = value(regular);
    type jsValue = {. "value": float};
    type rawJsType = float;
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
    type rawJsType = jsValue;
  });

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
  [@bs.send] external getLayout: t => layout = "";
  [@bs.send] external getTranslateTransform: t => translateTransform = "";
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
external loopWithConfig: (Animation.t, loopConfig) => Animation.t = "loop";

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
