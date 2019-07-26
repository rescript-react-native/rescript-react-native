module Make = (S: {type screenProps;}) => {
  type screenProps = S.screenProps;

  type contentComponentProps = {
    .
    "navigation": Navigation.t,
    "screenProps": screenProps,
  };

  type contentComponent = React.component(contentComponentProps);

  [@bs.module "react-navigation"]
  external drawerItems: contentComponent = "DrawerItems";

  type contentOptions;

  [@bs.obj]
  external contentOptions:
    (
      ~activeTintColor: string=?,
      ~activeBackgroundColor: string=?,
      ~inactiveTintColor: string=?,
      ~inactiveBackgroundColor: string=?,
      ~itemsContainerStyle: ReactNative.Style.t=?,
      ~itemStyle: ReactNative.Style.t=?,
      ~labelStyle: ReactNative.Style.t=?,
      ~activeLabelStyle: ReactNative.Style.t=?,
      ~inactiveLabelStyle: ReactNative.Style.t=?,
      ~iconContainerStyle: ReactNative.Style.t=?,
      // TODO: more props
      unit
    ) =>
    contentOptions =
    "";

  type config;

  [@bs.obj]
  external config:
    (
      ~mode: [@bs.string] [ | `card | `modal]=?,
      ~drawerWidth: float=?,
      ~drawerPosition: [@bs.string] [ | `left | `right]=?,
      ~contentComponent: contentComponent=?,
      ~contentOptions: contentOptions=?,
      ~useNativeAnimations: bool=?,
      ~drawerBackgroundColor: string=?,
      ~initialRouteName: string=?,
      ~backBehavior: [@bs.string] [ | `initialRoute | `none]=?,
      ~hideStatusBar: bool=?,
      // TODO: more props
      unit
    ) =>
    config =
    "";

  [@bs.module "react-navigation"]
  external make: Js.t('a) => Types.navigator = "createDrawerNavigator";

  [@bs.module "react-navigation"]
  external makeWithConfig: (Js.t('a), config) => Types.navigator =
    "createDrawerNavigator";
};
