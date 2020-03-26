---
id: apis/AppState
title: AppState
wip: true
---

```reason
type t;

[@bs.inline "dark"]
let dark: t;

[@bs.inline "light"]
let light: t;

[@bs.scope "Appearance"] [@bs.module "react-native"]
external getColorScheme: unit => option(t) = "getColorScheme";

[@bs.module "react-native"]
external useColorScheme: unit => option(t) = "useColorScheme";
```
