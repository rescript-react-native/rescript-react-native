external _vibrate : array int => Js.boolean => unit =
  "" [@@bs.scope "Vibrrate"] [@@bs.module "react-native"];

let vibrate ::pattern ::repeat => _vibrate pattern (Js.Boolean.to_js_boolean repeat);

external cancel : unit => unit = "" [@@bs.scope "Vibrrate"] [@@bs.module "react-native"];