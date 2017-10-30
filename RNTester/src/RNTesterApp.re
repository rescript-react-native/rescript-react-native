open ReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "header":
          style([
            height(60.),
            borderBottomWidth(StyleSheet.hairlineWidth),
            borderBottomColor("#96969A"),
            backgroundColor("#F5F5F6"),
            flexDirection(`row),
            paddingTop(20.)
          ]),
        "headerLeft": style([]),
        "headerCenter": style([flex(1.0), position(`absolute), top(27.), left(0.), right(0.)]),
        "title": style([fontSize(19.), fontWeight(`_600), textAlign(`center)]),
        "exampleContainer": style([flex(1.0)])
      }
    )
  );

let header = (~onBack=?, ~title, ()) =>
  <View style=styles##header>
    <View style=styles##headerCenter>
      <Text style=styles##title> (ReasonReact.stringToElement(title)) </Text>
    </View>
    (
      switch onBack {
      | None => ReasonReact.nullElement
      | Some(onBack) =>
        <View style=styles##headerLeft> <Button title="Back" onPress=onBack /> </View>
      }
    )
  </View>;

type state = {currentExample: option(ExampleList.item)};

let component = ReasonReact.statefulComponent("RNTesterApp");

let make = (_children) => {
  let onPress = (item, {ReasonReact.state}) =>
    switch state.currentExample {
    | None => ReasonReact.Update({currentExample: Some(item)})
    | Some(_) => ReasonReact.Update({currentExample: None})
    };
  let onBack = ((), _self) => ReasonReact.Update({currentExample: None});
  {
    ...component,
    initialState: () => {currentExample: None},
    render: ({state, update}) => {
      let components = ExampleList.components;
      switch state.currentExample {
      | None =>
        <View style=styles##exampleContainer>
          (header(~title="ReasonRNTester", ()))
          <RNTesterExampleList components onPress=(update(onPress)) />
        </View>
      | Some(example) =>
        <View style=styles##exampleContainer>
          (header(~title=example.title, ~onBack=update(onBack), ()))
          <RNTesterExampleContainer example />
        </View>
      }
    }
  }
};

let reactClass = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
