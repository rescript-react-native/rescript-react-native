open Utils;

external button : ReactRe.reactClass = "Button" [@@bs.module "react-native"];

let createElement ::accessibilityLabel=? ::color=? ::disabled=? ::onPress=? ::testID=? ::title=? =>
  ReactRe.wrapPropsShamelessly
    button
    {
      "accessibilityLabel": from_opt accessibilityLabel,
      "color": from_opt color,
      "disabled": from_opt (option_map to_js_boolean disabled),
      "onPress": from_opt onPress,
      "testID": from_opt testID,
      "title": from_opt title
    };