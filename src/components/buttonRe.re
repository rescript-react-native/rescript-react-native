external button : ReactRe.reactClass = "Button" [@@bs.module "react-native"];

let createElement ::accessibilityLabel=? ::color=? ::disabled=? ::onPress=? ::testID=? ::title=? =>
  ReactRe.wrapPropsShamelessly
    button
    Js.Undefined.({
      "accessibilityLabel": from_opt accessibilityLabel,
      "color": from_opt color,
      "disabled": from_opt (UtilsRN.optBoolToOptJsBoolean disabled),
      "onPress": from_opt onPress,
      "testID": from_opt testID,
      "title": from_opt title
    });