[@bs.scope "Vibration"] [@bs.module "react-native"]
external _vibrate: (array(int), bool) => unit = "vibrate";

let vibrate = (~pattern, ~repeat) => _vibrate(pattern, repeat);

[@bs.scope "Vibration"] [@bs.module "react-native"]
external cancel: unit => unit = "";
