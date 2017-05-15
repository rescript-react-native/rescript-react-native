type t;

external nativeModules : Js.Dict.t 'a = "NativeModules" [@@bs.module "react-native"];

let _get name: t => Js.Dict.unsafeGet nativeModules name;

let get name => _get name;

