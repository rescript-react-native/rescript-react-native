---
id: apis/Global
title: Global
autoLinkToOfficialDoc: false
---

This module contains various APIs & flags that are in JavaScript global scope.

## `Global.__DEV__`

This is the development flag known in JavaScript as just
[`__DEV__`](https://reactnative.dev/docs/javascript-environment).

You can use it like this:

```rescript
open ReactNative

let environmentText = if Global.__DEV__ {
  "This is development"
}
else {
  "This is production"
}
```

## `Global.hermesInternal`

This is the `HermesInternal` value known in JavaScript as
[`global.HermesInternal`](https://reactnative.dev/docs/hermes).

You can use it like this:

```rescript
open ReactNative

let isHermes = () => Global.hermesInternal != None
```
