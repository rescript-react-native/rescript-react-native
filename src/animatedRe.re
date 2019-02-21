module Animation = {
  type t;
  type endResult = {. "finished": bool};
  type endCallback = endResult => unit;
  [@bs.send]
  external _start: (t, Js.undefined(endCallback)) => unit = "start";
  let start = (t, ~callback=?, ()) =>
    _start(t, Js.Undefined.fromOption(callback));
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
    external makeConfig:
      (
        ~velocity: Val.rawJsType,
        ~deceleration: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?
      ) =>
      config =
      "";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _decay: (Val.t, config) => Animation.t = "decay";
    let animate =
        (
          ~value,
          ~velocity,
          ~deceleration=?,
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          (),
        ) =>
      _decay(
        value,
        makeConfig(
          ~velocity,
          ~deceleration?,
          ~isInteraction?,
          ~useNativeDriver?,
          ~onComplete?,
          ~iterations?,
        ),
      );
  };
  module Spring = {
    type toValue;
    type config;
    [@bs.obj]
    external makeConfig:
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
        ~iterations: int=?
      ) =>
      config =
      "";
    external toValueRaw: Val.rawJsType => toValue = "%identity";
    external toValueAnimated: Val.t => toValue = "%identity";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _spring: (Val.t, config) => Animation.t = "spring";
    let animate =
        (
          ~value,
          ~toValue,
          ~restDisplacementThreshold=?,
          ~overshootClamping=?,
          ~restSpeedThreshold=?,
          ~velocity=?,
          ~bounciness=?,
          ~speed=?,
          ~tension=?,
          ~friction=?,
          ~stiffness=?,
          ~mass=?,
          ~damping=?,
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          (),
        ) =>
      _spring(
        value,
        makeConfig(
          ~toValue=
            switch (toValue) {
            | `raw(x) => toValueRaw(x)
            | `animated(x) => toValueAnimated(x)
            },
          ~restDisplacementThreshold?,
          ~overshootClamping?,
          ~restSpeedThreshold?,
          ~velocity?,
          ~bounciness?,
          ~speed?,
          ~tension?,
          ~friction?,
          ~stiffness?,
          ~mass?,
          ~damping?,
          ~isInteraction?,
          ~useNativeDriver?,
          ~onComplete?,
          ~iterations?,
        ),
      );
  };
  module Timing = {
    type toValue;
    type config;
    [@bs.obj]
    external makeConfig:
      (
        ~toValue: toValue,
        ~easing: Easing.t=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?
      ) =>
      config =
      "";
    external toValueRaw: Val.rawJsType => toValue = "%identity";
    external toValueAnimated: Val.t => toValue = "%identity";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _timing: (Val.t, config) => Animation.t = "timing";
    let animate =
        (
          ~value,
          ~toValue,
          ~easing=?,
          ~duration=?,
          ~delay=?,
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          (),
        ) =>
      _timing(
        value,
        makeConfig(
          ~toValue=
            switch (toValue) {
            | `raw(x) => toValueRaw(x)
            | `animated(x) => toValueAnimated(x)
            },
          ~easing?,
          ~duration?,
          ~delay?,
          ~isInteraction?,
          ~useNativeDriver?,
          ~onComplete?,
          ~iterations?,
        ),
      );
  };
};

module Interpolation = {
  type t = value(calculated);
  type outputRange;
  external outputRangeCreate: 'a => outputRange = "%identity";
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let extrapolateString =
    fun
    | Extend => "extend"
    | Clamp => "clamp"
    | Identity => "identity";

  type config;
  [@bs.obj]
  external makeConfig:
    (
      ~inputRange: array(float),
      ~outputRange: outputRange,
      ~easing: Easing.t=?,
      ~extrapolate: string=?,
      ~extrapolateLeft: string=?,
      ~extrapolateRight: string=?
    ) =>
    config =
    "";
  [@bs.send] external _interpolate: (value('a), config) => t = "interpolate";
  let interpolate =
      (
        value,
        ~inputRange,
        ~outputRange,
        ~easing=?,
        ~extrapolate=?,
        ~extrapolateLeft=?,
        ~extrapolateRight=?,
        (),
      ) =>
    _interpolate(
      value,
      makeConfig(
        ~inputRange=Array.of_list(inputRange),
        ~outputRange=
          switch (outputRange) {
          | `string((x: list(string))) =>
            outputRangeCreate(Array.of_list(x))
          | `float((x: list(float))) => outputRangeCreate(Array.of_list(x))
          },
        ~easing?,
        ~extrapolate=?extrapolate->Belt.Option.map(extrapolateString),
        ~extrapolateRight=?
          extrapolateRight->Belt.Option.map(extrapolateString),
        ~extrapolateLeft=?extrapolateLeft->Belt.Option.map(extrapolateString),
      ),
    );
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
  external _resetAnimation: (t, Js.Undefined.t(callback)) => unit =
    "resetAnimation";
  [@bs.send]
  external _stopAnimation: (t, Js.Undefined.t(callback)) => unit =
    "stopAnimation";
  let resetAnimation = (value, ~callback=?, ()) =>
    _resetAnimation(value, Js.Undefined.fromOption(callback));
  let stopAnimation = (value, ~callback=?, ()) =>
    _stopAnimation(value, Js.Undefined.fromOption(callback));
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
  external _create: jsValue => t = "ValueXY";
  let create = (~x, ~y) => _create({"x": x, "y": y});
  [@bs.send] external _setValue: (t, jsValue) => unit = "setValue";
  let setValue = (t, ~x, ~y) => _setValue(t, {"x": x, "y": y});
  [@bs.send] external _setOffset: (t, jsValue) => unit = "setOffset";
  let setOffset = (t, ~x, ~y) => _setOffset(t, {"x": x, "y": y});
  [@bs.send] external flattenOffset: t => unit = "flattenOffset";
  [@bs.send] external extractOffset: t => unit = "extractOffset";
  [@bs.send]
  external resetAnimation: (t, option(callback)) => unit = "resetAnimation";
  [@bs.send]
  external stopAnimation: (t, option(callback)) => unit = "stopAnimation";
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

[@bs.module "react-native"] [@bs.scope "Animated"]
external _loop: (Animation.t, {. "iterations": int}) => Animation.t = "loop";

let loop = (~iterations=(-1), ~animation, ()) =>
  _loop(animation, {"iterations": iterations});

type animatedEvent;

[@bs.module "react-native"] [@bs.scope "Animated"]
external event: (array('a), 'b) => animatedEvent = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external createAnimatedComponent:
  ReasonReact.reactClass => ReasonReact.reactClass =
  "";

let timing = Value.Timing.animate;

let spring = Value.Spring.animate;

let decay = Value.Decay.animate;

let start = Animation.start;

let stop = Animation.stop;

let reset = Animation.reset;
