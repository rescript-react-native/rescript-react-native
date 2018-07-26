open Rebolt;
open Utils;

module InputAccessoryViewExampleBasic = {
  type state = {text: string};

  type action =
    | ChangeText(string)
    | Reset;

  let component =
    ReasonReact.reducerComponent("InputAccessoryViewExampleBasic");

  let make = _children => {
    ...component,
    initialState: () => {text: ""},
    reducer: (action, _state) =>
      switch (action) {
      | ChangeText(text) => ReasonReact.Update({text: text})
      | Reset => ReasonReact.Update({text: ""})
      },
    render: self =>
      <View>
        <ScrollView keyboardDismissMode=`interactive>
          <TextInput
            style=Style.(style([padding(Pt(10.)), paddingTop(Pt(50.))]))
            inputAccessoryViewID="test-input-accessory-view-id"
            onChangeText=(text => self.send(ChangeText(text)))
            value=self.state.text
          />
        </ScrollView>
        <InputAccessoryView nativeID="test-input-accessory-view-id">
          <Button onPress=(_event => self.send(Reset)) title="Reset Text" />
        </InputAccessoryView>
      </View>,
  };
};

let exampleType = Multiple;

let displayName = "InputAccessoryViewExample";

let title = "<InputAccessoryView>";

let description = "A component which enables customization of the keyboard input accessory view on iOS. The input accessory view is displayed above the keyboard whenever a TextInput has focus. This component can be used to create custom toolbars.";

let examples: array(Example.t) = [|
  {
    title: "InputAccessoryView",
    description: Some(""),
    render: () => <InputAccessoryViewExampleBasic />,
  },
|];
