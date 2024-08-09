include TouchableOpacityElement

type props = {
  ref?: ref,
  ...TouchableWithoutFeedback.touchableWithoutFeedbackProps,
  activeOpacity?: float,
  focusedOpacity?: float,
  hasTVPreferredFocus?: bool,
  style?: Style.t,
  tvParallaxProperties?: TV.parallax,
}

@module("react-native")
external make: React.component<props> = "TouchableOpacity"
