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
      ~onLongPress=?,
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
      {
        "accessible": accessible,
        "accessibilityLabel": accessibilityLabel,
        "delayLongPress": delayLongPress,
        "delayPressIn": delayPressIn,
        "delayPressOut": delayPressOut,
        "disabled": disabled,
        "hitSlop": hitSlop,
        "style": style,
        "onLayout": onLayout,
        "onPress": onPress,
        "onLongPress": onLongPress,
        "onPressIn": onPressIn,
        "onPressOut": onPressOut,
        "pressRetentionOffset": pressRetentionOffset,
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
        "focusedOpacity": focusedOpacity,
        "activeOpacity": activeOpacity,
        "tvParallaxProperties": tvParallaxProperties,
      },
  );
