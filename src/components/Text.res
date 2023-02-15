include NativeElement

type android_hyphenationFrequency = [
  | #normal
  | #none
  | #full
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

type lineBreakStrategyIOS = [#none | #standard | #"hangul-word" | #"push-out"]

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // Text props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityHint: string=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLanguage: string=?,
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
  ~lineBreakStrategyIOS: lineBreakStrategyIOS=?,
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
  // react-native-web 0.17 View props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  // react-native-web 0.17 View props, ClickProps
  ~onClick: option<ReactEvent.Mouse.t => unit>=?,
  ~onClickCapture: option<ReactEvent.Mouse.t => unit>=?,
  ~onContextMenu: option<ReactEvent.Mouse.t => unit>=?,
  // react-native-web 0.17 View props, FocusProps
  ~onFocus: option<ReactEvent.Focus.t => unit>=?,
  ~onBlur: option<ReactEvent.Focus.t => unit>=?,
  // react-native-web 0.17 View props, KeyboardProps
  ~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyDownCapture: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyUp: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyUpCapture: option<ReactEvent.Keyboard.t => unit>=?,
  // react-native-web 0.17 View props, Mouse forwarded props
  ~onMouseDown: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseEnter: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseLeave: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseMove: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseOut: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseOver: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseUp: option<ReactEvent.Mouse.t => unit>=?,
) => React.element = "Text"
