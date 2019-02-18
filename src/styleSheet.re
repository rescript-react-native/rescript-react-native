type t;

[@bs.module "react-native"] external t: t = "StyleSheet";

[@bs.send] external create: (t, Js.t('a)) => Js.t('a) = "create";

let create: Js.t('a) => Js.t('a) = a => create(t, a);

[@bs.get] external hairlineWidth: t => float = "hairlineWidth";

let hairlineWidth = hairlineWidth(t);

[@bs.get] external absoluteFill: t => Style.t = "absoluteFill";

let absoluteFill = absoluteFill(t);

[@bs.get] external absoluteFillObject: t => Style.t = "absoluteFillObject";

let absoluteFillObject = absoluteFillObject(t);

[@bs.send] external flatten: (t, array(Style.t)) => Style.t = "flatten";

let flatten = styles => flatten(t, Array.of_list(styles));

/* It really returns an int but we
 * abuse externals because we use
 * colors as strings everywhere
 */
[@bs.module "react-native"]
external processColor:
  ([@bs.unwrap] [ | `String(string) | `Number(int)]) => string =
  "processColor";
