---
id: apis/Clipboard
title: Clipboard
officialDoc: https://reactnative.dev/docs/clipboard
---

`Clipboard` has been deprecated and will be removed from React Native in the
future.

Please refer to [bindings](https://github.com/rescript-react-native/clipboard) for
the replacement
[community package](https://github.com/react-native-community/clipboard).

---

## Methods

### `getString`

To attempt reading content from the Clipboard; resolves to a `string` if
successful.

```rescript
getString: unit => Js.Promise.t(string)
```

### `setString`

To copy a `string` to the Clipbard.

```rescript
setString: string => unit
```
