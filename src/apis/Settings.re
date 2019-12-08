[@bs.module "react-native"] [@bs.scope "Settings"]
external get: string => string = "get";

[@bs.module "react-native"] [@bs.scope "Settings"]
external set: Js.Dict.t(string) => unit = "set";

type watchToken;

[@bs.module "react-native"] [@bs.scope "Settings"]
external watchKeys: (list(string), unit => unit) => watchToken = "watchKeys";

[@bs.module "react-native"] [@bs.scope "Settings"]
external clearWatch: watchToken => unit = "clearWatch";
