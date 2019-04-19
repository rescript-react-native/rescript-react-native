/**
Opens the standard Android date picker dialog.

You can read more on [DatePickerAndroid] API usage in official docs: {{:https://facebook.github.io/react-native/docs/datepickerandroid}}

{3 Types}
{4 response}
{[
type response = {
  year: int,
  month: int,
  day: int,
};
]}
{4 action}
{[
  type action =
  | Dismissed
  | Set(response);

]}
{4 mode }
{[
  type mode = [ | `calendar | `spinner | `default];
]}
{3 Methods}
{4 open}
{[
let open_:
  (
    ~date: Js.Date.t,
    ~minDate: Js.Date.t=?,
    ~maxDate: Js.Date.t=?,
    ~mode: mode=?,
    unit
  ) =>
  Js.Promise.t(action);
]}
*/

type response = {
  year: int,
  month: int,
  day: int,
};

type action =
  | Dismissed
  | Set(response);

type mode = [ | `calendar | `spinner | `default];

let open_:
  (
    ~date: Js.Date.t,
    ~minDate: Js.Date.t=?,
    ~maxDate: Js.Date.t=?,
    ~mode: mode=?,
    unit
  ) =>
  Js.Promise.t(action);
