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
