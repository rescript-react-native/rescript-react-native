open BsReactNative;
open Utils;

let exampleType = Multiple;

let displayName = "ProgressBarAndroid";

let title = "<ProgressBarAndroid>";

let description = "Simple React Native ProgressBarAndroid component (only Android)";

module ExampleHorizontal = {
  let component = ReasonReact.statelessComponent("ExampleHorizontal");

  let make = _children => {
    ...component,
    render: _children =>
      <View>
        <ProgressBarAndroid styleAttr=`Horizontal />
        <ProgressBarAndroid styleAttr=`Horizontal color="#2196F3" />
        <ProgressBarAndroid
          styleAttr=`Horizontal
          indeterminate=false
          progress=0.5
        />
      </View>,
  };
};

module ExampleInverse = {
  let component = ReasonReact.statelessComponent("ExampleInverse");

  let make = _children => {
    ...component,
    render: _children =>
      <View>
        <ProgressBarAndroid styleAttr=`Inverse />
        <ProgressBarAndroid styleAttr=`Inverse color="#2196F3" />
        <ProgressBarAndroid styleAttr=`Inverse progress=0.5 />
      </View>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "Horizontal",
    description: Some("ProgressBarAndroid with Horizontal styleAttr"),
    render: () => <ExampleHorizontal />,
  },
  {
    title: "Inverse",
    description: Some("ProgressBarAndroid with Inverse styleAttr"),
    render: () => <ExampleInverse />,
  },
|];
