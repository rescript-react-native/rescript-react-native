open ReactNavigation;
open Helpers;

module MessageList = {
  [@react.component]
  let make = (~navigation) => placeholder(~navigation, ~text="SearchList");

  make->NavigationOptions.setDynamicNavigationOptions(params =>
    NavigationOptions.t(
      ~title="Messages",
      ~headerLeft=avatarIcon(params),
      ~headerRight=headerIcon(Icons.settings),
      (),
    )
  );
};

module MessageListItem = {
  [@react.component]
  let make = (~navigation) =>
    placeholder(~navigation, ~text="Search result");

  make->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~title="Tweet", ()),
  );
};

let routes = {
  "MessageList": MessageList.make,
  "MessageListItem": MessageListItem.make,
};

let navigator =
  StackNavigator.(makeWithConfig(routes, config(~mode=`modal, ())));
navigator->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(
    ~title="Messages",
    ~tabBarIcon=tabBarIcon(Icons.message),
    (),
  ),
);
