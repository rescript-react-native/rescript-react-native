module Make = (T: {type t;}) => {
  [@bs.send] external openDrawer: (T.t, unit) => unit = "openDrawer";
  [@bs.send] external closeDrawer: (T.t, unit) => unit = "closeDrawer";
};
