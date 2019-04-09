type os = pri string;

[@bs.module "react-native"] [@bs.scope "Platform"] external os: os = "OS";

[@bs.inline "ios"]
let ios: os;

[@bs.inline "android"]
let android: os;