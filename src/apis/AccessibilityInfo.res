type announcementResult = {
  announcement: string,
  success: bool,
}

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

@scope("AccessibilityInfo") @module("react-native")
external setAccessibilityFocus: NativeTypes.nodeHandle => unit = "setAccessibilityFocus"

@scope("AccessibilityInfo") @module("react-native")
external announceForAccessibility: string => unit = "announceForAccessibility"

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
] => unit = "addEventListener"

@scope("AccessibilityInfo") @module("react-native")
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
