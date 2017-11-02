[@bs.module "react-native"] external button : ReasonReact.reactClass = "Button";

let make = (~accessibilityLabel=?, ~color=?, ~disabled=?, ~onPress=?, ~testID=?, ~title=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=button,
    ~props=
      Js.Undefined.(
        {
          "accessibilityLabel": from_opt(accessibilityLabel),
          "color": from_opt(color),
          "disabled": from_opt(UtilsRN.optBoolToOptJsBoolean(disabled)),
          "onPress": from_opt(onPress),
          "testID": from_opt(testID),
          "title": from_opt(title)
        }
      )
  );
