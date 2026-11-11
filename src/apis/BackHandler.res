type remove = {@meth "remove": unit => unit}

@scope("BackHandler") @module("react-native")
external exitApp: unit => unit = "exitApp"

type eventType = [#hardwareBackPress]

type hardwareBackPressEvent = {
  @as("type") type_: string,
  timeStamp: float,
}

@scope("BackHandler") @module("react-native")
external addEventListener: (eventType, hardwareBackPressEvent => nullable<bool>) => remove =
  "addEventListener"
