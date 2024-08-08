include TouchableOpacityElement

type touchableOpacityProps = {
  ref?: ref,
  ...TouchableWithoutFeedback.touchableWithoutFeedbackProps,
  activeOpacity?: float,
  focusedOpacity?: float,
  hasTVPreferredFocus?: bool,
  style?: Style.t,
  tvParallaxProperties?: TV.parallax,
}

@react.component(: touchableOpacityProps) @module("react-native")
external make: touchableOpacityProps => React.element = "TouchableOpacity"
