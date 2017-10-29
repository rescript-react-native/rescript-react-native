type t;

[@bs.module "react-native"] external t : t = "StyleSheet";

let create: Js.t('a) => Js.t('a);

let hairlineWidth: float;

let absoluteFill: StyleRe.t;

let absoluteFillObject: StyleRe.t;

let flatten: list(StyleRe.t) => StyleRe.t;

let processColor: [ | `String(string) | `Number(int)] => string;
