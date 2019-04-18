---
id: apis/NetInfo
title: NetInfo
wip: true
---

```reason
type info = {
  .
  "_type": NetInfoType.t,
  "effectiveType": NetInfoEffectiveType.t,
};

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external addEventListener:
  ([@bs.string] [ | `connectionChange], info => unit) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external removeEventListener:
  ([@bs.string] [ | `connectionChange], info => unit) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external isConnectionExpensive: unit => Js.Promise.t(bool) = "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external getConnectionInfo: unit => Js.Promise.t(info) = "";

module IsConnected = {
  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external addEventListener:
    ([@bs.string] [ | `connectionChange], bool => unit) => unit =
    "";
  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external removeEventListener:
    ([@bs.string] [ | `connectionChange], bool => unit) => unit =
    "";
  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external fetch: unit => Js.Promise.t(bool) = "";
};

```
