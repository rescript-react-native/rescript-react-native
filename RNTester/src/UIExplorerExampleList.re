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
            paddingHorizontal 15,
            paddingVertical 8
          ],
        "rowTitleText": style [fontSize 17, fontWeight `_500],
        "rowDetailText": style [fontSize 15, color "#888888", lineHeight 20],
        "separator":
          style [height StyleSheet.hairlineWidth, backgroundColor "#bbbbbb", marginLeft 15],
        "separatorHighlighted":
          style [height StyleSheet.hairlineWidth, backgroundColor "rgb(217, 217, 217)"]
      }
    );

module UIExplorerExampleList = {
  include ReactRe.Component;
  include
    SectionList.CreateComponent {
      type item = ExampleList.item;
    };
  type props = {onPress: ExampleList.item => unit, components: array ExampleList.item};
  let name = "UIExplorerExampleList";
  let renderItem onPress {item} =>
    <TouchableHighlight onPress=(fun () => onPress item)>
      <View style=styles##row>
        <Text style=styles##rowTitleText> (ReactRe.stringToElement item.title) </Text>
        <Text style=styles##rowDetailText> (ReactRe.stringToElement item.description) </Text>
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
  let render {props} =>
    <View style=styles##listContainer>
      <SectionList
        sections=[|SectionList.section data::props.components key::"components" ()|]
        renderItem=(renderItem props.onPress)
        keyExtractor=(fun item _ => item.key)
        itemSeparatorComponent
      />
    </View>;
};

include ReactRe.CreateComponent UIExplorerExampleList;

let createElement ::components ::onPress => wrapProps {components, onPress};