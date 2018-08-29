type error;

let showActionSheetWithOptions:
  (
    ~options: array(string),
    ~cancelButtonIndex: int=?,
    ~destructiveButtonIndex: int=?,
    ~title: string=?,
    ~message: string=?,
    ~tintColor: string=?,
    int => unit,
    unit
  ) =>
  unit;

type options =
  | Message(string)
  | URL(string);

let showShareActionSheetWithOptions:
  (
    ~options: options,
    ~subject: string=?,
    ~excludedActivityTypes: array(string)=?,
    error => unit,
    (bool, string) => unit,
    unit
  ) =>
  unit;