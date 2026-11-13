type nativeElement

include NativeElement.Impl({type t = nativeElement})

type props = {
  ref?: ref,
  accessibilityActions?: array<Accessibility.actionInfo>,
  accessibilityHint?: string,
  accessibilityLabel?: string,
  accessibilityLanguage?: string,
  accessibilityState?: Accessibility.state,
  accessible?: bool,
  @as("aria-busy") ariaBusy?: bool,
  @as("aria-checked") ariaChecked?: Accessibility.checked,
  @as("aria-disabled") ariaDisabled?: bool,
  @as("aria-expanded") ariaExpanded?: bool,
  @as("aria-label") ariaLabel?: string,
  @as("aria-selected") ariaSelected?: bool,
  color?: Color.t,
  disabled?: bool,
  importantForAccessibility?: Accessibility.importantForAccessibility,
  @deprecated("Use `focusable` instead.") hasTVPreferredFocus?: bool,
  nextFocusDown?: int,
  nextFocusForward?: int,
  nextFocusLeft?: int,
  nextFocusRight?: int,
  nextFocusUp?: int,
  onAccessibilityAction?: Accessibility.actionEvent => unit,
  onPress?: Event.pressEvent => unit,
  testID?: string,
  title: string,
  touchSoundDisabled?: bool,
}

@module("react-native")
external make: React.component<props> = "Button"
