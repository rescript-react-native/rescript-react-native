---
id: apis/Global
title: Global
wip: true
---

```reason
[@bs.val] external __DEV__: bool = "__DEV__";

```

## `Global.hermesInternal`

This is the `HermesInternal` value known in JavaScript as
[`global.HermesInternal`](https://facebook.github.io/react-native/docs/hermes).

You can use it like this:

```reason
let isHermes = () => Global.hermesInternal != None;
```
