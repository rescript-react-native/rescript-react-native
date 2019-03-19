[@bs.scope "Linking"] [@bs.module "react-native"]
external openURL: string => Js.Promise.t(unit) = "openURL";

[@bs.scope "Linking"] [@bs.module "react-native"]
external _canOpenURL: string => Js.Promise.t(bool) = "canOpenURL";

let canOpenURL = url =>
  _canOpenURL(url) |> Js.Promise.then_(bool => Js.Promise.resolve(bool));

[@bs.scope "Linking"] [@bs.module "react-native"]
external _getInitialURL: unit => Js.Promise.t(Js.Null.t(string)) =
  "getInitialURL";

let getInitialURL = () =>
  _getInitialURL()
  |> Js.Promise.then_(stringOrNull =>
       Js.Promise.resolve(Js.Null.toOption(stringOrNull))
     );

[@bs.scope "Linking"] [@bs.module "react-native"]
external addEventListener: (string, {. "url": string} => unit) => unit = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external removeEventListener: (string, {. "url": string} => unit) => unit =
  "";
