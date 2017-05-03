module Animation = {
  type t;
  type endResult = Js.t {. finished : Js.boolean};
  type endCallback = endResult => unit;
};

module type Value = {type t; type rawJsType;};

module CompositeAnimation = {
  type t;
  external start : t => Animation.endCallback => unit = "" [@@bs.send];
  external stop : t => unit = "" [@@bs.send];
  external start : t => unit = "" [@@bs.send];
};

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
  let config
      ::deceleration=?
      ::isInteraction=?
      ::useNativeDriver=?
      ::onComplete=?
      ::iterations=?
      ::velocity =>
    Js.Undefined.(
      {
        "velocity": velocity,
        "deceleration": from_opt deceleration,
        "isInteraction": from_opt (Utils.option_map Js.Boolean.to_js_boolean isInteraction),
        "useNativeDriver": from_opt (Utils.option_map Js.Boolean.to_js_boolean useNativeDriver),
        "onComplete": from_opt onComplete,
        "iterations": from_opt iterations
      }
    );
  external _decay : Val.t => config => CompositeAnimation.t =
    "decay" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  let decay ::value ::config => _decay value config;
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
  let config
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
      ::toValue
      :config =>
    Js.Undefined.(
      {
        "toValue": toValue,
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
  external toValueFloat : Val.rawJsType => toValue = "%identity";
  external toValueAnimated : Val.t => toValue = "%identity";
  external _spring : Val.t => config => CompositeAnimation.t =
    "spring" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  let spring ::value ::config => _spring value config;
};

module Timing (Val: Value) => {
  type toValue;
  type config =
    Js.t {
      .
        toValue: toValue,
      easing: Js.undefined (float => float),
      duration: Js.undefined float,
      delay: Js.undefined float,
      isInteraction : Js.undefined Js.boolean,
      useNativeDriver : Js.undefined Js.boolean,
      onComplete : Js.undefined Animation.endCallback,
      iterations : Js.undefined int
    };
  let config
      ::easing=?
      ::duration=?
      ::delay=?
      ::isInteraction=?
      ::useNativeDriver=?
      ::onComplete=?
      ::iterations=?
      ::toValue
      :config =>
    Js.Undefined.(
      {
        "toValue": toValue,
        "easing": from_opt easing,
        "duration": from_opt duration,
        "delay": from_opt delay,
        "isInteraction": from_opt isInteraction,
        "useNativeDriver": from_opt useNativeDriver,
        "onComplete": from_opt onComplete,
        "iterations": from_opt iterations
      }
    );
  external toValueFloat : Val.rawJsType => toValue = "%identity";
  external toValueAnimated : Val.t => toValue = "%identity";
  external _timing : Val.t => config => CompositeAnimation.t =
    "timing" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  let timing ::value ::config => _timing value config;
};

module ValueOperations (Val: Value) => {
  external add : Val.t => Val.t => Val.t = "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  external divide : Val.t => Val.t => Val.t =
    "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  external multiply : Val.t => Val.t => Val.t =
    "" [@@bs.module "react-native"] [@@bs.scope "Animated"];
  module Timing = Timing Val;
  module Spring = Spring Val;
  module Decay = Decay Val;
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
  let createConfig
      ::inputRange
      ::outputRange
      ::easing=?
      ::extrapolate=?
      ::extrapolateLeft=?
      ::extrapolateRight=?
      ()
      :config => {
    "inputRange": Array.of_list inputRange,
    "outputRange":
      switch outputRange {
      | `string (x: list string) => outputRangeCreate (Array.of_list x)
      | `float (x: list float) => outputRangeCreate (Array.of_list x)
      },
    "easing": Utils.from_opt easing,
    "extrapolate": Utils.from_opt (Utils.option_map extrapolateString extrapolate),
    "extrapolateRight": Utils.from_opt (Utils.option_map extrapolateString extrapolateRight),
    "extrapolateLeft": Utils.from_opt (Utils.option_map extrapolateString extrapolateLeft)
  };
  external interpolate : t => config => t = "interpolate" [@@bs.send];
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
  external resetAnimation : t => option callback => unit = "resetAnimation" [@@bs.send];
  external stopAnimation : t => option callback => unit = "stopAnimation" [@@bs.send];
  external interpolate : t => Interpolation.config => Interpolation.t = "interpolate" [@@bs.send];
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
  external getLayout : t => translateTransform = "getLayout" [@@bs.send];
  external getTranslateTransform : t => translateTransform = "getTranslateTransform" [@@bs.send];
  type value = t;
  include
    ValueOperations {
      type t = value;
      type rawJsType = jsValue;
    };
};

module View =
  ViewRe.CreateComponent {
    external view : ReactRe.reactClass =
      "View" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let view = view;
  };

module Image =
  ImageRe.CreateComponent {
    external view : ReactRe.reactClass =
      "Image" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let view = view;
  };

module Text =
  TextRe.CreateComponent {
    external view : ReactRe.reactClass =
      "Text" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let view = view;
  };

external event : 'a => 'b => unit => unit =
  "" [@@bs.module "react-native"] [@@bs.scope "Animated"];

module ScrollView = {
  let onScrollUpdater ::x=? ::y=? ::native=false =>
    event
      [
        {
          "nativeEvent": {
            "contentOffset": {"x": Js_undefined.from_opt x, "y": Js_undefined.from_opt y}
          }
        }
      ]
      {"useNativeDriver": Js.Boolean.to_js_boolean native};
  include
    ScrollViewRe.CreateComponent {
      external view : ReactRe.reactClass =
        "ScrollView" [@@bs.module "react-native"] [@@bs.scope "Animated"];
      let view = view;
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
  "" [@@bs.module "react-native"] [@@bs.scope "Animated"];

let loop ::iterations=(-1) ::animation => _loop animation {"iterations": iterations};
