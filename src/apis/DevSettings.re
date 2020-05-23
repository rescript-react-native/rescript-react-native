type handler = unit => unit;
type reason = string;
type title = string;

[@bs.scope "DevSettings"] [@bs.module "react-native"]
external addMenuItem: (title, handler) => unit = "addMenuItem";

[@bs.scope "DevSettings"] [@bs.module "react-native"]
external reload: unit => unit = "reload";

[@bs.scope "DevSettings"] [@bs.module "react-native"]
external reloadWithReason: reason => unit = "reload";
