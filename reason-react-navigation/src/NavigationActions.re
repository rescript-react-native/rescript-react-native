type action;

type navigateParams;

[@bs.obj]
external navigateParams:
  (~routeName: string, ~params: Js.t({..})=?, unit) => navigateParams =
  "";

type backParams;

[@bs.obj]
external backParams:
  (~key: string=?, ~immediate: bool=?, unit) => navigateParams =
  "";

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external navigate: navigateParams => action = "";

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external back: backParams => action = "";
