[@bs.module "react-native"]
external button : ReasonReact.reactClass = "Button";

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
    ~props=
      Js.Undefined.(
        {
          "accessibilityLabel": fromOption(accessibilityLabel),
          "color": fromOption(color),
          "disabled": fromOption(UtilsRN.optBoolToOptJsBoolean(disabled)),
          "onPress": onPress,
          "testID": fromOption(testID),
          "title": title,
        }
      ),
  );
