[@bs.scope "DatePickerAndroid"] [@bs.module "react-native"] external dateSet : string =
  "dateSetAction";

[@bs.scope "DatePickerAndroid"] [@bs.module "react-native"] external dismissed : string =
  "dismissedAction";

type mode =
  | Calendar
  | Spinner
  | Default;

type response = {
  year: int,
  month: int,
  day: int
};

type action =
  | Dismissed
  | Set(response);

let action = (resp) =>
  resp##action == dateSet ?
    Set({year: resp##year, month: resp##month, day: resp##day}) : Dismissed;

type responseJs = {. "action": string, "year": int, "month": int, "day": int};

type optsJs = {
  .
  "date": Js.Date.t,
  "minDate": Js.Nullable.t(Js.Date.t),
  "maxDate": Js.Nullable.t(Js.Date.t),
  "mode": string
};

[@bs.scope "DatePickerAndroid"] [@bs.module "react-native"]
external _open : optsJs => Js.Promise.t(responseJs) =
  "open";

let open_ = (~date: Js.Date.t, ~minDate=?, ~maxDate=?, ~mode=Default, ()) =>
  _open({
    "date": date,
    "minDate": Js.Nullable.from_opt(minDate),
    "maxDate": Js.Nullable.from_opt(maxDate),
    "mode":
      switch mode {
      | Default => "default"
      | Calendar => "calendar"
      | Spinner => "spinner"
      }
  })
  |> Js.Promise.then_((resp: responseJs) => resp |> action |> Js.Promise.resolve);
