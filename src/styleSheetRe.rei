type t;

external t : t = "StyleSheet" [@@bs.module "react-native"];

let create: Js.t 'a => Js.t 'a;

let hairlineWidth: int;

let absoluteFill: Style.t;

let absoluteFillObject: Style.t;

let flatten: list Style.t => Style.t;