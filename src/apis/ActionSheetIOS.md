---
id: apis/ActionSheetIOS
title: ActionSheetIOS
wip: true
---

```reason
type options;
[@bs.obj]
external options:
  (
    ~options: array(string),
    ~cancelButtonIndex: int=?,
    ~destructiveButtonIndex: int=?,
    ~title: string=?,
    ~message: string=?,
    ~tintColor: Color.t=?,
    unit
  ) =>
  options =
  "options";

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external showActionSheetWithOptions: (options, int => unit) => unit = "showActionSheetWithOptions";

type shareOptions;
[@bs.obj]
external shareOptions:
  (
    ~url: string=?,
    ~message: string=?,
    ~subject: string=?,
    ~excludedActivityTypes: array(string)=?,
    unit
  ) =>
  shareOptions =
  "";

type error = {. "stack": option(string)};

[@bs.module "react-native"] [@bs.scope "ActionSheetIOS"]
external showShareActionSheetWithOptions:
  (shareOptions, error => unit, (bool, string) => unit) => unit =
  "showShareActionSheetWithOptions";

```
