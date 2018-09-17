open BsReactNative;
open Utils;

let exampleType = FullScreen;

let displayName = "TextInputExample";

let title = "<TextInput>";

let description = "Simple React Native text input component.";

let examples: array(Example.t) = [|
  {
    title: "Simple TextInput",
    description:
      Some("Checking a simple TextInput with onKeyPress handler works"),
    render: () =>
      <TextInput onKeyPress=(ev => Js.log(ev##nativeEvent##key)) />,
  },
|];
