[@bs.module "react-native"]
external pickerIOS : ReasonReact.reactClass = "PickerIOS";

module Item = {
  [@bs.scope "PickerIOS"] [@bs.module "react-native"]
  external item : ReasonReact.reactClass = "Item";
  let make = (~label, ~value=?, ~color=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        Js.Undefined.(
          {
            "label": label,
            "value": fromOption(value),
            "color": fromOption(color),
          }
        ),
    );
};

let make = (~itemStyle=?, ~onValueChange=?, ~selectedValue=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=pickerIOS,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "itemStyle": fromOption(itemStyle),
            "onValueChange": fromOption(onValueChange),
            "selectedValue": fromOption(selectedValue),
          }
        ),
      ),
  );