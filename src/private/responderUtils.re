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
    : RN_types.touchResponderHandlers => {
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