type options = {
  options: array(string),
  cancelButtonIndex: option(int),
  destructiveButtonIndex: option(int),
  title: option(string),
  message: option(string),
  tintColor: option(Color.t),
};
// [@bs.obj]
// external options:
//   (
//     ~options: array(string),
//     ~cancelButtonIndex: int=?,
//     ~destructiveButtonIndex: int=?,
//     ~title: string=?,
//     ~message: string=?,
//     ~tintColor: Color.t=?,
//     unit
//   ) =>
//   options =
//   "";

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external showActionSheetWithOptions: (options, int => unit) => unit =
  "showActionSheetWithOptions";

type shareOptions = {
  url: option(string),
  message: option(string),
  subject: option(string),
  excludedActivityTypes: option(array(string)),
};
// [@bs.obj]
// external shareOptions:
//   (
//     ~url: string=?,
//     ~message: string=?,
//     ~subject: string=?,
//     ~excludedActivityTypes: array(string)=?,
//     unit
//   ) =>
//   shareOptions =
//   "";

type error = {stack: option(string)};

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external showShareActionSheetWithOptions:
  (shareOptions, error => unit, (bool, string) => unit) => unit =
  "showShareActionSheetWithOptions";
