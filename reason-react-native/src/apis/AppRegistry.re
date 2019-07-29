type task('data) = 'data => Js.Promise.t(unit);
type taskProvider('data) = unit => task('data);
type taskCanceller = unit => unit;
type taskCancelProvider = unit => taskCanceller;

type componentProvider('a) = unit => React.component('a);
type wrapperComponentProvider('a, 'b) = 'b => React.component('a);

type appParameters;

external asAppParameters: 'a => appParameters = "%identity";

type appConfig;

[@bs.obj]
external appConfig:
  (
    ~appKey: string,
    ~component: componentProvider('a)=?,
    ~run: appParameters => unit=?,
    ~section: bool=?,
    unit
  ) =>
  appConfig =
  "";

type runnable('a) = {
  .
  "component": Js.Nullable.t(componentProvider('a)),
  "run": appParameters => unit,
};

type registry('a) = {
  .
  "sections": array(string),
  "runnables": Js.Dict.t(runnable('a)),
};

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getAppKeys: unit => array(string) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getRegistry: unit => registry('a) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getRunnable: string => Js.Nullable.t(runnable('a)) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getSectionKeys: unit => array(string) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getSections: unit => Js.Dict.t(runnable('a)) = "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponent: (string, componentProvider('a)) => unit = "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponentWithSection:
  (string, componentProvider('a), string) => unit =
  "registerComponent";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerConfig: array(appConfig) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerRunnable: (string, appParameters => unit) => string = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerSection: (string, componentProvider('a)) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external runApplication: (string, 'a) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external setWrapperComponentProvider:
  Js.Nullable.t(wrapperComponentProvider('a, 'b)) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external unmountApplicationComponentAtRootTag: string => unit = "";

// Android only
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external cancelHeadlessTask: (float, string) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerCancellableHeadlessTask:
  (string, taskProvider('data), taskCancelProvider) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerHeadlessTask: (string, taskProvider('data)) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external startHeadlessTask: (float, string, 'a) => unit = "";

// react-native-web
type app = {
  .
  "element": React.element,
  [@bs.meth] "getStyleElement": unit => React.element,
};
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getApplication: (string, {. "initialProps": 'a}) => app = "";
