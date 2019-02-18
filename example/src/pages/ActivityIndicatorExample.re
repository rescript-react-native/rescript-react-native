open BsReactNative;
open Utils;

let exampleType = Multiple;

let displayName = "ActivityIndicator";

let title = "<ActivityIndicator>";

let description = "Simple React Native ActivityIndicator component.";

module ActivityIndicatorExample = {
  let component = ReasonReact.statelessComponent("ActivityIndicatorExample");
  let make = _children => {
    ...component,
    render: _self =>
      <View>
        <ActivityIndicator color={String("#0000ff")} size={`exact(40)} />
      </View>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "ActivityIndicator example",
    description: None,
    render: () => <ActivityIndicatorExample />,
  },
|];
