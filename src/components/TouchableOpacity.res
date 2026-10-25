include TouchableOpacityElement

type props = {
  ref?: ref,
  ...TouchableWithoutFeedback.coreProps,
  activeOpacity?: float,
  nextFocusDown?: float,
  nextFocusForward?: float,
  nextFocusLeft?: float,
  nextFocusRight?: float,
  nextFocusUp?: float,
  @deprecated("Use `focusable` instead.") hasTVPreferredFocus?: bool,
  style?: Style.t,
  tvParallaxProperties?: TV.parallax,
}

@module("react-native")
external make: React.component<props> = "TouchableOpacity"
