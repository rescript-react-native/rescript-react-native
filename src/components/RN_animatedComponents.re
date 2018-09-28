module View =
  RN_view.CreateComponent({
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external view: ReasonReact.reactClass = "View";
    let view = view;
  });

module Image =
  RN_image.CreateComponent({
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external view: ReasonReact.reactClass = "Image";
    let view = view;
  });

module FlatList =
  RN_flatList.CreateComponent({
    [@bs.module "react-native"]
    external nonAnimatedView: ReasonReact.reactClass = "FlatList";
    let view = RN_animatedRe.createAnimatedComponent(nonAnimatedView);
  });

module Text =
  RN_text.CreateComponent({
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external view: ReasonReact.reactClass = "Text";
    let view = view;
  });

module ScrollView = {
  type callback = RN_Event.NativeScrollEvent.t => unit;
  external wrapUpdaterShamelessly: RN_animatedRe.animatedEvent => callback =
    "%identity";
  let onScrollUpdater = (~x=?, ~y=?, ~native=false, ()) =>
    wrapUpdaterShamelessly(
      RN_animatedRe.event(
        [|
          {
            "nativeEvent": {
              "contentOffset": {
                "x": Js.Undefined.fromOption(x),
                "y": Js.Undefined.fromOption(y),
              },
            },
          },
        |],
        {"useNativeDriver": native},
      ),
    );
  include RN_scrollView.CreateComponent({
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external view: ReasonReact.reactClass = "ScrollView";
    let view = view;
  });
};