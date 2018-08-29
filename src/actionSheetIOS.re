type actionSheetConfig;

type shareActionSheetConfig;

type error;

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

[@bs.obj]
external makeShareActionSheetConfig :
  (
    ~message: string=?,
    ~url: string=?,
    ~subject: string=?,
    ~excludedActivityTypes: array(string)=?
  ) =>
  shareActionSheetConfig =
  "";

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external _showActionSheetWithOptions : (actionSheetConfig, int => unit) => unit =
  "showActionSheetWithOptions";

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external _showShareActionSheetWithOptions :
  (shareActionSheetConfig, error => unit, (bool, string) => unit) => unit =
  "showShareActionSheetWithOptions";

let showActionSheetWithOptions =
    (
      ~options,
      ~cancelButtonIndex=?,
      ~destructiveButtonIndex=?,
      ~title=?,
      ~message=?,
      ~tintColor=?,
      callback,
      (),
    ) =>
  _showActionSheetWithOptions(
    makeActionSheetConfig(
      ~options,
      ~cancelButtonIndex?,
      ~destructiveButtonIndex?,
      ~title?,
      ~message?,
      ~tintColor?,
    ),
    callback,
  );

let showShareActionSheetWithOptions =
    (
      ~message=?,
      ~url=?,
      ~subject=?,
      ~excludedActivityTypes=?,
      failureCallback,
      successCallback,
      (),
    ) =>
  _showShareActionSheetWithOptions(
    makeShareActionSheetConfig(
      ~message?,
      ~url?,
      ~subject?,
      ~excludedActivityTypes?,
    ),
    failureCallback,
    successCallback,
  );