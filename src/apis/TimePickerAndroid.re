type options;

[@bs.obj]
external options:
  (
    ~hour: int=?,
    ~minute: int=?,
    ~is24Hour: bool=?,
    ~mode: [@bs.string] [ | `clock | `spinner | `default]=?,
    unit
  ) =>
  options =
  "";

type response = {
  action: string,
  hour: int,
  minute: int,
};

[@bs.module "react-native"] [@bs.scope "TimePickerAndroid"]
external open_: options => Js.Promise.t(response) = "open";

[@bs.module "react-native"] [@bs.scope "TimePickerAndroid"]
external timeSetAction: string = "timeSetAction";

[@bs.module "react-native"] [@bs.scope "TimePickerAndroid"]
external dismissedAction: string = "dismissedAction";
