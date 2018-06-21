open Rebolt;

open Utils;

let onButtonPress = () => Alert.alert(~title="Button has been pressed!", ());

let exampleType = FullScreen;

let displayName = "DrawerLayoutAndroid";

let title = "<DrawerLayoutAndroid>";

let description = "DrawerLayoutAndroid component (supported only on Android).";
module ExampleContent = {
  type action;

  type state = {drawerRef: ref(option(ReasonReact.reactRef))};

  let setDrawerRef = (theRef, {ReasonReact.state}) =>
    state.drawerRef := Js.Nullable.toOption(theRef);

  let component = ReasonReact.reducerComponent("ExampleContent");

  let handleOpenPress = (_, {ReasonReact.state}) =>
    switch (state.drawerRef^) {
    | None => ()
    | Some(r) => ReasonReact.refToJsObj(r)##openDrawer()
    };

  let handleClosePress = (_, {ReasonReact.state}) =>
    switch (state.drawerRef^) {
    | None => ()
    | Some(r) => ReasonReact.refToJsObj(r)##closeDrawer()
    };

  let make = _children => {
    ...component,
    initialState: () => {drawerRef: ref(None)},
    reducer: (_action: action, _state: state) => ReasonReact.NoUpdate,
    render: self =>
      <DrawerLayoutAndroid
        renderNavigationView=(
          () =>
            <View>
              <Text> (ReasonReact.string("Drawer!")) </Text>
              <Button title="CLOSE" onPress=(self.handle(handleClosePress)) />
            </View>
        )
        ref=(self.handle(setDrawerRef))
        onDrawerClose=(() => Js.log("on close"))
        onDrawerOpen=(() => Js.log("on open"))
        onDrawerSlide=(() => Js.log("on slide"))
        onDrawerStateChanged=(x => Js.log(x))
        drawerWidth=250
        drawerPosition=`right
        drawerLockMode=`unlocked
        drawerBackgroundColor="#e6ecf0">
        <Button title="OPEN" onPress=(self.handle(handleOpenPress)) />
      </DrawerLayoutAndroid>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "DrawerLayoutAndroid",
    description: Some("Basic DrawerLayoutAndroid"),
    render: () => <ExampleContent />,
  },
|];