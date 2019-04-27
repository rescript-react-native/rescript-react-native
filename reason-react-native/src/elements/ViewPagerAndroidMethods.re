module Make = (T: {type t;}) => {
  [@bs.send] external setPage: (T.t, int) => unit = "";
  [@bs.send] external setPageWithoutAnimation: (T.t, int) => unit = "";
};
