type t 'a = Js.t 'a;

external nativeModules : Js.Dict.t 'a = "NativeModules" [@@bs.module "react-native"];

let _get name: t 'a => Js.Dict.unsafeGet nativeModules name;

let get name => _get name;

