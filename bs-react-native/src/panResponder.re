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

[@bs.scope "PanResponder"] [@bs.module "react-native"]
external _create: 'a => t = "create";

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
  "numberActiveTouches": int,
};

type callback('a) =
  ({. "nativeEvent": RNEvent.NativeEvent.t}, jsGestureState) => 'a;

let callback = (x: (RNEvent.NativeEvent.t, gestureState) => 'a): callback('a) =>
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
        y0: state##y0,
      },
    );

external shamelesslyWrapCallback: 'a => callback(unit) = "%identity";

let animatedEvent = l => {
  let config =
    List.fold_left(
      (x, y) =>
        switch (y) {
        | `X((value: AnimatedRe.Value.t)) => Js.Obj.assign(x, {"dx": value})
        | `Y((value: AnimatedRe.Value.t)) => Js.Obj.assign(x, {"dy": value})
        | `XY(value) =>
          Js.Obj.assign(
            x,
            AnimatedRe.ValueXY.{"dx": getX(value), "dy": getY(value)},
          )
        },
      Js.Obj.empty(),
      l,
    );
  shamelesslyWrapCallback(
    AnimatedRe.event(
      [|Js.null, Js.Null.return(config)|],
      {"useNativeDriver": false},
    ),
  );
};

let create =
    (
      ~onMoveShouldSetPanResponder: option(callback(bool))=?,
      ~onMoveShouldSetPanResponderCapture: option(callback(bool))=?,
      ~onStartShouldSetPanResponder: option(callback(bool))=?,
      ~onStartShouldSetPanResponderCapture: option(callback(bool))=?,
      ~onPanResponderReject: option(callback(unit))=?,
      ~onPanResponderGrant: option(callback(unit))=?,
      ~onPanResponderStart: option(callback(unit))=?,
      ~onPanResponderEnd: option(callback(unit))=?,
      ~onPanResponderRelease: option(callback(unit))=?,
      ~onPanResponderMove=?,
      ~onPanResponderTerminate: option(callback(unit))=?,
      ~onPanResponderTerminationRequest: option(callback(bool))=?,
      ~onShouldBlockNativeResponder: option(callback(bool))=?,
      (),
    ) =>
  _create({
    "onMoveShouldSetPanResponder":
      Js.Undefined.fromOption(onMoveShouldSetPanResponder),
    "onMoveShouldSetPanResponderCapture":
      Js.Undefined.fromOption(onMoveShouldSetPanResponderCapture),
    "onStartShouldSetPanResponder":
      Js.Undefined.fromOption(onStartShouldSetPanResponder),
    "onStartShouldSetPanResponderCapture":
      Js.Undefined.fromOption(onStartShouldSetPanResponderCapture),
    "onPanResponderReject": Js.Undefined.fromOption(onPanResponderReject),
    "onPanResponderGrant": Js.Undefined.fromOption(onPanResponderGrant),
    "onPanResponderStart": Js.Undefined.fromOption(onPanResponderStart),
    "onPanResponderEnd": Js.Undefined.fromOption(onPanResponderEnd),
    "onPanResponderRelease": Js.Undefined.fromOption(onPanResponderRelease),
    "onPanResponderMove":
      switch (onPanResponderMove) {
      | None => Js.undefined
      | Some(x) =>
        switch (x) {
        | `update(l) => Js.Undefined.return(animatedEvent(l))
        | `callback((x: callback(unit))) => Js.Undefined.return(x)
        }
      },
    "onPanResponderTerminate":
      Js.Undefined.fromOption(onPanResponderTerminate),
    "onPanResponderTerminationRequest":
      Js.Undefined.fromOption(onPanResponderTerminationRequest),
    "onShouldBlockNativeResponder":
      Js.Undefined.fromOption(onShouldBlockNativeResponder),
  });

[@bs.get] external _panHandlers: t => Js.t('a) = "panHandlers";

let panHandlers = (t): Types.touchResponderHandlers => {
  let jsHandlers = _panHandlers(t);
  Types.{
    onMoveShouldSetResponder:
      Js.Undefined.toOption(jsHandlers##onMoveShouldSetResponder),
    onMoveShouldSetResponderCapture:
      Js.Undefined.toOption(jsHandlers##onMoveShouldSetResponderCapture),
    onResponderGrant: Js.Undefined.toOption(jsHandlers##onResponderGrant),
    onResponderMove: Js.Undefined.toOption(jsHandlers##onResponderMove),
    onResponderReject: Js.Undefined.toOption(jsHandlers##onResponderReject),
    onResponderRelease: Js.Undefined.toOption(jsHandlers##onResponderRelease),
    onResponderTerminate:
      Js.Undefined.toOption(jsHandlers##onResponderTerminate),
    onResponderTerminationRequest:
      Js.Undefined.toOption(jsHandlers##onResponderTerminationRequest),
    onStartShouldSetResponder:
      Js.Undefined.toOption(jsHandlers##onStartShouldSetResponder),
    onStartShouldSetResponderCapture:
      Js.Undefined.toOption(jsHandlers##onStartShouldSetResponderCapture),
  };
};
