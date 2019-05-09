---
id: apis/Linking
title: Linking
wip: true
---

```reason
[@bs.scope "Linking"] [@bs.module "react-native"]
external openURL: string => Js.Promise.t(unit) = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external canOpenURL: string => Js.Promise.t(bool) = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external getInitialURL: unit => Js.Promise.t(Js.Null.t(string)) = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external addEventListener:
  ([@bs.string] [ | `url], {. "url": string} => unit) => unit =
  "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external removeEventListener:
  ([@bs.string] [ | `url], {. "url": string} => unit) => unit =
  "";

```
