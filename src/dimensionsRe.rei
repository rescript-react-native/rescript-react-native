type dimensions = Js.t {. fontScale : float, height : int, scale : float, width : int};

let get: [< | `screen | `window] => dimensions;

external addEventListener :
  string => (Js.t {. screen : dimensions, window : dimensions} => unit) => unit =
  "" [@@bs.scope "Dimensions"] [@@bs.module "react-native"];

external removeEventListener :
  string => (Js.t {. screen : dimensions, window : dimensions} => unit) => unit =
  "" [@@bs.scope "Dimensions"] [@@bs.module "react-native"];