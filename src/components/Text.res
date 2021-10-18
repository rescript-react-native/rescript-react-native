include NativeElement

type android_hyphenationFrequency = [
  | #normal
  | #none
  | #full
  | #high
  | #balanced
]
type dataDetectorType = [
  | #phoneNumber
  | #link
  | #address
  | #calendarEvent
  | #none
  | #all
]

type ellipsizeMode = [#clip | #head | #middle | #tail]

type textBreakStrategy = [#simple | #highQuality | #balanced]

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // Text props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityHint: string=?,
  ~accessibilityLabel: string=?,
  ~accessibilityRole: Accessibility.role=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessible: bool=?,
  ~adjustsFontSizeToFit: bool=?,
  ~allowFontScaling: bool=?,
  ~android_hyphenationFrequency: android_hyphenationFrequency=?,
  ~ariaLevel: int=?,
  ~children: React.element=?,
  ~dataDetectorTypes: array<dataDetectorType>=?,
  ~disabled: bool=?,
  ~ellipsizeMode: ellipsizeMode=?,
  ~maxFontSizeMultiplier: int=?,
  ~minimumFontScale: float=?,
  ~nativeID: string=?,
  ~numberOfLines: int=?,
  ~onAccessibilityAction: Accessibility.actionEvent => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLongPress: Event.pressEvent => unit=?,
  ~onPress: Event.pressEvent => unit=?,
  ~onPressIn: Event.pressEvent => unit=?,
  ~onPressOut: Event.pressEvent => unit=?,
  ~onTextLayout: Event.textLayoutEvent => unit=?,
  ~pressRetentionOffset: View.edgeInsets=?,
  ~selectable: bool=?,
  ~selectionColor: string=?,
  ~style: Style.t=?,
  ~suppressHighlighting: bool=?,
  ~testID: string=?,
  ~textBreakStrategy: textBreakStrategy=?,
  ~value: string=?,
  // Gesture Responder props
  ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
  ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
  ~onResponderEnd: Event.pressEvent => unit=?,
  ~onResponderGrant: Event.pressEvent => unit=?,
  ~onResponderMove: Event.pressEvent => unit=?,
  ~onResponderReject: Event.pressEvent => unit=?,
  ~onResponderRelease: Event.pressEvent => unit=?,
  ~onResponderStart: Event.pressEvent => unit=?,
  ~onResponderTerminate: Event.pressEvent => unit=?,
  ~onResponderTerminationRequest: Event.pressEvent => bool=?,
  ~onStartShouldSetResponder: Event.pressEvent => bool=?,
  ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
  // react-native-web 0.16 View props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~onMouseOver: ReactEvent.Mouse.t => unit=?,
  ~onMouseOut: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
) => React.element = "Text"
