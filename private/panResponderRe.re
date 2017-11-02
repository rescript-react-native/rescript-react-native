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
  numberActiveTouches: int
};

[@bs.scope "PanResponder"] [@bs.module "react-native"] external _create : 'a => t = "create";

type jsGestureState = {
  .
  "stateID": float,
  "moveX": float,
  "moveY": float,
  "x0": float,
  "y0": float,
  "dx": float,
  "dy": float,
  "vx": float,
  "vy": float,
  "numberActiveTouches": int
};

type callback('a) = ({. "nativeEvent": RNEvent.NativeEvent.t}, jsGestureState) => 'a;

let callback = (x: (RNEvent.NativeEvent.t, gestureState) => 'a) : callback('a) =>
  (event, state) =>
    x(
      event##nativeEvent,
      {
        dx: state##dx,
        dy: state##dy,
        moveX: state##moveX,
        moveY: state##moveY,
        numberActiveTouches: state##numberActiveTouches,
        stateID: state##stateID,
        vx: state##vx,
        vy: state##vy,
        x0: state##x0,
        y0: state##y0
      }
    );

external shamelesslyWrapCallback : 'a => callback(unit) = "%identity";

let animatedEvent = (l) => {
  let config =
    List.fold_left(
      (x, y) =>
        switch y {
        | `X((value: AnimatedRe.Value.t)) => Js.Obj.assign(x, {"dx": value})
        | `Y((value: AnimatedRe.Value.t)) => Js.Obj.assign(x, {"dy": value})
        | `XY(value) =>
          Js.Obj.assign(x, AnimatedRe.ValueXY.({"dx": getX(value), "dy": getY(value)}))
        },
      Js.Obj.empty(),
      l
    );
  shamelesslyWrapCallback(
    AnimatedRe.event([|Js.null, Js.Null.return(config)|], {"useNativeDriver": Js.false_})
  )
};

let create =
    (
      ~onMoveShouldSetPanResponder: option(callback(bool))=?,
      ~onMoveShouldSetPanResponderCapture: option(callback(bool))=?,
      ~onStartShouldSetPanResponder: option(callback(bool))=?,
      ~onStartShouldSetPanResponderCapture: option(callback(bool))=?,
      ~onPanResponderject: option(callback(unit))=?,
      ~onPanResponderGrant: option(callback(unit))=?,
      ~onPanResponderStart: option(callback(unit))=?,
      ~onPanResponderEnd: option(callback(unit))=?,
      ~onPanResponderlease: option(callback(unit))=?,
      ~onPanResponderMove=?,
      ~onPanResponderTerminate: option(callback(unit))=?,
      ~onPanResponderTerminationRequest: option(callback(bool))=?,
      ~onShouldBlockNativeResponder: option(callback(bool))=?,
      ()
    ) =>
  _create({
    "onMoveShouldSetPanResponder": Js.Undefined.from_opt(onMoveShouldSetPanResponder),
    "onMoveShouldSetPanResponderCapture": Js.Undefined.from_opt(onMoveShouldSetPanResponderCapture),
    "onStartShouldSetPanResponder": Js.Undefined.from_opt(onStartShouldSetPanResponder),
    "onStartShouldSetPanResponderCapture":
      Js.Undefined.from_opt(onStartShouldSetPanResponderCapture),
    "onPanResponderject": Js.Undefined.from_opt(onPanResponderject),
    "onPanResponderGrant": Js.Undefined.from_opt(onPanResponderGrant),
    "onPanResponderStart": Js.Undefined.from_opt(onPanResponderStart),
    "onPanResponderEnd": Js.Undefined.from_opt(onPanResponderEnd),
    "onPanResponderlease": Js.Undefined.from_opt(onPanResponderlease),
    "onPanResponderMove":
      switch onPanResponderMove {
      | None => Js.undefined
      | Some(x) =>
        switch x {
        | `update(l) => Js.Undefined.return(animatedEvent(l))
        | `callback((x: callback(unit))) => Js.Undefined.return(x)
        }
      },
    "onPanResponderTerminate": Js.Undefined.from_opt(onPanResponderTerminate),
    "onPanResponderTerminationRequest": Js.Undefined.from_opt(onPanResponderTerminationRequest),
    "onShouldBlockNativeResponder": Js.Undefined.from_opt(onShouldBlockNativeResponder)
  });
