external openURL : string => Js.Promise.t unit =
  "openUrl" [@@bs.scope "Linking"] [@@bs.module "react-native"];

external _canOpenUrl : string => Js.Promise.t Js.boolean =
  "canOpenUrl" [@@bs.scope "Linking"] [@@bs.module "react-native"];

let canOpenUrl url =>
  _canOpenUrl url |> Js.Promise.then_ (fun bool => Js.Promise.resolve (Js.to_bool bool));

external getInitialUrl : unit => Js.Promise.t string =
  "getInitialUrl" [@@bs.scope "Linking"] [@@bs.module "react-native"];

external addEventListener : string => (Js.t {. url : string} => unit) => unit =
  "" [@@bs.scope "Linking"] [@@bs.module "react-native"];

external removeEventListener : string => (Js.t {. url : string} => unit) => unit =
  "" [@@bs.scope "Linking"] [@@bs.module "react-native"];