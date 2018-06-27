---
title: Modal
---

## Example of use

`Modal` component simply displays content over an enclosing view.

### default

Wrap some content in `<Modal> </Modal>` and you are good to go

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Modal>
      <View
        style=Style.(
                style([
                  flex(1.),
                  justifyContent(Center),
                  alignItems(Center),
                  backgroundColor(String("tomato")),
                ])
              )>
        <Text> (ReasonReact.string("hey ho")) </Text>
      </View>
    </Modal>,
};
```

### animationType

There are three options for the `animationType`:

- ```reason
  `none
  ```

- ```reason
  `slide
  ```

- ```reason
  `fade
  ```

And this is how you apply one of those types:

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Modal animationType=`slide>
      <View
        style=Style.(
                style([
                  flex(1.),
                  justifyContent(Center),
                  alignItems(Center),
                  backgroundColor(String("tomato")),
                ])
              )>
        <Text> (ReasonReact.string("hey ho")) </Text>
      </View>
    </Modal>,
};
```

### onShow

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Modal onShow=(() => Js.log("Just displayed the modal..."))>
      <View
        style=Style.(
                style([
                  flex(1.),
                  justifyContent(Center),
                  alignItems(Center),
                  backgroundColor(String("tomato")),
                ])
              )>
        <Text> (ReasonReact.string("hey ho")) </Text>
      </View>
    </Modal>,
};
```

### supportedOrientations

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Modal supportedOrientations=[|`landscape, `portrait|]>
      <View
        style=Style.(
                style([
                  flex(1.),
                  justifyContent(Center),
                  alignItems(Center),
                  backgroundColor(String("tomato")),
                ])
              )>
        <Text> (ReasonReact.string("hey ho")) </Text>
      </View>
    </Modal>,
};
```

## Props

### animationType

```reason
animationType: [
  | `fade
  | `none
  | `slide
]=?
```

### onShow

```reason
onShow: unit => unit=?
```

### transparent

```reason
transparent: bool=?
```

### visible

```reason
visible: bool=?
```

### hardwareAccelerated

```reason
hardwareAccelerated: bool=?
```

### onRequestClose

```reason
onRequestClose: unit => unit=?
```

### onOrientationChange

```reason
onOrientationChange: unit => unit=?
```

### supportedOrientations

```reason
supportedOrientations: array(
  [
    | `landscape
    | `landscapeLeft
    | `landscapeRight
    | `portrait
    | `portraitUpsideDown
  ],
)=?
```
