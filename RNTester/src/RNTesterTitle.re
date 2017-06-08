open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "container":
          style [
            borderRadius 4.,
            borderWidth 1.,
            borderColor "#d6d7da",
            margin 10.,
            marginBottom 0.,
            height 45.,
            padding 10.,
            backgroundColor "white"
          ],
        "text": style [fontSize 19., fontWeight `_500]
      }
    );

let component = ReasonReact.statelessComponent "RNTesterTitle";

let make ::title _children => {
  ...component,
  render: fun _state _self =>
    <View style=styles##container>
      <Text style=styles##text> (ReasonReact.stringToElement title) </Text>
    </View>
};