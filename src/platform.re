type os =
  | IOS
  | Android;

[@bs.scope "Platform"] [@bs.module "react-native"] external _os : string = "OS";

let os =
  switch _os {
  | "ios" => IOS
  | _ => Android
  };

let equals = (targetOs) =>
  switch (os, targetOs) {
  | (IOS, IOS) => true
  | (Android, Android) => true
  | (IOS, Android) => false
  | (Android, IOS) => false
  };

[@bs.scope "Platform"] [@bs.module "react-native"] external version : int = "Version";

[@bs.scope "Platform"] [@bs.module "react-native"]
external _select : {. "ios": 'a, "android": 'a} => 'a =
  "select";

let select = (~ios, ~android) => _select({"ios": ios, "android": android});
