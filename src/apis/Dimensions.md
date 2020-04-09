---
id: apis/Dimensions
title: Dimensions
wip: true
---

```reason
type displayMetrics = {
  width: float,
  height: float,
  scale: float,
  fontScale: float,
};

type handler = {
  screen: displayMetrics,
  window: displayMetrics,
};

[@bs.module "react-native"] [@bs.scope "Dimensions"]
external get: ([@bs.string] [ | `window | `screen]) => displayMetrics = "get";
[@bs.module "react-native"] [@bs.scope "Dimensions"]
external addEventListener: ([@bs.string] [ | `change], handler => unit) => unit;
[@bs.module "react-native"] [@bs.scope "Dimensions"]
external removeEventListener:
  ([@bs.string] [ | `change], handler => unit) => unit;

[@bs.module "react-native"]
external useWindowDimensions: unit => displayMetrics = "useWindowDimensions";

```
