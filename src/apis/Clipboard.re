[@bs.module "react-native"] [@bs.scope "Clipboard"]
external getString: unit => Js.Promise.t(string) = "getString";

[@bs.module "react-native"] [@bs.scope "Clipboard"]
external setString: string => unit = "setString";
