module Animation = {
  type t;
  type endResult = {. "finished": Js.boolean};
  type endCallback = endResult => unit;
};

module type Value = {type t; type rawJsType;};

module CompositeAnimation = {
  type t;
  [@bs.send] external _start : (t, Js.undefined(Animation.endCallback)) => unit = "start";
  let start = (t, ~callback=?, ()) => _start(t, Js.Undefined.from_opt(callback));
  [@bs.send] external stop : t => unit = "";
  [@bs.send] external reset : t => unit = "";
};

module Animations = {
  module Decay = (Val: Value) => {
    type config;
    [@bs.obj]
    external makeConfig :
      (
        ~velocity: Val.rawJsType,
        ~deceleration: float=?,
        ~isInteraction: Js.boolean=?,
        ~useNativeDriver: Js.boolean=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?
      ) =>
      config =
      "";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _decay : (Val.t, config) => CompositeAnimation.t =
      "decay";
    let animate =
        (
          ~value,
          ~velocity,
          ~deceleration=?,
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          ()
        ) =>
      _decay(
        value,
        makeConfig(
          ~velocity,
          ~deceleration?,
          ~isInteraction=?UtilsRN.optBoolToOptJsBoolean(isInteraction),
          ~useNativeDriver=?UtilsRN.optBoolToOptJsBoolean(useNativeDriver),
          ~onComplete?,
          ~iterations?
        )
      );
  };
  module Spring = (Val: Value) => {
    type toValue;
    type config = {
      .
      "toValue": toValue,
      "restDisplacementThreshold": Js.undefined(float),
      "overshootClamping": Js.undefined(Js.boolean),
      "restSpeedThreshold": Js.undefined(float),
      "velocity": Js.undefined(Val.rawJsType),
      "bounciness": Js.undefined(float),
      "speed": Js.undefined(float),
      "tension": Js.undefined(float),
      "friction": Js.undefined(float),
      "isInteraction": Js.undefined(Js.boolean),
      "useNativeDriver": Js.undefined(Js.boolean),
      "onComplete": Js.undefined(Animation.endCallback),
      "iterations": Js.undefined(int)
    };
    external toValueRaw : Val.rawJsType => toValue = "%identity";
    external toValueAnimated : Val.t => toValue = "%identity";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _spring : (Val.t, config) => CompositeAnimation.t =
      "spring";
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
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          ()
        ) =>
      _spring(
        value,
        Js.Undefined.(
          {
            "toValue":
              switch toValue {
              | `raw(x) => toValueRaw(x)
              | `animated(x) => toValueAnimated(x)
              },
            "restDisplacementThreshold": from_opt(restDisplacementThreshold),
            "overshootClamping": from_opt(overshootClamping),
            "restSpeedThreshold": from_opt(restSpeedThreshold),
            "velocity": from_opt(velocity),
            "bounciness": from_opt(bounciness),
            "speed": from_opt(speed),
            "tension": from_opt(tension),
            "friction": from_opt(friction),
            "isInteraction": from_opt(isInteraction),
            "useNativeDriver": from_opt(useNativeDriver),
            "onComplete": from_opt(onComplete),
            "iterations": from_opt(iterations)
          }
        )
      );
  };
  module Timing = (Val: Value) => {
    type toValue;
    type config;
    [@bs.obj]
    external makeConfig :
      (
        ~toValue: toValue,
        ~easing: float => float=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: Js.boolean=?,
        ~useNativeDriver: Js.boolean=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?
      ) =>
      config =
      "";
    external toValueRaw : Val.rawJsType => toValue = "%identity";
    external toValueAnimated : Val.t => toValue = "%identity";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _timing : (Val.t, config) => CompositeAnimation.t =
      "timing";
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
          ()
        ) =>
      _timing(
        value,
        makeConfig(
          ~toValue=
            switch toValue {
            | `raw(x) => toValueRaw(x)
            | `animated(x) => toValueAnimated(x)
            },
          ~easing?,
          ~duration?,
          ~delay?,
          ~isInteraction?,
          ~useNativeDriver?,
          ~onComplete?,
          ~iterations?
        )
      );
  };
};

