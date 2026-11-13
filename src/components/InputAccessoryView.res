type props = {
  backgroundColor?: Color.t,
  nativeID?: string,
  style?: Style.t,
  testID?: string,
  children?: React.element,
}

@deprecated("InputAccessoryView is deprecated and will be removed in a future release.")
@module("react-native")
external make: React.component<props> = "InputAccessoryView"
