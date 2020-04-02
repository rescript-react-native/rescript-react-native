---
id: apis/DatePickerAndroid
title: DatePickerAndroid
wip: true
---

`DatePickerAndroid` has been deprecated and will be removed from React Native in
the future.

Please refer to
[bindings](https://github.com/reason-react-native/datetimepicker) for the
replacement
[community package](https://github.com/react-native-community/react-native-datetimepicker).

---

```reason
type options;

type date;

type action;

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
  "action": action,
  "year": int,
  "month": int,
  "day": int,
};

[@bs.module "react-native"] [@bs.scope "DatePickerAndroid"]
external open_: options => Js.Promise.t(response) = "open";

[@bs.module "react-native"] [@bs.scope "DatePickerAndroid"]
external dateSetAction: action = "dateSetAction";

[@bs.module "react-native"] [@bs.scope "DatePickerAndroid"]
external dismissedAction: action = "dismissedAction";

```
