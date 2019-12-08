module Make = (T: {type t;}) => {
  [@bs.send] external goForward: T.t => unit = "goForward";
  [@bs.send] external goBack: T.t => unit = "goBack";
  [@bs.send] external reload: T.t => unit = "reload";
  [@bs.send] external stopLoading: T.t => unit = "stopLoading";
};
