module View =
  ViewRe.CreateComponent {
    external view : ReactRe.reactClass =
      "View" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let view = view;
  };

module Image =
  ImageRe.CreateComponent {
    external view : ReactRe.reactClass =
      "Image" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let view = view;
  };

module Text =
  TextRe.CreateComponent {
    external view : ReactRe.reactClass =
      "Text" [@@bs.module "react-native"] [@@bs.scope "Animated"];
    let view = view;
  };

module ScrollView = {
  type callback = RNEvent.NativeEvent.t => unit;
  external wrapUpdaterShamelessly : AnimatedRe.animatedEvent => callback = "%identity";
  let onScrollUpdater ::x=? ::y=? ::native=false () =>
    wrapUpdaterShamelessly (
      AnimatedRe.event
        (
          Array.of_list [
            {
              "nativeEvent": {
                "contentOffset": {"x": Js.Undefined.from_opt x, "y": Js.Undefined.from_opt y}
              }
            }
          ]
        )
        {"useNativeDriver": Js.Boolean.to_js_boolean native}
    );
  include
    ScrollViewRe.CreateComponent {
      external view : ReactRe.reactClass =
        "ScrollView" [@@bs.module "react-native"] [@@bs.scope "Animated"];
      let view = view;
    };
};
