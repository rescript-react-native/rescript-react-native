type announcementResult = {announcement: string, success: bool}

@scope("AccessibilityInfo") @module("react-native")
external addEventListener: @string
[
  | #boldTextChanged(bool => unit)
  | #grayscaleChanged(bool => unit)
  | #invertColorsChanged(bool => unit)
  | #reduceMotionChanged(bool => unit)
  | #screenReaderChanged(bool => unit)
  | #reduceTransparencyChanged(bool => unit)
  | #announcementFinished(announcementResult => unit)
] => EventSubscription.t = "addEventListener"

@scope("AccessibilityInfo") @module("react-native")
external announceForAccessibility: string => unit = "announceForAccessibility"

@scope("AccessibilityInfo") @module("react-native")
external getRecommendedTimeoutMillis: float => Js.Promise.t<float> = "getRecommendedTimeoutMillis"

@scope("AccessibilityInfo") @module("react-native")
external isBoldTextEnabled: unit => Js.Promise.t<bool> = "isBoldTextEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isGrayscaleEnabled: unit => Js.Promise.t<bool> = "isGrayscaleEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isInvertColorsEnabled: unit => Js.Promise.t<bool> = "isInvertColorsEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isReduceMotionEnabled: unit => Js.Promise.t<bool> = "isReduceMotionEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isReduceTransparencyEnabled: unit => Js.Promise.t<bool> = "isReduceTransparencyEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isScreenReaderEnabled: unit => Js.Promise.t<bool> = "isScreenReaderEnabled"

@deprecated("Instead of using removeEventListener(), invoke `remove()` on the subscription itself.")
@scope("AccessibilityInfo")
@module("react-native")
external removeEventListener: @string
[
  | #boldTextChanged(bool => unit)
  | #grayscaleChanged(bool => unit)
  | #invertColorsChanged(bool => unit)
  | #reduceMotionChanged(bool => unit)
  | #screenReaderChanged(bool => unit)
  | #reduceTransparencyChanged(bool => unit)
  | #announcementFinished(announcementResult => unit)
] => unit = "removeEventListener"

@scope("AccessibilityInfo") @module("react-native")
external setAccessibilityFocus: NativeTypes.nodeHandle => unit = "setAccessibilityFocus"
