module Make = (T: {type t;}) => {
  [@bs.send] external isFocused: T.t => bool = "";
  [@bs.send] external clear: T.t => unit = "";
};
