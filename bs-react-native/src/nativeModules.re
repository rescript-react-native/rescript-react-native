type t('a) = Js.t('a);

[@bs.module "react-native"]
external nativeModules: Js.Dict.t('a) = "NativeModules";

let _get = (name): t('a) => Js.Dict.unsafeGet(nativeModules, name);

let get = name => _get(name);

[@bs.module "react-native"]
external requireNativeComponent:
  (string, Js.null(unit)) => ReasonReact.reactClass =
  "requireNativeComponent";

let requireNativeComponent = name =>
  requireNativeComponent(name, Js.Null.empty);
