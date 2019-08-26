---
id: apis/Clipboard
title: Clipboard
officialDoc: https://facebook.github.io/react-native/docs/clipboard
---

## Methods

### `getString`

To attempt reading content from the Clipboard; resolves to a `string` if
successful.

```reason
getString: unit => Js.Promise.t(string)
```

### `setString`

To copy a `string` to the Clipbard.

```reason
setString: string => unit
```
