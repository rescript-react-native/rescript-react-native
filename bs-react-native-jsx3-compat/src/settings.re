[@bs.module "react-native"] [@bs.scope "Settings"]
external get: string => string = "";

[@bs.module "react-native"] [@bs.scope "Settings"]
external set: Js.Dict.t(string) => unit = "";

type watchToken;

[@bs.module "react-native"] [@bs.scope "Settings"]
external watchKeys: (list(string), unit => unit) => watchToken = "";

[@bs.module "react-native"] [@bs.scope "Settings"]
external clearWatch: watchToken => unit = "";
