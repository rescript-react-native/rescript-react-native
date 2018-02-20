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
      ~style=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Js.Undefined.(
        {
          "accessible": fromOption(UtilsRN.optBoolToOptJsBoolean(accessible)),
          "accessibilityLabel": fromOption(accessibilityLabel),
          "delayLongPress": fromOption(delayLongPress),
          "delayPressIn": fromOption(delayPressIn),
          "delayPressOut": fromOption(delayPressOut),
          "disabled": fromOption(UtilsRN.optBoolToOptJsBoolean(disabled)),
          "hitSlop": fromOption(hitSlop),
          "onLayout": fromOption(onLayout),
          "onLongPress": fromOption(onLongPress),
          "onPress": fromOption(onPress),
          "onPressIn": fromOption(onPressIn),
          "onPressOut": fromOption(onPressOut),
          "pressRetentionOffset": fromOption(pressRetentionOffset),
          "style": fromOption(style),
          "accessibilityComponentType":
            fromOption(
              UtilsRN.option_map(
                x =>
                  switch x {
                  | `none => "none"
                  | `button => "button"
                  | `radiobutton_checked => "radiobutton_checked-none"
                  | `radiobutton_unchecked => "radiobutton_unchecked"
                  },
                accessibilityComponentType
              )
            ),
          "accessibilityTraits":
            fromOption(
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
                accessibilityTraits
              )
            )
        }
      )
  );
