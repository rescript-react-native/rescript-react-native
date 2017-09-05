type t;

external t : t = "StyleSheet" [@@bs.module "react-native"];

let create: Js.t 'a => Js.t 'a;

let hairlineWidth: float;

let absoluteFill: StyleRe.t;

let absoluteFillObject: StyleRe.t;

let flatten: list StyleRe.t => StyleRe.t;

let processColor: [ | `String string | `Number int] => string;
