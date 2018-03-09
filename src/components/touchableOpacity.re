[@bs.module "react-native"]
external view : ReasonReact.reactClass = "TouchableOpacity";

[@bs.send]
external setOpacityTo : (ReasonReact.reactRef, float, int) => unit =
  "setOpacityTo";

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
      ~style=?,
      ~onLayout=?,
      ~onPress=?,
      ~onPressIn=?,
      ~onPressOut=?,
      ~pressRetentionOffset=?,
      ~activeOpacity=?,
      ~focusedOpacity=?,
      ~tvParallaxProperties=?,
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
          "style": fromOption(style),
          "onLayout": fromOption(onLayout),
          "onPress": fromOption(onPress),
          "onPressIn": fromOption(onPressIn),
          "onPressOut": fromOption(onPressOut),
          "pressRetentionOffset": fromOption(pressRetentionOffset),
          "accessibilityComponentType":
            fromOption(
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
                accessibilityTraits,
              ),
            ),
          "focusedOpacity": fromOption(focusedOpacity),
          "activeOpacity": fromOption(activeOpacity),
          "tvParallaxProperties": fromOption(tvParallaxProperties),
        }
      ),
  );
