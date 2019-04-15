---
id: apis/BackHandler
title: BackHandler
wip: true
---

```reason
[@bs.scope "BackHandler"] [@bs.module "react-native"]
external exitApp: unit => unit = "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external addEventListener: (string, unit => bool) => EventSubscription.t = "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external removeEventListener: (string, unit => bool) => unit = "";

```
