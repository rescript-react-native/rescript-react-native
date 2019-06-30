open ReactNavigation;

module LeftRoute = {
  open ReactNative;
  [@react.component]
  let make = () =>
    <Centered> <Text> {"Left" |> React.string} </Text> </Centered>;

  make->setNavigationOptions(NavigationOptions.t(~title="Left", ()));
};

module RightRoute = {
  open ReactNative;
  [@react.component]
  let make = () =>
    <Centered> <Text> {"Right" |> React.string} </Text> </Centered>;

  make->setNavigationOptions(NavigationOptions.t(~title="Right", ()));
};

module Center = {
  let routes = {"CHome": Home.make, "CPrivacyPolicy": PrivacyPolicy.make};

  let navigator =
    StackNavigator.(makeWithConfig(routes, config(~mode=`modal, ())));

  navigator->setNavigationOptions(
    NavigationOptions.t(~title="Center", ~tabBarVisible=false, ()),
  );
};

module Left = {
  let routes = {
    "LeftHome": LeftRoute.make,
    "LPrivacyPolicy": PrivacyPolicy.make,
  };

  let navigator = DrawerNavigator.(makeWithConfig(routes, config()));
  navigator->setNavigationOptions(
    NavigationOptions.t(~title="Left", ~tabBarVisible=true, ()),
  );
};

module Right = {
  let routes = {
    "RHome": RightRoute.make,
    "RPrivacyPolicy": PrivacyPolicy.make,
  };

  let navigator =
    StackNavigator.(makeWithConfig(routes, config(~mode=`modal, ())));

  navigator->setNavigationOptions(
    NavigationOptions.t(~tabBarVisible=false, ()),
  );
};

let navigator =
  TabNavigator.(
    Material.makeWithConfig(
      {
        "Left": Left.navigator,
        "Center": Center.navigator,
        "Right": Right.navigator,
      },
      config(~initialRouteName="Center", ()),
    )
  );

let app =
  AppContainer.make(
    SwitchNavigator.make({
      "AppLoading": LoadingScreen.make,
      /*"Auth": LoginRoute.reactClass,*/
      "App": navigator,
    }),
  );
