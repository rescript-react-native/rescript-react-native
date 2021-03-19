type animationType = [
  | #spring
  | #linear
  | #easeInEaseOut
  | #easeIn
  | #easeOut
  | #keyboard
]

type property = [#opacity | #scaleX | #scaleY | #scaleXY]

type animationConfig
@obj
external animationConfig: (
  ~duration: float=?,
  ~delay: float=?,
  ~springDamping: float=?,
  ~initialVelocity: float=?,
  ~_type: animationType=?,
  ~property: property=?,
  unit,
) => animationConfig = ""

type layoutAnimationConfig
@obj
external layoutAnimationConfig: (
  ~duration: float,
  ~create: animationConfig=?,
  ~update: animationConfig=?,
  ~delete: animationConfig=?,
  unit,
) => layoutAnimationConfig = ""

// multiple externals
@module("react-native") @scope("LayoutAnimation")
external configureNext: layoutAnimationConfig => unit = "configureNext"

// multiple externals
@module("react-native") @scope("LayoutAnimation")
external configureNextWithEndCallback: (layoutAnimationConfig, unit => unit) => unit =
  "configureNext"

@module("react-native") @scope("LayoutAnimation")
external create: (
  ~duration: float,
  ~_type: animationType,
  ~property: property,
) => layoutAnimationConfig = "create"

@module("react-native") @scope("LayoutAnimation")
external easeInEaseOut: unit => unit = "easeInEaseOut"

@module("react-native") @scope("LayoutAnimation")
external linear: unit => unit = "linear"

@module("react-native") @scope("LayoutAnimation")
external spring: unit => unit = "spring"

module Presets = {
  @module("react-native") @scope(("LayoutAnimation", "Presets"))
  external easeInEaseOut: layoutAnimationConfig = "easeInEaseOut"

  @module("react-native") @scope(("LayoutAnimation", "Presets"))
  external linear: layoutAnimationConfig = "linear"

  @module("react-native") @scope(("LayoutAnimation", "Presets"))
  external spring: layoutAnimationConfig = "spring"
}
