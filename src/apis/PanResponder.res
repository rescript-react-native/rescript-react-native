type gestureState = {
  stateID: float,
  moveX: float,
  moveY: float,
  x0: float,
  y0: float,
  dx: float,
  dy: float,
  vx: float,
  vy: float,
  numberActiveTouches: int,
}

type t
type panHandlers
type callback<'a> = Event.pressEvent => 'a

type config = {
  onMoveShouldSetPanResponder?: (Event.pressEvent, gestureState) => bool,
  onMoveShouldSetPanResponderCapture?: (Event.pressEvent, gestureState) => bool,
  onStartShouldSetPanResponder?: (Event.pressEvent, gestureState) => bool,
  onStartShouldSetPanResponderCapture?: (Event.pressEvent, gestureState) => bool,
  onPanResponderReject?: (Event.pressEvent, gestureState) => unit,
  onPanResponderGrant?: (Event.pressEvent, gestureState) => unit,
  onPanResponderStart?: (Event.pressEvent, gestureState) => unit,
  onPanResponderEnd?: (Event.pressEvent, gestureState) => unit,
  onPanResponderRelease?: (Event.pressEvent, gestureState) => unit,
  onPanResponderMove?: (Event.pressEvent, gestureState) => unit,
  onPanResponderTerminate?: (Event.pressEvent, gestureState) => unit,
  onPanResponderTerminationRequest?: (Event.pressEvent, gestureState) => bool,
  onShouldBlockNativeResponder?: (Event.pressEvent, gestureState) => bool,
}

@module("react-native") @scope("PanResponder")
external create: config => t = "create"

@get external panHandlers: t => panHandlers = "panHandlers"

@get
external onMoveShouldSetResponder: panHandlers => callback<bool> = "onMoveShouldSetResponder"
@get
external onMoveShouldSetResponderCapture: panHandlers => callback<bool> =
  "onMoveShouldSetResponderCapture"
@get
external onStartShouldSetResponder: panHandlers => callback<bool> = "onStartShouldSetResponder"
@get
external onStartShouldSetResponderCapture: panHandlers => callback<bool> =
  "onStartShouldSetResponderCapture"
@get
external onResponderReject: panHandlers => callback<unit> = "onResponderReject"
@get
external onResponderGrant: panHandlers => callback<unit> = "onResponderGrant"
@get
external onResponderRelease: panHandlers => callback<unit> = "onResponderRelease"
@get
external onResponderMove: panHandlers => callback<unit> = "onResponderMove"
@get
external onResponderTerminate: panHandlers => callback<unit> = "onResponderTerminate"
@get
external onResponderTerminationRequest: panHandlers => callback<bool> =
  "onResponderTerminationRequest"
@get
external onResponderStart: panHandlers => callback<unit> = "onResponderStart"
@get
external onResponderEnd: panHandlers => callback<unit> = "onResponderEnd"
