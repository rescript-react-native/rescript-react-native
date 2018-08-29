type t;

[@bs.module "react-native"] external t : t = "StyleSheet";

let create: Js.t('a) => Js.t('a);

let hairlineWidth: float;

let absoluteFill: Style.t;

let absoluteFillObject: Style.t;

let flatten: list(Style.t) => Style.t;

let processColor: [ | `String(string) | `Number(int)] => string;