external _vibrate : array int => Js.boolean => unit =
  "vibrate" [@@bs.scope "Vibration"] [@@bs.module "react-native"];

let vibrate ::pattern ::repea => _vibrate pattern (Js.Boolean.to_js_boolean repeat);

external cancel : unit => unit = "" [@@bs.scope "Vibration"] [@@bs.module "react-native"];