type t;

module NativeEvent = {
  type t;
  external changedTouches : t => array (Js.t {..}) = "" [@@bs.get];
  external identifier : t => int = "" [@@bs.get];
  external locationX : t => float = "" [@@bs.get];
  external locationY : t => float = "" [@@bs.get];
  external pageX : t => float = "" [@@bs.get];
  external pageY : t => float = "" [@@bs.get];
  external target : t => Js.t {..} = "" [@@bs.get];
  external touches : t => array (Js.t {..}) = "" [@@bs.get];
  external timestamp : t => int = "" [@@bs.get];
};

module NativeLayoutEvent = {
  type t;
  type layout = {x: float, y: float, width: float, height: float};
  external _layout : t => Js.t 'a =
    "nativeEvent" [@@bs.get];
  let layout (t: t) => {
    let l = (_layout t)##layout;
    {x: l##x, y: l##y, width: l##width, height: l##height}
  };
};

external nativeEvent : t => NativeEvent.t = "" [@@bs.get];

external nativeLayoutEvent : t => NativeLayoutEvent.t = "nativeEvent" [@@bs.get];
