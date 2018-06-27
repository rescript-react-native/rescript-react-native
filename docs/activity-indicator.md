---
title: ActivityIndicator
---

## Example of use

### default

To render a default ActivityIndicator (spinner) you don't need to pass any props:

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ActivityIndicator />,
};
```

### size

In order to change the size of the indicator pass one of the [polymorphic variants](http://2ality.com/2018/01/polymorphic-variants-reasonml.html):

- ```reason
  `large
  ```

- ```reason
  `small
  ```

- passing an integer to the size prop is only supported on Android:
  ```reason
  `exact(SOME_INTEGER)
  ```

#### large size example

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ActivityIndicator size=`large />,
};
```

#### small size example

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ActivityIndicator size=`small />,
};
```

#### any size example [(Android only)](https://facebook.github.io/react-native/docs/activityindicator.html#size)

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ActivityIndicator size=(`exact(32)) />,
};
```

### color

#### named colors

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ActivityIndicator color="tomato" />,
};
```

#### hex colors

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ActivityIndicator color="#ff00ff" />,
};
```

#### rgb colors

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self => <ActivityIndicator color="rgb(255, 34, 11)" />,
};
```

## Props

### animating

```reason
animating: bool=?
```

### color

```reason
color: string=?
```

### size

```reason
size: [
  | `large
  | `small
  | `exact(int)
]=?
```

### hidesWhenStopped

```reason
hidesWhenStopped: bool=?
```

### accessibilityLabel

```reason
accessibilityLabel: ReasonReact.reactElement=?
```

### accessible

```reason
accessible: bool=?
```

### hitSlop

```reason
hitSlop: Types.insets=?
```

_reference:_

**Types.rei**

```reason
type insets = {
  .
  "left": int,
  "right": int,
  "top": int,
  "bottom": int,
};
```

### onAccessibilityTap

```reason
onAccessibilityTap: unit => unit=?
```

### onLayout

```reason
onLayout: RNEvent.NativeLayoutEvent.t => unit=?
```

### onMagicTap

```reason
onMagicTap: unit => unit=?
```

### responderHandlers

```reason
responderHandlers: Types.touchResponderHandlers=?
```

_reference:_

**Types.rei**

```reason
type touchResponderHandlers = {
  onMoveShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
  onMoveShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool),
  onResponderGrant: option(RNEvent.NativeEvent.t => unit),
  onResponderMove: option(RNEvent.NativeEvent.t => unit),
  onResponderReject: option(RNEvent.NativeEvent.t => unit),
  onResponderRelease: option(RNEvent.NativeEvent.t => unit),
  onResponderTerminate: option(RNEvent.NativeEvent.t => unit),
  onResponderTerminationRequest: option(RNEvent.NativeEvent.t => unit),
  onStartShouldSetResponder: option(RNEvent.NativeEvent.t => bool),
  onStartShouldSetResponderCapture: option(RNEvent.NativeEvent.t => bool)
};
```

**RNEvent.rei**

```reason
module NativeEvent: {
  type t;
  let changedTouches: t => array(Js.t({..}));
  let identifier: t => int;
  let locationX: t => float;
  let locationY: t => float;
  let pageX: t => float;
  let pageY: t => float;
  let target: t => Js.t({..});
  let touches: t => array(Js.t({..}));
  let timestamp: t => int;
  let data: t => string;
};
```

### pointerEvents

```reason
pointerEvents: [
  | `auto
  | `none
  | `boxNone
  | `boxOnly
]=?
```

### removeClippedSubviews

```reason
removeClippedSubviews: bool=?
```

### style

```reason
style: Style.t=?
```

### testID

```reason
testID: string=?
```

### accessibilityComponentType

```reason
accessibilityComponentType: [
  | `none
  | `button
  | `radiobutton_checked
  | `radiobutton_unchecked
]=?
```

### accessibilityLiveRegion

```reason
accessibilityLiveRegion: [
  | `none
  | `polite
  | `assertive
]=?
```

### collapsable

```reason
collapsable: bool=?
```

### importantForAccessibility

```reason
importantForAccessibility: [
  | `auto
  | `yes
  | `no
  | `noHideDescendants
]=?
```

### needsOffscreenAlphaCompositing

```reason
needsOffscreenAlphaCompositing: bool=?
```

### renderToHardwareTextureAndroid

```reason
renderToHardwareTextureAndroid: bool=?
```

### accessibilityTraits

```reason
accessibilityTraits:
  list(
    [
      | `adjustable
      | `allowsDirectInteraction
      | `button
      | `disabled
      | `frequentUpdates
      | `header
      | `image
      | `key
      | `link
      | `none
      | `pageTurn
      | `plays
      | `search
      | `selected
      | `startsMedia
      | `summary
      | `text
    ],
  )=?
```

### accessibilityViewIsModal

```reason
accessibilityViewIsModal: bool=?
```

### shouldRasterizeIOS

```reason
shouldRasterizeIOS: bool=?
```
