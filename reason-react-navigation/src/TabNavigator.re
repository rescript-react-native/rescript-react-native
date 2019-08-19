type tabBarOptions;

[@bs.obj]
external tabBarOptions:
  (
    ~activeTintColor: string=?,
    ~inactiveTintColor: string=?,
    ~showIcon: bool=?,
    ~showLabel: bool=?,
    ~upperCaseLabel: bool=?,
    ~pressColor: string=?,
    ~pressOpacity: float=?,
    ~scrollEnabled: bool=?,
    ~tabStyle: ReactNative.Style.t=?,
    ~indicatorStyle: ReactNative.Style.t=?,
    ~labelStyle: ReactNative.Style.t=?,
    ~iconStyle: ReactNative.Style.t=?,
    ~style: ReactNative.Style.t=?,
    ~allowFontScaling: bool=?,
    // TODO: more props
    unit
  ) =>
  tabBarOptions =
  "";

type config;

[@bs.obj]
external config:
  (
    ~backBehavior: [@bs.string] [ | `initialRoute | `order | `history]=?,
    ~swipeEnabled: bool=?,
    ~animationEnabled: bool=?,
    ~_lazy: bool=?,
    ~tabBarOptions: tabBarOptions=?,
    ~initialRouteName: string=?,
    // TODO: more props
    unit
  ) =>
  config =
  "";

module MaterialTop = {
  [@bs.module "react-navigation"]
  external make: Js.t('a) => Types.navigator =
    "createMaterialTopTabNavigator";

  [@bs.module "react-navigation"]
  external makeWithConfig: (Js.t('a), config) => Types.navigator =
    "createMaterialTopTabNavigator";
};

module Bottom = {
  [@bs.module "react-navigation"]
  external make: Js.t('a) => Types.navigator = "createBottomTabNavigator";

  [@bs.module "react-navigation"]
  external makeWithConfig: (Js.t('a), config) => Types.navigator =
    "createBottomTabNavigator";
};
