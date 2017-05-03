external exitApp : unit => unit =
  "" [@@bs.scope "BackHandler"] [@@bs.module "react-native"];

external addEventListener : string => (unit => unit) => unit =
  "" [@@bs.scope "BackHandler"] [@@bs.module "react-native"];

external removeEventListener : string => (unit => unit) => unit =
  "" [@@bs.scope "BackHandler"] [@@bs.module "react-native"];