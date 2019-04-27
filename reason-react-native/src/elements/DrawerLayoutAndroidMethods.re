module Make = (T: {type t;}) => {
  [@bs.send] external openDrawer: (T.t, unit) => unit = "";
  [@bs.send] external closeDrawer: (T.t, unit) => unit = "";
};
