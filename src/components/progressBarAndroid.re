[@bs.module "react-native"]
external component : ReasonReact.reactClass = "ProgressBarAndroid";

let style = attr =>
  switch (attr) {
  | `Horizontal => "Horizontal"
  | `Inverse => "Inverse"
  | `Large => "Large"
  | `LargeInverse => "LargeInverse"
  | `Normal => "Normal"
  | `Small => "Small"
  | `SmallInverse => "SmallInverse"
  };

let make =
    (
      ~animating=?,
      ~color=?,
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
            "animating": fromOption(animating),
            "color": fromOption(color),
            "indeterminate": fromOption(indeterminate),
            "progress": fromOption(progress),
            "styleAttr": fromOption(UtilsRN.option_map(style, styleAttr)),
            "testID": fromOption(testID),
          }
        ),
      ),
  );