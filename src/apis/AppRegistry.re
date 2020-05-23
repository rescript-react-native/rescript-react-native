type appKey = string;
type section = string;
type taskId = float;
type taskKey = string;

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
  appConfig;

type runnable('a) = {
  .
  "component": Js.Nullable.t(componentProvider('a)),
  [@bs.meth] "run": appParameters => unit,
};

type registry('a) = {
  sections: array(section),
  runnables: Js.Dict.t(runnable('a)),
};

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getAppKeys: unit => array(appKey) = "getAppKeys";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getRegistry: unit => registry('a) = "getRegistry";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getRunnable: appKey => option(runnable('a)) = "getRunnable";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getSectionKeys: unit => array(string) = "getSectionKeys";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getSections: unit => Js.Dict.t(runnable('a)) = "getSections";

// multiple externals
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponent: (appKey, componentProvider('a)) => unit =
  "registerComponent";

// multiple externals
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponentWithSection:
  (appKey, componentProvider('a), section) => unit =
  "registerComponent";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerConfig: array(appConfig) => unit = "registerConfig";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerRunnable: (appKey, appParameters => unit) => string =
  "registerRunnable";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerSection: (appKey, componentProvider('a)) => unit =
  "registerSection";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external runApplication: (appKey, 'a) => unit = "runApplication";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external setWrapperComponentProvider: wrapperComponentProvider('a, 'b) => unit =
  "setWrapperComponentProvider";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external unmountApplicationComponentAtRootTag: string => unit =
  "unmountApplicationComponentAtRootTag";

// Android only
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external cancelHeadlessTask: (taskId, taskKey) => unit = "cancelHeadlessTask";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerCancellableHeadlessTask:
  (taskKey, taskProvider('data), taskCancelProvider) => unit =
  "registerCancellableHeadlessTask";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerHeadlessTask: (taskKey, taskProvider('data)) => unit =
  "registerHeadlessTask";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external startHeadlessTask: (taskId, taskKey, 'data) => unit =
  "startHeadlessTask";

// react-native-web
type app = {
  .
  "element": React.element,
  [@bs.meth] "getStyleElement": unit => React.element,
};
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getApplication: (string, {. "initialProps": 'a}) => app =
  "getApplication";
