/**
[PanResponder] reconciles several touches into a single gesture. It makes single-touch gestures resilient to extra touches, and can be used to recognize simple multi-touch gestures.

By default, PanResponder holds an [InteractionManager] handle to block long-running JS events from interrupting active gestures.

It provides a predictable wrapper of the responder handlers provided by the gesture responder system. For each handler, it provides a new [gestureState] object alongside the native event object:

{[
  onPanResponderMove: [
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
]}

A native event is a synthetic touch event with the following form:

{[
  module NativeEvent: {
    type t;
    let changedTouches: t => array(Js.t({..}));
    let identifier: t => int;
    let locationX: t => float;
    let locationY: t => float;
    let pageX: t => float;
    let pageY: t => float;
    let target: t => Js.t({..});
    let touches: t => array(Js.t({..}));
    let timestamp: t => int;
    let data: t => string;
  };
]}

A gestureState type is the following
{[
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
]}

- [stateID] - ID of the gestureState- persisted as long as there at least one touch on screen
- [moveX] - the latest screen coordinates of the recently-moved touch
- [moveY] - the latest screen coordinates of the recently-moved touch
- [x0] - the screen coordinates of the responder grant
- [y0] - the screen coordinates of the responder grant
- [dx] - accumulated distance of the gesture since the touch started
- [dy] - accumulated distance of the gesture since the touch started
- [vx] - current velocity of the gesture
- [vy] - current velocity of the gesture
- [numberActiveTouches] - Number of touches currently on screen

You can read more on [PanResponder] API usage in official docs:
{{:https://facebook.github.io/react-native/docs/panresponder}}

{3 Types}
{4 t}
{[
type t;
]}
{4 gestureState}
{[
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
]}
{4 callback}
{[
  type callback('a);
]}
{4 callback}
{[
  let callback: ((RNEvent.NativeEvent.t, gestureState) => 'a) => callback('a);
]}
{4 create}
{[
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
]}
{4 panHandlers}
{[
  let panHandlers: t => Types.touchResponderHandlers;
]}

reference {b Types.touchResponderHandlers}
{[
  type touchResponderHandlers = {
  onMoveShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
  onMoveShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool),
  onResponderGrant: option(RNEvent.NativeEvent.t => unit),
  onResponderMove: option(RNEvent.NativeEvent.t => unit),
  onResponderReject: option(RNEvent.NativeEvent.t => unit),
  onResponderRelease: option(RNEvent.NativeEvent.t => unit),
  onResponderTerminate: option(RNEvent.NativeEvent.t => unit),
  onResponderTerminationRequest: option(RNEvent.NativeEvent.t => unit),
  onStartShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
  onStartShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool),
};
]}
reference {b RNEvent.NativeEvent}
{[
  module NativeEvent: {
  type t;
  let changedTouches: t => array(Js.t({..}));
  let identifier: t => int;
  let locationX: t => float;
  let locationY: t => float;
  let pageX: t => float;
  let pageY: t => float;
  let target: t => Js.t({..});
  let touches: t => array(Js.t({..}));
  let timestamp: t => int;
  let data: t => string;
};
]}
*/

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
