---
title: Button
---

## Example of use

`Button` in React Native has two required props (`title` and `onPress`), so in order to render a `Button` component you need to provide them:

### default

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Button title="Press me" onPress=(() => Js.log("pressed")) />,
};
```

### color

#### named colors

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Button
      color="tomato"
      title="Press me"
      onPress=(() => Js.log("pressed"))
    />,
};
```

#### hex colors

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Button
      color="#ff00ff"
      title="Press me"
      onPress=(() => Js.log("pressed"))
    />,
};
```

#### rgb colors

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Button
      color="rgb(255, 34, 11)"
      title="Press me"
      onPress=(() => Js.log("pressed"))
    />,
};
```

### disabled

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Button
      disabled=true
      title="Press me"
      onPress=(() => Js.log("pressed"))
    />,
};
```

## Props

### accessibilityLabel

[RN docs](https://facebook.github.io/react-native/docs/button.html#accessibilitylabel)

```reason
accessibilityLabel: string=?
```

### color

[RN docs](https://facebook.github.io/react-native/docs/button.html#color)

```reason
color: string=?
```

### disabled

[RN docs](https://facebook.github.io/react-native/docs/button.html#disabled)

```reason
disabled: bool=?
```

### onPress

[RN docs](https://facebook.github.io/react-native/docs/button.html#onpress)

```reason
onPress: unit => unit
```

### testID

[RN docs](https://facebook.github.io/react-native/docs/button.html#testid)

```reason
testID: string=?
```

### title

[RN docs](https://facebook.github.io/react-native/docs/button.html#title)

```reason
title: string
```
