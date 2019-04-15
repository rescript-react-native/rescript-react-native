[@bs.scope "Linking"] [@bs.module "react-native"]
external openURL: string => Js.Promise.t(unit) = "openURL";

[@bs.scope "Linking"] [@bs.module "react-native"]
external canOpenURL: string => Js.Promise.t(bool) = "canOpenURL";

[@bs.scope "Linking"] [@bs.module "react-native"]
external getInitialURL: unit => Js.Promise.t(Js.Null.t(string)) =
  "getInitialURL";

[@bs.scope "Linking"] [@bs.module "react-native"]
external addEventListener: (string, {. "url": string} => unit) => unit = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external removeEventListener: (string, {. "url": string} => unit) => unit =
  "";
