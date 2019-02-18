open BsReactNative;
open Utils;

let onButtonPress = () => Alert.alert(~title="Button has been pressed!", ());

let exampleType = Multiple;

let displayName = "TouchableNativeFeedback";

let title = "<TouchableNativeFeedback>";

let description = "Simple React Native TouchableNativeFeedback component (only Android)";

module ExampleContent = {
  let component =
    ReasonReact.statelessComponent("TouchableNativeFeedbackExampleContent");

  let make = _children => {
    ...component,
    render: _children =>
      <TouchableNativeFeedback
        background={TouchableNativeFeedback.selectableBackground()}>
        <View style=Style.(style([backgroundColor(String("#03DAC5"))]))>
          <Text
            style=Style.(
              style([
                marginVertical(Pt(20.)),
                textAlign(Center),
                fontSize(Float(20.)),
              ])
            )>
            {ReasonReact.string("Press the button")}
          </Text>
        </View>
      </TouchableNativeFeedback>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "TouchableNativeFeedback",
    description: Some("Base example"),
    render: () => <ExampleContent />,
  },
|];
