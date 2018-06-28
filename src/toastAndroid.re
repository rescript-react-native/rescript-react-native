type duration =
  | BOTTOM
  | CENTER
  | LONG
  | SHORT
  | TOP;

type gravity =
  | BOTTOM
  | CENTER
  | TOP;

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external show : (string, duration) => unit = "";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external show : (string, duration) => unit = "";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external showWithGravity : (string, duration, gravity) => unit = "";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external showWithGravityAndOffset :
  (string, duration, gravity, int, int) => unit =
  "";