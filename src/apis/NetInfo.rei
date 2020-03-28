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
  [@bs.as "type"]
  _type: ConnectionType.t,
  effectiveType: EffectiveConnectionType.t,
};

type remove = {. [@bs.meth] "remove": unit => unit};

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external addEventListener:
  ([@bs.string] [ | `connectionChange], info => unit) => remove =
  "addEventListener";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external removeEventListener:
  ([@bs.string] [ | `connectionChange], info => unit) => unit =
  "removeEventListener";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external isConnectionExpensive: unit => Js.Promise.t(bool) =
  "isConnectionExpensive";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external getConnectionInfo: unit => Js.Promise.t(info) = "getConnectionInfo";

module IsConnected: {
  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external addEventListener:
    ([@bs.string] [ | `connectionChange], bool => unit) => remove =
    "addEventListener";

  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external removeEventListener:
    ([@bs.string] [ | `connectionChange], bool => unit) => unit =
    "removeEventListener";

  [@bs.module "react-native"] [@bs.scope ("NetInfo", "isConnected")]
  external fetch: unit => Js.Promise.t(bool) = "fetch";
};
