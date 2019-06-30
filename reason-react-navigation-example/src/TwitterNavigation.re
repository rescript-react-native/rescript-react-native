open ReactNavigation;
open ReactNative;

module Icons = {
  let filter =
    Image.Source.fromRequired(Packager.require("./Icons/filter.png"));

  let settings =
    Image.Source.fromRequired(Packager.require("./Icons/settings.png"));

  let home = Image.Source.fromRequired(Packager.require("./Icons/home.png"));

  let message =
    Image.Source.fromRequired(Packager.require("./Icons/message.png"));

  let notification =
    Image.Source.fromRequired(Packager.require("./Icons/notification.png"));

  let search =
    Image.Source.fromRequired(Packager.require("./Icons/search.png"));

  let compose =
    Image.Source.fromRequired(Packager.require("./Icons/compose.png"));

  let avatar =
    Image.(
      Source.fromUriSource(
        uriSource(~uri="https://github.com/reasonml-community.png", ()),
      )
    );
};

type tweet = {
  id: string,
  text: string,
  thread: bool,
};

let dummyTweets = [|
  {id: "id_1", text: "Some insightful tweet", thread: false},
  {id: "id_2", text: "Some insightful tweet", thread: true},
  {id: "id_3", text: "Some insightful tweet", thread: false},
  {id: "id_4", text: "Some insightful tweet", thread: true},
  {id: "id_5", text: "Some insightful tweet", thread: false},
  {id: "id_6", text: "Some insightful tweet", thread: true},
  {id: "id_7", text: "Some insightful tweet", thread: false},
  {id: "id_8", text: "Some insightful tweet", thread: true},
  {id: "id_9", text: "Some insightful tweet", thread: false},
  {id: "id_10", text: "Some insightful tweet", thread: true},
|];

let getTweet = (~id, onResult) =>
  Js.Global.setTimeout(
    () => onResult(dummyTweets->Belt.Array.keep(tweet => tweet.id == id)),
    500,
  );

module ComposeRoute =
  Route({
    type params = unit;
    let routeName = "Compose";
  });

