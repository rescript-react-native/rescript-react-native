type displayMetrics = {
  width: float,
  height: float,
  scale: float,
  fontScale: float,
};

type handler = {
  screen: displayMetrics,
  window: displayMetrics,
};

[@bs.module "react-native"] [@bs.scope "Dimensions"]
external get: [ | `window | `screen] => displayMetrics = "get";

type eventType = [ | `change];

[@bs.module "react-native"] [@bs.scope "Dimensions"]
external addEventListener: (eventType, handler => unit) => unit =
  "addEventListener";
[@bs.module "react-native"] [@bs.scope "Dimensions"]
external removeEventListener: (eventType, handler => unit) => unit =
  "removeEventListener";

[@bs.module "react-native"]
external useWindowDimensions: unit => displayMetrics = "useWindowDimensions";
