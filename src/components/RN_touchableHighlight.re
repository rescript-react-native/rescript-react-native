[@bs.module "react-native"]
external view : ReasonReact.reactClass = "TouchableHighlight";

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
      ~onPress=?,
      ~onPressIn=?,
      ~onPressOut=?,
      ~pressRetentionOffset=?,
      ~activeOpacity=?,
      ~onHideUnderlay=?,
      ~onShowUnderlay=?,
      ~style=?,
      ~underlayColor=?,
      ~hasTVPreferredFocus=?,
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
        "onLayout": onLayout,
        "onPress": onPress,
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
        "activeOpacity": activeOpacity,
        "onHideUnderlay": onHideUnderlay,
        "onShowUnderlay": onShowUnderlay,
        "style": style,
        "underlayColor": underlayColor,
        "hasTVPreferredFocus": hasTVPreferredFocus,
        "tvParallaxProperties": tvParallaxProperties,
      },
  );
