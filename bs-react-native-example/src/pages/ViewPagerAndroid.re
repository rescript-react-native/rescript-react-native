open BsReactNative;

open Utils;

let exampleType = FullScreen;

let displayName = "ViewPagerAndroid";

let title = "<ViewPagerAndroid>";

let description = "ViewPagerAndroid component (supported only on Android).";

let styles =
  StyleSheet.create(
    Style.{
      "pageStyle": style([flex(1.), flexGrow(1.)]),
      "viewPager":
        style([alignItems(Center), padding(Pt(20.)), height(Pt(400.))]),
    },
  );

module ExampleContent = {
  type action;

  type state = {pagerRef: ref(option(ReasonReact.reactRef))};

  let setPagerRef = (theRef, {ReasonReact.state}) =>
    state.pagerRef := Js.Nullable.toOption(theRef);

  let component = ReasonReact.reducerComponent("ExampleContent");

  let handlePress = (_, {ReasonReact.state}) =>
    switch (state.pagerRef^) {
    | None => ()
    | Some(r) => ReasonReact.refToJsObj(r)##setPage(1)
    };

  let make = _children => {
    ...component,
    initialState: () => {pagerRef: ref(None)},
    reducer: (_action: action, _state: state) => ReasonReact.NoUpdate,
    render: self =>
      <ViewPagerAndroid
        ref={self.handle(setPagerRef)}
        initialPage=0
        style=styles##viewPager
        onLayout={_ => Js.log("JUPI")}
        onPageScroll={e =>
          Js.log("onPageScroll: " ++ string_of_int(e##nativeEvent##position))
        }
        onPageSelected={e =>
          Js.log(
            "onPageSelected: " ++ string_of_int(e##nativeEvent##position),
          )
        }>
        <View style=styles##pageStyle key="1">
          <Text> {ReasonReact.string("First page")} </Text>
          <Button
            title="Go to second page"
            onPress={self.handle(handlePress)}
          />
        </View>
        <View style=styles##pageStyle key="2">
          <Text> {ReasonReact.string("Second page")} </Text>
        </View>
      </ViewPagerAndroid>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "ViewPagerAndroid",
    description: Some("Basic ViewPagerAndroid"),
    render: () => <ExampleContent />,
  },
|];
