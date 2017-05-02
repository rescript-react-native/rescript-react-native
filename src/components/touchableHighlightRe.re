open Utils;

external view : ReactRe.reactClass = "TouchableHighlight" [@@bs.module "react-native"];

let createElement
    ::accessible=?
    ::accessibilityComponentType=?
    ::accessibilityTraits=?
    ::delayLongPress=?
    ::delayPressIn=?
    ::delayPressOut=?
    ::disabled=?
    ::hitSlop=?
    ::onLayout=?
    ::onPress=?
    ::onPressIn=?
    ::onPressOut=?
    ::pressRetentionOffset=?
    ::activeOpacity=?
    ::onHideUnderlay=?
    ::onShowUnderlay=?
    ::style=?
    ::underlayColor=?
    ::hasTVPreferredFocus=?
    ::tvParallaxProperties=? =>
  ReactRe.wrapPropsShamelessly
    view
    {
      "accessible": from_opt (option_map to_js_boolean accessible),
      "delayLongPress": from_opt delayLongPress,
      "delayPressIn": from_opt delayPressIn,
      "delayPressOut": from_opt delayPressOut,
      "disabled": from_opt (option_map to_js_boolean disabled),
      "hitSlop": from_opt hitSlop,
      "onLayout": from_opt onLayout,
      "onPress": from_opt onPress,
      "onPressIn": from_opt onPressIn,
      "onPressOut": from_opt onPressOut,
      "pressRetentionOffset": from_opt pressRetentionOffset,
      "accessibilityComponentType":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `none => "none"
                | `button => "button"
                | `radiobutton_checked => "radiobutton_checked-none"
                | `radiobutton_unchecked => "radiobutton_unchecked"
                }
            )
            accessibilityComponentType
        ),
      "accessibilityTraits":
        from_opt (
          option_map
            (
              fun traits => {
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
                traits |> List.map to_string |> Array.of_list
              }
            )
            accessibilityTraits
        ),
      "activeOpacity": from_opt activeOpacity,
      "onHideUnderlay": from_opt onHideUnderlay,
      "onShowUnderlay": from_opt onShowUnderlay,
      "style": from_opt style,
      "underlayColor": from_opt underlayColor,
      "hasTVPreferredFocus": from_opt (option_map to_js_boolean hasTVPreferredFocus),
      "tvParallaxProperties": from_opt tvParallaxProperties
    };