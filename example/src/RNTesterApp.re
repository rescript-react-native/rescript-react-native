open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "header":
        style([
          height(Pt(60.)),
          borderBottomWidth(StyleSheet.hairlineWidth),
          borderBottomColor(String("#96969A")),
          backgroundColor(String("#F5F5F6")),
          alignItems(Center),
          justifyContent(Center),
          flexDirection(Row),
        ]),
      "headerLeft":
        style([
          position(Absolute),
          top(Pt(0.)),
          left(Pt(10.)),
          bottom(Pt(0.)),
          alignItems(Center),
          justifyContent(Center),
        ]),
      "headerCenter": style([flex(1.0)]),
      "title":
        style([
          fontSize(Float(19.)),
          fontWeight(`_600),
          textAlign(Center),
        ]),
      "exampleContainer": style([flex(1.0)]),
      "appContainer":
        style([
          flex(1.0),
          backgroundColor(String("#F5F5F6")),
          marginTop(Pt(Platform.os() == Platform.Android ? 20.0 : 0.0)),
        ]),
    },
  );

let header = (~onBack=?, ~title, ()) =>
  <View style=styles##header>
    <View style=styles##headerCenter>
      <Text style=styles##title> {ReasonReact.string(title)} </Text>
    </View>
    {switch (onBack) {
     | None => ReasonReact.null
     | Some(onBack) =>
       <View style=styles##headerLeft>
         <Button title="Back" onPress=onBack />
       </View>
     }}
  </View>;

type action =
  | ChangeCurrentExample(option(ExampleList.item));

type state = {currentExample: option(ExampleList.item)};

let component = ReasonReact.reducerComponent("RNTesterApp");

let make = _children => {
  ...component,
  initialState: () => {currentExample: None},
  reducer: (action, _state) =>
    switch (action) {
    | ChangeCurrentExample(example) => Update({currentExample: example})
    },
  didMount: self => {
    let handler = () => {
      let didHandleBackButton = ref(false);
      self.handle(
        (_, self) => {
          self.send(ChangeCurrentExample(None));
          didHandleBackButton := Js.Option.isSome(self.state.currentExample);
        },
        (),
      );
      didHandleBackButton^;
    };
    BackHandler.addEventListener("hardwareBackPress", handler);
    self.onUnmount(() =>
      BackHandler.removeEventListener("hardwareBackPress", handler)
    );
  },
  render: ({state, send}) => {
    let components = ExampleList.components;
    <SafeAreaView style=styles##appContainer>
      {switch (state.currentExample) {
       | None =>
         <View style=styles##exampleContainer>
           {header(~title="ReasonRNTester", ())}
           <RNTesterExampleList
             components
             onPress={item =>
               switch (state.currentExample) {
               | None => send(ChangeCurrentExample(Some(item)))
               | Some(_) => send(ChangeCurrentExample(None))
               }
             }
           />
         </View>
       | Some(example) when example.exampleType === FullScreen =>
         example.examples[0].render()
       | Some(example) =>
         <View style=styles##exampleContainer>
           {header(
              ~title=example.title,
              ~onBack=_event => send(ChangeCurrentExample(None)),
              (),
            )}
           <RNTesterExampleContainer example />
         </View>
       }}
    </SafeAreaView>;
  },
};

let reactComponentForJs =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
