type action = NavigationAction.t;

[@bs.deriving {abstract: light}]
type navigateParams('params) = {
  routeName: string,
  [@bs.optional]
  params: 'params,
  [@bs.optional]
  action,
  [@bs.optional]
  key: string,
};

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external navigate: navigateParams('params) => action = "";

[@bs.deriving {abstract: light}]
type backParams = {
  [@bs.optional]
  key: string,
  [@bs.optional]
  immediate: bool,
};

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external back: backParams => action = "";

[@bs.deriving {abstract: light}]
type initParams('params) = {
  [@bs.optional]
  params: 'params,
};

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external init: initParams('params) => action = "";

[@bs.deriving {abstract: light}]
type setParamsParams('params) = {
  key: string,
  params: 'params,
};

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external setParams: setParamsParams('params) => action = "";
