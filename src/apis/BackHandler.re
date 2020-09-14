type remove = {. [@bs.meth] "remove": unit => unit};

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external exitApp: unit => unit = "exitApp";

type eventType = [ | `backPress | `hardwareBackPress];

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external addEventListener: (eventType, unit => bool) => remove =
  "addEventListener";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external removeEventListener: (eventType, unit => bool) => unit =
  "removeEventListener";
