---
id: apis/Global
title: Global
---

This module contains various APIs & flags that are in JavaScript global scope.

## `Global.__DEV__`

This is the development flag known in JavaScript as just `__DEV__`.

You can use it like this:

```reason
let environmentText = if (Global.__DEV__) {
  "This is development"
}
else {
  "This is production"
}
```
