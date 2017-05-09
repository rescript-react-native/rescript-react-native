type t;

module NativeEvent = {
  type t;
  external changedTouches : t => array (Js.t {..}) = "" [@@bs.get];
  external identifier : t => int = "" [@@bs.get];
  external locationX : t => int = "" [@@bs.get];
  external locationY : t => int = "" [@@bs.get];
  external pageX : t => int = "" [@@bs.get];
  external pageY : t => int = "" [@@bs.get];
  external target : t => Js.t {..} = "" [@@bs.get];
  external touches : t => array (Js.t {..}) = "" [@@bs.get];
  external timestamp : t => float = "" [@@bs.get];
};

module NativeLayoutEvent = {
  type t;
  type layout = {x: int, y: int, width: int, height: int};
  external _layout : t => Js.t {. x : int, y : int, width : int, height : int} =
    "layout" [@@bs.get];
  let layout (t: t) => {
    let l = _layout t;
    {x: l##x, y: l##y, width: l##width, height: l##height}
  };
};

external nativeEvent : t => NativeEvent.t = "" [@@bs.get];

external nativeLayoutEvent : t => NativeLayoutEvent.t = "nativeEvent" [@@bs.get];
