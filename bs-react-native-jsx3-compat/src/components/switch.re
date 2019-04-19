open Belt;

[@bs.module "react-native"] external view: ReasonReact.reactClass = "Switch";

let make =
    (
      ~disabled: option(bool)=?,
      ~trackColorTrue: option(string)=?,
      ~trackColorFalse: option(string)=?,
      ~iosBackgroundColor: option(string)=?,
      ~onValueChange: option(bool => unit)=?,
      ~thumbColor: option(string)=?,
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
      ~accessibilityRole=?,
      ~accessibilityStates=?,
      ~accessibilityHint=?,
      ~accessibilityIgnoresInvertColors=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      ViewProps.extend(
        {
          "value": value,
          "disabled": disabled,
          "onValueChange": onValueChange,
          "trackColor": {
            "true":
              trackColorTrue->Option.mapWithDefault(
                Js.Nullable.null,
                Js.Nullable.return,
              ),
            "false":
              trackColorFalse->Option.mapWithDefault(
                Js.Nullable.null,
                Js.Nullable.return,
              ),
          },
          "ios_backgroundColor": iosBackgroundColor,
          "thumbColor": thumbColor,
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
        ~accessibilityRole?,
        ~accessibilityStates?,
        ~accessibilityHint?,
        ~accessibilityIgnoresInvertColors?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
