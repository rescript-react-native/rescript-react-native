/**
You can read more on [ActionSheetIOS] API usage in official docs: {{:https://facebook.github.io/react-native/docs/actionsheetios}}


{3 Example of use}
{4 showActionSheetWithOptions}
  {[
    ActionSheetIOS.showActionSheetWithOptions(
    ~options=[|"Agree", "Disagree", "Leave"|],
    ~cancelButtonIndex=2,
    ~destructiveButtonIndex=1,
    buttonIndex =>
      Js.log(
        "You pressed button with index: " ++ string_of_int(buttonIndex),
      ),
    (),
  );
]}

{4 showShareActionSheetWithOptions}
{[
  ActionSheetIOS.showShareActionSheetWithOptions(
  ~options=Message("Hello, welcome to my new ReasonML app"),
  ~subject="New app",
  error => Js.log(error),
  (hasSucceeded, methodOfSharing) =>
      Js.log(
        "Has sharing succeeded: "
        ++ string_of_bool(hasSucceeded)
        ++ ", with method: "
        ++ methodOfSharing,
      ),
    (),
  );
]}

{3 Function parameters}

{4 showActionSheetWithOptions}
{4 options}
{[
  ~options: array(string)
]}
{4 reference}
{[

type options =
  | Message(string)
  | URL(string);
]}

{4 cancelButtonIndex}
{[
  ~cancelButtonIndex: int=?
]}
{4 destructiveButtonIndex}
{[
  ~destructiveButtonIndex: int=?
]}
{4 title}
{[
  ~title: string=?
]}
{4 message}
{[
  ~message: string=?
]}
{4 tintColor}
{[
  ~tintColor: string=?
]}
{4 callback}
{[
  int => unit
]}
{4 non-labeled argument}
{[
  unit
]}

{4 showShareActionSheetWithOptions}
{4 options}
{[
  ~options: array(string)
]}
{4 reference}
{[

type options =
  | Message(string)
  | URL(string);
]}

{4 subject}
{[
  ~subject: string=?
]}

{4 excludedActivityTypes}
{[
  ~excludedActivityTypes: array(string)=?
]}

{4 error}
{[
  error => unit
]}

{4 callback}
{[
  (bool, string) => unit
]}
{4 non-labeled argument}
{[
  unit
]}


*/

type options =
  | Message(string)
  | URL(string);

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

type error;

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
