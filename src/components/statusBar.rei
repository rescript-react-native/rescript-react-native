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
    ~backgroundColor: string=?
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

let make:
  (
    ~animated: bool=?,
    ~barStyle: [ | `darkContent | `default | `lightContent]=?,
    ~hidden: bool=?,
    ~backgroundColor: string=?,
    ~translucent: bool=?,
    ~networkActivityIndicatorVisible: bool=?,
    ~showHideTransition: [ | `fade | `none | `slide]=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );

/**
  {4 setBarStyle}
  Set the status bar style
   */

let setHidden: (bool, ~animation: [ | `fade | `none | `slide]=?, unit) => unit;

/**
  {4 setNetworkActivityIndicatorVisible}
  Control the visibility of the network activity indicator
   */

let setBarStyle:
  ([ | `darkContent | `default | `lightContent], ~animated: bool=?, unit) =>
  unit;

/**
  {4 setBackgroundColor}
  Set the background color for the status bar
   */

let setNetworkActivityIndicatorVisible: bool => unit;

/**
  {4 setTranslucent}
  Control the translucency of the status bar
   */

let setBackgroundColor: (string, ~animated: bool=?, unit) => unit;

let setTranslucent: bool => unit;
