[@bs.module "react-native"]
external view : ReasonReact.reactClass = "TouchableNativeFeedback";

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
    ~reactClass=view,
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