open ReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "listContainer": style([flex(1.0)]),
        "row":
          style([
            backgroundColor("white"),
            justifyContent(`center),
            paddingHorizontal(15.),
            paddingVertical(8.)
          ]),
        "rowTitleText": style([fontSize(17.), fontWeight(`_500)]),
        "rowDetailText": style([fontSize(15.), color("#888888"), lineHeight(20.)]),
        "separator":
          style([height(StyleSheet.hairlineWidth), backgroundColor("#bbbbbb"), marginLeft(15.)]),
        "separatorHighlighted":
          style([height(StyleSheet.hairlineWidth), backgroundColor("rgb(217, 217, 217)")])
      }
    )
  );

let component = ReasonReact.statelessComponent("RNTesterExampleList");

let renderItem = (onPress) =>
  SectionList.renderItem(
    ({item}) =>
      <TouchableHighlight onPress=(() => onPress(item))>
        <View style=styles##row>
          <Text style=styles##rowTitleText>
            (ReasonReact.stringToElement(item.ExampleList.title))
          </Text>
          <Text style=styles##rowDetailText>
            (ReasonReact.stringToElement(item.description))
          </Text>
        </View>
      </TouchableHighlight>
  );

let itemSeparatorComponent =
  SectionList.separatorComponent(
    ({highlighted}) =>
      <View style=(highlighted ? styles##separatorHighlighted : styles##separator) />
  );

let make = (~components, ~onPress, _children) => {
  let sections =
    SectionList.sections([|SectionList.section(~data=components, ~key="components", ())|]);
  {
    ...component,
    render: (_self) =>
      <View style=styles##listContainer>
        <SectionList
          sections
          renderItem=(renderItem(onPress))
          keyExtractor=((item, _) => item.key)
          itemSeparatorComponent
        />
      </View>
  }
};
