open BsReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container":
          style([
            borderRadius(3.),
            borderWidth(1.),
            borderColor("#d6d7da"),
            backgroundColor("#ffffff"),
            margin(Px(10.)),
            marginVertical(Px(5.)),
            overflow(`Hidden)
          ]),
        "titleContainer":
          style([
            borderBottomWidth(1.),
            borderTopLeftRadius(3.),
            borderTopRightRadius(3.),
            borderBottomColor("#d6d7da"),
            backgroundColor("#f6f7f8"),
            paddingHorizontal(Px(10.)),
            paddingVertical(Px(5.))
          ]),
        "titleText": style([fontSize(14.), fontWeight(`_500)]),
        "descriptionText": style([fontSize(14.)]),
        "disclosure":
          style([position(`Absolute), top(Px(0.)), right(Px(0.)), padding(Px(10.))]),
        "disclosureIcon": style([width(Px(12.)), height(Px(8.))]),
        "children": style([margin(Px(10.))])
      }
    )
  );

let comp = ReasonReact.statelessComponent("RNTesterBlock");

let make = (~description, ~title, children) => {
  ...comp,
  render: (_self) =>
    <View style=styles##container>
      <View style=styles##titleContainer>
        <Text style=styles##titleText> (ReasonReact.stringToElement(title)) </Text>
        (
          switch description {
          | Some(description) =>
            <Text style=styles##descriptionText>
              (ReasonReact.stringToElement(description))
            </Text>
          | None => ReasonReact.nullElement
          }
        )
      </View>
      (View.make(~style=styles##children, children) |> ReasonReact.element)
    </View>
};
