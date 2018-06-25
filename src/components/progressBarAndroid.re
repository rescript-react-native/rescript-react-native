[@bs.module "react-native"]
external component : ReasonReact.reactClass = "ProgressBarAndroid";

let style = attr =>
  switch (attr) {
  | `Horizontal => "Horizontal"
  | `Normal => "Normal"
  | `Small => "Small"
  | `Large => "Large"
  | `Inverse => "Inverse"
  | `SmallInverse => "SmallInverse"
  | `LargeInverse => "LargeInverse"
  };

let make =
    (
      ~color=?,
      ~animating=?,
      ~indeterminate=?,
      ~progress=?,
      ~styleAttr=?,
      ~testID=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=component,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "color": fromOption(color),
            "animating": fromOption(animating),
            "indeterminate": fromOption(indeterminate),
            "progress": fromOption(progress),
            "styleAttr": fromOption(UtilsRN.option_map(style, styleAttr)),
            "testID": fromOption(testID),
          }
        ),
      ),
  );