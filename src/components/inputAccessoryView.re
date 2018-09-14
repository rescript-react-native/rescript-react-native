[@bs.module "react-native"]
external inputAccessoryView : ReasonReact.reactClass = "InputAccessoryView";

let make = (~backgroundColor=?, ~nativeID, ~style=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=inputAccessoryView,
    ~props=
      Js.Undefined.(
        {
          "backgroundColor": fromOption(backgroundColor),
          "nativeID": nativeID,
          "style": fromOption(style),
        }
      ),
  );
