module ConnectionType: {
  type t;

  [@bs.inline "bluetooth"]
  let bluetooth: t;

  [@bs.inline "cellular"]
  let cellular: t;

  [@bs.inline "ethernet"]
  let ethernet: t;

  [@bs.inline "unknown"]
  let unknown: t;

  [@bs.inline "wifi"]
  let wifi: t;

  [@bs.inline "wimax"]
  let wimax: t;
};

module EffectiveConnectionType: {
  type t;

  [@bs.inline "2g"]
  let net2G: t;

  [@bs.inline "3g"]
  let net3G: t;

  [@bs.inline "4g"]
  let net4G: t;

  [@bs.inline "unknown"]
  let unknown: t;
};

type info = {
  .
  "effectiveType": EffectiveConnectionType.t,
  "_type": ConnectionType.t,
};

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external addEventListener:
  ([@bs.string] [ | `connectionChange], info => unit) => EventSubscription.t =
  "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external removeEventListener:
  ([@bs.string] [ | `connectionChange], info => unit) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external isConnectionExpensive: unit => Js.Promise.t(bool) = "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external getConnectionInfo: unit => Js.Promise.t(info) = "";

module IsConnected: {
  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external addEventListener:
    ([@bs.string] [ | `connectionChange], bool => unit) => EventSubscription.t =
    "";

  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external removeEventListener:
    ([@bs.string] [ | `connectionChange], bool => unit) => unit =
    "";

  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external fetch: unit => Js.Promise.t(bool) = "";
};
