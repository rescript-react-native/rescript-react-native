type insets = {
  .
  "left": int,
  "right": int,
  "top": int,
  "bottom": int,
};

type touchResponderHandlers = {
  onMoveShouldSetResponder: option(RN_Event.NativeEvent.t => bool),
  onMoveShouldSetResponderCapture: option(RN_Event.NativeEvent.t => bool),
  onResponderGrant: option(RN_Event.NativeEvent.t => unit),
  onResponderMove: option(RN_Event.NativeEvent.t => unit),
  onResponderReject: option(RN_Event.NativeEvent.t => unit),
  onResponderRelease: option(RN_Event.NativeEvent.t => unit),
  onResponderTerminate: option(RN_Event.NativeEvent.t => unit),
  onResponderTerminationRequest: option(RN_Event.NativeEvent.t => unit),
  onStartShouldSetResponder: option(RN_Event.NativeEvent.t => bool),
  onStartShouldSetResponderCapture: option(RN_Event.NativeEvent.t => bool),
};