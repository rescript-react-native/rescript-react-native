---
id: apis/TimePickerAndroid
title: TimePickerAndroid
wip: true
---

```reason
type options;

type action;

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
  .
  "action": action,
  "hour": int,
  "minute": int,
};

[@bs.module "react-native"] [@bs.scope "TimePickerAndroid"]
external open_: options => Js.Promise.t(response) = "open";

[@bs.module "react-native"] [@bs.scope "TimePickerAndroid"]
external timeSetAction: action = "timeSetAction";

[@bs.module "react-native"] [@bs.scope "TimePickerAndroid"]
external dismissedAction: action = "dismissedAction";

```
