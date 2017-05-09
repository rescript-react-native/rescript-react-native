module Animation: {
  type t;
  type endResult = Js.t {. finished : Js.boolean};
  type endCallback = endResult => unit;
};

module CompositeAnimation: {
  type t;
  let stop: t => unit;
  let start: t => callback::Animation.endCallback? => unit => unit;
  let reset: t => unit;
};

module Interpolation: {
  type t;
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let interpolate:
    value::t =>
    inputRange::list float =>
    outputRange::[< | `float (list float) | `string (list string)] =>
    easing::(float => float)? =>
    extrapolate::extrapolate? =>
    extrapolateLeft::extrapolate? =>
    extrapolateRight::extrapolate? =>
    unit =>
    t;
};

module Value: {
  type t;
  type callback = float => unit;
  let create: float => t;
  let setValue: t => float => unit;
  let setOffset: t => float => unit;
  let flattenOffset: t => unit;
  let extractOffset: t => unit;
  let addListener: t => callback => string;
  let removeListener: t => string => unit;
  let removeAllListeners: t => unit;
  let resetAnimation: t => option callback => unit;
  let stopAnimation: t => option callback => unit;
  let interpolate:
    t =>
    inputRange::list float =>
    outputRange::[< | `float (list float) | `string (list string)] =>
    easing::(float => float)? =>
    extrapolate::Interpolation.extrapolate? =>
    extrapolateLeft::Interpolation.extrapolate? =>
    extrapolateRight::Interpolation.extrapolate? =>
    unit =>
    Interpolation.t;
  let animate: t => Animation.t => Animation.endCallback => unit;
  let stopTracking: t => unit;
  let track: t => unit;
  let modulo: t => float => t;
  let diffClamp: t => float => float => t;
  type value = t;
  let add: value => value => value;
  let divide: value => value => value;
  let multiply: value => value => value;
  module Timing: {
    type config;
    let animate:
      value::value =>
      toValue::[ `raw float | `animated value] =>
      easing::(float => float)? =>
      duration::float? =>
      delay::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      unit =>
      CompositeAnimation.t;
  };
  module Spring: {
    type config;
    let animate:
      value::value =>
      toValue::[ `raw float | `animated value] =>
      restDisplacementThreshold::float? =>
      overshootClamping::Js.boolean? =>
      restSpeedThreshold::float? =>
      velocity::float? =>
      bounciness::float? =>
      speed::float? =>
      tension::float? =>
      friction::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      unit =>
      CompositeAnimation.t;
  };
  module Decay: {
    type config;
    let animate:
      value::value =>
      velocity::float =>
      deceleration::float? =>
      isInteraction::bool? =>
      useNativeDriver::bool? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      unit =>
      CompositeAnimation.t;
  };
};

module ValueXY: {
  type t;
  type jsValue = Js.t {. x : float, y : float};
  type callback = jsValue => unit;
  type translateTransform = Js.t {. translateX : Value.t, translateY : Value.t};
  type layout = Js.t {. left : Value.t, top : Value.t};
  let create: x::float => y::float => t;
  let setValue: t => x::float => y::float => unit;
  let setOffset: t => x::float => y::float => unit;
  let flattenOffset: t => unit;
  let extractOffset: t => unit;
  let resetAnimation: t => option callback => unit;
  let stopAnimation: t => option callback => unit;
  let addListener: t => callback => string;
  let removeListener: t => string => unit;
  let removeAllListeners: t => unit;
  let getLayout: t => layout;
  let getTranslateTransform: t => translateTransform;
  let add: t => t => t;
  let divide: t => t => t;
  let multiply: t => t => t;
  let getX: t => Value.t;
  let getY: t => Value.t;
  type value = t;
  module Timing: {
    type config;
    let animate:
      value::value =>
      toValue::[ `raw jsValue | `animated value] =>
      easing::(float => float)? =>
      duration::float? =>
      delay::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      unit =>
      CompositeAnimation.t;
  };
  module Spring: {
    type config;
    let animate:
      value::value =>
      toValue::[ `raw jsValue | `animated value] =>
      restDisplacementThreshold::float? =>
      overshootClamping::Js.boolean? =>
      restSpeedThreshold::float? =>
      velocity::jsValue? =>
      bounciness::float? =>
      speed::float? =>
      tension::float? =>
      friction::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      unit =>
      CompositeAnimation.t;
  };
  module Decay: {
    type config;
    let animate:
      value::value =>
      velocity::jsValue =>
      deceleration::float? =>
      isInteraction::bool? =>
      useNativeDriver::bool? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      unit =>
      CompositeAnimation.t;
  };
};

type animatedEvent;
let event: array 'a => 'b => animatedEvent;

let delay: float => CompositeAnimation.t;

let sequence: array CompositeAnimation.t => CompositeAnimation.t;

let parallel:
  array CompositeAnimation.t => Js.t {. stopTogether : Js.boolean} => CompositeAnimation.t;

let stagger: float => array CompositeAnimation.t => CompositeAnimation.t;

let loop: iterations::int? => animation::CompositeAnimation.t => CompositeAnimation.t;

module Timing = Value.Timing;

module TimingXY = ValueXY.Timing;

module Spring = Value.Spring;

module SpringXY = ValueXY.Spring;

module Decay = Value.Decay;

module DecayXY = ValueXY.Decay;
