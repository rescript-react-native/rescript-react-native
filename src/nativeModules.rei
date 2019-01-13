/**

You can read more on [NativeModules] API usage in official docs:
- IOS: {{:https://facebook.github.io/react-native/docs/native-modules-ios}}
- Android: {{:https://facebook.github.io/react-native/docs/native-components-android}}

*/

type t('a) = Js.t('a);

let get: string => t('a);

let requireNativeComponent: string => ReasonReact.reactClass;
