---
id: components/Pressable
title: Pressable
officialDoc: https://reactnative.dev/docs/pressable
---

Pressable is a Core Component wrapper that can detect various stages of press interactions on any of it's defined children.

⚠️ Current `Pressable` is deprecated, prefer `Pressable_` that offers interaction states (eg: `pressed` state).

## How it works

On an element wrapped by `Pressable`:

1. `onPressIn` is called when a press is activated.
2. `onPressOut` is called when the press gesture is deactivated.

You can read more about this [on the official Pressable documentation](https://reactnative.dev/docs/pressable).

## Example

Current Pressable (deprecated because doesn't provide pressed state).

```rescript
open ReactNative

@react.component
let make = () =>
  <Pressable onPress={_ => Js.log("Pressed")}>
    <Text> {"Press Me"->React.string} </Text>
  </Pressable>
```

Next Pressable (with interactionState)

```rescript
open ReactNative

@react.component
let make = () =>
  <Pressable_
    onPress={_ => Js.log("Pressed")}
    style={({pressed}) => {
      open Style
      style(~backgroundColor=pressed ? "rgb(210, 230, 255)" : "white", ())
    }}>
    {({pressed}) =>
      <Text> {(pressed ? "Pressed!" : "Press Me")->React.string} </Text>}
  </Pressable_>
```
