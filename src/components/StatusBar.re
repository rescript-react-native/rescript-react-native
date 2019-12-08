[@react.component] [@bs.module "react-native"]
external make:
  (
    ~animated: bool=?,
    ~barStyle: [@bs.string] [
                 | `default
                 | [@bs.as "light-content"] `lightContent
                 | [@bs.as "dark-content"] `darkContent
               ]
                 =?,
    ~hidden: bool=?,
    ~backgroundColor: string=?,
    ~translucent: bool=?,
    ~networkActivityIndicatorVisible: bool=?,
    ~showHideTransition: [@bs.string] [ | `fade | `none | `slide]=?
  ) =>
  React.element =
  "StatusBar";

[@bs.module "react-native"] [@bs.scope "StatusBar"]
external setHidden: (bool, [@bs.string] [ | `none | `fade | `slide]) => unit =
  "setHidden";

[@bs.module "react-native"] [@bs.scope "StatusBar"]
external setBarStyle:
  (
    [@bs.string] [
      | `default
      | [@bs.as "light-content"] `lightContent
      | [@bs.as "dark-content"] `darkContent
    ],
    bool
  ) =>
  unit =
  "setBarStyle";

[@bs.module "react-native"] [@bs.scope "StatusBar"]
external setNetworkActivityIndicatorVisible: bool => unit =
  "setNetworkActivityIndicatorVisible";

[@bs.module "react-native"] [@bs.scope "StatusBar"]
external setBackgroundColor: (Color.t, bool) => unit = "setBackgroundColor";

[@bs.module "react-native"] [@bs.scope "StatusBar"]
external setTranslucent: bool => unit = "setTranslucent";

[@bs.module "react-native"] [@bs.scope "StatusBar"]
external currentHeight: float = "currentHeight";
