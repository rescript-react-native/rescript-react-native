type t = [#active | #background | #inactive | #unknown | #extension]

@scope("AppState") @module("react-native")
external currentState: t = "currentState"

@scope("AppState") @module("react-native")
external addEventListener: @string
[
  | #change(t => unit)
  | #focus(unit => unit)
  | #blur(unit => unit)
  | #memoryWarning(unit => unit)
] => unit = "addEventListener"

@scope("AppState") @module("react-native")
external removeEventListener: @string
[
  | #change(t => unit)
  | #focus(unit => unit)
  | #blur(unit => unit)
  | #memoryWarning(unit => unit)
] => unit = "removeEventListener"
