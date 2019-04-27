module Make = (T: {type t;}) => {
  [@bs.send] external goForward: T.t => unit = "";
  [@bs.send] external goBack: T.t => unit = "";
  [@bs.send] external reload: T.t => unit = "";
  [@bs.send] external stopLoading: T.t => unit = "";
};
