type message = string;
type duration;
type gravity;

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external short: duration = "SHORT";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external long: duration = "LONG";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external top: gravity = "TOP";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external bottom: gravity = "BOTTOM";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external center: gravity = "CENTER";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external show: (message, duration) => unit = "show";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external showWithGravity: (message, duration, gravity) => unit =
  "showWithGravity";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external showWithGravityAndOffset:
  (message, duration, gravity, ~xOffset: float, ~yOffset: float) => unit =
  "showWithGravityAndOffset";
