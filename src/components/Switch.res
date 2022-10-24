include NativeElement

type trackColor = {
  \"true"?: Color.t,
  \"false"?: Color.t,
}

@obj @deprecated("Directly create record instead")
external trackColor: (~\"true": Color.t=?, ~\"false": Color.t=?, unit) => trackColor = ""

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // Switch props
  ~disabled: bool=?,
  ~trackColor: trackColor=?,
  ~ios_backgroundColor: Color.t=?,
  ~onValueChange: bool => unit=?,
  ~thumbColor: Color.t=?,
  ~value: bool=?,
  // rescript-react-native 0.69 View props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityElementsHidden: bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityIgnoresInvertColors: bool=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLabelledBy: array<string>=?,
  ~accessibilityLanguage: string=?,
  ~accessibilityLiveRegion: Accessibility.liveRegion=?,
  ~accessibilityRole: Accessibility.role=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessibilityValue: Accessibility.value=?,
  ~accessibilityViewIsModal: bool=?,
  ~accessible: bool=?,
  ~collapsable: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~importantForAccessibility: View.importantForAccessibility=?,
  ~nativeID: string=?,
  ~needsOffscreenAlphaCompositing: bool=?,
  ~onAccessibilityAction: Accessibility.actionEvent => unit=?,
  ~onAccessibilityEscape: unit => unit=?,
  ~onAccessibilityTap: unit => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onMagicTap: unit => unit=?,
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
  ~pointerEvents: View.pointerEvents=?,
  ~removeClippedSubviews: bool=?,
  ~renderToHardwareTextureAndroid: bool=?,
  ~shouldRasterizeIOS: bool=?,
  ~style: Style.t=?,
  ~testID: string=?,
  ~children: React.element=?,
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
) => React.element = "Switch"
