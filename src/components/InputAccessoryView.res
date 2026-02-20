type props = {
  backgroundColor?: Color.t,
  nativeID?: string,
  style?: Style.t,
  testID?: string,
  children?: React.element,
}

@module("react-native")
external make: React.component<props> = "InputAccessoryView"
