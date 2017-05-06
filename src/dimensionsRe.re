type dimensions = Js.t {. width : int, height : int, scale : float, fontScale : float};

external _get : string => dimensions =
  "get" [@@bs.scope "Dimensions"] [@@bs.module "react-native"];

let get key => {
  let strKey =
    switch key {
    | `window => "window"
    | `screen => "screen"
    };
  _get strKey
};

external addEventListener :
  string => (Js.t {. screen : dimensions, window : dimensions} => unit) => unit =
  "" [@@bs.scope "Dimensions"] [@@bs.module "react-native"];

external removeEventListener :
  string => (Js.t {. screen : dimensions, window : dimensions} => unit) => unit =
  "" [@@bs.scope "Dimensions"] [@@bs.module "react-native"];