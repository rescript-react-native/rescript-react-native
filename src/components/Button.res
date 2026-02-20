include NativeElement

type props = {
  ref?: ref,
  accessibilityActions?: array<Accessibility.actionInfo>,
  accessibilityLabel?: string,
  accessibilityLanguage?: string,
  accessibilityState?: Accessibility.state,
  accessible?: bool,
  color?: Color.t,
  disabled?: bool,
  hasTVPreferredFocus?: bool,
  nextFocusDown?: int,
  nextFocusForward?: int,
  nextFocusLeft?: int,
  nextFocusRight?: int,
  nextFocusUp?: int,
  onAccessibilityAction?: Accessibility.actionEvent => unit,
  onPress: Event.pressEvent => unit,
  testID?: string,
  title?: string,
  touchSoundDisabled?: bool,
}

@module("react-native")
external make: React.component<props> = "Button"
