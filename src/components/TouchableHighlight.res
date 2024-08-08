include NativeElement

type touchableHighlightProps = {
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

@react.component(: touchableHighlightProps) @module("react-native")
external make: touchableHighlightProps => React.element = "TouchableHighlight"
