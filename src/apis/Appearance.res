type t = [#dark | #light]

@module("react-native") @scope("Appearance")
external getColorScheme: unit => Js.Null.t<t> = "getColorScheme"

@module("react-native")
external useColorScheme: unit => Js.Null.t<t> = "useColorScheme"

@module("react-native") @scope("Appearance")
external addChangeListener: (unit => unit) => EventSubscription.t = "addChangeListener"
