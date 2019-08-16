open ReactNative;
open ReactNavigation;
open Helpers;

module All = {
  [@react.component]
  let make = (~navigation as _) =>
    <Centered>
      <Text> {"List of notifications" |> React.string} </Text>
    </Centered>;

  make->NavigationOptions.(setNavigationOptions(t(~title="All", ())));
};

module Mentions = {
  [@react.component]
  let make = (~navigation as _) =>
    <Centered> <Text> {"List of mentions" |> React.string} </Text> </Centered>;

  make->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~title="Mentions", ()),
  );
};

let tabNavigator =
  TabNavigator.(
    MaterialTop.makeWithConfig(
      {"All": All.make, "Mentions": Mentions.make},
      TabNavigator.config(
        ~tabBarOptions=
          tabBarOptions(
            ~activeTintColor="#81A7ED",
            ~inactiveTintColor="grey",
            ~style=Style.style(~backgroundColor="white", ()),
            ~indicatorStyle=Style.style(~backgroundColor="#81A7ED", ()),
            (),
          ),
        (),
      ),
    )
  );

tabNavigator->NavigationOptions.setDynamicNavigationOptions(params =>
  NavigationOptions.t(
    ~title="Notifications",
    ~headerLeft=avatarIcon(params),
    ~headerRight=headerIcon(Icons.settings),
    (),
  )
);

let navigator = StackNavigator.(make({"NotificationsRoot": tabNavigator}));
navigator->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(
    ~title="Notifications",
    ~tabBarIcon=tabBarIcon(Icons.notification),
    (),
  ),
);
