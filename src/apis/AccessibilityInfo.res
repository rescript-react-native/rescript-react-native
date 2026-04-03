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
  | #highTextContrastChanged(bool => unit)
  | #darkerSystemColorsChanged(bool => unit)
  | #accessibilityServiceChanged(bool => unit)
  | #announcementFinished(announcementResult => unit)
] => EventSubscription.t = "addEventListener"

@scope("AccessibilityInfo") @module("react-native")
external announceForAccessibility: string => unit = "announceForAccessibility"

type announceForAccessibilityOptions = {queue?: bool}

@scope("AccessibilityInfo") @module("react-native")
external announceForAccessibilityWithOptions: (string, announceForAccessibilityOptions) => unit =
  "announceForAccessibilityWithOptions"

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
external isHighTextContrastEnabled: unit => promise<bool> = "isHighTextContrastEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isDarkerSystemColorsEnabled: unit => promise<bool> = "isDarkerSystemColorsEnabled"

@scope("AccessibilityInfo") @module("react-native")
external isAccessibilityServiceEnabled: unit => promise<bool> = "isAccessibilityServiceEnabled"

@deprecated("Prefer using sendAccessibilityEvent with eventType focus instead.")
@scope("AccessibilityInfo")
@module("react-native")
external setAccessibilityFocus: NativeTypes.nodeHandle => unit = "setAccessibilityFocus"

type accessibilityEventTypes = [
  | #click
  | #focus
  | #viewHoverEnter
  | #windowStateChange
]

@scope("AccessibilityInfo") @module("react-native")
external sendAccessibilityEvent: (NativeElement.ref, accessibilityEventTypes) => unit =
  "sendAccessibilityEvent"

@scope("AccessibilityInfo") @module("react-native")
external prefersCrossFadeTransitions: unit => promise<bool> = "prefersCrossFadeTransitions"
