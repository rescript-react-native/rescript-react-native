type os =
  | IOS
  | Android;

let os: unit => os;

external version : int = "Version" [@@bs.scope "Platform"] [@@bs.module "react-native"];

let select: ios::'a => android::'a => 'a;