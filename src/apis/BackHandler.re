type remove = {. [@bs.meth] "remove": unit => unit};

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external exitApp: unit => unit = "exitApp";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external addEventListener:
  ([@bs.string] [ | `backPress | `hardwareBackPress], unit => bool) => remove =
  "addEventListener";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external removeEventListener:
  ([@bs.string] [ | `backPress | `hardwareBackPress], unit => bool) => unit =
  "removeEventListener";
