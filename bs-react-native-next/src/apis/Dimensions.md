---
id: apis/Dimensions
title: Dimensions
wip: true
---

```reason
type t = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};

type handler = {
  .
  "screen": t,
  "window": t,
};

[@bs.module "react-native"] [@bs.scope "Dimensions"]
external get: ([@bs.string] [ | `window | `screen]) => t = "";
[@bs.module "react-native"] [@bs.scope "Dimensions"]
external addEventListener: (string, handler => unit) => unit = "";
[@bs.module "react-native"] [@bs.scope "Dimensions"]
external removeEventListener: (string, handler => unit) => unit = "";

```
