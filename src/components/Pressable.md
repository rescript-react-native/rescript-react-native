---
id: components/Pressable
title: Pressable
officialDoc: https://reactnative.dev/docs/pressable
---

Pressable is a Core Component wrapper that can detect various stages of press interactions on any of it's defined children.

## How it works

On an element wrapped by `Pressable`:

1. `onPressIn` is called when a press is activated.
2. `onPressOut` is called when the press gesture is deactivated.

You can read more about this [on the official Pressable documentation](https://reactnative.dev/docs/pressable).

## Example

```reason
open ReactNative;

[@react.component]
let make = () => {
  <Pressable
    onPress={_ => Js.log("Pressed")}
    style={({pressed}) =>
      Style.(
        style(~backgroundColor=pressed ? "rgb(210, 230, 255)" : "white", ())
      )
    }>
    {({pressed}) =>
        <Text> {pressed ? "Pressed!" : "Press Me"}->React.string </Text>}
  </Pressable>;
};
```
