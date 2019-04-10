open Belt;
open ReactNative;

type pageData = {
  id: string,
  title: option(string),
  body: string,
};

let styles =
  StyleSheet.create(
    Style.{
      "container": style(~flex=1., ()),
      "title":
        style(
          ~fontSize=52.,
          ~fontWeight=`_700,
          ~color=Consts.Colors.darkless->color,
          (),
        ),
      "body": style(~display=`flex, ()),
    },
  );

[@react.component]
let make = (~pageData) => {
  <SpacedView style=styles##container vertical=SpacedView.L>
    <Text style=styles##title>
      {pageData.title->Option.getWithDefault(pageData.id)->React.string}
    </Text>
    <Spacer size=Spacer.XL />
    <Text style=styles##body>
      <div
        className="htmlContent"
        style={ReactDOMRe.Style.make(~flex="1", ~whiteSpace="normal", ())}
        dangerouslySetInnerHTML={"__html": pageData.body}
      />
    </Text>
  </SpacedView>;
};
