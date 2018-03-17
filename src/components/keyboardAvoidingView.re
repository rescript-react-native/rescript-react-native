[@bs.deriving jsConverter]
type behavior = [ | `height | `position | `padding];

[@bs.module "react-native"]
external keyboardAvoidingView : ReasonReact.reactClass =
  "KeyboardAvoidingView";

let make =
    (
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
      ~keyboardVerticalOffset=?,
      ~behavior=?,
      ~contentContainerStyle=?,
      ~relativeKeyboardHeight=?,
      ~onKeyboardChange=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=keyboardAvoidingView,
    ~props=
      Js.Undefined.(
        Props.extendView(
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
          {
            "keyboardVerticalOffset": fromOption(keyboardVerticalOffset),
            "behavior":
              fromOption(UtilsRN.option_map(behaviorToJs, behavior)),
            "contentContainerStyle": fromOption(contentContainerStyle),
            "relativeKeyboardHeight": fromOption(relativeKeyboardHeight),
            "onKeyboardChange": fromOption(onKeyboardChange),
          },
        )
      ),
  );
