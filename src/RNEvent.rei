type t;

module NativeEvent: {
  type t;
  external changedTouches : t => array (Js.t {..}) = "" [@@bs.get];
  external identifier : t => int = "" [@@bs.get];
  external locationX : t => int = "" [@@bs.get];
  external locationY : t => int = "" [@@bs.get];
  external pageX : t => int = "" [@@bs.get];
  external pageY : t => int = "" [@@bs.get];
  external target : t => Js.t {..} = "" [@@bs.get];
  external touches : t => array (Js.t {..}) = "" [@@bs.get];
  let timestamp: t => float;
};

module NativeLayoutEvent: {
  type t;
  type layout = {x: int, y: int, width: int, height: int};
  let layout: t => layout;
};

external nativeEvent : t => NativeEvent.t = "" [@@bs.get];

external nativeLayoutEvent : t => NativeLayoutEvent.t = "nativeEvent" [@@bs.get];
