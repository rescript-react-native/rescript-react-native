/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * Converted from https://github.com/facebook/react-native/blob/d752446b23e0a12171ca0c01d20f5be625f40455/template/App.js
 */
open BsReactNative;

let instructions =
  switch (Platform.os()) {
  | IOS(_) => "Press Cmd+R to reload,\n" ++ "Cmd+D or shake for dev menu"
  | Android =>
    "Double tap R on your keyboard to reload,\n"
    ++ "Shake or press menu button for dev menu"
  | exception (Platform.UnknownPlatform(p)) when p == "web" => "Press Cmd+R to reload."
  | exception (Platform.UnknownPlatform(_p)) => ""
  };

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style([
          flex(1.),
          justifyContent(Center),
          alignItems(Center),
          backgroundColor(String("#F5FCFF")),
        ]),
      "welcome":
        style([
          fontSize(Float(20.)),
          textAlign(Center),
          margin(Pt(10.)),
        ]),
      "instructions":
        style([
          textAlign(Center),
          color(String("#333333")),
          marginBottom(Pt(5.)),
        ]),
    })
  );

let app = () =>
  <View
    style={
      styles##container;
    }>
    <Text style={styles##welcome}>
      "Welcome to (Bs) React Native!"->ReasonReact.string
    </Text>
    <Text style={styles##instructions}>
      "To get started, edit src/App.re"->ReasonReact.string
    </Text>
    <Text style={styles##instructions}>
      instructions->ReasonReact.string
    </Text>
  </View>;
