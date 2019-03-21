type t('a) = Js.t('a);

[@bs.module "react-native"]
external nativeModules: Js.Dict.t('a) = "NativeModules";

let get = (name): t('a) => Js.Dict.unsafeGet(nativeModules, name);

[@bs.module "react-native"]
external requireNativeComponent:
  (string, [@bs.as {json|null|json}] _) => React.component('a) =
  "requireNativeComponent";
