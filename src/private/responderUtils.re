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
      ()
    )
    : TypesRN.touchResponderHandlers => {
  onMoveShouldSetResponder,
  onMoveShouldSetResponderCapture,
  onResponderGrant,
  onResponderMove,
  onResponderReject,
  onResponderRelease,
  onResponderTerminate,
  onResponderTerminationRequest,
  onStartShouldSetResponder,
  onStartShouldSetResponderCapture
};
