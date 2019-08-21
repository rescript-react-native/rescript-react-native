type t = unit => unit;

type netInfoStateType = string;

[@bs.inline]
let none = "none";

[@bs.inline]
let unknown = "unknown";

[@bs.inline]
let cellular = "cellular";

[@bs.inline]
let wifi = "wifi";

[@bs.inline]
let bluetooth = "bluetooth";

[@bs.inline]
let ethernet = "ethernet";

[@bs.inline]
let wimax = "wimax";

[@bs.inline]
let vpn = "vpn";

[@bs.inline]
let other = "other";

type netInfoCellularGeneration = string;

[@bs.inline]
let net2G = "2g";

[@bs.inline]
let net3G = "3g";

[@bs.inline]
let net4G = "4g";

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

module ConnectionType = {
  type t = string;

  [@bs.inline]
  let bluetooth = "bluetooth";

  [@bs.inline]
  let cellular = "cellular";

  [@bs.inline]
  let ethernet = "ethernet";

  [@bs.inline]
  let unknown = "unknown";

  [@bs.inline]
  let wifi = "wifi";

  [@bs.inline]
  let wimax = "wimax";
};

module EffectiveConnectionType = {
  type t = string;

  [@bs.inline]
  let net2G = "2g";

  [@bs.inline]
  let net3G = "3g";

  [@bs.inline]
  let net4G = "4g";

  [@bs.inline]
  let unknown = "unknown";
};

type info = {
  .
  "_type": ConnectionType.t,
  "effectiveType": EffectiveConnectionType.t,
};

type remove = {. "remove": unit => unit};

module Legacy = {
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

  module IsConnected = {
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
