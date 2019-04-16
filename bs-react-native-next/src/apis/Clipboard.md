---
id: apis/Clipboard
title: Clipboard
wip: true
---

```reason
[@bs.module "react-native"] [@bs.scope "Clipboard"]
external getString: unit => Js.Promise.t(string) = "";

[@bs.module "react-native"] [@bs.scope "Clipboard"]
external setString: string => unit = "";

```
