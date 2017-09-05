type t 'a = Js.t 'a;

external nativeModules : Js.Dict.t 'a = "NativeModules" [@@bs.module "react-native"];

let _get name :t 'a => Js.Dict.unsafeGet nativeModules name;

let get name => _get name;

external requireNativeComponent : string => Js.null unit => ReasonReact.reactClass =
  "requireNativeComponent" [@@bs.module "react-native"];

let requireNativeComponent name => requireNativeComponent name Js.Null.empty;
