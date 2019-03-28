open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "listContainer": style([flex(1.0)]),
      "row":
        style([
          backgroundColor(String("white")),
          justifyContent(Center),
          paddingHorizontal(Pt(15.)),
          paddingVertical(Pt(8.)),
        ]),
      "rowTitleText": style([fontSize(Float(17.)), fontWeight(`_500)]),
      "rowDetailText":
        style([
          fontSize(Float(15.)),
          color(String("#888888")),
          lineHeight(20.),
        ]),
      "separator":
        style([
          height(Pt(StyleSheet.hairlineWidth)),
          backgroundColor(String("#bbbbbb")),
          marginLeft(Pt(15.)),
        ]),
      "separatorHighlighted":
        style([
          height(Pt(StyleSheet.hairlineWidth)),
          backgroundColor(String("rgb(217, 217, 217)")),
        ]),
    },
  );

let component = ReasonReact.statelessComponent("RNTesterExampleList");

let renderItem = onPress =>
  SectionList.renderItem(({item}) =>
    <TouchableHighlight onPress={_ => onPress(item)}>
      <View style=styles##row>
        <Text style=styles##rowTitleText>
          {ReasonReact.string(item.ExampleList.title)}
        </Text>
        <Text style=styles##rowDetailText>
          {ReasonReact.string(item.description)}
        </Text>
      </View>
    </TouchableHighlight>
  );

let itemSeparatorComponent =
  SectionList.separatorComponent(({highlighted}) =>
    <View
      style={highlighted ? styles##separatorHighlighted : styles##separator}
    />
  );

let make = (~components, ~onPress, _children) => {
  let sections =
    SectionList.sections([|
      SectionList.section(~data=components, ~key="components", ()),
    |]);
  {
    ...component,
    render: _self =>
      <View style=styles##listContainer>
        <SectionList
          sections
          renderItem={renderItem(onPress)}
          keyExtractor={(item, _) => item.key}
          itemSeparatorComponent
        />
      </View>,
  };
};
