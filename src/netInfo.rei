type infoType;

type infoEffectiveType;

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
  "_type": infoType,
  "effectiveType": infoEffectiveType,
};

let connectionType: infoType => connectionType;

let effectiveConnectionType: infoEffectiveType => effectiveConnectionType;

let addEventListener: (info => unit) => unit;

let removeEventListener: (info => unit) => unit;

let isConnectionExpensive: unit => Js.Promise.t(bool);

let getConnectionInfo: unit => Js.Promise.t(info);

module IsConnected: {
  let addEventListener: (bool => unit) => unit;
  let removeEventListener: (bool => unit) => unit;
  let fetch: unit => Js.Promise.t(bool);
};