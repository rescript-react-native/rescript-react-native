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
external setHidden: (bool, ~animation: showHideTransition=?) => unit = "setHidden"

@module("react-native") @scope("StatusBar")
external setBarStyle: (barStyle, ~animated: bool=?) => unit = "setBarStyle"

@module("react-native") @scope("StatusBar")
external currentHeight: nullable<float> = "currentHeight"

// returned by `pushStackEntry`, to pass to `popStackEntry` / `replaceStackEntry`
@notUndefined
type stackEntry

@module("react-native") @scope("StatusBar")
external pushStackEntry: props => stackEntry = "pushStackEntry"

@module("react-native") @scope("StatusBar")
external popStackEntry: stackEntry => unit = "popStackEntry"

@module("react-native") @scope("StatusBar")
external replaceStackEntry: (stackEntry, props) => stackEntry = "replaceStackEntry"
