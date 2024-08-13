include NativeElement

type rippleConfig = {
  borderless?: bool,
  color?: Color.t,
  foreground?: bool,
  radius?: float,
}

// This is usually only used as a callback param and not created by the user.
// Therefore prefer option<...> to an optional field for easier matching.
type interactionState = {
  pressed: bool,
  // React Native Web
  hovered?: bool,
  focused?: bool,
}

type accessibilityProps = {
  accessibilityActions?: array<Accessibility.actionInfo>,
  accessibilityElementsHidden?: bool,
  accessibilityHint?: string,
  accessibilityIgnoresInvertColors?: bool,
  accessibilityLabel?: string,
  accessibilityLanguage?: string,
  accessibilityLiveRegion?: Accessibility.liveRegion,
  accessibilityRole?: Accessibility.role,
  accessibilityState?: Accessibility.state,
  accessibilityValue?: Accessibility.value,
  accessibilityViewIsModal?: bool,
  accessible?: bool,
  focusable?: bool,
  importantForAccessibility?: View.importantForAccessibility,
}

type webProps = {
  ...View.webLinkProps,
  ...View.webClickProps,
  // don't use View.webFocusProps because TextInput
  // already has a react-native onFocus and onBlur
  ...View.webKeyboardProps,
  ...View.webMouseForwardedProps,
  onHoverIn?: ReactEvent.Mouse.t => unit,
  onHoverOut?: ReactEvent.Mouse.t => unit,
}

type props = {
  ...accessibilityProps,
  ...webProps,
  ref?: ref,
  android_disableSound?: bool,
  android_ripple?: rippleConfig,
  children?: interactionState => React.element,
  delayLongPress?: int,
  disabled?: bool,
  hitSlop?: Rect.t,
  onBlur?: Event.blurEvent => unit,
  onFocus?: Event.focusEvent => unit,
  onLayout?: Event.layoutEvent => unit,
  onLongPress?: Event.pressEvent => unit,
  onPress?: Event.pressEvent => unit,
  onPressIn?: Event.pressEvent => unit,
  onPressOut?: Event.pressEvent => unit,
  pressRetentionOffset?: Rect.t,
  style?: interactionState => Style.t,
  testID?: string,
  testOnly_pressed?: bool,
  unstable_pressDelay?: int,
}

@module("react-native")
external make: React.component<props> = "Pressable"
