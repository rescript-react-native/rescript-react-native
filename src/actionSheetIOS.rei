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

let showShareActionSheetWithOptions:
  (
    ~message: string=?,
    ~url: string=?,
    ~subject: string=?,
    ~excludedActivityTypes: array(string)=?,
    error => unit,
    (bool, string) => unit,
    unit
  ) =>
  unit;