open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "container": style([backgroundColor(String("#e9eaed")), flex(1.0)]),
      "spacer": style([height(Pt(270.))]),
      "wrapper": style([flex(1.0), paddingTop(Pt(10.))]),
    },
  );

let component = ReasonReact.statelessComponent("RNTesterPage");

let make = (~title=?, ~noScroll=false, ~noSpacer=false, children) => {
  let contentWrapper = (children_: array(ReasonReact.reactElement)) =>
    if (noScroll) {
      <View key="wrapper" style=styles##wrapper>
        {ReasonReact.array(children_)}
      </View>;
    } else {
      let automaticallyAdjustContentInsets =
        switch (title) {
        | Some(_) => true
        | None => false
        };
      <ScrollView
        key="wrapper"
        automaticallyAdjustContentInsets
        keyboardShouldPersistTaps=`handled
        keyboardDismissMode=`interactive
        style=styles##wrapper>
        {ReasonReact.array(children_)}
      </ScrollView>;
    };
  {
    ...component,
    render: _self => {
      let title =
        switch (title) {
        | Some(title) => <RNTesterTitle key="title" title />
        | None => ReasonReact.null
        };
      let spacer =
        if (noSpacer) {
          ReasonReact.null;
        } else {
          <View key="spacer" style=styles##spacer />;
        };
      <View style=styles##container>
        title
        {contentWrapper(Array.append(children, [|spacer|]))}
      </View>;
    },
  };
};
