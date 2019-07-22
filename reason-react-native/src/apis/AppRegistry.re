[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponent: (string, unit => React.component('a)) => unit =
  "";

type task('data) = 'data => Js.Promise.t(unit);

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerHeadlessTask: (string, unit => task('data)) => unit = "";

// react-native-web
type app = {
  .
  "element": React.element,
  [@bs.meth] "getStyleElement": unit => React.element,
};
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getApplication: (string, {. "initialProps": 'a}) => app = "";
