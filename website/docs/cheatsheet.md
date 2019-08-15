---
id: cheatsheet
title: Cheatsheet
---

If you are not familiar with ReasonML or BuckleScript, be sure to check

- [ReasonML Syntax Cheatsheet](https://reasonml.github.io/docs/en/syntax-cheatsheet)
  to compare ReasonML syntax to JavaScript
- [BuckleScript Cheatsheet](https://bucklescript.github.io/docs/en/interop-cheatsheet)
  to learn how to interop with JavaScript

## JSX String

### JavaScript JSX String

```javascript
<Text>Hello, world!</Text>
```

### Reason JSX String

```reason
<Text> "Hello, world!"->React.string </Text>
```

## JSX Number (int)

### JavaScript JSX Number (int)

```javascript
<Text>42</Text>
```

### Reason JSX Number (int)

```reason
<Text>
  42
  ->Js.Int.toString
  ->React.string
</Text>
```

## JSX Number (float)

### JavaScript JSX Number (float)

```javascript
<Text>4.2</Text>
```

### Reason JSX Number (float)

```reason
<Text>
  4.2
  ->Js.Float.toString
  ->React.string
</Text>
```

## JSX Array (of string)

### JavaScript JSX Array (of string)

```javascript
{items.map((item, i) =>
  <Text key={i++item}>
    item
  </Text>
)}
```

### Reason JSX Array (of string)

```reason
{items
->Belt.Array.mapWithIndex((item, index) =>
  <Text
    key=((index->Js.Int.toString)++item)>
    item->React.string
  </Text>
  )
->React.array}
```

## JSX conditional string

### JavaScript JSX conditional string

```javascript
<Text>{condition && something}</Text>
```

### Reason JSX conditional string

```reason
<Text>
  {
    condition ? something->React.string : React.null
  }
</Text>
```

## JSX optional value

### JavaScript JSX optional string

_Assuming `something` is a `string` that can be `undefined`._

```javascript
{
  something && <Text>{something.toUpperCase()}</Text>;
}
```

### Reason JSX optional string

_Recommended: Assuming `something` is an
[optional](https://reasonml.github.io/docs/en/null-undefined-option) `string`._

```reason
{
  something
  ->Belt.Option.map(thing =>
    <Text>
      thing
      ->Js.String.toUpperCase
      ->React.string
    </Text>
  )
  ->Belt.Option.getWithDefault(React.null)
}
```

_If you have to work with JavaScript/JSON: Assuming `something` is a JavaScript
`string` that can be `undefined`._

```reason
{
  something
  ->Js.Nullable.toOption /* convert undefined || string  as option(string) */
  ->Belt.Option.map(thing =>
    <Text>
      thing
      ->Js.String.toUpperCase
      ->React.string
    </Text>
  )
  ->Belt.Option.getWithDefault(React.null)
}
```

## React Native StyleSheet

### JavaScript React Native StyleSheet

```javascript
import { StyleSheet } from "react-native";

const styles = StyleSheet.create({
  container: {
    maxHeight: 600,
    width: 800,
    justifyContent: "flex-start",
    alignItems: "center",
    margin: "auto",
  },
  cornerThing: {
    position: "absolute",
    top: 100,
    right: -20,
    transform: [{ rotate: "4deg" }],
  },
  text: {
    textTransform: "uppercase",
  },
});

console.log(StyleSheet.flatten([styles.container]));
```

### Reason React Native StyleSheet

```reason
open ReactNative;

let styles =
  Style.(
  /* = open Style; just between ()*/
  /* this is useful since all units & style methods comes from Style module */
    StyleSheet.create({
      "container":
        viewStyle(
          ~maxHeight=600.->dp,
          ~width=80.->pct,
          ~justifyContent=`flexStart,
          ~alignItems=`center,
          ~margin=auto,
          (),
        ),
      "cornerThing":
        viewStyle(
          ~position=`absolute,
          ~top=100.->dp,
          ~right=(-20.)->dp,
          ~transform=[|rotate(~rotate=4.->deg)|],
          (),
        ),
      "text": textStyle(~textTransform=`uppercase, ()),
    })
  );

Js.log(StyleSheet.flatten([|styles##container|]));
```

## Concatened styles

### JavaScript Concatened styles

```javascript
<View style={[styles.container, styles.containerAdditionalStyles]} />
```

### Reason Concatened styles

```reason
<View
  style=Style.(array([|
    styles##container,
    styles##containerAdditionalStyles
  |]))
/>
```

## Optional styles

### JavaScript Optional styles

```javascript
<View
  style={[
    styles.container,
    condition && styles.containerAdditionalStyles,
    condition2 && { width: 40 },
  ]}
/>
```

### Reason Optional styles

```reason
<View
  style=Style.(arrayOption([|
    Some(styles##container),
    condition ? Some(styles##containerAdditionalStyles) : None,
    condition2 ? Some(viewStyle(~width=40.->dp, ())) : None,
  |]))
/>
```

## Hello world

### JavaScript Hello World

```javascript
/* App.js */
import React, { Component } from "react";
import { Text, View } from "react-native";

export default class HelloWorld extends Component {
  render() {
    return (
      <View
        style={{
          flex: 1,
          justifyContent: "center",
          alignItems: "center",
        }}
      >
        <Text>Hello, {this.props.name || "world"}!</Text>
      </View>
    );
  }
}
```

### Reason Hello World

```reason
/* App.re */
open Belt;
open ReactNative;

[@react.component]
let make = (~name=?) => {
  <View
    style=Style.(
      viewStyle(~flex=1., ~justifyContent=`center, ~alignItems=`center, ())
    )>
    <Text>
      {("Hello, " ++ name->Option.getWithDefault("world") ++ "!")
       ->React.string}
    </Text>
  </View>;
};
```

---

## Further reading

- [Migration from `bs-react-native`](/reason-react-native/en/docs/migration/jsx3/)

## In case you missed it

- [Getting Started](/reason-react-native/en/docs/)
- [Installation](/reason-react-native/en/docs/install/)
- [Usage](/reason-react-native/en/docs/usage/)
- [Example](/reason-react-native/en/docs/example/)
