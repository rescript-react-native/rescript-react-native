open ReactNative;
open ReactNavigation;
open Helpers;
module TimelineItem = {
  [@react.component]
  let make = (~text, ~onPress) =>
    <TouchableOpacity
      onPress
      style=Style.(
        style(~paddingHorizontal=16.->dp, ~paddingVertical=26.->dp, ())
      )>
      <Text> {text |> React.string} </Text>
    </TouchableOpacity>;
};

module TimelineList = {
  [@react.component]
  let make = (~navigation: Navigation.t) =>
    <>
      <FlatList
        data=Tweet.dummyTweets
        keyExtractor={({id}, _) => id}
        _ItemSeparatorComponent={_ =>
          <View
            style=Style.(
              style(~borderBottomColor="#ddd", ~borderBottomWidth=1., ())
            )
          />
        }
        renderItem={props =>
          <TimelineItem
            onPress={_ =>
              navigation->Navigation.navigateWithParams(
                "Tweet",
                {"tweet": props##item},
              )
            }
            text={props##item.text}
          />
        }
      />
      <ComposeButton
        onPress={_ => navigation->Navigation.navigate("Compose")}
      />
    </>;

  make->NavigationOptions.setDynamicNavigationOptions(params =>
    NavigationOptions.(
      t(
        ~title="Timeline",
        ~headerLeft=avatarIcon(params),
        ~headerRight=headerIcon(Icons.filter),
        (),
      )
    )
  );
};

let routes = {"TimelineList": TimelineList.make};

let navigator =
  StackNavigator.(makeWithConfig(routes, config(~mode=`modal, ())));

navigator->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(
    ~title="Timeline",
    ~tabBarIcon=tabBarIcon(Icons.home),
    (),
  ),
);
