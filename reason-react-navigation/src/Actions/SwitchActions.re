type action = NavigationAction.t;

[@bs.deriving {abstract: light}]
type jumpToParams('params) = {
  [@bs.optional] //inconsistency in TS/Flow typing
  preserveFocus: bool,
  routeName: string,
  key: string,
  [@bs.optional]
  params: 'params,
};

[@bs.module "react-navigation"] [@bs.scope "SwitchActions"]
external jumpTo: jumpToParams('params) => action = "";
