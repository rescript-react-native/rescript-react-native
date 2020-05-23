type animationConfig;
[@bs.obj]
external animationConfig:
  (
    ~duration: float=?,
    ~delay: float=?,
    ~springDamping: float=?,
    ~initialVelocity: float=?,
    ~_type: [@bs.string] [
              | `spring
              | `linear
              | `easeInEaseOut
              | `easeIn
              | `easeOut
              | `keyboard
            ]
              =?,
    ~property: [@bs.string] [ | `opacity | `scaleX | `scaleY | `scaleXY]=?,
    unit
  ) =>
  animationConfig;

type layoutAnimationConfig;
[@bs.obj]
external layoutAnimationConfig:
  (
    ~duration: float,
    ~create: animationConfig=?,
    ~update: animationConfig=?,
    ~delete: animationConfig=?,
    unit
  ) =>
  layoutAnimationConfig;

// multiple externals
[@bs.module "react-native"] [@bs.scope "LayoutAnimation"]
external configureNext: layoutAnimationConfig => unit = "configureNext";

// multiple externals
[@bs.module "react-native"] [@bs.scope "LayoutAnimation"]
external configureNextWithEndCallback:
  (layoutAnimationConfig, unit => unit) => unit =
  "configureNext";

[@bs.module "react-native"] [@bs.scope "LayoutAnimation"]
external create:
  (
    ~duration: float,
    ~_type: [@bs.string] [
              | `spring
              | `linear
              | `easeInEaseOut
              | `easeIn
              | `easeOut
              | `keyboard
            ],
    ~property: [@bs.string] [ | `opacity | `scaleX | `scaleY | `scaleXY]
  ) =>
  layoutAnimationConfig =
  "create";

[@bs.module "react-native"] [@bs.scope "LayoutAnimation"]
external easeInEaseOut: unit => unit = "easeInEaseOut";

[@bs.module "react-native"] [@bs.scope "LayoutAnimation"]
external linear: unit => unit = "linear";

[@bs.module "react-native"] [@bs.scope "LayoutAnimation"]
external spring: unit => unit = "spring";

module Presets = {
  [@bs.module "react-native"] [@bs.scope ("LayoutAnimation", "Presets")]
  external easeInEaseOut: layoutAnimationConfig = "easeInEaseOut";

  [@bs.module "react-native"] [@bs.scope ("LayoutAnimation", "Presets")]
  external linear: layoutAnimationConfig = "linear";

  [@bs.module "react-native"] [@bs.scope ("LayoutAnimation", "Presets")]
  external spring: layoutAnimationConfig = "spring";
};
