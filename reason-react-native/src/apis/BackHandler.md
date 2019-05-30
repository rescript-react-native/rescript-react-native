---
id: apis/BackHandler
title: BackHandler
wip: true
---

```reason
type remove = {. "remove": unit => unit};

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external exitApp: unit => unit = "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external addEventListener:
  ([@bs.string] [ | `backPress | `hardwareBackPress], unit => bool) => remove =
  "";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external removeEventListener:
  ([@bs.string] [ | `backPress | `hardwareBackPress], unit => bool) => unit =
  "";

```
