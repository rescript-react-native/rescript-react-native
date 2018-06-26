type calculated;

type regular;

type value('a);

type valueXY('a);

module Animation: {
  type t;
  type endResult = {. "finished": bool};
  type endCallback = endResult => unit;
  let stop: t => unit;
  let start: (t, ~callback: endCallback=?, unit) => unit;
  let reset: t => unit;
};

module Interpolation: {
  type t = value(calculated);
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let interpolate:
    (
      value('a),
      ~inputRange: list(float),
      ~outputRange: [< | `float(list(float)) | `string(list(string))],
      ~easing: Easing.t=?,
      ~extrapolate: extrapolate=?,
      ~extrapolateLeft: extrapolate=?,
      ~extrapolateRight: extrapolate=?,
      unit
    ) =>
    t;
};

module Value: {
  type t = value(regular);
  type jsValue = {. "value": float};
  type callback = jsValue => unit;
  let create: float => t;
  let setValue: (t, float) => unit;
  let setOffset: (t, float) => unit;
  let flattenOffset: t => unit;
  let extractOffset: t => unit;
  let addListener: (t, callback) => string;
  let removeListener: (t, string) => unit;
  let removeAllListeners: t => unit;
  let resetAnimation: (t, ~callback: callback=?, unit) => unit;
  let stopAnimation: (t, ~callback: callback=?, unit) => unit;
  let interpolate:
    (
      value('a),
      ~inputRange: list(float),
      ~outputRange: [< | `float(list(float)) | `string(list(string))],
      ~easing: Easing.t=?,
      ~extrapolate: Interpolation.extrapolate=?,
      ~extrapolateLeft: Interpolation.extrapolate=?,
      ~extrapolateRight: Interpolation.extrapolate=?,
      unit
    ) =>
    Interpolation.t;
  let animate: (t, Animation.t, Animation.endCallback) => unit;
  let stopTracking: t => unit;
  let track: t => unit;
  module Timing: {
    type config;
    let animate:
      (
        ~value: value(regular),
        ~toValue: [ | `raw(float) | `animated(value(regular))],
        ~easing: Easing.t=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  module Spring: {
    type config;
    let animate:
      (
        ~value: value(regular),
        ~toValue: [ | `raw(float) | `animated(value(regular))],
        ~restDisplacementThreshold: float=?,
        ~overshootClamping: bool=?,
        ~restSpeedThreshold: float=?,
        ~velocity: float=?,
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
      Animation.t;
  };
  module Decay: {
    type config;
    let animate:
      (
        ~value: value(regular),
        ~velocity: float,
        ~deceleration: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  let add: (value('a), value('b)) => value(calculated);
  let divide: (value('a), value('b)) => value(calculated);
  let multiply: (value('a), value('b)) => value(calculated);
  let modulo: (value('a), float) => value(calculated);
  let diffClamp: (value('a), float, float) => value(calculated);
};

module ValueXY: {
  type t = valueXY(regular);
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
  let create: (~x: float, ~y: float) => t;
  let setValue: (t, ~x: float, ~y: float) => unit;
  let setOffset: (t, ~x: float, ~y: float) => unit;
  let flattenOffset: t => unit;
  let extractOffset: t => unit;
  let resetAnimation: (t, option(callback)) => unit;
  let stopAnimation: (t, option(callback)) => unit;
  let addListener: (t, callback) => string;
  let removeListener: (t, string) => unit;
  let removeAllListeners: t => unit;
  let getLayout: t => layout;
  let getTranslateTransform: t => translateTransform;
  let getX: t => Value.t;
  let getY: t => Value.t;
  module Timing: {
    type config;
    let animate:
      (
        ~value: valueXY(regular),
        ~toValue: [ | `raw(jsValue) | `animated(valueXY(regular))],
        ~easing: Easing.t=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  module Spring: {
    type config;
    let animate:
      (
        ~value: valueXY(regular),
        ~toValue: [ | `raw(jsValue) | `animated(valueXY(regular))],
        ~restDisplacementThreshold: float=?,
        ~overshootClamping: bool=?,
        ~restSpeedThreshold: float=?,
        ~velocity: jsValue=?,
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
      Animation.t;
  };
  module Decay: {
    type config;
    let animate:
      (
        ~value: valueXY(regular),
        ~velocity: jsValue,
        ~deceleration: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
};

type animatedEvent;

let event: (array('a), 'b) => animatedEvent;

let delay: float => Animation.t;

let sequence: array(Animation.t) => Animation.t;

let parallel: (array(Animation.t), {. "stopTogether": bool}) => Animation.t;

let stagger: (float, array(Animation.t)) => Animation.t;

let loop: (~iterations: int=?, ~animation: Animation.t, unit) => Animation.t;

let createAnimatedComponent: ReasonReact.reactClass => ReasonReact.reactClass;

let timing:
  (
    ~value: value(regular),
    ~toValue: [ | `raw(float) | `animated(value(regular))],
    ~easing: Easing.t=?,
    ~duration: float=?,
    ~delay: float=?,
    ~isInteraction: bool=?,
    ~useNativeDriver: bool=?,
    ~onComplete: Animation.endCallback=?,
    ~iterations: int=?,
    unit
  ) =>
  Animation.t;

let spring:
  (
    ~value: value(regular),
    ~toValue: [ | `raw(float) | `animated(value(regular))],
    ~restDisplacementThreshold: float=?,
    ~overshootClamping: bool=?,
    ~restSpeedThreshold: float=?,
    ~velocity: float=?,
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
  Animation.t;

let decay:
  (
    ~value: value(regular),
    ~velocity: float,
    ~deceleration: float=?,
    ~isInteraction: bool=?,
    ~useNativeDriver: bool=?,
    ~onComplete: Animation.endCallback=?,
    ~iterations: int=?,
    unit
  ) =>
  Animation.t;

let stop: Animation.t => unit;

let start: (Animation.t, ~callback: Animation.endCallback=?, unit) => unit;

let reset: Animation.t => unit;

[@deprecated "Please use Easing module instead"]
module Easing = Easing;

[@deprecated
  "Please use Animated.start, Animated.stop or Animated.reset instead"
]
module CompositeAnimation = Animation;

[@deprecated "Please use Animated.timing instead"]
module Timing = Value.Timing;

module TimingXY = ValueXY.Timing;

[@deprecated "Please use Animated.spring instead"]
module Spring = Value.Spring;

module SpringXY = ValueXY.Spring;

[@deprecated "Please use Animated.decay instead"]
module Decay = Value.Decay;

module DecayXY = ValueXY.Decay;