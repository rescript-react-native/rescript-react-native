include NativeElement

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // Button props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityLabel: string=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessible: bool=?,
  ~color: Color.t=?,
  ~disabled: bool=?,
  ~hasTVPreferredFocus: bool=?,
  ~nextFocusDown: int=?,
  ~nextFocusForward: int=?,
  ~nextFocusLeft: int=?,
  ~nextFocusRight: int=?,
  ~nextFocusUp: int=?,
  ~onAccessibilityAction: Accessibility.actionEvent => unit=?,
  ~onPress: Event.pressEvent => unit,
  ~testID: string=?,
  ~title: string,
  ~touchSoundDisabled: bool=?,
) => React.element = "Button"
