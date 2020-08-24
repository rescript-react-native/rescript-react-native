---
id: components/Pressable
title: Pressable
wip: true
---

Pressable is a Core Component wrapper that can detect various stages of press interactions on any of it's defined children.

## How it works

On an element wrapped by Pressable:

1. onPressIn is called when a press is activated.
2. onPressOut is called when the press gesture is deactivated.

You can read more about this here.

## Example

```reason
open ReactNative;

[@react.component]
let make = () => {
    <Pressable onPress={_ => Js.log("Pressed")}>
        <Text> "Press Me"->React.string </Text>
    </Pressable>;
};
```
