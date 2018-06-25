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
      ~delayLongPress=?,
      ~delayPressIn=?,
      ~delayPressOut=?,
      ~disabled=?,
      ~hitSlop=?,
      ~onLayout=?,
      ~onLongPress=?,
      ~onPress=?,
      ~onPressIn=?,
      ~onPressOut=?,
      ~pressRetentionOffset=?,
      ~background=?,
      ~useForeground=?,
      ~style=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=component,
    ~props=
      Js.Undefined.(
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
          "style": fromOption(style),
        }
      ),
  );