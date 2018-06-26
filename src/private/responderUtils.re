let responderHandlers =
    (
      ~onMoveShouldSetResponder=?,
      ~onMoveShouldSetResponderCapture=?,
      ~onResponderGrant=?,
      ~onResponderMove=?,
      ~onResponderReject=?,
      ~onResponderRelease=?,
      ~onResponderTerminate=?,
      ~onResponderTerminationRequest=?,
      ~onStartShouldSetResponder=?,
      ~onStartShouldSetResponderCapture=?,
      (),
    )
    : Types.touchResponderHandlers => {
  onMoveShouldSetResponder,
  onMoveShouldSetResponderCapture,
  onResponderGrant,
  onResponderMove,
  onResponderReject,
  onResponderRelease,
  onResponderTerminate,
  onResponderTerminationRequest,
  onStartShouldSetResponder,
  onStartShouldSetResponderCapture,
};