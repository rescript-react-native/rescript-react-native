module Animation = {
  type t;
  type endResult = Js.t {. finished : Js.boolean};
  type endCallback = endResult => unit;
};

module type Value = {type t; type rawJsType;};

module CompositeAnimation = {
  type t;
  external _start : t => Js.undefined Animation.endCallback => unit = "start" [@@bs.send];
  let start t ::callback=? () => _start t (Js.Undefined.from_opt callback);
  external stop : t => unit = "" [@@bs.send];
  external reset : t => unit = "" [@@bs.send];
};

module Animations = {
  module Decay (Val: Value) => {
    type config =
      Js.t {
        .
        velocity : Val.rawJsType,
        deceleration : Js.undefined float,
        isInteraction : Js.undefined Js.boolean,
        useNativeDriver : Js.undefined Js.boolean,
        onComplete : Js.undefined Animation.endCallback,
        iterations : Js.undefined int
      };
    external _decay : Val.t => config => CompositeAnimation.t =
      "decay" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let animate
        ::value
        ::velocity
        ::deceleration=?
        ::isInteraction=?
        ::useNativeDriver=?
        ::onComplete=?
        ::iterations=?
        ()
 =>
      _decay
        value
        Js.Undefined.(
          {
            "velocity": velocity,
            "deceleration": from_opt deceleration,
            "isInteraction": from_opt (UtilsRN.optBoolToOptJsBoolean isInteraction),
            "useNativeDriver": from_opt (UtilsRN.optBoolToOptJsBoolean useNativeDriver),
            "onComplete": from_opt onComplete,
            "iterations": from_opt iterations
          }
        );
  };
  module Spring (Val: Value) => {
    type toValue;
    type config =
      Js.t {
        .
        toValue : toValue,
        restDisplacementThreshold : Js.undefined float,
        overshootClamping : Js.undefined Js.boolean,
        restSpeedThreshold : Js.undefined float,
        velocity : Js.undefined Val.rawJsType,
        bounciness : Js.undefined float,
        speed : Js.undefined float,
        tension : Js.undefined float,
        friction : Js.undefined float,
        isInteraction : Js.undefined Js.boolean,
        useNativeDriver : Js.undefined Js.boolean,
        onComplete : Js.undefined Animation.endCallback,
        iterations : Js.undefined int
      };
    external toValueRaw : Val.rawJsType => toValue = "%identity";
    external toValueAnimated : Val.t => toValue = "%identity";
    external _spring : Val.t => config => CompositeAnimation.t =
      "spring" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let animate
        ::value
        ::toValue
        ::restDisplacementThreshold=?
        ::overshootClamping=?
        ::restSpeedThreshold=?
        ::velocity=?
        ::bounciness=?
        ::speed=?
        ::tension=?
        ::friction=?
        ::isInteraction=?
        ::useNativeDriver=?
        ::onComplete=?
        ::iterations=?
        ()
 =>
      _spring
        value
        Js.Undefined.(
          {
            "toValue": switch toValue {
              | `raw x => toValueRaw x
              | `animated x => toValueAnimated x
            },
            "restDisplacementThreshold": from_opt restDisplacementThreshold,
            "overshootClamping": from_opt overshootClamping,
            "restSpeedThreshold": from_opt restSpeedThreshold,
            "velocity": from_opt velocity,
            "bounciness": from_opt bounciness,
            "speed": from_opt speed,
            "tension": from_opt tension,
            "friction": from_opt friction,
            "isInteraction": from_opt isInteraction,
            "useNativeDriver": from_opt useNativeDriver,
            "onComplete": from_opt onComplete,
            "iterations": from_opt iterations
          }
        );
  };
  module Timing (Val: Value) => {
    type toValue;
    type config =
      Js.t {
        .
        toValue : toValue,
        easing : Js.undefined (float => float),
        duration : Js.undefined float,
        delay : Js.undefined float,
        isInteraction : Js.undefined Js.boolean,
        useNativeDriver : Js.undefined Js.boolean,
        onComplete : Js.undefined Animation.endCallback,
        iterations : Js.undefined int
      };
    external toValueRaw : Val.rawJsType => toValue = "%identity";
    external toValueAnimated : Val.t => toValue = "%identity";
    external _timing : Val.t => config => CompositeAnimation.t =
      "timing" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let animate
        ::value
        ::toValue
        ::easing=?
        ::duration=?
        ::delay=?
        ::isInteraction=?
        ::useNativeDriver=?
        ::onComplete=?
        ::iterations=?
        ()
         =>
      _timing
        value
        Js.Undefined.(
          {
            "toValue": switch toValue {
              | `raw x => toValueRaw x
              | `animated x => toValueAnimated x
            },
            "easing": from_opt easing,
            "duration": from_opt duration,
            "delay": from_opt delay,
            "isInteraction": from_opt isInteraction,
            "useNativeDriver": from_opt useNativeDriver,
            "onComplete": from_opt onComplete,
            "iterations": from_opt iterations
          }
        );
  };
};

