[@bs.scope "Vibration"] [@bs.module "react-native"]
external vibrateWithDuration: (int, ~repeat: bool=?, unit) => unit = "vibrate";

[@bs.scope "Vibration"] [@bs.module "react-native"]
external vibrateWithPattern: (array(int), ~repeat: bool=?, unit) => unit =
  "vibrate";

[@bs.scope "Vibration"] [@bs.module "react-native"]
external cancel: unit => unit = "cancel";
