---
title: Picker
---

## Example of use

In order to render a `Picker` component you will need to pass one or many `Picker.Item` components as children.

And `Picker.Item` has a required `label` prop

### default

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <View>
      <Picker>
        <Picker.Item label="ReasonML" value="reason" />
        <Picker.Item label="Ocaml" value="ocaml" />
        <Picker.Item label="JavaScript" value="js" />
      </Picker>
    </View>,
};
```

### selectedValue and onValueChange

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <View>
      <Picker selectedValue="ocaml" onValueChange=(value => Js.log(value))>
        <Picker.Item label="ReasonML" value="reason" />
        <Picker.Item label="Ocaml" value="ocaml" />
        <Picker.Item label="JavaScript" value="js" />
      </Picker>
    </View>,
};  
```

## Props

### onValueChange

```reason
onValueChange: 'value => unit=?
```

### selectedValue

```reason
selectedValue: 'value=?
```

### enabled

```reason
enabled: bool=?
```

### mode

On **Android only**, specifies how to display the selection items when the user taps on the picker:

- `dialog - shows a modal dialog. This is the default.
- `dropdown - shows a dropdown anchored to the picker view

```reason
mode: [
  | `dialog
  | `dropdown
]=?
```

### prompt

```reason
prompt: string=?
```

### itemStyle

```reason
itemStyle: Style.t=?
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

_reference:_

**RNEvent.rei**

```reason
module NativeLayoutEvent: {
  type t;
  type layout = {
    x: float,
    y: float,
    width: float,
    height: float
  };
  let layout: t => layout;
};
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
accessibilityTraits: list(
  [
    | `none
    | `button
    | `link
    | `header
    | `search
    | `image
    | `selected
    | `plays
    | `key
    | `text
    | `summary
    | `disabled
    | `frequentUpdates
    | `startsMedia
    | `adjustable
    | `allowsDirectInteraction
    | `pageTurn
  ]
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