module ComposeButton = {
  [@react.component]
  let make = (~onPress) =>
    <TouchableOpacity
      onPress
      style=Style.(
        style(
          ~backgroundColor="#5D9FEF",
          ~elevation=3.,
          ~shadowRadius=3.,
          ~shadowOpacity=0.3,
          ~shadowOffset=offset(~height=2., ~width=0.),
          ~position=`absolute,
          ~right=16.->dp,
          ~bottom=14.->dp,
          ~alignItems=`center,
          ~justifyContent=`center,
          ~borderRadius=25.,
          ~width=50.->dp,
          ~height=50.->dp,
          (),
        )
      )>
      <Image
        style=Style.(
          style(~width=24.->dp, ~margin=11.->dp, ~height=24.->dp, ())
        )
        source=Icons.compose
      />
    </TouchableOpacity>;
};

let placeholder = (~text, ~navigation: navigation) =>
  <>
    <Centered> <Text> {text |> React.string} </Text> </Centered>
    <ComposeButton
      onPress={_ => navigation->Navigation.navigate("Compose")}
    />
  </>;

let headerIcon = (~style as additionalStyle=Style.style(), source) =>
  headerRenderItem(
    `Element(
      <Image
        style=Style.(
          array([|
            style(~width=24.->dp, ~margin=11.->dp, ~height=24.->dp, ()),
            additionalStyle,
          |])
        )
        source
      />,
    ),
  );

let tabBarIcon = source =>
  TabNavigator.(
    ScreenOptions.tabBarIcon(
      `Render(
        props =>
          Js.Nullable.return(
            <Image
              style=Style.(
                style(
                  ~tintColor=
                    props->TabBarIconProps.focusedGet ? "#1da1f2" : "grey",
                  ~width=24.->dp,
                  ~margin=11.->dp,
                  ~height=24.->dp,
                  (),
                )
              )
              source
            />,
          ),
      ),
    )
  );

let avatarIcon = params =>
  headerRenderItem(
    `Element(
      <TouchableOpacity
        onPress={_ =>
          params->NavigationParams.navigation->Navigation.openDrawer()
        }>
        <Image
          style=Style.(
            style(
              ~backgroundColor="grey",
              ~width=24.->dp,
              ~borderRadius=12.,
              ~margin=11.->dp,
              ~height=24.->dp,
              (),
            )
          )
          source=Icons.avatar
        />
      </TouchableOpacity>,
    ),
  );

module Tweet = {
  include Route({
    type params = {. "tweet": tweet};
    let routeName = "Tweet";
  });
  [@react.component]
  let make = (~navigation) => {
    <Centered>
      <Text>
        {"Tweet: " ++ navigation->getParams()##tweet.id |> React.string}
      </Text>
    </Centered>;
  };

  module Header = {
    [@react.component]
    let make = (~children: string) => {
      let navigation = useNavigation();

      let tweet: Js.nullable(tweet) = navigation->getParam("tweet");

      <View>
        <Text>
          {(
             switch (tweet->Js.Nullable.toOption) {
             | Some({thread}) => thread ? "Thread" : "Tweet"
             | None => children
             }
           )
           |> React.string}
        </Text>
      </View>;
    };
  };

  let headerTitle =
    HeaderTitle.(t(`Render(props => <Header> props->children </Header>)));

  make->setDynamicNavigationOptions(params =>
    NavigationOptions.t(~title="Tweet", ~headerTitle, ())
  );
};

module Camera = {
  [@react.component]
  let cameraScreen = () =>
    <SafeAreaView
      style=Style.(style(~flex=1.0, ~backgroundColor="black", ()))>
      <TouchableOpacity
        style=Style.(
          style(
            ~backgroundColor="#aaa",
            ~position=`absolute,
            ~bottom=34.->dp,
            ~alignItems=`center,
            ~alignSelf=`center,
            ~justifyContent=`center,
            ~borderRadius=25.,
            ~width=50.->dp,
            ~height=50.->dp,
            (),
          )
        )>
        <View
          style=Style.(
            style(
              ~width=24.->dp,
              ~backgroundColor="#eee",
              ~height=24.->dp,
              (),
            )
          )
        />
      </TouchableOpacity>
    </SafeAreaView>;

  let routes = {"Camera": cameraScreen, "CameraModal": PrivacyPolicy.make};

  let navigator =
    StackNavigator.(
      makeWithConfig(routes, config(~mode=`modal, ~headerMode=`none, ()))
    );

  navigator->setNavigationOptions(
    NavigationOptions.t(~tabBarVisible=false, ~swipeEnabled=true, ()),
  );
};

let avatar = headerIcon(Icons.avatar);

module Timeline = {
  let header = header(`Null(Js.null));

  module TimelineItem = {
    [@react.component]
    let make = (~text, ~onPress) =>
      <>
        <TouchableOpacity
          onPress
          style=Style.(
            style(~paddingHorizontal=16.->dp, ~paddingVertical=26.->dp, ())
          )>
          <Text> {text |> React.string} </Text>
        </TouchableOpacity>
        <View
          style=Style.(
            style(~borderBottomColor="#ddd", ~borderBottomWidth=1., ())
          )
        />
      </>;
  };

  module TimelineList = {
    [@react.component]
    let make = (~navigation: navigation) =>
      <>
        <ReactNavigation.FlatList
          data=dummyTweets
          keyExtractor={({id}, _) => id}
          renderItem={props =>
            <TimelineItem
              onPress={_ =>
                navigation->Tweet.navigateWithParams({"tweet": props##item})
              }
              text={props##item.text}
            />
          }
        />
        <ComposeButton onPress={_ => navigation->ComposeRoute.navigate} />
      </>;

    make->setDynamicNavigationOptions(params =>
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

  navigator->setNavigationOptions(
    NavigationOptions.t(
      ~title="Timeline",
      ~tabBarIcon=tabBarIcon(Icons.home),
      (),
    ),
  );
};

module Search = {
  module SearchList = {
    [@react.component]
    let make = (~navigation) => placeholder(~navigation, ~text="SearchList");

    let headerTitle =
      HeaderTitle.t(
        `Element(
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
          />,
        ),
      );

    make->setDynamicNavigationOptions(params =>
      NavigationOptions.t(
        ~headerLeft=avatarIcon(params),
        ~headerTitle,
        ~headerRight=headerIcon(Icons.settings),
        (),
      )
    );
  };

  module SearchResultItem = {
    [@react.component]
    let make = (~navigation) =>
      placeholder(~navigation, ~text="Search result");

    make->setNavigationOptions(NavigationOptions.t(~title="Tweet", ()));
  };

  let routes = {
    "SearchList": SearchList.make,
    "SearchResultItem": SearchResultItem.make,
  };

  let navigator =
    StackNavigator.(makeWithConfig(routes, config(~mode=`modal, ())));
  navigator->setNavigationOptions(
    NavigationOptions.t(
      ~title="Search",
      ~tabBarIcon=tabBarIcon(Icons.search),
      (),
    ),
  );
};

module Notifications = {
  module All = {
    [@react.component]
    let make = (~navigation) =>
      <Centered>
        <Text> {"List of notifications" |> React.string} </Text>
      </Centered>;

    make->setNavigationOptions(NavigationOptions.t(~title="All", ()));
  };

  module Mentions = {
    [@react.component]
    let make = (~navigation) =>
      <Centered>
        <Text> {"List of mentions" |> React.string} </Text>
      </Centered>;

    make->setNavigationOptions(NavigationOptions.t(~title="Mentions", ()));
  };

  let tabNavigator =
    TabNavigator.(
      Material.makeWithConfig(
        {"All": All.make, "Mentions": Mentions.make},
        config(
          ~tabBarOptions=
            TabBar.options(
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

  tabNavigator->setDynamicNavigationOptions(params =>
    NavigationOptions.t(
      ~title="Notifications",
      ~headerLeft=avatarIcon(params),
      ~headerRight=headerIcon(Icons.settings),
      (),
    )
  );

  let navigator = StackNavigator.(make({"NotificationsRoot": tabNavigator}));
  navigator->setNavigationOptions(
    NavigationOptions.t(
      ~title="Notifications",
      ~tabBarIcon=tabBarIcon(Icons.notification),
      (),
    ),
  );
};

module Messages = {
  module MessageList = {
    [@react.component]
    let make = (~navigation) => placeholder(~navigation, ~text="SearchList");

    make->setDynamicNavigationOptions(params =>
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

    make->setNavigationOptions(NavigationOptions.t(~title="Tweet", ()));
  };

  let routes = {
    "MessageList": MessageList.make,
    "MessageListItem": MessageListItem.make,
  };

  let navigator =
    StackNavigator.(makeWithConfig(routes, config(~mode=`modal, ())));
  navigator->setNavigationOptions(
    NavigationOptions.t(
      ~title="Messages",
      ~tabBarIcon=tabBarIcon(Icons.message),
      (),
    ),
  );
};

let rec getActiveRoute = route =>
  NavigationState.(
    switch (route->routesGet) {
    | Some(routes) =>
      let routeCount = routes->Array.length;
      if (routeCount == 0 || route->indexGet >= routeCount) {
        route;
      } else {
        getActiveRoute(
          routes->Belt.Array.getUnsafe(route->NavigationState.indexGet),
        );
      };
    | None => route
    }
  );

module Compose = {
  [@react.component]
  let make = (~navigation) => <View />;

  make->setNavigationOptions(NavigationOptions.t(~title="Compose", ()));
};

module Profile = {
  [@react.component]
  let make = (~navigation) => placeholder(~navigation, ~text="Profile");

  make->setNavigationOptions(NavigationOptions.t(~title="Profile", ()));
};

module Content = {
  open DrawerNavigator;

  module NavRow = {
    [@react.component]
    let make = (~navigation, ~route, ~title) =>
      <TouchableOpacity
        onPress={_ => {
          navigation->Navigation.closeDrawer();
          navigation->Navigation.navigate(route);
        }}
        style=Style.(style(~padding=14.->dp, ()))>
        <Text style=Style.(style(~color="#444", ()))>
          {title |> React.string}
        </Text>
      </TouchableOpacity>;
  };

  let contentComponent = (props: ContentComponent.props(unit)) => {
    let navigation = props->ContentComponent.navigation;
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
    makeWithConfig(
      {
        "Root":
          TabNavigator.(
            Bottom.makeWithConfig(
              {
                "Timeline": Timeline.navigator,
                "Search": Search.navigator,
                "Notifications": Notifications.navigator,
                "Messages": Messages.navigator,
              },
              config(~initialRouteName="Timeline", ()),
            )
          ),
      },
      config(~contentComponent, ()),
    );

  navigator->setDynamicNavigationOptions(params => {
    let navigation = params->NavigationParams.navigation;
    let state = navigation->Navigation.state;
    let routeName = getActiveRoute(state)->NavigationState.routeNameGet;
    let swipeEnabled = routeName == "TimelineList";

    NavigationOptions.(t(~tabBarVisible=false, ~swipeEnabled, ()));
  });
};

module ContentView = {
  let navigator =
    TabNavigator.(
      Material.make({
        "Content": Content.navigator,
        "Camera": Camera.navigator,
      })
    );
  let header = header(`Null(Js.null));
  navigator->setNavigationOptions(NavigationOptions.t(~header, ()));
};

let app =
  AppContainer.make(
    SwitchNavigator.make({
      "App":
        StackNavigator.(
          makeWithConfig(
            {
              "View": ContentView.navigator,
              "Compose": Compose.make,
              "Tweet": Tweet.make,
              "Profile": Profile.make,
            },
            config(),
          )
        ),
      "AppLoading": LoadingScreen.make,
      /*"Auth": LoginRoute.reactClass,*/
    }),
  );
