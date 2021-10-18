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
] => EventSubscription.t = "addEventListener"
