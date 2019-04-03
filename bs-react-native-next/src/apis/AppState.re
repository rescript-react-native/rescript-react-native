type t;

external fromString: string => t = "%identity";

let active = "active"->fromString;
let background = "background"->fromString;
let inactive = "inactive"->fromString;

[@bs.scope "AppState"] [@bs.module "react-native"]
external currentState: t = "currentState";

[@bs.scope "AppState"] [@bs.module "react-native"]
external addEventListener: (string, unit => unit) => EventSubscription.t = "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener: (string, unit => unit) => unit = "";
