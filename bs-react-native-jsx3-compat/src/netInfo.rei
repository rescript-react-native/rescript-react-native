/**
NetInfo exposes info about online/offline status


You can read more on [NetInfo] API usage in official docs:
{{:https://facebook.github.io/react-native/docs/netinfo}}

{3 Types}
{4 infoType}
{[
  type infoType;
]}
{4 infoEffectiveType}
{[
  type infoEffectiveType;
]}
{4 connectionType}
{[
  type connectionType =
  | None
  | WiFi
  | Cellular
  | Unknown
  | Bluetooth
  | Ethernet
  | WiMax;
]}
{4 effectiveConnectionType}
{[
  type effectiveConnectionType =
  | Net2G
  | Net3G
  | Net4G
  | Unknown;
]}
{4 info}
{[
  type info = {
  .
  "_type": infoType,
  "effectiveType": infoEffectiveType,
};
]}
{3 Methods }
{4 connectionType}
{[
  let connectionType: infoType => connectionType;
]}
{4 effectiveConnectionType}
{[
  let effectiveConnectionType: infoEffectiveType => effectiveConnectionType;
]}
{4 addEventListener}
{[
  let addEventListener: (info => unit) => unit;
]}
{4 removeEventListener}
{[
  let removeEventListener: (info => unit) => unit;
]}
{4 isConnectionExpensive}
{[
  let isConnectionExpensive: unit => Js.Promise.t(bool);
]}
{4 getConnectionInfo}
{[
  let getConnectionInfo: unit => Js.Promise.t(info);
]}

*/

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

/**
    {3 Methods}
    {4 addEventListener}
    {[
      let addEventListener: (bool => unit) => unit;
    ]}
    {4 removeEventListener}
    {[
      let removeEventListener: (bool => unit) => unit;
    ]}
    {4 fetch}
    {[
      let fetch: unit => Js.Promise.t(bool);
    ]}
   */

module IsConnected: {
  let addEventListener: (bool => unit) => unit;
  let removeEventListener: (bool => unit) => unit;
  let fetch: unit => Js.Promise.t(bool);
};
