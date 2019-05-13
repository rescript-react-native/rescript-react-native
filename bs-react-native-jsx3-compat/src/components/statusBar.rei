/**
  Component to control the app status bar.
  You can read more on [StatusBar] component usage in official docs: {{:https://facebook.github.io/react-native/docs/statusbar}}

  {3 Props}

  {4 animated}
  {[
    ~animated: bool=?,
  ]}
  {4 barStyle}
  {[
    barStyle: [
      | `darkContent
      | `default
      | `lightContent
    ]=?
  ]}
  {4 hidden}
  {[
    ~hidden: bool=?
  ]}
  {4 backgroundColor}
  {[
    ~backgroundColor: ReactNative.Color.t=?
  ]}
  {4 translucent}
  {[
    ~translucent: bool=?
  ]}
  {4 networkActivityIndicatorVisible}
  {[
    ~networkActivityIndicatorVisible: bool=?
  ]}
  {4 showHideTransition}
  {[
    showHideTransition: [
      | `fade
      | `none
      | `slide
    ]=?
  ]}

  {3 Methods}
  {4 setHidden}
  Show or hide the status bar

 */

[@react.component]
let make:
  (
    ~animated: bool=?,
    ~barStyle: [ | `darkContent | `default | `lightContent]=?,
    ~hidden: bool=?,
    ~backgroundColor: ReactNative.Color.t=?,
    ~translucent: bool=?,
    ~networkActivityIndicatorVisible: bool=?,
    ~showHideTransition: [ | `fade | `none | `slide]=?
  ) =>
  React.element;

let setHidden: (bool, ~animation: [ | `fade | `none | `slide]=?, unit) => unit;

let setBarStyle:
  ([ | `darkContent | `default | `lightContent], ~animated: bool=?, unit) =>
  unit;

let setNetworkActivityIndicatorVisible: bool => unit;

let setBackgroundColor: (string, ~animated: bool=?, unit) => unit;

let setTranslucent: bool => unit;
