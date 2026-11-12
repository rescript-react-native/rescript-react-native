type barStyle = [
  | #default
  | // follows the current color scheme
  #auto
  | #"light-content"
  | #"dark-content"
]

type showHideTransition = [#fade | #none | #slide]

type props = {
  animated?: bool,
  barStyle?: barStyle,
  hidden?: bool,
  showHideTransition?: showHideTransition,
}

@module("react-native")
external make: React.component<props> = "StatusBar"

@module("react-native") @scope("StatusBar")
external setHidden: (bool, showHideTransition) => unit = "setHidden"

@module("react-native") @scope("StatusBar")
external setBarStyle: (barStyle, bool) => unit = "setBarStyle"

@module("react-native") @scope("StatusBar")
external currentHeight: nullable<float> = "currentHeight"
