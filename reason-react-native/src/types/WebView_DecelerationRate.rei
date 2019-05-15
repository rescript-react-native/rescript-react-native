type t;

external value: float => t = "%identity";

[@bs.inline "normal"]
let normal: t;

[@bs.inline "fast"]
let fast: t;
