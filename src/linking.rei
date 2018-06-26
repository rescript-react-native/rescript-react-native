let canOpenURL: string => Js.Promise.t(bool);

[@bs.scope "Linking"] [@bs.module "react-native"]
external openURL : string => Js.Promise.t(unit) = "openURL";

let getInitialURL: unit => Js.Promise.t(option(string));

[@bs.scope "Linking"] [@bs.module "react-native"]
external addEventListener : (string, {. "url": string} => unit) => unit = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external removeEventListener : (string, {. "url": string} => unit) => unit =
  "";