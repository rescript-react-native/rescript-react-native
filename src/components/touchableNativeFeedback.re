[@bs.module "react-native"]
external view : ReasonReact.reactClass = "TouchableNativeFeedback";

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
      ~style=?,
      ~background=?,
      ~useForeground=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      {
        "accessible": accessible,
        "accessibilityLabel": accessibilityLabel,
        "delayLongPress": delayLongPress,
        "delayPressIn": delayPressIn,
        "delayPressOut": delayPressOut,
        "disabled": disabled,
        "hitSlop": hitSlop,
        "onLayout": onLayout,
        "onLongPress": onLongPress,
        "onPress": onPress,
        "background": background,
        "onPressIn": onPressIn,
        "onPressOut": onPressOut,
        "pressRetentionOffset": pressRetentionOffset,
        "style": style,
        "useForeground": useForeground,
        "accessibilityComponentType":
          UtilsRN.option_map(
            x =>
              switch (x) {
              | `none => "none"
              | `button => "button"
              | `radiobutton_checked => "radiobutton_checked-none"
              | `radiobutton_unchecked => "radiobutton_unchecked"
              },
            accessibilityComponentType,
          ),
        "accessibilityTraits":
          UtilsRN.option_map(
            traits => {
              let to_string =
                fun
                | `none => "none"
                | `button => "button"
                | `link => "link"
                | `header => "header"
                | `search => "search"
                | `image => "image"
                | `selected => "selected"
                | `plays => "plays"
                | `key => "key"
                | `text => "text"
                | `summary => "summary"
                | `disabled => "disabled"
                | `frequentUpdates => "frequentUpdates"
                | `startsMedia => "startsMedia"
                | `adjustable => "adjustable"
                | `allowsDirectInteraction => "allowsDirectInteraction"
                | `pageTurn => "pageTurn";
              traits |> List.map(to_string) |> Array.of_list;
            },
            accessibilityTraits,
          ),
      },
  );
