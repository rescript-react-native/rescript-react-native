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
};

type t;
type config = {
  onMoveShouldSetPanResponder:
    (Event.pressEvent, gestureState) => option(bool),
  onMoveShouldSetPanResponderCapture:
    (Event.pressEvent, gestureState) => option(bool),
  onStartShouldSetPanResponder:
    (Event.pressEvent, gestureState) => option(bool),
  onStartShouldSetPanResponderCapture:
    (Event.pressEvent, gestureState) => option(bool),
  onPanResponderReject: (Event.pressEvent, gestureState) => option(unit),
  onPanResponderGrant: (Event.pressEvent, gestureState) => option(unit),
  onPanResponderStart: (Event.pressEvent, gestureState) => option(unit),
  onPanResponderEnd: (Event.pressEvent, gestureState) => option(unit),
  onPanResponderRelease: (Event.pressEvent, gestureState) => option(unit),
  onPanResponderMove: (Event.pressEvent, gestureState) => option(unit),
  onPanResponderTerminate: (Event.pressEvent, gestureState) => option(unit),
  onPanResponderTerminationRequest:
    (Event.pressEvent, gestureState) => option(bool),
  onShouldBlockNativeResponder:
    (Event.pressEvent, gestureState) => option(bool),
};
type panHandlers;
type callback('a) = Event.pressEvent => 'a;

[@bs.module "react-native"] [@bs.scope "PanResponder"]
external create: config => t = "create";

[@bs.get] external panHandlers: t => panHandlers = "panHandlers";

[@bs.get]
external onMoveShouldSetResponder: panHandlers => callback(bool) =
  "onMoveShouldSetResponder";
[@bs.get]
external onMoveShouldSetResponderCapture: panHandlers => callback(bool) =
  "onMoveShouldSetResponderCapture";
[@bs.get]
external onStartShouldSetResponder: panHandlers => callback(bool) =
  "onStartShouldSetResponder";
[@bs.get]
external onStartShouldSetResponderCapture: panHandlers => callback(bool) =
  "onStartShouldSetResponderCapture";
[@bs.get]
external onResponderReject: panHandlers => callback(unit) =
  "onResponderReject";
[@bs.get]
external onResponderGrant: panHandlers => callback(unit) = "onResponderGrant";
[@bs.get]
external onResponderRelease: panHandlers => callback(unit) =
  "onResponderRelease";
[@bs.get]
external onResponderMove: panHandlers => callback(unit) = "onResponderMove";
[@bs.get]
external onResponderTerminate: panHandlers => callback(unit) =
  "onResponderTerminate";
[@bs.get]
external onResponderTerminationRequest: panHandlers => callback(bool) =
  "onResponderTerminationRequest";
[@bs.get]
external onResponderStart: panHandlers => callback(unit) = "onResponderStart";
[@bs.get]
external onResponderEnd: panHandlers => callback(unit) = "onResponderEnd";
