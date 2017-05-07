type t;

external t : t = "StyleSheet" [@@bs.module "react-native"];

let create: Js.t 'a => Js.t 'a;

let hairlineWidth: int;

let absoluteFill: StyleRe.t;

let absoluteFillObject: StyleRe.t;

let flatten: list StyleRe.t => StyleRe.t;