[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponent: (string, unit => React.component('a)) => unit =
  "registerComponent";

// react-native-web
type app = {
  .
  "element": React.element,
  [@bs.meth] "getStyleElement": unit => React.element,
};
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getApplication: (string, {. "initialProps": 'a}) => app =
  "getApplication";
