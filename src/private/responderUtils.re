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
    : Types.touchResponderHandlers =>
  Types.{
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
