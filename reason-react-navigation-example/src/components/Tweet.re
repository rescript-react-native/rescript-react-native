open ReactNative;
open ReactNavigation;

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
[@react.component]
let make = (~navigation) =>
  <Centered>
    <Text>
      {(
         "Tweet: "
         ++ navigation
            ->Navigation.getParam("tweet")
            ->Js.Nullable.toOption
            ->Belt.Option.mapWithDefault("unknown", tweet => tweet.id)
       )
       ->React.string}
    </Text>
  </Centered>;

module TweetHeader = {
  [@react.component]
  let make = (~children: React.element) => {
    let navigation = Navigation.useNavigation();

    let tweet: Js.nullable(tweet) = navigation->Navigation.getParam("tweet");

    <View>
      <Text>
        {switch (tweet->Js.Nullable.toOption) {
         | Some({thread}) => (thread ? "Thread" : "Tweet")->React.string
         | None => children
         }}
      </Text>
    </View>;
  };
};

NavigationOptions.(
  make->setNavigationOptions(
    t(
      ~title="Tweet",
      ~headerTitle=
        HeaderTitle.render(props =>
          <TweetHeader> {props##children} </TweetHeader>
        ),
      (),
    ),
  )
);
