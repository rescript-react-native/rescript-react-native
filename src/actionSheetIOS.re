type actionSheetConfig;

[@bs.obj]
external makeActionSheetConfig :
  (
    ~options: array(string),
    ~cancelButtonIndex: int=?,
    ~destructiveButtonIndex: int=?,
    ~title: string=?,
    ~message: string=?,
    ~tintColor: string=?
  ) =>
  actionSheetConfig =
  "";

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external _showActionSheetWithOptions : (actionSheetConfig, int => unit) => unit =
  "showActionSheetWithOptions";

let showActionSheetWithOptions =
    (
      ~options,
      ~cancelButtonIndex=?,
      ~destructiveButtonIndex=?,
      ~title=?,
      ~message=?,
      ~tintColor=?,
      callback,
      ()
    ) =>
  _showActionSheetWithOptions(
    makeActionSheetConfig(
      ~options,
      ~cancelButtonIndex?,
      ~destructiveButtonIndex?,
      ~title?,
      ~message?,
      ~tintColor?
    ),
    callback
  );
