---
id: apis/Global
title: Global
---

This module contains various APIs & flags that are in JavaScript global scope.

## `Global.__DEV__`

This is the development flag known in JavaScript as just
[`__DEV__`](https://reactnative.dev/docs/javascript-environment).

You can use it like this:

```reason
open ReactNative;

let environmentText = if (Global.__DEV__) {
  "This is development"
}
else {
  "This is production"
}
```

## `Global.unstable_enableLogBox``

Enable React Native unstable
[LogBox](https://reactnative.dev/blog/2020/03/26/version-0.62#other-improvements)

```reason
open ReactNative;

if (Global.__DEV__) {
  Global.unstable_enableLogBox();
};
```

## `Global.hermesInternal`

This is the `HermesInternal` value known in JavaScript as
[`global.HermesInternal`](https://reactnative.dev/docs/hermes).

You can use it like this:

```reason
open ReactNative;

let isHermes = () => Global.hermesInternal != None;
```
