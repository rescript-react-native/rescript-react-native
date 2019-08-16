open ReactNative;

module Header = {
  type t;

  // type renderFunction('params) = headerProps('params) => React.element; TODO

  external element: React.element => t = "%identity";
  // external render: renderFunction('params) => t = "%identity"; TODO
};

module HeaderTitle = {
  type t;

  type props = {
    .
    "allowFontScaling": bool,
    "style": Style.t,
    "children": React.element,
  };

  type renderFunction = props => React.element;

  external string: string => t = "%identity";
  external element: React.element => t = "%identity";
  external render: renderFunction => t = "%identity";
};

module TabBarIcon = {
  type t;

  type props = {
    .
    "focused": bool,
    "horizontal": bool,
    "tintColor": Color.t,
  };

  type renderFunction = props => React.element;

  external element: React.element => t = "%identity";
  external render: renderFunction => t = "%identity";
};

module TabBarLabel = {
  type t;

  type props = {
    .
    "focused": bool,
    "tintColor": Color.t,
  };

  type renderFunction = props => React.element;

  external string: string => t = "%identity";
  external element: React.element => t = "%identity";
  external render: renderFunction => t = "%identity";
};

module DrawerIcon = {
  type t;

  type props = {
    .
    "focused": bool,
    "tintColor": Color.t,
  };

  type renderFunction = props => React.element;

  external element: React.element => t = "%identity";
  external render: renderFunction => t = "%identity";
};

module DrawerLabel = {
  type t;

  type props = {
    .
    "focused": bool,
    "tintColor": Color.t,
  };

  type renderFunction = props => React.element;

  external string: string => t = "%identity";
  external element: React.element => t = "%identity";
  external render: renderFunction => t = "%identity";
};

type tabBarOnPressParams = {
  .
  "previousScene": bool,
  "scene": bool,
  "jumpToIndex": int => unit,
};

type t;

[@bs.obj]
external t:
  (
    ~title: string=?,
    /* TabNavigator */
    ~swipeEnabled: bool=?,
    ~tabBarOnPress: tabBarOnPressParams => unit=?,
    ~tabBarOnLongPress: tabBarOnPressParams => unit=?,
    ~tabBarIcon: TabBarIcon.t=?,
    ~tabBarLabel: TabBarLabel.t=?,
    ~tabBarVisible: bool=?,
    ~tabBarTestIDProps: bool=?,
    /* DrawerNavigator */
    ~drawerIcon: DrawerIcon.t=?,
    ~drawerLabel: DrawerLabel.t=?,
    ~drawerLockMode: [@bs.string] [
                       | `unlocked
                       | [@bs.as "locked-closed"] `lockedClosed
                       | [@bs.as "locked-open"] `lockedOpen
                     ]
                       =?,
    /* StackNavigator */
    ~title: string=?,
    ~header: Header.t=?,
    ~headerTransparent: bool=?,
    ~headerTitle: HeaderTitle.t=?, // TODO
    ~headerTitleStyle: Style.t=?,
    ~headerTitleAllowFontScaling: bool=?,
    ~headerTintColor: Color.t=?,
    ~headerLeft: React.element=?, // TODO
    ~headerBackTitle: Js.nullable(string)=?,
    ~headerBackImage: React.element=?,
    ~headerTruncatedBackTitle: string=?,
    ~headerBackTitleStyle: Style.t=?,
    ~headerPressColorAndroid: Color.t=?,
    ~headerRight: React.element=?, // TODO
    ~headerStyle: Style.t=?,
    ~headerLeftContainerStyle: Style.t=?,
    ~headerRightContainerStyle: Style.t=?,
    // ~headerForceInset: HeaderForceInset.t=?,
    /* TODO: double check this as it's typed as: React.ReactNode | React.ReactType */
    ~headerBackground: React.element=?,
    ~headerBackgroundTransitionPreset: [@bs.string] [
                                         | `toggle
                                         | `fade
                                         | `translate
                                       ]
                                         =?,
    ~gesturesEnabled: bool=?,
    // ~gestureResponseDistance: gestureResponseDistance=?, TODO
    ~gestureDirection: [@bs.string] [ | `default | `inverted]=?,
    unit
  ) =>
  t =
  "";

type navigationParams('screenProps) = {
  .
  "navigation": Navigation.t,
  "navigationOptions": t,
  "screenProps": 'screenProps,
};

[@bs.set]
external setNavigationOptions: (React.component('props), t) => unit =
  "navigationOptions";

[@bs.set]
external setDynamicNavigationOptions:
  (React.component('props), navigationParams('screenProps) => t) => unit =
  "navigationOptions";
