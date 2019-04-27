type t = string;

external pt: float => t = "%identity";

let pct = num => num->Js.Float.toString ++ "%";
