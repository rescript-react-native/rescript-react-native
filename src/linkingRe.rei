let canOpenUrl: string => Js.Promise.t bool;

external openURL : string => Js.Promise.t unit =
  "openUrl" [@@bs.scope "Linking"] [@@bs.module "react-native"];

external getInitialUrl : unit => Js.Promise.t string =
  "getInitialUrl" [@@bs.scope "Linking"] [@@bs.module "react-native"];

external addEventListener : string => (Js.t {. url : string} => unit) => unit =
  "" [@@bs.scope "Linking"] [@@bs.module "react-native"];

external removeEventListener : string => (Js.t {. url : string} => unit) => unit =
  "" [@@bs.scope "Linking"] [@@bs.module "react-native"];