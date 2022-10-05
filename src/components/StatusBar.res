type barStyle = [
  | #default
  | #"light-content"
  | #"dark-content"
]

type showHideTransition = [#fade | #none | #slide]

@react.component @module("react-native")
external make: (
  ~animated: bool=?,
  ~barStyle: barStyle=?,
  ~hidden: bool=?,
  ~backgroundColor: string=?,
  ~translucent: bool=?,
  ~networkActivityIndicatorVisible: bool=?,
  ~showHideTransition: showHideTransition=?,
) => React.element = "StatusBar"

@module("react-native") @scope("StatusBar")
external setHidden: (bool, showHideTransition) => unit = "setHidden"

@module("react-native") @scope("StatusBar")
external setBarStyle: (barStyle, bool) => unit = "setBarStyle"

@module("react-native") @scope("StatusBar")
external setNetworkActivityIndicatorVisible: bool => unit = "setNetworkActivityIndicatorVisible"

@module("react-native") @scope("StatusBar")
external setBackgroundColor: (Color.t, bool) => unit = "setBackgroundColor"

@module("react-native") @scope("StatusBar")
external setTranslucent: bool => unit = "setTranslucent"

@module("react-native") @scope("StatusBar")
external currentHeight: float = "currentHeight"
