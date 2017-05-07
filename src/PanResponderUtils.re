external _panHandlers : PanResponderRe.t => Js.t 'a = "panHandlers" [@@bs.get];

let panHandlers t: Props.touchResponderHandlers => {
  let jsHandlers = _panHandlers t;
  Js.log jsHandlers;
  {
    onMoveShouldSetResponder: Js.Undefined.to_opt jsHandlers##onMoveShouldSetResponder,
    onMoveShouldSetResponderCapture: Js.Undefined.to_opt jsHandlers##onMoveShouldSetResponderCapture,
    onResponderGrant: Js.Undefined.to_opt jsHandlers##onResponderGrant,
    onResponderMove: Js.Undefined.to_opt jsHandlers##onResponderMove,
    onResponderReject: Js.Undefined.to_opt jsHandlers##onResponderReject,
    onResponderRelease: Js.Undefined.to_opt jsHandlers##onResponderRelease,
    onResponderTerminate: Js.Undefined.to_opt jsHandlers##onResponderTerminate,
    onResponderTerminationRequest: Js.Undefined.to_opt jsHandlers##onResponderTerminationRequest,
    onStartShouldSetResponder: Js.Undefined.to_opt jsHandlers##onStartShouldSetResponder,
    onStartShouldSetResponderCapture: Js.Undefined.to_opt jsHandlers##onStartShouldSetResponderCapture
  };
};
