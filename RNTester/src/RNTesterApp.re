open BsReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "header":
          style([
            height(Pt(60.)),
            borderBottomWidth(StyleSheet.hairlineWidth),
            borderBottomColor(String("#96969A")),
            backgroundColor(String("#F5F5F6")),
            flexDirection(Row),
            paddingTop(Pt(20.)),
          ]),
        "headerLeft": style([]),
        "headerCenter":
          style([
            flex(1.0),
            position(Absolute),
            top(Pt(27.)),
            left(Pt(0.)),
            right(Pt(0.)),
          ]),
        "title":
          style([
            fontSize(Float(19.)),
            fontWeight(`_600),
            textAlign(Center),
          ]),
        "exampleContainer": style([flex(1.0)]),
      }
    ),
  );

let header = (~onBack=?, ~title, ()) =>
  <View style=styles##header>
    <View style=styles##headerCenter>
      <Text style=styles##title> (ReasonReact.stringToElement(title)) </Text>
    </View>
    (
      switch (onBack) {
      | None => ReasonReact.nullElement
      | Some(onBack) =>
        <View style=styles##headerLeft>
          <Button title="Back" onPress=onBack />
        </View>
      }
    )
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
  render: ({state, send}) => {
    let components = ExampleList.components;
    switch (state.currentExample) {
    | None =>
      <View style=styles##exampleContainer>
        (header(~title="ReasonRNTester", ()))
        <RNTesterExampleList
          components
          onPress=(
            item =>
              switch (state.currentExample) {
              | None => send(ChangeCurrentExample(Some(item)))
              | Some(_) => send(ChangeCurrentExample(None))
              }
          )
        />
      </View>
    | Some(example) =>
      <View style=styles##exampleContainer>
        (
          header(
            ~title=example.title,
            ~onBack=_event => send(ChangeCurrentExample(None)),
            (),
          )
        )
        <RNTesterExampleContainer example />
      </View>
    };
  },
};

let reactClass =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));