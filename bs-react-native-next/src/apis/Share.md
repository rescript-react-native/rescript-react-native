---
id: apis/Share
title: Share
wip: true
---

```reason
type content;
type options;

[@bs.obj]
external content:
  (~title: string=?, ~message: string=?, ~url: string=?, unit) => content =
  "";

[@bs.obj]
external options:
  (
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?,
    unit
  ) =>
  options =
  "";

type action;

[@bs.module "react-native"] [@bs.scope "Share"]
external sharedAction: action = "";

[@bs.module "react-native"] [@bs.scope "Share"]
external dismissedAction: action = "";

type shareResult = {
  .
  "action": action,
  "activityType": option(string),
};

[@bs.module "react-native"] [@bs.scope "Share"]
external share: content => Js.Promise.t(shareResult) = "";

[@bs.module "react-native"] [@bs.scope "Share"]
external shareWithOptions: (content, options) => Js.Promise.t(bool) = "share";

```
