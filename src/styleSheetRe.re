type t;

external t : t = "StyleSheet" [@@bs.module "react-native"];

external create : t => Js.t 'a => Js.t 'a = "create" [@@bs.send];

let create: Js.t 'a => Js.t 'a = fun a => create t a;

external hairlineWidth : t => float = "hairlineWidth" [@@bs.get];

let hairlineWidth = hairlineWidth t;

external absoluteFill : t => StyleRe.t = "absoluteFill" [@@bs.get];

let absoluteFill = absoluteFill t;

external absoluteFillObject : t => StyleRe.t = "absoluteFillObject" [@@bs.get];

let absoluteFillObject = absoluteFillObject t;

external flatten : t => array StyleRe.t => StyleRe.t = "flatten" [@@bs.send];

let flatten styles => flatten t (Array.of_list styles);

/* It really returns an int but we
 * abuse externals because we use
 * colors as strings everywhere
 */
external processColor : [ | `String string | `Number int] [@bs.unwrap] => string =
  "processColor" [@@bs.module "react-native"];
