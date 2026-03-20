type remove = {@meth "remove": unit => unit}

@scope("BackHandler") @module("react-native")
external exitApp: unit => unit = "exitApp"

type eventType = [#hardwareBackPress]

@scope("BackHandler") @module("react-native")
external addEventListener: (eventType, unit => Js.Nullable.t<bool>) => remove = "addEventListener"
