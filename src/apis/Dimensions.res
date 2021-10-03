type displayMetrics = {
  width: float,
  height: float,
  scale: float,
  fontScale: float,
}

type handler = {
  screen: displayMetrics,
  window: displayMetrics,
}

@module("react-native") @scope("Dimensions")
external get: [#window | #screen] => displayMetrics = "get"

type eventType = [#change]

@module("react-native") @scope("Dimensions")
external addEventListener: (eventType, handler => unit) => EventSubscription.t = "addEventListener"

@deprecated("Use `remove` on the EventSubscription from `addEventListener`.")
@module("react-native")
@scope("Dimensions")
external removeEventListener: (eventType, handler => unit) => unit = "removeEventListener"

@module("react-native")
external useWindowDimensions: unit => displayMetrics = "useWindowDimensions"
