open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "container":
          style [
            borderRadius 4,
            borderWidth 1,
            borderColor "#d6d7da",
            margin 10,
            marginBottom 0,
            height 45,
            padding 10,
            backgroundColor "white"
          ],
        "text": style [fontSize 19, fontWeight `_500]
      }
    ); 

module RNTesterTitle = {
  include ReactRe.Component;
  let name = "RNTesterTitle";
  type props = {title: string};
  let render {props} =>
    <View style=styles##container>
      <Text style=styles##text> (ReactRe.stringToElement props.title) </Text>
    </View>;
};

include ReactRe.CreateComponent RNTesterTitle;

let createElement ::title => wrapProps {title: title};