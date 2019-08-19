open ReactNative;
open ReactNavigation;
open Helpers;

module Content = {
  open DrawerNavigator;

  module NavRow = {
    [@react.component]
    let make = (~navigation, ~route, ~title) =>
      <TouchableOpacity
        onPress={_ => {
          navigation->Navigation.closeDrawer;
          navigation->Navigation.navigate(route);
        }}
        style=Style.(style(~padding=14.->dp, ()))>
        <Text style=Style.(style(~color="#444", ()))>
          {title |> React.string}
        </Text>
      </TouchableOpacity>;
  };

  let contentComponent = props => {
    let navigation = props##navigation;
    <SafeAreaView style={Style.style(~flex=1., ())}>
      <View
        style=Style.(
          style(~borderBottomWidth=1., ~borderBottomColor="#eee", ())
        )>
        <Image
          style=Style.(
            style(
              ~backgroundColor="grey",
              ~width=36.->dp,
              ~borderRadius=18.,
              ~margin=11.->dp,
              ~height=36.->dp,
              (),
            )
          )
          source=Icons.avatar
        />
      </View>
      <View
        style=Style.(
          style(~borderBottomWidth=1., ~borderBottomColor="#eee", ())
        )>
        <NavRow route="Profile" title="Profile" navigation />
        <NavRow route="Lists" title="Lists" navigation />
        <NavRow route="Bookmarks" title="Bookmarks" navigation />
        <NavRow route="Moments" title="Moments" navigation />
      </View>
      <View
        style=Style.(
          style(~borderBottomWidth=1., ~borderBottomColor="#eee", ())
        )>
        <NavRow route="Settings" title="Settings and privacy" navigation />
        <NavRow route="Help" title="Help Centre" navigation />
      </View>
    </SafeAreaView>;
  };

  let navigator =
    DrawerNavigator.makeWithConfig(
      {
        "Root":
          TabNavigator.Bottom.makeWithConfig(
            {
              "Timeline": Timeline.navigator,
              "Search": Search.navigator,
              "Notifications": Notifications.navigator,
              "Messages": Messages.navigator,
            },
            TabNavigator.config(~initialRouteName="Timeline", ()),
          ),
      },
      config(~contentComponent, ()),
    );

  navigator->NavigationOptions.setDynamicNavigationOptions(params => {
    let routeName =
      params##navigation->Navigation.state->getActiveRoute##routeName;

    let swipeEnabled = routeName == "TimelineList";

    NavigationOptions.t(~tabBarVisible=false, ~swipeEnabled, ());
  });
};

module ContentView = {
  let navigator =
    TabNavigator.MaterialTop.make({
      "Content": Content.navigator,
      "Camera": Camera.navigator,
    });

  NavigationOptions.(
    navigator->setNavigationOptions(
      t(~header=Header.element(React.null), ()),
    )
  );
};

module TwitterAppContainer =
  AppContainer.Make({
    type screenProps = {. "someProp": int};

    let navigator =
      SwitchNavigator.make({
        "App":
          StackNavigator.make({
            "View": ContentView.navigator,
            "Compose": Compose.make,
            "Tweet": Tweet.make,
            "Profile": Profile.make,
          }),
        "AppLoading": LoadingScreen.make,
        /*"Auth": LoginRoute.reactClass,*/
      });
  });

[@react.component]
let make = () => {
  let screenProps = {"someProp": 42};

  <TwitterAppContainer screenProps />;
};
