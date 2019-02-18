open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "container":
        style([
          borderRadius(4.),
          borderWidth(1.),
          borderColor(String("#d6d7da")),
          margin(Pt(10.)),
          marginBottom(Pt(0.)),
          height(Pt(45.)),
          padding(Pt(10.)),
          backgroundColor(String("white")),
        ]),
      "text": style([fontSize(Float(19.)), fontWeight(`_500)]),
    },
  );

let component = ReasonReact.statelessComponent("RNTesterTitle");

let make = (~title, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text style=styles##text> {ReasonReact.string(title)} </Text>
    </View>,
};
