type t;

[@bs.module "react-native"] external t: t = "StyleSheet";

let create: Js.t('a) => Js.t('a);

let hairlineWidth: float;

let absoluteFill: RN_style.t;

let absoluteFillObject: RN_style.t;

let flatten: list(RN_style.t) => RN_style.t;

let processColor: [ | `String(string) | `Number(int)] => string;