module ValueOperations (Val: Value) => {
  external add : Val.t => Val.t => Val.t = "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  external divide : Val.t => Val.t => Val.t =
    "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  external multiply : Val.t => Val.t => Val.t =
    "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  module Timing = Animations.Timing Val;
  module Spring = Animations.Spring Val;
  module Decay = Animations.Decay Val;
};

module Interpolation = {
  type t;
  type outputRange;
  external outputRangeCreate : 'a => outputRange = "%identity";
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let extrapolateString x =>
    switch x {
    | Extend => "extend"
    | Clamp => "clamp"
    | Identity => "identity"
    };
  type config =
    Js.t {
      .
      inputRange : array float,
      outputRange : outputRange,
      easing : Js.undefined (float => float),
      extrapolate : Js.undefined string,
      extrapolateLeft : Js.undefined string,
      extrapolateRight : Js.undefined string
    };
  external _interpolate : t => config => t = "interpolate" [@@bs.send];
  let interpolate
      ::value
      ::inputRange
      ::outputRange
      ::easing=?
      ::extrapolate=?
      ::extrapolateLeft=?
      ::extrapolateRight=?
      () =>
    _interpolate
      value
      {
        "inputRange": Array.of_list inputRange,
        "outputRange":
          switch outputRange {
          | `string (x: list string) => outputRangeCreate (Array.of_list x)
          | `float (x: list float) => outputRangeCreate (Array.of_list x)
          },
        "easing": Js.Undefined.from_opt easing,
        "extrapolate": Js.Undefined.from_opt (UtilsRN.option_map extrapolateString extrapolate),
        "extrapolateRight":
          Js.Undefined.from_opt (UtilsRN.option_map extrapolateString extrapolateRight),
        "extrapolateLeft":
          Js.Undefined.from_opt (UtilsRN.option_map extrapolateString extrapolateLeft)
      };
};

module Value = {
  type t;
  type callback = float => unit;
  external create : float => t =
    "Value" [@@bs.new] [@@bs.scope "Animated"] [@@bs.module "react-native"];
  external setValue : t => float => unit = "setValue" [@@bs.send];
  external setOffset : t => float => unit = "setOffset" [@@bs.send];
  external flattenOffset : t => unit = "flattenOffset" [@@bs.send];
  external extractOffset : t => unit = "extractOffset" [@@bs.send];
  external addListener : t => callback => string = "addListener" [@@bs.send];
  external removeListener : t => string => unit = "removeListener" [@@bs.send];
  external removeAllListeners : t => unit = "removeAllListeners" [@@bs.send];
  external _resetAnimation : t => Js.Undefined.t callback => unit = "resetAnimation" [@@bs.send];
  external _stopAnimation : t => Js.Undefined.t callback => unit = "stopAnimation" [@@bs.send];
  let resetAnimation value ::callback=? () => {
    _resetAnimation value (Js.Undefined.from_opt callback);
  };
  let stopAnimation value ::callback=? () => {
    _stopAnimation value (Js.Undefined.from_opt callback);
  };
  external _interpolate : t => Interpolation.config => Interpolation.t = "interpolate" [@@bs.send];
  let interpolate
      value
      ::inputRange
      ::outputRange
      ::easing=?
      ::extrapolate=?
      ::extrapolateLeft=?
      ::extrapolateRight=?
      () =>
    _interpolate
      value
      {
        "inputRange": Array.of_list inputRange,
        "outputRange":
          switch outputRange {
          | `string (x: list string) => Interpolation.outputRangeCreate (Array.of_list x)
          | `float (x: list float) => Interpolation.outputRangeCreate (Array.of_list x)
          },
        "easing": Js.Undefined.from_opt easing,
        "extrapolate":
          Js.Undefined.from_opt (UtilsRN.option_map Interpolation.extrapolateString extrapolate),
        "extrapolateRight":
          Js.Undefined.from_opt (UtilsRN.option_map Interpolation.extrapolateString extrapolateRight),
        "extrapolateLeft":
          Js.Undefined.from_opt (UtilsRN.option_map Interpolation.extrapolateString extrapolateLeft)
      };
  external animate : t => Animation.t => Animation.endCallback => unit = "animate" [@@bs.send];
  external stopTracking : t => unit = "stopTracking" [@@bs.send];
  external track : t => unit = "track" [@@bs.send];
  external modulo : t => float => t = "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  external diffClamp : t => float => float => t =
    "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  type value = t;
  include
    ValueOperations {
      type t = value;
      type rawJsType = float;
    };
};

