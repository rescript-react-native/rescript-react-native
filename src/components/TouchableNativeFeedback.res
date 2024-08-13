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

type props = {
  ref?: ref,
  ...TouchableWithoutFeedback.coreProps,
  background?: Background.t,
  useForeground?: bool,
}

@module("react-native")
external make: React.component<props> = "TouchableNativeFeedback"
