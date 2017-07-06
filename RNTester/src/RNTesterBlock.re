open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "container":
          style [
            borderRadius 3.,
            borderWidth 1.,
            borderColor "#d6d7da",
            backgroundColor "#ffffff",
            margin 10.,
            marginVertical 5.,
            overflow `hidden
          ],
        "titleContainer":
          style [
            borderBottomWidth 1.,
            borderTopLeftRadius 3.,
            borderTopRightRadius 3.,
            borderBottomColor "#d6d7da",
            backgroundColor "#f6f7f8",
            paddingHorizontal 10.,
            paddingVertical 5.
          ],
        "titleText": style [fontSize 14., fontWeight `_500],
        "descriptionText": style [fontSize 14.],
        "disclosure": style [position `absolute, top 0., right 0., padding 10.],
        "disclosureIcon": style [width 12., height 8.],
        "children": style [margin 10.]
      }
    );

let comp = ReasonReact.statelessComponent "RNTesterBlock";

let make ::description ::title children => {
  ...comp,
  render: fun _self =>
    <View style=styles##container>
      <View style=styles##titleContainer>
        <Text style=styles##titleText> (ReasonReact.stringToElement title) </Text>
        (
          switch description {
          | Some description =>
            <Text style=styles##descriptionText> (ReasonReact.stringToElement description) </Text>
          | None => ReasonReact.nullElement
          }
        )
      </View>
      (View.make style::styles##children children |> ReasonReact.element)
    </View>
};