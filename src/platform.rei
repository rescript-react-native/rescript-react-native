type os =
  | IOS
  | Android;

let os: os;

let equals: os => bool;

[@bs.scope "Platform"] [@bs.module "react-native"] external version : int = "Version";

let select: (~ios: 'a, ~android: 'a) => 'a;
