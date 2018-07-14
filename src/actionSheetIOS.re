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

type options =
  | Message(string)
  | URL(string);

[@bs.obj]
external makeShareActionSheetConfig :
  (
    ~options: options,
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
      ~options,
      ~subject=?,
      ~excludedActivityTypes=?,
      failureCallback,
      successCallback,
      (),
    ) =>
  _showShareActionSheetWithOptions(
    makeShareActionSheetConfig(~options, ~subject?, ~excludedActivityTypes?),
    failureCallback,
    successCallback,
  );