open ReactNative;
module Make = (S: {type screenProps;}) => {
  type screenProps = S.screenProps;
  /* TODO: Navigation State and LeafRoute
     module NavigationLeafRoute = {
       [@bs.deriving abstract]
       type t('params) = {
         key: string,
         index: int,
         routeName: string,
         [@bs.optional]
         path: string,
         [@bs.optional]
         params: 'params,
         routes: array(t('params)),
       };
     };
     */

  module NavigationState = {
    type t('params) = {
      .
      "key": string,
      "index": int,
      "routes": option(array(t('params))),
      "isDrawerOpen": option(bool),
      /*[@bs.optional]*/
      "params": 'params,
      "isTransitioning": bool,
      "routeName": string,
    };
  };

  type navigationRoute('params) = NavigationState.t('params);

  module type Params = {type params;};

  module type Route = {
    include Params;
    let routeName: string;
  };

  type navigation;

  module NavigationBase = (M: Params) => {
    type t = navigation;

    [@bs.get] external state: t => NavigationState.t(M.params) = "";
    [@bs.send] external navigate: (t, string) => unit = "";
    [@bs.send] external goBack: (t, ~from: string=?, unit) => unit = "";
    [@bs.send] external pop: (t, unit) => unit = "";
    [@bs.send] external openDrawer: (t, unit) => unit = "";
    [@bs.send] external closeDrawer: (t, unit) => unit = "";
    [@bs.send] external toggleDrawer: (t, unit) => unit = "";
    [@bs.send]
    external getParam: (navigation, string) => Js.nullable('a) = "";
    [@bs.send]
    external getParamWithDefault: (navigation, string, 'a) => 'a = "getParam";
  };

  module Navigation =
    NavigationBase({
      type params = unit;
    });

  type navigatorProps;
  type navigator = React.component(navigatorProps);

  type route = (string, navigator);

  type navigationPathsConfig('a) = Js.t('a);

  module NavigationScene = {
    type t = {
      .
      "index": int,
      "isActive": bool,
      "isStale": bool,
      "key": string,
      "route": navigationRoute(Js.t({.})),
      "screenProps": option(screenProps),
    };
  };

  module NavigationRouter = {
    type t('params);

    [@bs.send]
    external getStateForAction:
      (
        t('params),
        NavigationAction.t,
        ~lastState: NavigationState.t('params)=?,
        unit
      ) =>
      Js.nullable(NavigationState.t('params)) =
      "";

    [@bs.send]
    external getActionForPathAndParams:
      (t('params), string, ~params: 'params=?, unit) =>
      Js.nullable(NavigationAction.t) =
      "";

    /* TODO: */
    type pathAndParamsForState('params);

    [@bs.send]
    external getPathAndParamsForState:
      (t('params), NavigationState.t('params)) =>
      pathAndParamsForState('params) =
      "";

    /* TODO: */
    type navigationComponent('params);

    [@bs.send]
    external getComponentForRouteName:
      (t('params), string) => navigationComponent('params) =
      "";

    [@bs.send]
    external getComponentForState:
      (t('params), NavigationState.t('params)) =>
      navigationComponent('params) =
      "";
  };

  module NavigationScreenProp = {
    type t = navigation;

    [@bs.send] external dispatch: (t, NavigationAction.t) => bool = "";
    /* TODO: goBackFrom? */
    [@bs.send] external goBack: (t, ~from: string=?, unit) => bool = "";
    [@bs.send] external navigate: (t, string) => unit = "";
    [@bs.send]
    external navigateWithParams: (t, string, Js.t({..})) => unit = "navigate";

    [@bs.send] external openDrawer: (t, unit) => unit = "";
    [@bs.send] external closeDrawer: (t, unit) => unit = "";
    [@bs.send] external toggleDrawer: (t, unit) => unit = "";

    [@bs.send] external getParam: (t, string, 'a) => 'a = "";
    [@bs.send] external setParams: (t, Js.t({..})) => bool = "";

    /* Possible TS inconsistency? */
    type eventName = string;
    //TODO: [@bs.string] [ | `willBlur | `willFocus | `didFocus | `didBlur];
    type eventType = string;
    /* TODO:
         [@bs.string] [
           | `willBlur
           | `willFocus
           | `didFocus
           | `didBlur
           | `action
         ];
       */
    [@bs.deriving {abstract: light}]
    type navigationEventPayload('params) = {
      eventType,
      action: NavigationAction.t,
      state: NavigationState.t('params),
      lastState: Js.nullable(NavigationState.t('params)),
    };

    type navigationEventCallback('params) =
      navigationEventPayload('params) => unit;

    [@bs.deriving {abstract: light}]
    type navigationEventSubscription = {remove: unit => unit};

    [@bs.send]
    external addListener: (t, eventName) => navigationEventSubscription = "";

    [@bs.send]
    external push:
      (t, string, ~params: 'params=?, ~action: NavigationAction.t=?, unit) =>
      bool =
      "";

    [@bs.send]
    external replace:
      (t, string, ~params: 'params=?, ~action: NavigationAction.t=?, unit) =>
      bool =
      "";

    type popParams = {. "immediate": bool};

    [@bs.send]
    external reset:
      (t, ~actions: array(NavigationAction.t)=?, ~index: int=?, unit) => bool =
      "";

    [@bs.send]
    external pop: (t, ~n: int=?, ~params: popParams=?, unit) => bool = "";

    [@bs.send] external popToTop: (t, ~params: popParams=?, unit) => bool = "";

    [@bs.send] external isFocused: (t, unit) => bool = "";

    [@bs.send] external isFirstRouteInParent: (t, unit) => bool = "";

    [@bs.send] external router: (t, unit) => NavigationRouter.t('params) = "";

    [@bs.send]
    external dangerouslyGetParent:
      (t, unit) => Js.nullable(NavigationState.t('params)) =
      "";
  };

  module TabBarIconProps = {
    type t = {
      .
      "tintColor": Js.nullable(Color.t),
      "focused": bool,
      "horizontal": bool,
    };
  };

  module TabBarLabelProps = {
    type t = {
      .
      "tintColor": Js.nullable(Color.t),
      "focused": bool,
    };
  };

  module TabScene = {
    type t('params) = {
      .
      "route": navigationRoute('params),
      "focused": bool,
      "index": int,
      "tintColor": option(Color.t),
    };
  };

  module TabBarOnPress = {
    type options = {
      .
      "previousScene": bool,
      "scene": bool,
      "jumpToIndex": int => unit,
    };

    type t = options => unit;
  };

  module TabBarOnLongPress = {
    type options = {
      .
      "previousScene": bool,
      "scene": bool,
      "jumpToIndex": int => unit,
    };

    type t = options => unit;
  };

  type tabBarIcon;
  [@bs.val] [@bs.module "./Interop"]
  external tabBarIcon:
    (
    [@bs.unwrap]
    [
      | `Element(React.element)
      | `Render(TabBarIconProps.t => Js.nullable(React.element))
    ]
    ) =>
    tabBarIcon =
    "identity";

  type tabBarLabel;
  [@bs.val] [@bs.module "./Interop"]
  external tabBarLabel:
    (
    [@bs.unwrap]
    [
      | `String(string)
      | `Element(React.element)
      | `Render(TabBarLabelProps.t => Js.nullable(React.element))
    ]
    ) =>
    tabBarLabel =
    "identity";

  module DrawerIconProps = {
    type t = {
      .
      "tintColor": Js.nullable(Color.t),
      "focused": bool,
    };
  };

  module DrawerLabelProps = {
    type t = {
      .
      "tintColor": Js.nullable(Color.t),
      "focused": bool,
    };
  };

  type drawerItem('params) = {
    .
    "route": navigationRoute('params),
    "focused": bool,
  };

  type drawerScene('params) = {
    .
    "route": navigationRoute('params),
    "focused": bool,
    "index": int,
    "tintColor": option(Color.t),
  };

  module NavigationScreenDetails = {
    type t('params) = {
      .
      "options": 'params,
      "state": navigationRoute('params),
      "navigation": NavigationScreenProp.t,
    };
  };

  module NavigationLayout = {
    type t = {
      .
      "height": Animated.Value.t,
      "initHeight": float,
      "initWidth": float,
      "isMeasured": bool,
      "width": Animated.Value.t,
    };
  };

  module NavigationTransitionProps = {
    type t = {
      .
      "layout": NavigationLayout.t,
      "position": Animated.Value.t,
      "progress": Animated.Value.t,
      "scene": NavigationScene.t,
      "index": int,
      "screenProps": option(screenProps),
    };
  };

  module NavigationTransitionSpec = {
    type spec;

    [@bs.obj]
    external spec:
      (
        ~duration: float=?,
        ~duration: float => float=?,
        ~timing: (Animated.Value.t, 'any) => 'any=?,
        ~friction: float=?,
        ~tension: float=?,
        ~useNativeDriver: bool=?,
        unit
      ) =>
      spec =
      "";
  };

  /* There's a note about why these are equal in TS & Flow typings */
  module NavigationSceneRendererProps = NavigationTransitionProps;

  type interpolator('result) = NavigationSceneRendererProps.t => 'result;

  type mode = string; //TODO: [ | `float | `screen | `none]
  type headerProps('params) = {
    .
    "mode": mode,
    "router": NavigationRouter.t('params),
    "getScreenDetails":
      NavigationScene.t => NavigationScreenDetails.t('params),
    "leftInterpolator": interpolator({.}),
    "titleInterpolator": interpolator({.}),
    "rightInterpolator": interpolator({.}),
    "style": Style.t,
    /* extends NavigationSceneRendererProps */
    "layout": NavigationLayout.t,
    "position": Animated.Value.t,
    "progress": Animated.Value.t,
    "scene": NavigationScene.t,
    "index": int,
    "screenProps": option(screenProps),
  };

  type header;
  [@bs.val] [@bs.module "./Interop"]
  external header:
    (
    [@bs.unwrap]
    [
      | `Element(React.element)
      | `Render(headerProps('params) => React.element)
      | `Null(Js.null(unit))
    ]
    ) =>
    header =
    "identity";

  type backButtonProps = {
    .
    /* Unfortunate api design, where everything is optional? :/ */
    "onPress": option(unit => unit),
    "pressColorAndroid": option(Color.t),
    "title": option(Js.nullable(string)),
    "titleStyle": option(Style.t),
    "tintColor": option(Color.t),
    "truncatedTitle": option(string),
    "width": option(float),
    "disabled": option(bool),
  };

  type headerRenderItem;
  [@bs.val] [@bs.module "./Interop"]
  external headerRenderItem:
    (
    [@bs.unwrap]
    [
      | `Element(React.element)
      | `Render(backButtonProps => React.element)
      | `Null(Js.null(unit))
    ]
    ) =>
    headerRenderItem =
    "identity";

  module HeaderForceInset = {
    type t;
    [@bs.obj]
    external t:
      (
        ~horizontal: string=?,
        ~vertical: string=?,
        ~left: string=?,
        ~right: string=?,
        ~top: string=?,
        ~bottom: string=?,
        unit
      ) =>
      t =
      "";
  };

  type gestureResponseDistance;
  [@bs.obj]
  external gestureResponseDistance:
    (~vertical: float=?, ~horizontal: float=?, unit) => gestureResponseDistance =
    "";

  module HeaderTitle = {
    type t;

    type headerTitleProps = {
      .
      "allowFontScaling": bool,
      "style": Style.t,
      "children": string,
    };

    [@bs.val] [@bs.module "./Interop"]
    external t:
      (
      [@bs.unwrap]
      [
        | `String(string)
        | `Element(React.element)
        | `Render(headerTitleProps => React.element)
      ]
      ) =>
      t =
      "identity";
  };

  module NavigationOptions = {
    type t;

    [@bs.obj]
    external t:
      (
        ~swipeEnabled: bool=?,
        ~tabBarOnPress: TabBarOnPress.t=?,
        ~tabBarOnLongPress: TabBarOnLongPress.t=?,
        /* NavigationTabScreenOptionsBase */
        ~title: string=?,
        ~tabBarIcon: tabBarIcon=?,
        ~tabBarLabel: tabBarLabel=?,
        ~tabBarVisible: bool=?,
        ~tabBarTestIDProps: bool=?,
        /*DrawerScreenOptions*/
        ~title: bool=?,
        ~drawerIcon: DrawerIconProps.t=?,
        ~drawerLabel: DrawerLabelProps.t=?,
        ~drawerLockMode: [@bs.string] [
                           | `unlocked
                           | [@bs.as "locked-closed"] `lockedClosed
                           | [@bs.as "locked-open"] `lockedOpen
                         ]
                           =?,
        /* StackNavigator */
        ~title: string=?,
        ~header: header=?,
        ~headerTransparent: bool=?,
        ~headerTitle: HeaderTitle.t=?,
        ~headerTitleStyle: Style.t=?,
        ~headerTitleAllowFontScaling: bool=?,
        ~headerTintColor: Color.t=?,
        ~headerLeft: headerRenderItem=?,
        ~headerBackTitle: Js.nullable(string)=?,
        ~headerBackImage: React.element=?,
        ~headerTruncatedBackTitle: string=?,
        ~headerBackTitleStyle: Style.t=?,
        ~headerPressColorAndroid: Color.t=?,
        ~headerRight: headerRenderItem=?,
        ~headerStyle: Style.t=?,
        ~headerLeftContainerStyle: Style.t=?,
        ~headerRightContainerStyle: Style.t=?,
        ~headerForceInset: HeaderForceInset.t=?,
        /* TODO: double check this as it's typed as: React.ReactNode | React.ReactType */
        ~headerBackground: React.element=?,
        ~headerBackgroundTransitionPreset: [@bs.string] [
                                             | `toggle
                                             | `fade
                                             | `translate
                                           ]
                                             =?,
        ~gesturesEnabled: bool=?,
        ~gestureResponseDistance: gestureResponseDistance=?,
        ~gestureDirection: [@bs.string] [ | `default | `inverted]=?,
        unit
      ) =>
      t =
      "";
  };

  module rec NavigationScreenProps: {
    type t('params, 'options) = {
      .
      "navigation": NavigationScreenProp.t,
      "screenProps": option(screenProps),
      "navigationOptions": option(NavigationScreenConfig.t('options)),
    };
  } = NavigationScreenProps
  and NavigationScreenConfig: {
    type t('options);

    [@bs.val] [@bs.module "./Interop"]
    external t:
      (
      [@bs.unwrap]
      [
        | `Static('options)
        | `Dynamic(NavigationScreenProps.t(screenProps, 'options))
      ]
      ) =>
      t('options) =
      "identity";
  } = NavigationScreenConfig;

  module TransitionConfig = {
    type config;

    [@bs.obj]
    external config:
      (
        ~transitionSpec: NavigationTransitionSpec.spec=?,
        ~screenInterpolator: interpolator('any)=?,
        ~headerLeftInterpolator: interpolator('any)=?,
        ~headerTitleInterpolator: interpolator('any)=?,
        ~headerRightInterpolator: interpolator('any)=?,
        ~containerStyle: Style.t=?,
        unit
      ) =>
      config =
      "";
  };

  module StackNavigator = {
    type config;

    [@bs.obj]
    /* NavigationStackViewConfig */
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
        ~cardShadowEnabled: bool=?,
        ~cardOverlayEnabled: bool=?,
        ~cardStyle: Style.t=?,
        ~transparentCard: bool=?,
        ~transitionConfig: TransitionConfig.config=?,
        ~onTransitionStart: unit => unit=?,
        ~onTransitionEnd: unit => unit=?,
        ~disableKeyboardHandling: bool=?,
        /* NavigationStackRouterConfig */
        ~initialRouteName: string=?,
        ~initialRouteParams: 'routeParams=?,
        ~paths: Js.t({..})=?,
        ~defaultNavigationOptions: NavigationScreenConfig.t(
                                     NavigationOptions.t,
                                   )
                                     =?,
        ~navigationOptions: NavigationScreenConfig.t(NavigationOptions.t)=?,
        ~initialRouteKey: string=?,
        ~containerOptions: 'any=?,
        unit
      ) =>
      config =
      "";

    [@bs.module "react-navigation"]
    external make: Js.t('a) => navigator = "createStackNavigator";

    [@bs.module "react-navigation"]
    external makeWithConfig: (Js.t('a), config) => navigator =
      "createStackNavigator";

    module ScreenOptions = {
      type options;

      [@bs.obj]
      /* NavigationStackScreenOptions */
      external options:
        (
          ~title: string=?,
          ~header: header=?,
          ~headerTransparent: bool=?,
          ~headerTitle: HeaderTitle.t=?,
          ~headerTitleStyle: Style.t=?,
          ~headerTitleAllowFontScaling: bool=?,
          ~headerTitleContainerStyle: Style.t=?,
          ~headerTintColor: Color.t=?,
          ~headerLeft: headerRenderItem=?,
          ~headerBackTitle: Js.nullable(string)=?,
          ~headerBackImage: React.element=?,
          ~headerTruncatedBackTitle: string=?,
          ~headerBackTitleStyle: Style.t=?,
          ~headerPressColorAndroid: Color.t=?,
          ~headerRight: headerRenderItem=?,
          ~headerStyle: Style.t=?,
          ~headerForceInset: HeaderForceInset.t=?,
          /* TODO: double check this as it's typed as: React.ReactNode | React.ReactType */
          ~headerBackground: React.element=?,
          ~headerBackgroundTransitionPreset: [@bs.string] [
                                               | `toggle
                                               | `fade
                                               | `translate
                                             ]
                                               =?,
          ~gesturesEnabled: bool=?,
          ~gestureResponseDistance: gestureResponseDistance=?,
          ~gestureDirection: [@bs.string] [ | `default | `inverted]=?,
          unit
        ) =>
        options =
        "";
    };
  };

  module SwitchNavigator = {
    type config;

    [@bs.obj]
    /* NavigationStackRouterConfig */
    external config:
      (
        ~initialRouteName: string=?,
        ~initialRouteParams: 'params=?,
        ~paths: navigationPathsConfig('paths)=?,
        ~defaultNavigationOptions: NavigationScreenConfig.t(
                                     NavigationOptions.t,
                                   )
                                     =?,
        ~order: array(string)=?,
        ~backBehavior: [@bs.string] [
                         | `none
                         | `initialRoute
                         | `history
                         | `order
                       ]
                         =?, //defaults to `none
        ~resetOnBlur: bool=?,
        unit
      ) =>
      config =
      "";

    [@bs.module "react-navigation"]
    external make: Js.t('a) => navigator = "createSwitchNavigator";

    [@bs.module "react-navigation"]
    external makeWithConfig: (Js.t('a), config) => navigator =
      "createSwitchNavigator";

    [@bs.module "react-navigation"]
    external makeWithTypedConfig: (Js.t('a), config) => navigator =
      "createSwitchNavigator";
  };

  type initialLayout = {
    .
    "height": float,
    "width": float,
  };

  module TabBar = {
    type options;

    [@bs.obj]
    external options:
      (
        ~activeTintColor: Color.t=?,
        ~allowFontScaling: bool=?,
        ~activeBackgroundColor: Color.t=?,
        ~inactiveTintColor: Color.t=?,
        ~inactiveBackgroundColor: Color.t=?,
        ~showLabel: bool=?,
        ~style: Style.t=?,
        ~labelStyle: Style.t=?,
        ~iconStyle: Style.t=?,
        /* Top */
        ~showIcon: bool=?,
        ~upperCaseLabel: bool=?,
        ~pressColor: Color.t=?,
        ~pressOpacity: float=?,
        ~scrollEnabled: bool=?,
        ~tabStyle: Style.t=?,
        ~indicatorStyle: Style.t=?,
        unit
      ) =>
      options =
      "";
  };

  module DrawerNavigator = {
    module ContentComponent = {
      type drawerPosition = string; //TODO: [@bs.string] [ | `left | `right];
      type props('params) = {
        .
        "navigation": navigation,
        "items": array(navigationRoute('params)),
        "activeTintColor": option(Color.t),
        "activeBackgroundColor": option(Color.t),
        "inactiveTintColor": option(Color.t),
        "inactiveBackgroundColor": option(Color.t),
        "getLabel": drawerScene('params) => React.element,
        "renderIcon": drawerScene('params) => React.element,
        "onItemPress": drawerItem('params) => unit,
        "itemsContainerStyle": option(Style.t),
        "itemStyle": option(Style.t),
        "labelStyle": option(Style.t),
        "activeLabelStyle": option(Style.t),
        "inactiveLabelStyle": option(Style.t),
        "iconContainerStyle": option(Style.t),
        "drawerPosition": drawerPosition,
      };

      type t('params) = React.component(props('params));
    };

    [@bs.module "react-navigation"]
    external t: ContentComponent.t('params) = "DrawerItems";

    module ContentOptions = {
      type t;

      external t:
        (
          ~activeTintColor: Color.t=?,
          ~activeBackgroundColor: Color.t=?,
          ~inactiveTintColor: Color.t=?,
          ~inactiveBackgroundColor: Color.t=?,
          ~style: Style.t=?,
          ~labelStyle: Style.t=?,
          unit
        ) =>
        t =
        "";
    };

    type config;

    [@bs.obj]
    /* DrawerNavigatorConfig extends NavigationTabRouterConfig, DrawerViewConfig */
    external config:
      (
        ~containerConfig: 'any=?,
        ~drawerType: [@bs.string] [ | `front | `back | `slide]=?,
        ~drawerLockMode: [@bs.string] [
                           | `unlocked
                           | [@bs.as "locked-closed"] `lockedClosed
                           | [@bs.as "locked-open"] `lockedOpen
                         ]
                           =?,
        ~edgeWidth: float=?,
        ~hideStatusBar: bool=?,
        ~overlayColor: Color.t=?,
        /* DrawerViewConfig */
        ~drawerBackgroundColor: Color.t=?,
        ~drawerWidth: float=?,
        ~drawerPosition: [@bs.string] [ | `left | `right]=?,
        ~contentComponent: ContentComponent.t('screenProps)=?,
        ~contentOptions: ContentOptions.t=?,
        ~style: Style.t=?,
        /* NavigationTabRouterConfig extends NavigationTabRouterConfigBase */
        ~defaultNavigationOptions: NavigationScreenConfig.t(
                                     NavigationOptions.t,
                                   )
                                     =?,
        ~navigationOptions: NavigationScreenConfig.t(NavigationOptions.t)=?,
        /* NavigationTabRouterConfigBase */
        ~initialRouteName: string=?,
        ~initialRouteParams: 'routeParams=?,
        ~paths: navigationPathsConfig('paths)=?,
        ~order: array(string)=?,
        ~backBehavior: [@bs.string] [
                         | `none
                         | `initialRoute
                         | `history
                         | `order
                       ]
                         =?,
        unit
      ) =>
      config =
      "";

    [@bs.module "react-navigation"]
    external make: Js.t('a) => navigator = "createDrawerNavigator";

    [@bs.module "react-navigation"]
    external makeWithConfig: (Js.t('a), config) => navigator =
      "createDrawerNavigator";

    module ScreenOptions = {
      type options;

      type drawerIcon;
      [@bs.val] [@bs.module "./Interop"]
      external drawerIcon:
        (
        [@bs.unwrap]
        [
          | `Element(React.element)
          | `Render(DrawerIconProps.t => Js.nullable(React.element))
        ]
        ) =>
        drawerIcon =
        "identity";

      type drawerLabel;
      [@bs.val] [@bs.module "./Interop"]
      external drawerLabel:
        (
        [@bs.unwrap]
        [
          | `String(string)
          | `Element(React.element)
          | `Render(DrawerLabelProps.t => Js.nullable(React.element))
        ]
        ) =>
        drawerLabel =
        "identity";

      [@bs.obj]
      external options:
        (
          ~title: bool=?,
          ~drawerIcon: DrawerIconProps.t=?,
          ~drawerLabel: DrawerLabelProps.t=?,
          ~drawerLockMode: [@bs.string] [
                             | `unlocked
                             | [@bs.as "locked-closed"] `lockedClosed
                             | [@bs.as "locked-open"] `lockedOpen
                           ]
                             =?,
          unit
        ) =>
        options =
        "";
    };
  };

  module TabNavigator = {
    type config;

    [@bs.obj]
    /* NavigationTabRouterConfigBase */
    external config:
      (
        ~initialRouteName: string=?,
        ~initialRouteParams: 'routeParams=?,
        ~paths: navigationPathsConfig('paths)=?,
        ~order: array(string)=?,
        ~backBehavior: [@bs.string] [
                         | `none
                         | `initialRoute
                         | `history
                         | `order
                       ]
                         =?,
        ~resetOnBlur: bool=?,
        /* NavigationTabRouterConfig */
        ~defaultNavigationOptions: NavigationScreenConfig.t(
                                     NavigationOptions.t,
                                   )
                                     =?,
        ~navigationOptions: NavigationScreenConfig.t(NavigationOptions.t)=?,
        /* TabNavigatorConfig */
        //TODO: _lazy as lazy
        ~_lazy: [@bs.as "lazy"] bool=?,
        ~removeClippedSubviews: bool=?,
        ~initialLayout: initialLayout=?,
        /* TabViewConfig */
        ~tabBarComponent: React.element=?, /* TODO: React.ReactType */
        ~tabBarPosition: [@bs.string] [ | `top | `bottom]=?,
        ~tabBarOptions: TabBar.options=?,
        ~swipeEnabled: bool=?,
        ~animationEnabled: bool=?,
        unit
      ) =>
      config =
      "";

    module Material = {
      [@bs.module "react-navigation"]
      external make: Js.t('a) => navigator = "createMaterialTopTabNavigator";

      [@bs.module "react-navigation"]
      external makeWithConfig: (Js.t('a), config) => navigator =
        "createMaterialTopTabNavigator";
    };

    module Bottom = {
      [@bs.module "react-navigation"]
      external make: Js.t('a) => navigator = "createBottomTabNavigator";

      [@bs.module "react-navigation"]
      external makeWithConfig: (Js.t('a), config) => navigator =
        "createBottomTabNavigator";
    };

    [@bs.module "react-navigation"]
    external makeTabNavigator: Js.t('a) => navigator = "createTabNavigator";

    [@bs.module "react-navigation"]
    external makeTabNavigatorWithConfig: (Js.t('a), config) => navigator =
      "createTabNavigator";

    module BottomTabBar = {
      [@react.component] [@bs.module "react-navigation"]
      external make:
        (
          ~activeTintColor: Color.t=?,
          ~activeBackgroundColor: Color.t=?,
          ~adaptive: bool=?,
          ~inactiveTintColor: Color.t=?,
          ~inactiveBackgroundColor: Color.t=?,
          ~showLabel: bool=?,
          ~allowFontScaling: bool=?,
          ~position: Animated.Value.t=?,
          ~navigation: NavigationScreenProp.t=?,
          ~jumpToIndex: int => unit=?,
          // TODO: Org, typings return ReactNode | string
          ~getLabelText: TabScene.t('params) => React.element=?,
          ~getOnPress: (
                         navigationRoute('params),
                         TabScene.t('params),
                         TabBarOnPress.t
                       ) =>
                       unit
                         =?,
          ~getTestIDProps: (TabScene.t('params), TabScene.t('params)) => unit
                             =?,
          ~renderIcon: TabScene.t('params) => React.element=?,
          ~style: Style.t=?,
          ~animateStyle: Style.t=?,
          ~labelStyle: Style.t=?,
          ~tabStyle: Style.t=?,
          ~showIcon: bool=?,
          ~safeAreaInset: [@bs.string] [ | `always | `never]=?
        ) =>
        React.element =
        "BottomTabBar";
    };

    module MaterialTopTabBar = {
      [@react.component] [@bs.module "react-navigation"]
      external make:
        (
          ~activeTintColor: Color.t=?,
          ~inactiveTintColor: Color.t=?,
          ~indicatorStyle: Color.t=?,
          ~showIcon: bool=?,
          ~showLabel: bool=?,
          ~upperCaseLabel: bool=?,
          ~allowFontScaling: bool=?,
          ~position: Animated.Value.t=?,
          ~tabBarPosition: [@bs.string] [ | `top | `bottom]=?,
          ~navigation: NavigationScreenProp.t=?,
          ~jumpToIndex: int => unit=?,
          ~getLabelText: TabScene.t('params) => React.element=?,
          ~getOnPress: (
                         navigationRoute('params),
                         TabScene.t('params),
                         TabBarOnPress.t
                       ) =>
                       unit
                         =?,
          ~renderIcon: TabScene.t('params) => React.element=?,
          ~labelStyle: Style.t=?,
          ~iconStyle: Style.t=?
        ) =>
        React.element =
        "MaterialTopTabBar";
    };

    module ScreenOptions = {
      type options;

      [@bs.obj]
      external options:
        (
          ~swipeEnabled: bool=?,
          ~tabBarOnPress: TabBarOnPress.t=?,
          ~tabBarOnLongPress: TabBarOnLongPress.t=?,
          /* NavigationTabScreenOptionsBase */
          ~title: string=?,
          ~tabBarIcon: tabBarIcon=?,
          ~tabBarLabel: tabBarLabel=?,
          ~tabBarVisible: bool=?,
          ~tabBarTestIDProps: bool=?,
          unit
        ) =>
        options =
        "";
    };
  };

  /*
   export type NavigationScreenOptions = NavigationStackScreenOptions &
       NavigationTabScreenOptions &
       NavigationDrawerScreenOptions;
   */

  type persistNavigationState('params) =
    NavigationState.t('params) => Js.Promise.t(unit);
  type loadNavigationState('params) =
    unit => Js.Promise.t(option(NavigationState.t('params)));
  type onNavigationStateChange('params) =
    (
      NavigationState.t('params),
      NavigationState.t('params),
      NavigationAction.t
    ) =>
    Js.Nullable.t(unit);
  type appContainerProps('params) = {
    .
    "uriPrefix": option(string),
    "enableURLHandling": option(bool),
    "onNavigationStateChange": option(onNavigationStateChange('params)),
    "navigation": option(NavigationScreenProp.t),
    "persistNavigationState": option(persistNavigationState('params)),
    "loadNavigationState": option(loadNavigationState('params)),
    "renderLoadingExperimental": option(React.element),
    "screenProps": option(screenProps),
    "navigationOptions": option(NavigationOptions.t),
    "style": option(Style.t),
  };

  type params;

  module type AppContainer = {
    [@react.component]
    let make:
      (
        ~uriPrefix: string=?,
        ~enableURLHandling: bool=?,
        ~onNavigationStateChange: onNavigationStateChange(params)=?,
        ~navigation: NavigationScreenProp.t=?,
        ~persistNavigationState: persistNavigationState(params)=?,
        ~loadNavigationState: loadNavigationState(params)=?,
        ~renderLoadingExperimental: React.element=?,
        ~screenProps: screenProps=?,
        ~navigationOptions: NavigationOptions.t=?,
        ~style: Style.t=?
      ) =>
      React.element;
  };

  [@bs.module "react-navigation"]
  external _createAppContainer:
    navigator => React.component(appContainerProps(params)) =
    "createAppContainer";

  let makeAppContainer = (navigator: navigator): (module AppContainer) => {
    let make = _createAppContainer(navigator);

    (module
     {
       [@bs.obj]
       external makeProps:
         (
           ~uriPrefix: string=?,
           ~enableURLHandling: bool=?,
           ~onNavigationStateChange: onNavigationStateChange(params)=?,
           ~navigation: NavigationScreenProp.t=?,
           ~persistNavigationState: persistNavigationState(params)=?,
           ~loadNavigationState: loadNavigationState(params)=?,
           ~renderLoadingExperimental: React.element=?,
           ~screenProps: screenProps=?,
           ~navigationOptions: NavigationOptions.t=?,
           ~style: Style.t=?,
           ~key: string=?,
           unit
         ) =>
         appContainerProps(params) =
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
    (
      React.component('props),
      NavigationScreenProps.t('params, 'options) => NavigationOptions.t
    ) =>
    unit =
    "navigationOptions";

  module Route = (M: Route) => {
    include NavigationBase(M);
    let navigate = navigation => navigate(navigation, M.routeName);
    [@bs.send]
    external navigateWithParams: (t, string, M.params) => unit = "navigate";
    let navigateWithParams = (navigation, params: M.params) =>
      navigateWithParams(navigation, M.routeName, params);

    let getParams = (navigation: t, ()): M.params =>
      navigation->state##params;

    [@bs.set]
    external setNavigationOptions:
      (React.component('props), NavigationOptions.t) => unit =
      "navigationOptions";
    [@bs.set]
    external setDynamicNavigationOptions:
      (
        React.component('props),
        NavigationScreenProps.t(M.params, 'options) => NavigationOptions.t
      ) =>
      unit =
      "navigationOptions";
  };

  [@bs.val] [@bs.module "@react-navigation/core"]
  external navigationContext: React.Context.t(navigation) =
    "NavigationContext";

  module type Config = {
    type context;
    let defaultValue: context;
  };

  let useNavigation = () => React.useContext(navigationContext);
};

/* TODO: Maybe we can do this smarter without declaring everything from scratch.
   We just need to state that the bs.module is `react-navigation` instead of `react-native`
   */
module FlatList = {
  include ReactNative.FlatList;

  [@react.component] [@bs.module "react-navigation"]
  external make:
    (
      ~ref: ref=?,
      // FlatList props
      ~_ItemSeparatorComponent: React.component(
                                  separatorComponentProps('item),
                                )
                                  =?,
      ~columnWrapperStyle: Style.t=?,
      ~data: array('item),
      ~getItemLayout: (array('item), int) => VirtualizedList.itemLayout=?,
      ~numColumns: 'int=?,
      // VirtualizedList props
      // ~_CellRendererComponent: VirtualizedList.cellRendererComponent('item)=?,
      ~_ListEmptyComponent: unit => React.element=?,
      ~_ListFooterComponent: unit => React.element=?,
      ~_ListFooterComponentStyle: Style.t=?,
      ~_ListHeaderComponent: unit => React.element=?,
      ~_ListHeaderComponentStyle: Style.t=?,
      ~debug: bool=?,
      // ~data: 'data, // any collection of 'item
      ~disableVirtualization: bool=?, // deprecated
      ~extraData: 'extraData=?,
      // ~getItem: ('data, int) => 'item=?,
      // ~getItemCount: 'data => int=?,
      // ~getItemLayout: ('data, int) => VirtualizedList.itemLayout=?,
      ~initialNumToRender: int=?,
      ~initialScrollIndex: int=?,
      ~inverted: bool=?,
      ~keyExtractor: ('item, int) => string,
      ~maxToRenderPerBatch: int=?,
      ~onEndReached: VirtualizedList.onEndReachedParams => unit=?,
      ~onEndReachedThreshold: float=?,
      ~onRefresh: unit => unit=?,
      ~onScrollToIndexFailed: VirtualizedList.onScrollToIndexFailedParams =>
                              unit
                                =?,
      ~onViewableItemsChanged: VirtualizedList.viewableItemsChanged('item) =>
                               unit
                                 =?,
      ~progressViewOffset: float=?,
      ~refreshing: bool=?,
      ~renderItem: VirtualizedList.renderItemCallback('item),
      ~renderScrollComponent: unit => React.element=?, // TODO: params?
      ~updateCellsBatchingPeriod: float=?,
      ~viewabilityConfig: VirtualizedList.viewabilityConfig=?,
      ~viewabilityConfigCallbackPairs: VirtualizedList.viewabilityConfigCallbackPairs(
                                         'item,
                                       )
                                         =?,
      ~windowSize: int=?,
      // ScrollView props
      ~alwaysBounceHorizontal: bool=?,
      ~alwaysBounceVertical: bool=?,
      ~automaticallyAdjustContentInsets: bool=?,
      ~bounces: bool=?,
      ~bouncesZoom: bool=?,
      ~canCancelContentTouches: bool=?,
      ~centerContent: bool=?,
      ~contentContainerStyle: Style.t=?,
      ~contentInset: View.edgeInsets=?,
      ~contentInsetAdjustmentBehavior: [@bs.string] [
                                         | `automatic
                                         | `scrollableAxes
                                         | `never
                                         | `always
                                       ]
                                         =?,
      ~contentOffset: ScrollView.contentOffset=?,
      ~decelerationRate: [@bs.string] [ | `fast | `normal]=?,
      ~directionalLockEnabled: bool=?,
      ~endFillColor: Color.t=?,
      ~horizontal: bool=?,
      ~indicatorStyle: [@bs.string] [ | `default | `black | `white]=?,
      ~keyboardDismissMode: [@bs.string] [
                              | `none
                              | `interactive
                              | [@bs.as "on-drag"] `onDrag
                            ]
                              =?,
      ~keyboardShouldPersistTaps: [@bs.string] [ | `always | `never | `handled]
                                    =?,
      ~maximumZoomScale: float=?,
      ~minimumZoomScale: float=?,
      ~nestedScrollEnabled: bool=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onMomentumScrollBegin: Event.scrollEvent => unit=?,
      ~onMomentumScrollEnd: Event.scrollEvent => unit=?,
      ~onScroll: Event.scrollEvent => unit=?,
      ~onScrollBeginDrag: Event.scrollEvent => unit=?,
      ~onScrollEndDrag: Event.scrollEvent => unit=?,
      ~overScrollMode: [@bs.string] [ | `always | `never | `auto]=?,
      ~pagingEnabled: bool=?,
      ~pinchGestureEnabled: bool=?,
      ~refreshControl: React.element=?,
      ~scrollEnabled: bool=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: View.edgeInsets=?,
      ~scrollPerfTag: string=?,
      ~scrollsToTop: bool=?,
      ~scrollToOverflowEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~snapToAlignment: [@bs.string] [ | `start | `center | `end_]=?,
      ~snapToEnd: bool=?,
      ~snapToInterval: float=?,
      ~snapToOffsets: array(float)=?,
      ~snapToStart: bool=?,
      ~stickyHeaderIndices: array(int)=?,
      ~zoomScale: float=?,
      // View props
      ~accessibilityComponentType: [@bs.string] [
                                     | `none
                                     | `button
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityElementsHidden: bool=?,
      ~accessibilityHint: string=?,
      ~accessibilityIgnoresInvertColors: bool=?,
      ~accessibilityLabel: string=?,
      ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]
                                  =?,
      ~accessibilityRole: [@bs.string] [
                            | `none
                            | `button
                            | `link
                            | `search
                            | `image
                            | `keyboardkey
                            | `text
                            | `adjustable
                            | `header
                            | `summary
                            | `imagebutton
                          ]
                            =?,
      ~accessibilityStates: array(AccessibilityState.t)=?,
      ~accessibilityTraits: array(AccessibilityTrait.t)=?,
      ~accessibilityViewIsModal: bool=?,
      ~accessible: bool=?,
      ~collapsable: bool=?,
      ~hitSlop: View.edgeInsets=?,
      ~importantForAccessibility: [@bs.string] [
                                    | `auto
                                    | `yes
                                    | `no
                                    | [@bs.as "no-hide-descendants"]
                                      `noHideDescendants
                                  ]
                                    =?,
      ~nativeID: string=?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~onAccessibilityEscape: unit => unit=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: Event.layoutEvent => unit=?,
      ~onMagicTap: unit => unit=?,
      // Gesture Responder props
      ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
      ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
      ~onResponderEnd: Event.pressEvent => unit=?,
      ~onResponderGrant: Event.pressEvent => unit=?,
      ~onResponderMove: Event.pressEvent => unit=?,
      ~onResponderReject: Event.pressEvent => unit=?,
      ~onResponderRelease: Event.pressEvent => unit=?,
      ~onResponderStart: Event.pressEvent => unit=?,
      ~onResponderTerminate: Event.pressEvent => unit=?,
      ~onResponderTerminationRequest: Event.pressEvent => unit=?,
      ~onStartShouldSetResponder: Event.pressEvent => bool=?,
      ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
      ~pointerEvents: [@bs.string] [
                        | `auto
                        | `none
                        | [@bs.as "box-none"] `boxNone
                        | [@bs.as "box-only"] `boxOnly
                      ]
                        =?,
      ~removeClippedSubviews: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~shouldRasterizeIOS: bool=?,
      ~style: Style.t=?,
      ~testID: string=?
    ) =>
    React.element =
    "FlatList";
};

module ScrollView = {
  include ReactNative.ScrollView;

  [@react.component] [@bs.module "react-navigation"]
  external make:
    (
      ~ref: ref=?,
      // ScrollView props
      ~alwaysBounceHorizontal: bool=?,
      ~alwaysBounceVertical: bool=?,
      ~automaticallyAdjustContentInsets: bool=?,
      ~bounces: bool=?,
      ~bouncesZoom: bool=?,
      ~canCancelContentTouches: bool=?,
      ~centerContent: bool=?,
      ~contentContainerStyle: Style.t=?,
      ~contentInset: View.edgeInsets=?,
      ~contentInsetAdjustmentBehavior: [@bs.string] [
                                         | `automatic
                                         | `scrollableAxes
                                         | `never
                                         | `always
                                       ]
                                         =?,
      ~contentOffset: contentOffset=?,
      ~decelerationRate: [@bs.string] [ | `fast | `normal]=?,
      ~directionalLockEnabled: bool=?,
      ~endFillColor: Color.t=?,
      ~horizontal: bool=?,
      ~indicatorStyle: [@bs.string] [ | `default | `black | `white]=?,
      ~keyboardDismissMode: [@bs.string] [
                              | `none
                              | `interactive
                              | [@bs.as "on-drag"] `onDrag
                            ]
                              =?,
      ~keyboardShouldPersistTaps: [@bs.string] [ | `always | `never | `handled]
                                    =?,
      ~maximumZoomScale: float=?,
      ~minimumZoomScale: float=?,
      ~nestedScrollEnabled: bool=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onMomentumScrollBegin: Event.scrollEvent => unit=?,
      ~onMomentumScrollEnd: Event.scrollEvent => unit=?,
      ~onScroll: Event.scrollEvent => unit=?,
      ~onScrollBeginDrag: Event.scrollEvent => unit=?,
      ~onScrollEndDrag: Event.scrollEvent => unit=?,
      ~overScrollMode: [@bs.string] [ | `always | `never | `auto]=?,
      ~pagingEnabled: bool=?,
      ~pinchGestureEnabled: bool=?,
      ~refreshControl: React.element=?,
      ~scrollEnabled: bool=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: View.edgeInsets=?,
      ~scrollPerfTag: string=?,
      ~scrollsToTop: bool=?,
      ~scrollToOverflowEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~snapToAlignment: [@bs.string] [ | `start | `center | `end_]=?,
      ~snapToEnd: bool=?,
      ~snapToInterval: float=?,
      ~snapToOffsets: array(float)=?,
      ~snapToStart: bool=?,
      ~stickyHeaderIndices: array(int)=?,
      ~zoomScale: float=?,
      // View props
      ~accessibilityComponentType: [@bs.string] [
                                     | `none
                                     | `button
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityElementsHidden: bool=?,
      ~accessibilityHint: string=?,
      ~accessibilityIgnoresInvertColors: bool=?,
      ~accessibilityLabel: string=?,
      ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]
                                  =?,
      ~accessibilityRole: [@bs.string] [
                            | `none
                            | `button
                            | `link
                            | `search
                            | `image
                            | `keyboardkey
                            | `text
                            | `adjustable
                            | `header
                            | `summary
                            | `imagebutton
                          ]
                            =?,
      ~accessibilityStates: array(AccessibilityState.t)=?,
      ~accessibilityTraits: array(AccessibilityTrait.t)=?,
      ~accessibilityViewIsModal: bool=?,
      ~accessible: bool=?,
      ~collapsable: bool=?,
      ~hitSlop: View.edgeInsets=?,
      ~importantForAccessibility: [@bs.string] [
                                    | `auto
                                    | `yes
                                    | `no
                                    | [@bs.as "no-hide-descendants"]
                                      `noHideDescendants
                                  ]
                                    =?,
      ~nativeID: string=?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~onAccessibilityEscape: unit => unit=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: Event.layoutEvent => unit=?,
      ~onMagicTap: unit => unit=?,
      // Gesture Responder props
      ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
      ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
      ~onResponderEnd: Event.pressEvent => unit=?,
      ~onResponderGrant: Event.pressEvent => unit=?,
      ~onResponderMove: Event.pressEvent => unit=?,
      ~onResponderReject: Event.pressEvent => unit=?,
      ~onResponderRelease: Event.pressEvent => unit=?,
      ~onResponderStart: Event.pressEvent => unit=?,
      ~onResponderTerminate: Event.pressEvent => unit=?,
      ~onResponderTerminationRequest: Event.pressEvent => unit=?,
      ~onStartShouldSetResponder: Event.pressEvent => bool=?,
      ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
      ~pointerEvents: [@bs.string] [
                        | `auto
                        | `none
                        | [@bs.as "box-none"] `boxNone
                        | [@bs.as "box-only"] `boxOnly
                      ]
                        =?,
      ~removeClippedSubviews: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~shouldRasterizeIOS: bool=?,
      ~style: Style.t=?,
      ~testID: string=?,
      ~children: React.element=?
    ) =>
    React.element =
    "ScrollView";
};

module SectionList = {
  include ReactNative.SectionList;

  [@react.component] [@bs.module "react-navigation"]
  external make:
    (
      ~ref: ref=?,
      // VirtualizedSectionList props
      ~_ItemSeparatorComponent: VirtualizedSectionList.separatorProps(
                                  'item,
                                ) =>
                                React.element
                                  =?,
      ~_SectionSeparatorComponent: VirtualizedSectionList.separatorProps(
                                     'item,
                                   ) =>
                                   React.element
                                     =?,
      ~renderItem: VirtualizedSectionList.renderItemCallback('item),
      ~renderSectionFooter: VirtualizedSectionList.renderSectionHeaderCallback(
                              'item,
                            )
                              =?,
      ~renderSectionHeader: VirtualizedSectionList.renderSectionHeaderCallback(
                              'item,
                            )
                              =?,
      ~sections: array(VirtualizedSectionList.section('item)),
      ~stickySectionHeadersEnabled: bool=?,
      // VirtualizedList props
      ~_CellRendererComponent: VirtualizedList.cellRendererComponent('item)=?,
      ~_ListEmptyComponent: unit => React.element=?,
      ~_ListFooterComponent: unit => React.element=?,
      ~_ListFooterComponentStyle: Style.t=?,
      ~_ListHeaderComponent: unit => React.element=?,
      ~_ListHeaderComponentStyle: Style.t=?,
      ~debug: bool=?,
      // ~enableVirtualization: bool=?, // not working, disableVirtualization?
      // ~data: 'data, // any collection of 'item
      ~disableVirtualization: bool=?, // deprecated
      ~extraData: 'extraData=?,
      ~getItem: ('data, int) => 'item=?,
      ~getItemCount: 'data => int=?,
      ~getItemLayout: ('data, int) => VirtualizedList.itemLayout=?,
      ~initialNumToRender: int=?,
      ~initialScrollIndex: int=?,
      ~inverted: bool=?,
      ~keyExtractor: ('item, int) => string,
      ~maxToRenderPerBatch: int=?,
      ~onEndReached: VirtualizedList.onEndReachedParams => unit=?,
      ~onEndReachedThreshold: float=?,
      ~onRefresh: unit => unit=?,
      ~onScrollToIndexFailed: VirtualizedList.onScrollToIndexFailedParams =>
                              unit
                                =?,
      ~onViewableItemsChanged: VirtualizedList.viewableItemsChanged('item) =>
                               unit
                                 =?,
      ~progressViewOffset: float=?,
      ~refreshing: bool=?,
      // ~renderItem: VirtualizedList.renderItemCallback('item),
      ~renderScrollComponent: unit => React.element=?, // TODO: params?
      ~updateCellsBatchingPeriod: float=?,
      ~viewabilityConfig: VirtualizedList.viewabilityConfig=?,
      ~viewabilityConfigCallbackPairs: VirtualizedList.viewabilityConfigCallbackPairs(
                                         'item,
                                       )
                                         =?,
      ~windowSize: int=?,
      // ScrollView props
      ~alwaysBounceHorizontal: bool=?,
      ~alwaysBounceVertical: bool=?,
      ~automaticallyAdjustContentInsets: bool=?,
      ~bounces: bool=?,
      ~bouncesZoom: bool=?,
      ~canCancelContentTouches: bool=?,
      ~centerContent: bool=?,
      ~contentContainerStyle: Style.t=?,
      ~contentInset: View.edgeInsets=?,
      ~contentInsetAdjustmentBehavior: [@bs.string] [
                                         | `automatic
                                         | `scrollableAxes
                                         | `never
                                         | `always
                                       ]
                                         =?,
      ~contentOffset: ScrollView.contentOffset=?,
      ~decelerationRate: [@bs.string] [ | `fast | `normal]=?,
      ~directionalLockEnabled: bool=?,
      ~endFillColor: Color.t=?,
      ~horizontal: bool=?,
      ~indicatorStyle: [@bs.string] [ | `default | `black | `white]=?,
      ~keyboardDismissMode: [@bs.string] [
                              | `none
                              | `interactive
                              | [@bs.as "on-drag"] `onDrag
                            ]
                              =?,
      ~keyboardShouldPersistTaps: [@bs.string] [ | `always | `never | `handled]
                                    =?,
      ~maximumZoomScale: float=?,
      ~minimumZoomScale: float=?,
      ~nestedScrollEnabled: bool=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onMomentumScrollBegin: Event.scrollEvent => unit=?,
      ~onMomentumScrollEnd: Event.scrollEvent => unit=?,
      ~onScroll: Event.scrollEvent => unit=?,
      ~onScrollBeginDrag: Event.scrollEvent => unit=?,
      ~onScrollEndDrag: Event.scrollEvent => unit=?,
      ~overScrollMode: [@bs.string] [ | `always | `never | `auto]=?,
      ~pagingEnabled: bool=?,
      ~pinchGestureEnabled: bool=?,
      ~refreshControl: React.element=?,
      ~scrollEnabled: bool=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: View.edgeInsets=?,
      ~scrollPerfTag: string=?,
      ~scrollsToTop: bool=?,
      ~scrollToOverflowEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~snapToAlignment: [@bs.string] [ | `start | `center | `end_]=?,
      ~snapToEnd: bool=?,
      ~snapToInterval: float=?,
      ~snapToOffsets: array(float)=?,
      ~snapToStart: bool=?,
      ~stickyHeaderIndices: array(int)=?,
      ~zoomScale: float=?,
      // View props
      ~accessibilityComponentType: [@bs.string] [
                                     | `none
                                     | `button
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityElementsHidden: bool=?,
      ~accessibilityHint: string=?,
      ~accessibilityIgnoresInvertColors: bool=?,
      ~accessibilityLabel: string=?,
      ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]
                                  =?,
      ~accessibilityRole: [@bs.string] [
                            | `none
                            | `button
                            | `link
                            | `search
                            | `image
                            | `keyboardkey
                            | `text
                            | `adjustable
                            | `header
                            | `summary
                            | `imagebutton
                          ]
                            =?,
      ~accessibilityStates: array(AccessibilityState.t)=?,
      ~accessibilityTraits: array(AccessibilityTrait.t)=?,
      ~accessibilityViewIsModal: bool=?,
      ~accessible: bool=?,
      ~collapsable: bool=?,
      ~hitSlop: View.edgeInsets=?,
      ~importantForAccessibility: [@bs.string] [
                                    | `auto
                                    | `yes
                                    | `no
                                    | [@bs.as "no-hide-descendants"]
                                      `noHideDescendants
                                  ]
                                    =?,
      ~nativeID: string=?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~onAccessibilityEscape: unit => unit=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: Event.layoutEvent => unit=?,
      ~onMagicTap: unit => unit=?,
      // Gesture Responder props
      ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
      ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
      ~onResponderEnd: Event.pressEvent => unit=?,
      ~onResponderGrant: Event.pressEvent => unit=?,
      ~onResponderMove: Event.pressEvent => unit=?,
      ~onResponderReject: Event.pressEvent => unit=?,
      ~onResponderRelease: Event.pressEvent => unit=?,
      ~onResponderStart: Event.pressEvent => unit=?,
      ~onResponderTerminate: Event.pressEvent => unit=?,
      ~onResponderTerminationRequest: Event.pressEvent => unit=?,
      ~onStartShouldSetResponder: Event.pressEvent => bool=?,
      ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
      ~pointerEvents: [@bs.string] [
                        | `auto
                        | `none
                        | [@bs.as "box-none"] `boxNone
                        | [@bs.as "box-only"] `boxOnly
                      ]
                        =?,
      ~removeClippedSubviews: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~shouldRasterizeIOS: bool=?,
      ~style: Style.t=?,
      ~testID: string=?
    ) =>
    React.element =
    "SectionList";
};

include Make({
  type screenProps = {.};
});
