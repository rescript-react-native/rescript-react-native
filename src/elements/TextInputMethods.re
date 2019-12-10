module Make = (T: {type t;}) => {
  [@bs.send] external isFocused: T.t => bool = "isFocused";
  [@bs.send] external clear: T.t => unit = "clear";
};
