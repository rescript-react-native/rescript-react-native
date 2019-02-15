type actionSheetConfig;

type shareActionSheetConfig;
external shareActionSheetConfig: Js.t('a) => shareActionSheetConfig =
  "%identity";

type error;

[@bs.obj]
external makeActionSheetConfig:
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

let makeShareActionSheetConfig =
    (~options, ~subject=?, ~excludedActivityTypes=?, ()) => {
  let obj = {
    "subject": Js.Nullable.fromOption(subject),
    "excludedActivityTypes": Js.Nullable.fromOption(excludedActivityTypes),
  };
  (
    switch (options) {
    | URL(url) => Js.Obj.assign(obj, {"url": url})
    | Message(message) => Js.Obj.assign(obj, {"message": message})
    }
  )
  |> shareActionSheetConfig;
};

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external _showActionSheetWithOptions: (actionSheetConfig, int => unit) => unit =
  "showActionSheetWithOptions";

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external _showShareActionSheetWithOptions:
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
    makeShareActionSheetConfig(
      ~options,
      ~subject?,
      ~excludedActivityTypes?,
      (),
    ),
    failureCallback,
    successCallback,
  );
