type t = string;

[@bs.inline]
let active = "active";

[@bs.inline]
let background = "background";

[@bs.inline]
let inactive = "inactive";

[@bs.scope "AppState"] [@bs.module "react-native"]
external currentState: t = "currentState";

[@bs.scope "AppState"] [@bs.module "react-native"]
external addEventListener:
  (
  [@bs.string]
  [
    | `change(t => unit)
    | `focus(unit => unit)
    | `blur(unit => unit)
    | `memoryWarning(unit => unit)
  ]
  ) =>
  unit =
  "addEventListener";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener:
  (
  [@bs.string]
  [
    | `change(t => unit)
    | `focus(unit => unit)
    | `blur(unit => unit)
    | `memoryWarning(unit => unit)
  ]
  ) =>
  unit =
  "removeEventListener";
