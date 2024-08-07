include TouchableOpacityElement

type touchableOpacityProps = {
  ...TouchableWithoutFeedback.touchableWithoutFeedbackProps,
  activeOpacity?: float,
  focusedOpacity?: float,
  hasTVPreferredFocus?: bool,
  style?: Style.t,
  tvParallaxProperties?: TV.parallax,
}

@react.component(: touchableOpacityProps) @module("react-native")
external make: touchableOpacityProps => React.element = "TouchableOpacity"
