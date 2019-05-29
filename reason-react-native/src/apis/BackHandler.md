---
id: apis/BackHandler
title: BackHandler
wip: true
---

```reason
[@bs.scope "BackHandler"] [@bs.module "react-native"]
external exitApp: unit => unit = "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external addEventListener:
  ([@bs.string] [ | `backPress | `hardwareBackPress], unit => bool) =>
  EventSubscription.t =
  "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external removeEventListener:
  ([@bs.string] [ | `backPress | `hardwareBackPress], unit => bool) => unit =
  "";

```
