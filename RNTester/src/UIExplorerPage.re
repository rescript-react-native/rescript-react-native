open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "container": style [backgroundColor "#e9eaed", flex 1.0],
        "spacer": style [height 270],
        "wrapper": style [flex 1.0, paddingTop 10]
      }
    );

module UIEXplorerPage = {
  include ReactRe.Component;
  let name = "UIExplorerPage";
  type props = {
    noScroll: bool,
    noSpacer: bool,
    children: list ReactRe.reactElement,
    title: option string
  };
  let contentWrapper props children =>
    if props.noScroll {
      <View key="wrapper" style=styles##wrapper> (ReactRe.listToElement children) </View>
    } else {
      let automaticallyAdjustContentInsets =
        switch props.title {
        | Some _ => true
        | None => false
        };
      <ScrollView
      key="wrapper" 
        automaticallyAdjustContentInsets
        keyboardShouldPersistTaps=`handled
        keyboardDismissMode=`interactive
        style=styles##wrapper>
        (ReactRe.listToElement children)
      </ScrollView> 
    };
  let render {props} => {
    let title =
      switch props.title {
      | Some title => <UIExplorerTitle key="title" title />
      | None => ReactRe.nullElement
      };
    let spacer =
      if props.noSpacer {
        ReactRe.nullElement
      } else {
        <View key="spacer" style=styles##spacer />
      };
    <View style=styles##container>
      (ReactRe.listToElement [title, contentWrapper props (props.children @ [spacer])])
    </View>
  };
};

include ReactRe.CreateComponent UIEXplorerPage;

let createElement ::title=? ::noScroll=? ::noSpacer=? ::children =>
  wrapProps
    {
      title,
      noScroll:
        switch noScroll {
        | Some noScroll => noScroll
        | None => false
        },
      noSpacer:
        switch noSpacer {
        | Some noSpacer => noSpacer
        | None => false
        },
      children
    }
    ::children;