type config;

[@bs.obj]
external config:
  (
    ~initialRouteName: string=?,
    ~initialRouteParams: 'params=?,
    // ~paths: navigationPathsConfig('paths)=?,
    // ~defaultNavigationOptions: NavigationScreenConfig.t(NavigationOptions.t)=?,
    ~order: array(string)=?,
    ~backBehavior: [@bs.string] [ | `none | `initialRoute | `history | `order]
                     =?, //defaults to `none
    ~resetOnBlur: bool=?,
    unit
  ) =>
  config =
  "";

[@bs.module "react-navigation"]
external make: Js.t('a) => Types.navigator = "createSwitchNavigator";

[@bs.module "react-navigation"]
external makeWithConfig: (Js.t('a), config) => Types.navigator =
  "createSwitchNavigator";
