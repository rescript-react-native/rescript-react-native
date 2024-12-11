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
external getRecommendedTimeoutMillis: float => promise<float> = "getRecommendedTimeoutMillis"

@scope("AccessibilityInfo") @module("react-native")
external isBoldTextEnabled: unit => promise<bool> = "isBoldTextEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isGrayscaleEnabled: unit => promise<bool> = "isGrayscaleEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isInvertColorsEnabled: unit => promise<bool> = "isInvertColorsEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isReduceMotionEnabled: unit => promise<bool> = "isReduceMotionEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isReduceTransparencyEnabled: unit => promise<bool> = "isReduceTransparencyEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isScreenReaderEnabled: unit => promise<bool> = "isScreenReaderEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isAccessibilityServiceEnabled: unit => promise<bool> = "isAccessibilityServiceEnabled"

@scope("AccessibilityInfo") @module("react-native")
external setAccessibilityFocus: NativeTypes.nodeHandle => unit = "setAccessibilityFocus"

@scope("AccessibilityInfo") @module("react-native")
external prefersCrossFadeTransitions: unit => promise<bool> = "prefersCrossFadeTransitions"
