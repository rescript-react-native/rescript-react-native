[@bs.module "react-native"] external view: ReasonReact.reactClass = "Switch";

let make =
    (
      ~disabled: option(bool)=?,
      ~trackColorTrue: option(string)=?,
      ~trackColorFalse: option(string)=?,
      ~iosBackgroundColor: option(string)=?,
      ~onTintColor: option(string)=?,
      ~onValueChange: option(bool => unit)=?,
      ~thumbTintColor: option(string)=?,
      ~thumbColor: option(string)=?,
      ~tintColor: option(string)=?,
      ~value: option(bool)=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~style=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        {
          "value": value,
          "disabled": disabled,
          "onValueChange": onValueChange,
          "trackColor": {
            let d = Js.Dict.empty();
            Js.Dict.set(
              d,
              "true",
              Belt.Option.mapWithDefault(
                trackColorTrue,
                Js.Nullable.null,
                Js.Nullable.return,
              ),
            );
            Js.Dict.set(
              d,
              "false",
              Belt.Option.mapWithDefault(
                trackColorFalse,
                Js.Nullable.null,
                Js.Nullable.return,
              ),
            );
            d;
          },
          "ios_backgroundColor": iosBackgroundColor,
          "onTintColor": onTintColor,
          "thumbTintColor": thumbTintColor,
          "thumbColor": thumbColor,
          "tintColor": tintColor,
        },
        ~accessibilityLabel?,
        ~accessible?,
        ~hitSlop?,
        ~onAccessibilityTap?,
        ~onLayout?,
        ~onMagicTap?,
        ~responderHandlers?,
        ~pointerEvents?,
        ~removeClippedSubviews?,
        ~style?,
        ~testID?,
        ~accessibilityComponentType?,
        ~accessibilityLiveRegion?,
        ~collapsable?,
        ~importantForAccessibility?,
        ~needsOffscreenAlphaCompositing?,
        ~renderToHardwareTextureAndroid?,
        ~accessibilityTraits?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
