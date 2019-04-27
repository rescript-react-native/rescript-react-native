type t = string;

[@bs.inline]
let small = "small";

[@bs.inline]
let large = "large";

external exact: float => t = "%identity";
