type os = string;

[@bs.module "react-native"] [@bs.scope "Platform"] external os: os = "OS";

[@bs.inline]
let ios = "ios";

[@bs.inline]
let android = "android";
