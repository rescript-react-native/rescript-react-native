open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "header":
          style [
            height 60,
            borderBottomWidth StyleSheet.hairlineWidth,
            borderBottomColor "#96969A",
            backgroundColor "#F5F5F6",
            flexDirection `row,
            paddingTop 20
          ],
        "headerLeft": style [],
        "headerCenter": style [flex 1.0, position `absolute, top 27, left 0, right 0],
        "title": style [fontSize 19, fontWeight `_600, textAlign `center],
        "exampleContainer": style [flex 1.0]
      }
    );

let header ::onBack=? ::title () =>
  <View style=styles##header>
    <View style=styles##headerCenter>
      <Text style=styles##title> (ReactRe.stringToElement title) </Text>
    </View>
    (
      switch onBack {
      | None => ReactRe.nullElement
      | Some onBack =>
        <View style=styles##headerLeft> <Button title="Back" onPress=onBack /> </View>
      }
    )
  </View>;

module UIExplorerApp = {
  include ReactRe.Component.Stateful.JsProps;
  let name = "UIExplorerApp";
  type props = unit;
  type state = {currentExample: option ExampleList.item};
  let getInitialState () => {currentExample: None};
  type jsProps = option (unit => unit);
  let jsPropsToReasonProps = Some (fun _ => ());
  let onPress {state} item =>
    switch state.currentExample {
    | None => Some {currentExample: Some item}
    | Some _ => Some {currentExample: None}
    };
  let onBack _ () => Some {currentExample: None};
  let render {state, updater} => {
    let components = ExampleList.components;
    switch state.currentExample {
    | None =>
      <View style=styles##exampleContainer>
        (header title::"ReasonUIExplorer" ())
        <UIExplorerExampleList components onPress=(updater onPress) />
      </View>
    | Some example =>
      <View style=styles##exampleContainer>
        (header title::example.title onBack::(updater onBack) ())
        <UIExplorerExampleContainer example />
      </View>
    }
  };
};

include ReactRe.CreateComponent UIExplorerApp;

let createElement = wrapProps ();