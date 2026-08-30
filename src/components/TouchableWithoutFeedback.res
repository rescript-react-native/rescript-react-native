type nativeElement

include NativeElement.Impl({type t = nativeElement})

type coreProps = {
  ...Accessibility.viewProps,
  delayLongPress?: int,
  delayPressIn?: int,
  delayPressOut?: int,
  disabled?: bool,
  hitSlop?: Rect.t,
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
