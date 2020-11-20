type t;

[@bs.inline "small"]
let small: t;

[@bs.inline "large"]
let large: t;

external exact: float => t = "%identity";
