include NativeElement

type props = {
  ref?: ref,
  ...TouchableWithoutFeedback.touchableWithoutFeedbackProps,
  activeOpacity?: float,
  hasTVPreferredFocus?: bool,
  onHideUnderlay?: unit => unit,
  onShowUnderlay?: unit => unit,
  style?: Style.t,
  tvParallaxProperties?: TV.parallax,
  underlayColor?: string,
}

@module("react-native")
external make: React.component<props> = "TouchableHighlight"
