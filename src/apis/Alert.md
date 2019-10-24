---
id: apis/Alert
title: Alert
wip: true
---

## Methods

### `alert`

Launches an alert dialog with the specified `title` and `message`. Optionally,
an array of `buttons` can be provided: on Android the maximum is 3, on iOS any
number is okay.

On Android, the dialog can be dismissed by tapping outside of the alert box.
This triggers the `onDismiss` callback available in the `options`. With the
`cancelable` option, this behavior can be deactivated altogether.

#### `alert` Example

```reason
  open ReactNative;

  Alert.alert(
    ~title="Do you really want to quit?",
    ~message="We miss you already.",
    ~buttons=[|
      Alert.button(~text="OK", ~style=`destructive, ~onPress={() => Js.log("Bye!")}, ()),
      Alert.button(~text="Cancel", ~style=`cancel, ()),
    |],
    ~options=Alert.options(~cancelable=true, ~onDismiss={_ => Js.log("Dismissed.")}, ()),
    (),
  );
```
