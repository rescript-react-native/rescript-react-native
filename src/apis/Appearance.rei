type t;

[@bs.inline "dark"]
let dark: t;

[@bs.inline "light"]
let light: t;

[@bs.scope "Appearance"] [@bs.module "react-native"]
external getColorScheme: unit => Js.Null.t(t) = "getColorScheme";

[@bs.module "react-native"]
external useColorScheme: unit => Js.Null.t(t) = "useColorScheme";