module ValueOperations = (Val: Value) => {
  [@bs.module "react-native"] [@bs.scope "Animated"] external add : (Val.t, Val.t) => Val.t = "";
  [@bs.module "react-native"] [@bs.scope "Animated"] external divide : (Val.t, Val.t) => Val.t =
    "";
  [@bs.module "react-native"] [@bs.scope "Animated"] external multiply : (Val.t, Val.t) => Val.t =
    "";
  module Timing = Animations.Timing(Val);
  module Spring = Animations.Spring(Val);
  module Decay = Animations.Decay(Val);
};

module Interpolation = {
  type t;
  type outputRange;
  external outputRangeCreate : 'a => outputRange = "%identity";
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let extrapolateString = (x) =>
    switch x {
    | Extend => "extend"
    | Clamp => "clamp"
    | Identity => "identity"
    };
  type config;
  [@bs.obj]
  external makeConfig :
    (
      ~inputRange: array(float),
      ~outputRange: outputRange,
      ~easing: float => float=?,
      ~extrapolate: string=?,
      ~extrapolateLeft: string=?,
      ~extrapolateRight: string=?
    ) =>
    config =
    "";
  [@bs.send] external _interpolate : (t, config) => t = "interpolate";
  let interpolate =
      (
        ~value,
        ~inputRange,
        ~outputRange,
        ~easing=?,
        ~extrapolate=?,
        ~extrapolateLeft=?,
        ~extrapolateRight=?,
        ()
      ) =>
    _interpolate(
      value,
      makeConfig(
        ~inputRange=Array.of_list(inputRange),
        ~outputRange=
          switch outputRange {
          | `string((x: list(string))) => outputRangeCreate(Array.of_list(x))
          | `float((x: list(float))) => outputRangeCreate(Array.of_list(x))
          },
        ~easing?,
        ~extrapolate=?UtilsRN.option_map(extrapolateString, extrapolate),
        ~extrapolateRight=?UtilsRN.option_map(extrapolateString, extrapolateRight),
        ~extrapolateLeft=?UtilsRN.option_map(extrapolateString, extrapolateLeft)
      )
    );
};

module Value = {
  type t;
  type callback = float => unit;
  [@bs.new] [@bs.scope "Animated"] [@bs.module "react-native"] external create : float => t =
    "Value";
  [@bs.send] external setValue : (t, float) => unit = "setValue";
  [@bs.send] external setOffset : (t, float) => unit = "setOffset";
  [@bs.send] external flattenOffset : t => unit = "flattenOffset";
  [@bs.send] external extractOffset : t => unit = "extractOffset";
  [@bs.send] external addListener : (t, callback) => string = "addListener";
  [@bs.send] external removeListener : (t, string) => unit = "removeListener";
  [@bs.send] external removeAllListeners : t => unit = "removeAllListeners";
  [@bs.send] external _resetAnimation : (t, Js.Undefined.t(callback)) => unit = "resetAnimation";
  [@bs.send] external _stopAnimation : (t, Js.Undefined.t(callback)) => unit = "stopAnimation";
  let resetAnimation = (value, ~callback=?, ()) =>
    _resetAnimation(value, Js.Undefined.from_opt(callback));
  let stopAnimation = (value, ~callback=?, ()) =>
    _stopAnimation(value, Js.Undefined.from_opt(callback));
  [@bs.send] external _interpolate : (t, Interpolation.config) => Interpolation.t = "interpolate";
  let interpolate =
      (
        value,
        ~inputRange,
        ~outputRange,
        ~easing=?,
        ~extrapolate=?,
        ~extrapolateLeft=?,
        ~extrapolateRight=?,
        ()
      ) =>
    _interpolate(
      value,
      Interpolation.makeConfig(
        ~inputRange=Array.of_list(inputRange),
        ~outputRange=
          switch outputRange {
          | `string((x: list(string))) => Interpolation.outputRangeCreate(Array.of_list(x))
          | `float((x: list(float))) => Interpolation.outputRangeCreate(Array.of_list(x))
          },
        ~easing?,
        ~extrapolate=?UtilsRN.option_map(Interpolation.extrapolateString, extrapolate),
        ~extrapolateLeft=?UtilsRN.option_map(Interpolation.extrapolateString, extrapolateLeft),
        ~extrapolateRight=?UtilsRN.option_map(Interpolation.extrapolateString, extrapolateRight)
      )
    );
  [@bs.send] external animate : (t, Animation.t, Animation.endCallback) => unit = "animate";
  [@bs.send] external stopTracking : t => unit = "stopTracking";
  [@bs.send] external track : t => unit = "track";
  [@bs.module "react-native"] [@bs.scope "Animated"] external modulo : (t, float) => t = "";
  [@bs.module "react-native"] [@bs.scope "Animated"] external diffClamp : (t, float, float) => t =
    "";
  type value = t;
  include
    ValueOperations(
      {
        type t = value;
        type rawJsType = float;
      }
    );
};

