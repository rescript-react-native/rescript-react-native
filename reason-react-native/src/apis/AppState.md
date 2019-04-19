---
id: apis/AppState
title: AppState
wip: true
---

```reason
type t;

[@bs.inline "active"]
let active: t;

[@bs.inline "background"]
let background: t;

[@bs.inline "inactive"]
let inactive: t;

[@bs.scope "AppState"] [@bs.module "react-native"]
external currentState: t = "currentState";

[@bs.scope "AppState"] [@bs.module "react-native"]
external addEventListener: (string, unit => unit) => EventSubscription.t = "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener: (string, unit => unit) => unit = "";
```
