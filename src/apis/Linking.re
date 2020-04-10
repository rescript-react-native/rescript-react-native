type extra;
[@bs.obj] external extra: (~key: string, ~value: 'a) => extra;

[@bs.scope "Linking"] [@bs.module "react-native"]
external openURL: string => Js.Promise.t(unit) = "openURL";

[@bs.scope "Linking"] [@bs.module "react-native"]
external canOpenURL: string => Js.Promise.t(bool) = "canOpenURL";

[@bs.scope "Linking"] [@bs.module "react-native"]
external getInitialURL: unit => Js.Promise.t(Js.Null.t(string)) =
  "getInitialURL";

[@bs.scope "Linking"] [@bs.module "react-native"]
external openSettings: unit => Js.Promise.t('a) = "openSettings";

// multiple externals
[@bs.scope "Linking"] [@bs.module "react-native"]
external sendIntent: string => unit = "sendIntent";

// multiple externals
[@bs.scope "Linking"] [@bs.module "react-native"]
external sendIntentWithExtras: (string, array(extra)) => unit = "sendIntent";

type url = {url: string};

[@bs.scope "Linking"] [@bs.module "react-native"]
external addEventListener: ([@bs.string] [ | `url], url => unit) => unit =
  "addEventListener";

[@bs.scope "Linking"] [@bs.module "react-native"]
external removeEventListener: ([@bs.string] [ | `url], url => unit) => unit =
  "removeEventListener";
