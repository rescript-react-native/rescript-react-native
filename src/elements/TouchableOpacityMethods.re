module Make = (T: {type t;}) => {
  [@bs.send]
  external setOpacityTo: (T.t, ~value: float, ~duration: float) => unit =
    "setOpacityTo";
};
