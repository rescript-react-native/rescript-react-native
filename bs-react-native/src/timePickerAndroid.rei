/**
Opens the standard Android time picker dialog.

You can read more on [TimePickerAndroid] API usage in official docs: {{:https://facebook.github.io/react-native/docs/timepickerandroid}}

{3 Methods }
{4 open }
{[
  let open_:
  (~hour: int=?, ~minute: int=?, ~is24Hour: bool=?, ~mode: mode=?, unit) =>
  Js.Promise.t(action);
]}

*/

type response = {
  hour: int,
  minute: int,
};

type action =
  | Dismissed
  | Set(response);

type mode = [ | `clock | `spinner | `default];

let open_:
  (~hour: int=?, ~minute: int=?, ~is24Hour: bool=?, ~mode: mode=?, unit) =>
  Js.Promise.t(action);
