type options;

type date;

external calendarDate: Js.Date.t => date = "%identity";
external timestamp: float => date = "%identity";

[@bs.obj]
external options:
  (
    ~date: date=?,
    ~minDate: date=?,
    ~maxDate: date=?,
    ~mode: [@bs.string] [ | `calendar | `spinner | `default]=?,
    unit
  ) =>
  options =
  "";

type response = {
  .
  "action": string,
  "year": int,
  "month": int,
  "day": int,
};

[@bs.module "react-native"] [@bs.scope "DatePickerAndroid"]
external open_: options => Js.Promise.t(response) = "open";

[@bs.module "react-native"] [@bs.scope "DatePickerAndroid"]
external dateSetAction: string = "";

[@bs.module "react-native"] [@bs.scope "DatePickerAndroid"]
external dismissedAction: string = "";
