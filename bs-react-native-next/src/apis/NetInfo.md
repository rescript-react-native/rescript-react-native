---
id: apis/NetInfo
title: NetInfo
wip: true
---

```reason
type info;

[@bs.obj]
external info:
  (
    ~effectiveType: [@bs.string] [
                      | [@bs.as "2g"] `Net2G
                      | [@bs.as "3g"] `Net3G
                      | [@bs.as "4g"] `Net4G
                      | `unknown
                    ]
                      =?,
    ~_type: [@bs.string] [
              | `bluetooth
              | `cellular
              | `ethernet
              | `unknown
              | `wifi
              | `wimax
            ]
              =?,
    unit
  ) =>
  info =
  "";

[@bs.get] external effectiveType: info => string = "";
[@bs.get] external _type: info => string = "type";

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
