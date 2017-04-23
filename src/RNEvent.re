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
/*type nativeEv 'a =
    Js.t {
      .
      identifier : int,
      locationX : int,
      locationY : int,
      pageX : int,
      pageY : int,
      target : Js.t 'a
      /*changedTouches : array (Js.t {..}),*/
      /*touches : array (Js.t {..})*/
    };

  external nativeEvent : t => nativeEv = "" [@@bs.get];*/