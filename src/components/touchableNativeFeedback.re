[@bs.module "react-native"]
external component : ReasonReact.reactClass = "TouchableNativeFeedback";

type t;

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external selectableBackground : unit => t = "SelectableBackground";

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external selectableBackgroundBorderless : unit => t =
  "SelectableBackgroundBorderless";

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external canUseNativeForeground : unit => t = "CanUseNativeForeground";

[@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
external ripple : (string, bool) => t = "Ripple";

let make =
    (
      ~accessible=?,
      ~accessibilityLabel=?,
      ~accessibilityComponentType=?,
      ~accessibilityTraits=?,
      ~onAccessibilityTap=?,
      ~delayLongPress=?,
      ~delayPressIn=?,
      ~delayPressOut=?,
      ~disabled=?,
      ~hitSlop=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~onLongPress=?,
      ~onPress=?,
      ~onPressIn=?,
      ~onPressOut=?,
      ~pressRetentionOffset=?,
      ~background=?,
      ~useForeground=?,
      ~style=?,
      ~testID=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=component,
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
            "accessible": fromOption(accessible),
            "accessibilityLabel": fromOption(accessibilityLabel),
            "accessibilityComponentType":
              fromOption(accessibilityComponentType),
            "accessibilityTraits": fromOption(accessibilityTraits),
            "delayLongPress": fromOption(delayLongPress),
            "delayPressIn": fromOption(delayPressIn),
            "delayPressOut": fromOption(delayPressOut),
            "disabled": fromOption(disabled),
            "hitSlop": fromOption(hitSlop),
            "onLayout": fromOption(onLayout),
            "onLongPress": fromOption(onLongPress),
            "onPress": fromOption(onPress),
            "onPressIn": fromOption(onPressIn),
            "onPressOut": fromOption(onPressOut),
            "pressRetentionOffset": fromOption(pressRetentionOffset),
            "background": fromOption(background),
            "useForeground": fromOption(useForeground),
          },
        )
      ),
  );
