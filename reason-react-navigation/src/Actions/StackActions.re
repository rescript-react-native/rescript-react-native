type action = NavigationAction.t;

[@bs.deriving {abstract: light}]
type popParams = {
  [@bs.optional]
  n: int,
  [@bs.optional]
  immediate: bool,
};

[@bs.module "react-navigation"] [@bs.scope "StackActions"]
external pop: popParams => action = "";

[@bs.deriving {abstract: light}]
type popToTopParams = {
  [@bs.optional]
  immediate: bool,
};

[@bs.module "react-navigation"] [@bs.scope "StackActions"]
external popToTop: popToTopParams => action = "";

[@bs.deriving {abstract: light}]
type pushParams('params) = {
  routeName: string,
  [@bs.optional]
  params: 'params,
  [@bs.optional]
  action,
  [@bs.optional]
  key: string,
};

[@bs.module "react-navigation"] [@bs.scope "StackActions"]
external push: pushParams('params) => action = "";

[@bs.deriving {abstract: light}]
type resetParams = {
  index: int,
  [@bs.optional]
  key: string,
  action: array(action),
};

[@bs.module "react-navigation"] [@bs.scope "StackActions"]
external resetParams: resetParams => action = "";

[@bs.deriving {abstract: light}]
type replaceParams('params) = {
  key: string,
  routeName: string,
  [@bs.optional]
  params: 'params,
  [@bs.optional]
  action,
};

[@bs.module "react-navigation"] [@bs.scope "StackActions"]
external replaceParams: replaceParams('params) => action = "";

[@bs.deriving {abstract: light}]
type completeTransitionParams = {
  [@bs.optional]
  key: string,
};

[@bs.module "react-navigation"] [@bs.scope "StackActions"]
external completeTransition: completeTransitionParams => action = "";
