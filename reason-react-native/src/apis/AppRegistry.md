---
id: apis/AppRegistry
title: AppRegistry
wip: true
---

```reason
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
  appConfig =
  "";

type runnable('a) = {
  .
  "component": Js.Nullable.t(componentProvider('a)),
  "run": appParameters => unit,
};

type registry('a) = {
  .
  "sections": array(section),
  "runnables": Js.Dict.t(runnable('a)),
};

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getAppKeys: unit => array(appKey) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getRegistry: unit => registry('a) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getRunnable: appKey => option(runnable('a)) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getSectionKeys: unit => array(string) = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getSections: unit => Js.Dict.t(runnable('a)) = "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponent: (appKey, componentProvider('a)) => unit = "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerComponentWithSection:
  (appKey, componentProvider('a), section) => unit =
  "registerComponent";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerConfig: array(appConfig) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerRunnable: (appKey, appParameters => unit) => string = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerSection: (appKey, componentProvider('a)) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external runApplication: (appKey, 'a) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external setWrapperComponentProvider:
  wrapperComponentProvider('a, 'b) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external unmountApplicationComponentAtRootTag: string => unit = "";

// Android only
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external cancelHeadlessTask: (taskId, taskKey) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerCancellableHeadlessTask:
  (taskKey, taskProvider('data), taskCancelProvider) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external registerHeadlessTask: (taskKey, taskProvider('data)) => unit = "";

[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external startHeadlessTask: (taskId, taskKey, 'data) => unit = "";

// react-native-web
type app = {
  .
  "element": React.element,
  [@bs.meth] "getStyleElement": unit => React.element,
};
[@bs.module "react-native"] [@bs.scope "AppRegistry"]
external getApplication: (string, {. "initialProps": 'a}) => app = "";

```
