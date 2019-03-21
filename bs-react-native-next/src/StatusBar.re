[@react.component] [@bs.module "react-native"]
external make:
  (
    ~animated: bool=?,
    ~barStyle: [@bs.string] [ | `darkContent | `default | `lightContent]=?,
    ~hidden: bool=?,
    ~backgroundColor: string=?,
    ~translucent: bool=?,
    ~networkActivityIndicatorVisible: bool=?,
    ~showHideTransition: [@bs.string] [ | `fade | `none | `slide]=?
  ) =>
  React.element =
  "StatusBar";
