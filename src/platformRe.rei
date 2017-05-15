type os =
  | IOS
  | Android;

let os: os;

let equals: os => bool;

external version : int = "Version" [@@bs.scope "Platform"] [@@bs.module "react-native"];

let select: ios::'a => android::'a => 'a;