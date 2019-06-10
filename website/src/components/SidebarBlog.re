open Belt;
open ReactNative;
open ReactMultiversal;

let styles =
  StyleSheet.create(
    Style.{
      "container": style(~height=100.->pct, ~overflow=`scroll, ()),
      "title": style(~fontSize=16., ~fontWeight=`_600, ~color="#333", ()),
      "link":
        style(
          ~fontSize=14.,
          ~fontWeight=`_400,
          ~color="#555",
          ~paddingVertical=(Spacer.space /. 4.)->dp,
          (),
        ),
      "notlink":
        style(
          ~fontSize=14.,
          ~fontWeight=`_400,
          ~color="#ddd",
          ~paddingVertical=(Spacer.space /. 4.)->dp,
          (),
        ),
    },
  );

type item = (string, string);

let makeSections =
    (sections: list(Consts.section))
    : array(VirtualizedSectionList.section(item)) => {
  sections
  ->List.toArray
  ->Array.map(section =>
      {
        "key": Some(section.title),
        "data": section.data->List.toArray,
        "renderItem": None,
        "ItemSeparatorComponent": None,
        "keyExtractor": None,
      }
    );
};

let sections = makeSections(Consts.sections);

[@react.component]
let make = (~blogIndex) => {
  <SpacedView>
    <SpacedView vertical=SpacedView.M horizontal=SpacedView.None>
      <Text style=styles##title>
        {"Recent posts"->String.uppercase->React.string}
      </Text>
    </SpacedView>
    {{blogIndex->Array.map(indexEntry =>
        <TextLink
          key=indexEntry##title
          href={Consts.baseUrl ++ "/en/blog/" ++ indexEntry##id}
          style=styles##link>
          {indexEntry##title->React.string}
        </TextLink>
      )}
     ->React.array}
    <Spacer size=Spacer.S />
  </SpacedView>;
};
