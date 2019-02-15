type infoType = string;

type infoEffectiveType = string;

type connectionType =
  | None
  | WiFi
  | Cellular
  | Unknown
  | Bluetooth
  | Ethernet
  | WiMax;

type effectiveConnectionType =
  | Net2G
  | Net3G
  | Net4G
  | Unknown;

type info = {
  .
  "effectiveType": infoEffectiveType,
  "_type": infoType,
};

let connectionType = connectionType =>
  switch (connectionType) {
  | "none" => None
  | "wifi" => WiFi
  | "cellular" => Cellular
  | "unknown" => Unknown
  | "bluetooth" => Bluetooth
  | "ethernet" => Ethernet
  | "wimax" => WiMax
  | connection =>
    failwith("NetInfo, unexpected `connection` type: " ++ connection)
  };

let effectiveConnectionType = effectiveConnectionType =>
  switch (effectiveConnectionType) {
  | "2g" => Net2G
  | "3g" => Net3G
  | "4g" => Net4G
  | "unknown" => Unknown
  | connection =>
    failwith("NetInfo, unexpected `effectiveConnection` type: " ++ connection)
  };

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external addEventListener:
  ([@bs.as "connectionChange"] _, info => unit) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external removeEventListener:
  ([@bs.as "connectionChange"] _, info => unit) => unit =
  "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external isConnectionExpensive: unit => Js.Promise.t(bool) = "";

[@bs.module "react-native"] [@bs.scope "NetInfo"]
external getConnectionInfo: unit => Js.Promise.t(info) = "";

module IsConnected = {
  type t;
  [@bs.module "react-native"] [@bs.scope "NetInfo"] [@bs.val]
  external isConnected: t = "";
  [@bs.send.pipe: t]
  external _addEventListener:
    ([@bs.as "connectionChange"] _, bool => unit) => unit =
    "addEventListener";
  [@bs.send.pipe: t]
  external _removeEventListener:
    ([@bs.as "connectionChange"] _, bool => unit) => unit =
    "removeEventListener";
  [@bs.send.pipe: t] external _fetch: unit => Js.Promise.t(bool) = "fetch";
  let addEventListener = listener =>
    isConnected |> _addEventListener(listener);
  let removeEventListener = listener =>
    isConnected |> _removeEventListener(listener);
  let fetch = () => isConnected |> _fetch();
};
