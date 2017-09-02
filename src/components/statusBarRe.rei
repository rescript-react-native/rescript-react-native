let setHidden: bool => animation::[ | `fade | `none | `slide]? => unit => unit;

let setBarStyle: [ | `darkContent | `default | `lightContent] => animated::bool? => unit => unit;

let setNetworkActivityIndicatorVisible: bool => unit;

let setBackgroundColor: string => animated::bool? => unit => unit;

let setTranslucent: bool => unit;

let make:
  animated::bool? =>
  barStyle::[ | `darkContent | `default | `lightContent]? =>
  hidden::bool? =>
  backgroundColor::string? =>
  translucent::bool? =>
  networkActivityIndicatorVisible::bool? =>
  showHideTransition::[ | `fade | `none | `slide]? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps unit;
