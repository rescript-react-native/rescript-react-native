type os =
  | IOS
  | Android;

external _os : string = "OS" [@@bs.scope "Platform"] [@@bs.module "react-native"];

let os =
  switch _os {
  | "ios" => IOS
  | _ => Android
  };

let equals targetOs =>
  switch (os, targetOs) {
  | (IOS, IOS) => true
  | (Android, Android) => true
  | (IOS, Android) => false
  | (Android, IOS) => false
  };

external version : int = "Version" [@@bs.scope "Platform"] [@@bs.module "react-native"];

external _select : Js.t {. ios : 'a, android : 'a} => 'a =
  "select" [@@bs.scope "Platform"] [@@bs.module "react-native"];

let select ::ios ::android => _select {"ios": ios, "android": android};