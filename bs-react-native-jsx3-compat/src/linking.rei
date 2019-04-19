/**

You can read more on [Linking] API usage in official docs: {{:https://facebook.github.io/react-native/docs/linking}}

{3 Methods}
{4 canOpenURL}
{[
let canOpenURL: string => Js.Promise.t(bool);
]}
{4 openURL}
{[
  openURL: string => Js.Promise.t(unit)
]}
{4 getInitialURL}
{[
  let getInitialURL: unit => Js.Promise.t(option(string));
]}
{4 addEventListener}
{[
  addEventListener: (string, {. "url": string} => unit) => unit
]}
{4 removeEventListener}
{[
  removeEventListener: (string, {. "url": string} => unit) => unit
]}
*/

let canOpenURL: string => Js.Promise.t(bool);

[@bs.scope "Linking"] [@bs.module "react-native"]
external openURL: string => Js.Promise.t(unit) = "openURL";

let getInitialURL: unit => Js.Promise.t(option(string));

[@bs.scope "Linking"] [@bs.module "react-native"]
external addEventListener: (string, {. "url": string} => unit) => unit = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external removeEventListener: (string, {. "url": string} => unit) => unit =
  "";