module ValueXY = {
  type t;
  type jsValue = Js.t {. x : float, y : float};
  type callback = jsValue => unit;
  type translateTransform = Js.t {. translateX : Value.t, translateY : Value.t};
  type layout = Js.t {. left : Value.t, top : Value.t};
  external _create : jsValue => t =
    "ValueXY" [@@bs.new] [@@bs.scope "Animated"] [@@bs.module "react-native"];
  let create ::x ::y => _create {"x": x, "y": y};
  external _setValue : t => jsValue => unit = "setValue" [@@bs.send];
  let setValue t ::x ::y => _setValue t {"x": x, "y": y};
  external _setOffset : t => jsValue => unit = "setOffset" [@@bs.send];
  let setOffset t ::x ::y => _setOffset t {"x": x, "y": y};
  external flattenOffset : t => unit = "flattenOffset" [@@bs.send];
  external extractOffset : t => unit = "extractOffset" [@@bs.send];
  external resetAnimation : t => option callback => unit = "resetAnimation" [@@bs.send];
  external stopAnimation : t => option callback => unit = "stopAnimation" [@@bs.send];
  external addListener : t => callback => string = "addListener" [@@bs.send];
  external removeListener : t => string => unit = "removeListener" [@@bs.send];
  external removeAllListeners : t => unit = "removeAllListeners" [@@bs.send];
  external getLayout : t => layout = "getLayout" [@@bs.send];
  external getTranslateTransform : t => translateTransform = "getTranslateTransform" [@@bs.send];
  external getX : t => Value.t = "x" [@@bs.get];
  external getY : t => Value.t = "y" [@@bs.get];
  type value = t;
  include
    ValueOperations {
      type t = value;
      type rawJsType = jsValue;
    };
};

external delay : float => CompositeAnimation.t =
  "" [@@bs.module "react-native"] [@@bs.scope "Animated"];

external sequence : array CompositeAnimation.t => CompositeAnimation.t =
  "" [@@bs.module "react-native"] [@@bs.scope "Animated"];

external parallel :
  array CompositeAnimation.t => Js.t {. stopTogether : Js.boolean} => CompositeAnimation.t =
  "" [@@bs.module "react-native"] [@@bs.scope "Animated"];

external stagger : float => array CompositeAnimation.t => CompositeAnimation.t =
  "" [@@bs.module "react-native"] [@@bs.scope "Animated"];

external _loop : CompositeAnimation.t => Js.t {. iterations : int} => CompositeAnimation.t =
  "loop" [@@bs.module "react-native"] [@@bs.scope "Animated"];

type animatedEvent;
external event : array 'a => 'b => animatedEvent =
  "" [@@bs.module "react-native"] [@@bs.scope "Animated"];

let loop ::iterations=(-1) ::animation () => _loop animation {"iterations": iterations};

module Timing = Value.Timing;

module TimingXY = ValueXY.Timing;

module Spring = Value.Spring;

module SpringXY = ValueXY.Spring;

module Decay = Value.Decay;

module DecayXY = ValueXY.Decay;

