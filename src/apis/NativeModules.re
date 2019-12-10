// We recommend that you bind your own custom native modules like this:
//
// [@bs.module "react-native"] [@bs.scope ("NativeModules", "MyCustomModule")]
// external myFunc: unit => unit = "myFunc"

[@bs.module "react-native"]
external nativeModules: Js.Dict.t('a) = "NativeModules";

[@bs.module "react-native"]
external requireNativeComponent:
  (string, [@bs.as {json|null|json}] _) => React.component('a) =
  "requireNativeComponent";