module ValueXY = {
  type t;
  type jsValue = {. "x": float, "y": float};
  type callback = jsValue => unit;
  type translateTransform = {. "translateX": Value.t, "translateY": Value.t};
  type layout = {. "left": Value.t, "top": Value.t};
  [@bs.new] [@bs.scope "Animated"] [@bs.module "react-native"] external _create : jsValue => t =
    "ValueXY";
  let create = (~x, ~y) => _create({"x": x, "y": y});
  [@bs.send] external _setValue : (t, jsValue) => unit = "setValue";
  let setValue = (t, ~x, ~y) => _setValue(t, {"x": x, "y": y});
  [@bs.send] external _setOffset : (t, jsValue) => unit = "setOffset";
  let setOffset = (t, ~x, ~y) => _setOffset(t, {"x": x, "y": y});
  [@bs.send] external flattenOffset : t => unit = "flattenOffset";
  [@bs.send] external extractOffset : t => unit = "extractOffset";
  [@bs.send] external resetAnimation : (t, option(callback)) => unit = "resetAnimation";
  [@bs.send] external stopAnimation : (t, option(callback)) => unit = "stopAnimation";
  [@bs.send] external addListener : (t, callback) => string = "addListener";
  [@bs.send] external removeListener : (t, string) => unit = "removeListener";
  [@bs.send] external removeAllListeners : t => unit = "removeAllListeners";
  [@bs.send] external getLayout : t => layout = "getLayout";
  [@bs.send] external getTranslateTransform : t => translateTransform = "getTranslateTransform";
  [@bs.get] external getX : t => Value.t = "x";
  [@bs.get] external getY : t => Value.t = "y";
  type value = t;
  include
    ValueOperations(
      {
        type t = value;
        type rawJsType = jsValue;
      }
    );
};

[@bs.module "react-native"] [@bs.scope "Animated"] external delay : float => CompositeAnimation.t =
  "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external sequence : array(CompositeAnimation.t) => CompositeAnimation.t =
  "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external parallel :
  (array(CompositeAnimation.t), {. "stopTogether": Js.boolean}) => CompositeAnimation.t =
  "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external stagger : (float, array(CompositeAnimation.t)) => CompositeAnimation.t =
  "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external _loop : (CompositeAnimation.t, {. "iterations": int}) => CompositeAnimation.t =
  "loop";

type animatedEvent;

[@bs.module "react-native"] [@bs.scope "Animated"]
external event : (array('a), 'b) => animatedEvent =
  "";

let loop = (~iterations=(-1), ~animation, ()) => _loop(animation, {"iterations": iterations});

module Timing = Value.Timing;

module TimingXY = ValueXY.Timing;

module Spring = Value.Spring;

module SpringXY = ValueXY.Spring;

module Decay = Value.Decay;

module DecayXY = ValueXY.Decay;
