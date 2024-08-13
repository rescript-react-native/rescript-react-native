include NativeElement

type coreProps = {
  accessible?: bool,
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
  delayLongPress?: int,
  delayPressIn?: int,
  delayPressOut?: int,
  disabled?: bool,
  hitSlop?: Rect.t,
  importantForAccessibility?: View.importantForAccessibility,
  onBlur?: Event.targetEvent => unit,
  onFocus?: Event.targetEvent => unit,
  onLayout?: Event.layoutEvent => unit,
  onLongPress?: Event.pressEvent => unit,
  onPress?: Event.pressEvent => unit,
  onPressIn?: Event.pressEvent => unit,
  onPressOut?: Event.pressEvent => unit,
  pressRetentionOffset?: Rect.t,
  testID?: string,
  touchSoundDisabled?: bool,
  children?: React.element,
}

type props = {
  ref?: ref,
  ...coreProps,
}

@module("react-native")
external make: React.component<props> = "TouchableWithoutFeedback"
