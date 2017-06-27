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

external _create : 'a => t = "create" [@@bs.scope "PanResponder"] [@@bs.module "react-native"];

type jsGestureState =
  Js.t {
    .
    stateID : float,
    moveX : float,
    moveY : float,
    x0 : float,
    y0 : float,
    dx : float,
    dy : float,
    vx : float,
    vy : float,
    numberActiveTouches : int
  };

type callback 'a = Js.t {. nativeEvent : RNEvent.NativeEvent.t} => jsGestureState => 'a;

let callback (x: RNEvent.NativeEvent.t => gestureState => 'a) :callback 'a =>
  fun event state =>
    x
      event##nativeEvent
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
      };

external shamelesslyWrapCallback : 'a => callback unit = "%identity";

let animatedEvent l => {
  let config =
    List.fold_left
      (
        fun x y =>
          switch y {
          | `X (value: AnimatedRe.Value.t) => Js.Obj.assign x {"dx": value}
          | `Y (value: AnimatedRe.Value.t) => Js.Obj.assign x {"dy": value}
          | `XY value => Js.Obj.assign x AnimatedRe.ValueXY.({"dx": getX value, "dy": getY value})
          }
      )
      (Js.Obj.empty ())
      l;
  shamelesslyWrapCallback (
    AnimatedRe.event [|Js.null, Js.Null.return config|] {"useNativeDriver": Js.false_}
  )
};

let create
    onMoveShouldSetPanResponder::(onMoveShouldSetPanResponder: option (callback bool))=?
    onMoveShouldSetPanResponderCapture::
      (onMoveShouldSetPanResponderCapture: option (callback bool))=?
    onStartShouldSetPanResponder::(onStartShouldSetPanResponder: option (callback bool))=?
    onStartShouldSetPanResponderCapture::
      (onStartShouldSetPanResponderCapture: option (callback bool))=?
    onPanResponderReject::(onPanResponderReject: option (callback unit))=?
    onPanResponderGrant::(onPanResponderGrant: option (callback unit))=?
    onPanResponderStart::(onPanResponderStart: option (callback unit))=?
    onPanResponderEnd::(onPanResponderEnd: option (callback unit))=?
    onPanResponderRelease::(onPanResponderRelease: option (callback unit))=?
    ::onPanResponderMove=?
    onPanResponderTerminate::(onPanResponderTerminate: option (callback unit))=?
    onPanResponderTerminationRequest::(onPanResponderTerminationRequest: option (callback bool))=?
    onShouldBlockNativeResponder::(onShouldBlockNativeResponder: option (callback bool))=?
    () =>
  _create {
    "onMoveShouldSetPanResponder": Js.Undefined.from_opt onMoveShouldSetPanResponder,
    "onMoveShouldSetPanResponderCapture": Js.Undefined.from_opt onMoveShouldSetPanResponderCapture,
    "onStartShouldSetPanResponder": Js.Undefined.from_opt onStartShouldSetPanResponder,
    "onStartShouldSetPanResponderCapture":
      Js.Undefined.from_opt onStartShouldSetPanResponderCapture,
    "onPanResponderReject": Js.Undefined.from_opt onPanResponderReject,
    "onPanResponderGrant": Js.Undefined.from_opt onPanResponderGrant,
    "onPanResponderStart": Js.Undefined.from_opt onPanResponderStart,
    "onPanResponderEnd": Js.Undefined.from_opt onPanResponderEnd,
    "onPanResponderRelease": Js.Undefined.from_opt onPanResponderRelease,
    "onPanResponderMove":
      switch onPanResponderMove {
      | None => Js.undefined
      | Some x =>
        switch x {
        | `update l => Js.Undefined.return (animatedEvent l)
        | `callback (x: callback unit) => Js.Undefined.return x
        }
      },
    "onPanResponderTerminate": Js.Undefined.from_opt onPanResponderTerminate,
    "onPanResponderTerminationRequest": Js.Undefined.from_opt onPanResponderTerminationRequest,
    "onShouldBlockNativeResponder": Js.Undefined.from_opt onShouldBlockNativeResponder
  };