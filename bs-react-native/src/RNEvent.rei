type t;

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

module NativePressEvent = NativeEvent;

module NativeScrollEvent: {
  type t;
  type point = {
    x: float,
    y: float,
  };
  type size = {
    width: float,
    height: float,
  };
  type contentInset = {
    bottom: float,
    top: float,
    left: float,
    right: float,
  };
  let contentOffset: t => point;
  let contentSize: t => size;
  let contentInset: t => contentInset;
  let layoutMeasurement: t => size;
};

module NativeLayoutEvent: {
  type t;
  type layout = {
    x: float,
    y: float,
    width: float,
    height: float,
  };
  let layout: t => layout;
};

let nativeEvent: t => NativeEvent.t;

let nativeLayoutEvent: t => NativeLayoutEvent.t;

let nativeScrollEvent: t => NativeScrollEvent.t;
