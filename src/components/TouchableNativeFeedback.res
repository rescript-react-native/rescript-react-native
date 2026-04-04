type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asTouchableNativeFeedbackElement: DOMAPI.anyElement => element = "%identity"

module Background = {
  type t

  @module("react-native") @scope("TouchableNativeFeedback")
  external selectableBackground: (~rippleRadius: float=?) => t = "SelectableBackground"

  @module("react-native") @scope("TouchableNativeFeedback")
  external selectableBackgroundBorderless: (~rippleRadius: float=?) => t =
    "SelectableBackgroundBorderless"

  @module("react-native") @scope("TouchableNativeFeedback")
  external canUseNativeForeground: unit => bool = "canUseNativeForeground"

  @module("react-native") @scope("TouchableNativeFeedback")
  external ripple: (string, bool, ~rippleRadius: float=?) => t = "Ripple"
}

type props = {
  ref?: ref,
  ...TouchableWithoutFeedback.coreProps,
  background?: Background.t,
  useForeground?: bool,
}

@module("react-native")
external make: React.component<props> = "TouchableNativeFeedback"
