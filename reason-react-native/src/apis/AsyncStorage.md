---
id: apis/AsyncStorage
title: AsyncStorage
wip: true
---

```reason
type error;

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external getItem: string => Js.Promise.t(Js.Null.t(string)) = "getItem";
let getItem = key =>
  getItem(key) |> Js.Promise.then_(PromiseUtils.nullableToOption);

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external setItem: (string, string) => Js.Promise.t(unit) = "setItem";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external removeItem: string => Js.Promise.t(unit) = "removeItem";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external mergeItem: (string, string) => Js.Promise.t(unit) = "mergeItem";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external clear: unit => Js.Promise.t(unit) = "clear";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external getAllKeys: unit => Js.Promise.t(Js.Null.t(array(string))) =
  "getAllKeys";
let getAllKeys = () =>
  getAllKeys() |> Js.Promise.then_(PromiseUtils.nullableToOption);

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external flushGetRequests: unit => unit = "";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external multiGet:
  array(string) => Js.Promise.t(Js.Null.t(array(array(string)))) =
  "multiGet";
let multiGet = keys =>
  multiGet(keys) |> Js.Promise.then_(PromiseUtils.nullableToOption);

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external multiSet: array((string, string)) => Js.Promise.t(unit) =
  "multiSet";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external multiRemove: array(string) => Js.Promise.t(unit) = "multiRemove";

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external multiMerge: array(array(string)) => Js.Promise.t(unit) =
  "multiMerge";

```
