type t = [#dark | #light]

@scope("Appearance") @module("react-native")
external getColorScheme: unit => Js.Null.t<t> = "getColorScheme"

@module("react-native")
external useColorScheme: unit => Js.Null.t<t> = "useColorScheme"
