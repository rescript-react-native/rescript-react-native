type t = unit => unit;

type netInfoStateType;

[@bs.inline "none"]
let none: netInfoStateType;

[@bs.inline "unknown"]
let unknown: netInfoStateType;

[@bs.inline "cellular"]
let cellular: netInfoStateType;

[@bs.inline "wifi"]
let wifi: netInfoStateType;

[@bs.inline "bluetooth"]
let bluetooth: netInfoStateType;

[@bs.inline "ethernet"]
let ethernet: netInfoStateType;

[@bs.inline "wimax"]
let wimax: netInfoStateType;

[@bs.inline "vpn"]
let vpn: netInfoStateType;

[@bs.inline "other"]
let other: netInfoStateType;

type netInfoCellularGeneration;

[@bs.inline "2g"]
let net2G: netInfoCellularGeneration;

[@bs.inline "3g"]
let net3G: netInfoCellularGeneration;

[@bs.inline "4g"]
let net4G: netInfoCellularGeneration;

type details = {
  .
  "isConnectionExpensive": bool,
  "cellularGeneration": Js.Nullable.t(netInfoCellularGeneration),
};

type netInfoState = {
  .
  "_type": netInfoStateType,
  "isConnected": bool,
  "details": Js.Null.t(details),
};

[@bs.module "@react-native-community/netinfo"]
external fetch: unit => Js.Promise.t(netInfoState) = "";

[@bs.module "@react-native-community/netinfo"]
external addEventListener: (netInfoState => unit) => t = "";

[@bs.module "@react-native-community/netinfo"]
external useNetInfo: unit => netInfoState = "";

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

type remove = {. "remove": unit => unit};

module Legacy: {
  [@bs.module "@react-native-community/netinfo"]
  external addEventListener:
    ([@bs.string] [ | `connectionChange], info => unit) => remove =
    "";

  [@bs.module "@react-native-community/netinfo"]
  external removeEventListener:
    ([@bs.string] [ | `connectionChange], info => unit) => unit =
    "";

  [@bs.module "@react-native-community/netinfo"]
  external isConnectionExpensive: unit => Js.Promise.t(bool) = "";

  [@bs.module "@react-native-community/netinfo"]
  external getConnectionInfo: unit => Js.Promise.t(info) = "";

  module IsConnected: {
    [@bs.module "@react-native-community/netinfo"] [@bs.scope "isConnected"]
    external addEventListener:
      ([@bs.string] [ | `connectionChange], bool => unit) => remove =
      "";

    [@bs.module "@react-native-community/netinfo"] [@bs.scope "isConnected"]
    external removeEventListener:
      ([@bs.string] [ | `connectionChange], bool => unit) => unit =
      "";

    [@bs.module "@react-native-community/netinfo"] [@bs.scope "isConnected"]
    external fetch: unit => Js.Promise.t(bool) = "";
  };
};
