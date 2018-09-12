[@bs.module "react-native"]
external view : ReasonReact.reactClass = "TouchableWithoutFeedback";

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
        "onPressIn": onPressIn,
        "onPressOut": onPressOut,
        "pressRetentionOffset": pressRetentionOffset,
        "style": style,
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
