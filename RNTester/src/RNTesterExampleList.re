open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "listContainer": style [flex 1.0],
        "row":
          style [
            backgroundColor "white",
            justifyContent `center,
            paddingHorizontal 15.,
            paddingVertical 8.
          ],
        "rowTitleText": style [fontSize 17., fontWeight `_500],
        "rowDetailText": style [fontSize 15., color "#888888", lineHeight 20.],
        "separator":
          style [height StyleSheet.hairlineWidth, backgroundColor "#bbbbbb", marginLeft 15.],
        "separatorHighlighted":
          style [height StyleSheet.hairlineWidth, backgroundColor "rgb(217, 217, 217)"]
      }
    );

include
  SectionList.CreateComponent {
    type item = ExampleList.item;
  };

let component = ReasonReact.statelessComponent "RNTesterExampleList";

let make = {
  let renderItem onPress {item} =>
    <TouchableHighlight onPress=(fun () => onPress item)>
      <View style=styles##row>
        <Text style=styles##rowTitleText> (ReasonReact.stringToElement item.title) </Text>
        <Text style=styles##rowDetailText> (ReasonReact.stringToElement item.description) </Text>
      </View>
    </TouchableHighlight>;
  let itemSeparatorComponent {highlighted} =>
    <View
      style=(
              if highlighted {
                styles##separatorHighlighted
              } else {
                styles##separator
              }
            )
    />;
  fun ::components ::onPress _children => {
    ...component,
    render: fun _state _self =>
      <View style=styles##listContainer>
        <SectionList
          sections=[|SectionList.section data::components key::"components" ()|]
          renderItem=(renderItem onPress)
          keyExtractor=(fun item _ => item.key)
          itemSeparatorComponent
        />
      </View>
  }
};