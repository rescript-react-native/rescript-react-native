type t;

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

type callback('a);

let callback: ((RNEvent.NativeEvent.t, gestureState) => 'a) => callback('a);

let create:
  (
    ~onMoveShouldSetPanResponder: callback(bool)=?,
    ~onMoveShouldSetPanResponderCapture: callback(bool)=?,
    ~onStartShouldSetPanResponder: callback(bool)=?,
    ~onStartShouldSetPanResponderCapture: callback(bool)=?,
    ~onPanResponderReject: callback(unit)=?,
    ~onPanResponderGrant: callback(unit)=?,
    ~onPanResponderStart: callback(unit)=?,
    ~onPanResponderEnd: callback(unit)=?,
    ~onPanResponderRelease: callback(unit)=?,
    ~onPanResponderMove: [
                           | `callback(callback(unit))
                           | `update(
                               list(
                                 [
                                   | `X(AnimatedRe.Value.t)
                                   | `XY(AnimatedRe.ValueXY.t)
                                   | `Y(AnimatedRe.Value.t)
                                 ],
                               ),
                             )
                         ]
                           =?,
    ~onPanResponderTerminate: callback(unit)=?,
    ~onPanResponderTerminationRequest: callback(bool)=?,
    ~onShouldBlockNativeResponder: callback(bool)=?,
    unit
  ) =>
  t;

let panHandlers: t => Types.touchResponderHandlers;