[@bs.scope "Vibration"] [@bs.module "react-native"]
external _vibrate : (array(int), Js.boolean) => unit =
  "vibrate";

let vibrate = (~pattern, ~repeat) => _vibrate(pattern, Js.Boolean.to_js_boolean(repeat));

[@bs.scope "Vibration"] [@bs.module "react-native"] external cancel : unit => unit = "";
