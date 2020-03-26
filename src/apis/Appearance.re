type t = string;

[@bs.inline]
let dark = "dark";

[@bs.inline]
let light = "light";

[@bs.scope "Appearance"] [@bs.module "react-native"]
external getColorScheme: unit => option(t) = "getColorScheme";

[@bs.module "react-native"]
external useColorScheme: unit => option(t) = "useColorScheme";
