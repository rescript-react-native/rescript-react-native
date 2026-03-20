type keyboardMetrics = {
  screenX: float,
  screenY: float,
  width: float,
  height: float,
}

type eventType = [
  | #keyboardWillShow
  | #keyboardDidShow
  | #keyboardWillHide
  | #keyboardDidHide
  | #keyboardWillChangeFrame
  | #keyboardDidChangeFrame
]

type keyboardEvent = {
  duration: float,
  easing: LayoutAnimation.animationType,
  endCoordinates: keyboardMetrics,
  startCoordinates: keyboardMetrics,
  isEventFromThisApp: bool,
}

type listener = keyboardEvent => unit

@module("react-native") @scope("Keyboard")
external addListener: (eventType, listener) => EventSubscription.t = "addListener"

@module("react-native") @scope("Keyboard")
external removeAllListeners: eventType => unit = "removeAllListeners"

@module("react-native") @scope("Keyboard")
external dismiss: unit => unit = "dismiss"

@module("react-native") @scope("Keyboard")
external isVisible: unit => bool = "isVisible"

@module("react-native") @scope("Keyboard")
external scheduleLayoutAnimation: keyboardEvent => unit = "scheduleLayoutAnimation"

@module("react-native") @scope("Keyboard") @return(nullable)
external metrics: unit => option<keyboardMetrics> = "metrics"
