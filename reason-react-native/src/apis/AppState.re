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
external addEventListener: (string, unit => unit) => EventSubscription.t = "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener: (string, unit => unit) => unit = "";
