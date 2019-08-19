open ReactNative;
open ReactNavigation;
open Helpers;

module SearchHeader = {
  [@react.component]
  let make = () =>
    <TextInput
      style=Style.(
        style(
          ~backgroundColor="rgb(230, 236, 240)",
          ~paddingVertical=6.->dp,
          ~paddingHorizontal=10.->dp,
          ~fontSize=12.,
          ~flex=1.,
          ~color="#333",
          ~borderRadius=14.,
          (),
        )
      )
      placeholder="Search Twitter"
    />;
};

module SearchList = {
  [@react.component]
  let make = (~navigation) => placeholder(~navigation, ~text="SearchList");

  NavigationOptions.(
    make->setDynamicNavigationOptions(params =>
      t(
        ~headerLeft=avatarIcon(params),
        ~headerTitle=HeaderTitle.element(<SearchHeader />),
        ~headerRight=headerIcon(Icons.settings),
        (),
      )
    )
  );
};

module SearchResultItem = {
  [@react.component]
  let make = (~navigation) =>
    placeholder(~navigation, ~text="Search result");

  make->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~title="Tweet", ()),
  );
};

let routes = {
  "SearchList": SearchList.make,
  "SearchResultItem": SearchResultItem.make,
};

let navigator =
  StackNavigator.(makeWithConfig(routes, config(~mode=`modal, ())));
navigator->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(
    ~title="Search",
    ~tabBarIcon=tabBarIcon(Icons.search),
    (),
  ),
);
