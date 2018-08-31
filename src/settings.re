[@bs.module "react-native"] [@bs.scope "Settings"]
external get : string => string = "";

[@bs.module "react-native"] [@bs.scope "Settings"]
external set : Js.Dict.t(string) => unit = "";

[@bs.module "react-native"] [@bs.scope "Settings"]
external watchKeys : (list(string), unit => unit) => int = "";

[@bs.module "react-native"] [@bs.scope "Settings"]
external clearWatch : int => unit = "";