[@bs.module "react-native"] external button: ReasonReact.reactClass = "Button";

let make =
    (
      ~accessibilityLabel=?,
      ~color=?,
      ~disabled=?,
      ~onPress,
      ~testID=?,
      ~title,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=button,
    ~props={
      "accessibilityLabel": accessibilityLabel,
      "color": color,
      "disabled": disabled,
      "onPress": onPress,
      "testID": testID,
      "title": title,
    },
  );
