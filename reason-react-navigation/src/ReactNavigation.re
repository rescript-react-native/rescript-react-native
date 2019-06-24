open ReactNative;

module Make = (S: {type screenProps;}) => {
  type screenProps = S.screenProps;

  type navigationState = {
    .
    "index": int,
    "routes": option(array(navigationState)),
    "isDrawerOpen": bool,
  };

  module NavigationActions = {
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
  };

  module NavigationContainer = {
    type t;

    [@bs.send] external dispatch: (t, NavigationActions.action) => unit = "";
  };

  module Navigation = {
    type t;

    [@bs.get] external state: t => navigationState = "";

    [@bs.send] external navigate: (t, string) => unit = "";
    [@bs.send]
    external navigateWithParams: (t, string, Js.t({..})) => unit = "navigate";
    [@bs.send] external goBack: t => unit = "";
    [@bs.send] external goBackToRoute: (t, string) => unit = "";
    [@bs.send] external getParam: (t, string, 'a) => 'a = "";
    // TODO: addListener, setParams, ...
    // Stack Actions
    // TODO: push, replace, ...
    [@bs.send] external pop: t => unit = "";
    [@bs.send] external popN: (t, int) => unit = "";
    [@bs.send] external popToTop: t => unit = "";
    // Drawer navigator only
    [@bs.send] external openDrawer: t => unit = "";
    [@bs.send] external closeDrawer: t => unit = "";
    [@bs.send] external toggleDrawer: t => unit = "";
  };

  type navigatorProps;
  type navigator = React.component(navigatorProps);

  module StackNavigator = {
    type config;

    [@bs.obj]
    external config:
      (
        ~mode: [@bs.string] [ | `card | `modal]=?,
        ~headerMode: [@bs.string] [ | `float | `screen | `none]=?,
        ~headerBackTitleVisible: bool=?,
        ~headerTransitionPreset: [@bs.string] [
                                   | [@bs.as "fade-in-place"] `fadeInPlace
                                   | `uikit
                                 ]
                                   =?,
        ~headerLayoutPreset: [@bs.string] [ | `left | `center]=?,
        ~cardStyle: Style.t=?,
        ~cardShadowEnabled: bool=?,
        ~cardOverlayEnabled: bool=?,
        // TODO: many more props
        unit
      ) =>
      config =
      "";

    [@bs.module "react-navigation"]
    external make: Js.t('a) => navigator = "createStackNavigator";

    [@bs.module "react-navigation"]
    external makeWithConfig: (Js.t('a), config) => navigator =
      "createStackNavigator";
  };

  module DrawerNavigator = {
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
        ~itemsContainerStyle: Style.t=?,
        ~itemStyle: Style.t=?,
        ~labelStyle: Style.t=?,
        ~activeLabelStyle: Style.t=?,
        ~inactiveLabelStyle: Style.t=?,
        ~iconContainerStyle: Style.t=?,
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
    external make: Js.t('a) => navigator = "createDrawerNavigator";

    [@bs.module "react-navigation"]
    external makeWithConfig: (Js.t('a), config) => navigator =
      "createDrawerNavigator";
  };

  module TabNavigator = {
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
        ~tabStyle: Style.t=?,
        ~indicatorStyle: Style.t=?,
        ~labelStyle: Style.t=?,
        ~iconStyle: Style.t=?,
        ~style: Style.t=?,
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
        // TODO: more props
        unit
      ) =>
      config =
      "";

    [@bs.module "react-navigation"]
    external makeMaterialTopNavigator: Js.t('a) => navigator =
      "createMaterialTopTabNavigator";

    [@bs.module "react-navigation"]
    external makeMaterialTopNavigatorWithConfig:
      (Js.t('a), config) => navigator =
      "createMaterialTopTabNavigator";
  };

  module NavigationOptions = {
    [@bs.deriving {abstract: light}]
    type t = {
      [@bs.optional]
      title: string,
      /* header: option [ | `custom (headerProps => React.element) | `notVisible], */
      [@bs.optional]
      headerTitle: React.element,
      [@bs.optional]
      headerTitleStyle: Style.t,
      [@bs.optional]
      headerTintColor: string,
      [@bs.optional]
      headerBackTitle: Js.Nullable.t(string),
      [@bs.optional]
      headerTruncatedBackTitle: string,
      [@bs.optional]
      headerLeft: React.element,
      [@bs.optional]
      headerBackTitleStyle: Style.t,
      [@bs.optional]
      headerPressColorAndroid: string,
      [@bs.optional]
      headerRight: React.element,
      [@bs.optional]
      headerStyle: Style.t,
      [@bs.optional]
      gesturesEnabled: bool,
      /* Drawer Navigator */
      [@bs.optional]
      drawerIcon: React.element,
      [@bs.optional]
      drawerLabel: string,
      /* {
           .
           "focused": bool,
           "tintColor": string,
         } =>
         React.element, */
      [@bs.optional]
      drawerLockMode: string /* unlocked | locked-closed | locked-open */
    };
  };

  type navigationParams = {
    .
    "navigation": Navigation.t,
    "navigationOptions": NavigationOptions.t,
    "screenProps": screenProps,
  };

  type persistNavigationState = navigationState => Js.Promise.t(unit);
  type loadNavigationState = unit => Js.Promise.t(option(navigationState));

  type appContainerProps = {
    .
    "persistNavigationState": option(persistNavigationState),
    "loadNavigationState": option(loadNavigationState),
    "screenProps": option(screenProps),
    "setNavigatorRef": Js.Nullable.t(NavigationContainer.t) => unit,
  };

  module type AppContainer = {
    [@react.component]
    let make:
      (
        ~persistNavigationState: persistNavigationState=?,
        ~loadNavigationState: loadNavigationState=?,
        ~screenProps: screenProps=?,
        ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit
      ) =>
      React.element;
  };

  [@bs.module "react-navigation"]
  external _createAppContainer:
    navigator => React.component(appContainerProps) =
    "createAppContainer";

  let makeAppContainer = (navigator: navigator): (module AppContainer) => {
    let make = _createAppContainer(navigator);

    (module
     {
       [@bs.obj]
       external makeProps:
         (
           ~persistNavigationState: persistNavigationState=?,
           ~loadNavigationState: loadNavigationState=?,
           ~screenProps: screenProps=?,
           ~setNavigatorRef: Js.Nullable.t(NavigationContainer.t) => unit,
           ~key: string=?,
           unit
         ) =>
         appContainerProps =
         "";

       let make = make;
     });
  };

  [@bs.set]
  external setNavigationOptions:
    (React.component('props), NavigationOptions.t) => unit =
    "navigationOptions";
  [@bs.set]
  external setDynamicNavigationOptions:
    (React.component('props), navigationParams => NavigationOptions.t) => unit =
    "navigationOptions";
};