type reason = string;

[@bs.scope "DevSettings"] [@bs.module "react-native"]
external addMenuItem: (string, unit => 'a) => unit = "addMenuItem";

[@bs.scope "DevSettings"] [@bs.module "react-native"]
external reload: unit => unit = "reload";

[@bs.scope "DevSettings"] [@bs.module "react-native"]
external reloadWithReason: reason => unit = "reload";
