[@bs.module "react-native"]
external progressViewIOS : ReasonReact.reactClass = "ProgressViewIOS";

let make =
    (
      ~progress=?,
      ~progressImage=?,
      ~progressTintColor=?,
      ~progressViewStyle=?,
      ~trackImage=?,
      ~trackTintColor=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=progressViewIOS,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "progress": fromOption(progress),
            "progressImage": fromOption(progressImage),
            "progressTintColor": fromOption(progressTintColor),
            "progressViewStyle": fromOption(progressViewStyle),
            "trackImage": fromOption(trackImage),
            "trackTintColor": fromOption(trackTintColor),
          }
        ),
      ),
  );