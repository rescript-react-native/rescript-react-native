include NativeElement

module Background = {
  type t

  @module("react-native") @scope("TouchableNativeFeedback")
  external selectableBackground: unit => t = "SelectableBackground"

  @module("react-native") @scope("TouchableNativeFeedback")
  external selectableBackgroundBorderless: unit => t = "SelectableBackgroundBorderless"

  @module("react-native") @scope("TouchableNativeFeedback")
  external canUseNativeForeground: unit => bool = "canUseNativeForeground"

  @module("react-native") @scope("TouchableNativeFeedback")
  external ripple: (string, bool) => t = "Ripple"
}

type touchableNativeFeedbackProps = {
  ...TouchableWithoutFeedback.touchableWithoutFeedbackProps,
  background?: Background.t,
  useForeground?: bool,
}

@react.component(: touchableNativeFeedbackProps) @module("react-native")
external make: touchableNativeFeedbackProps => React.element = "TouchableNativeFeedback"
