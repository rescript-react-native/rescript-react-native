---
title: View
---

## Props

### accessibilityLabel

[RN docs](https://facebook.github.io/react-native/docs/view.html#accessibilitylabel)

```reason
accessibilityLabel: string=?
```

### accessible

[RN docs](https://facebook.github.io/react-native/docs/view.html#accessible)

```reason
accessible: bool=?
```

### hitSlop

[RN docs](https://facebook.github.io/react-native/docs/view.html#hitslop)

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

[RN docs](https://facebook.github.io/react-native/docs/view.html#onaccessibilityTap)

```reason
onAccessibilityTap: unit => unit=?
```

### onLayout

[RN docs](https://facebook.github.io/react-native/docs/view.html#onlaout)

```reason
onLayout: RNEvent.NativeLayoutEvent.t => unit=?
```

_reference:_

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

[RN docs](https://facebook.github.io/react-native/docs/view.html#onmagictap)

```reason
onMagicTap: unit => unit=?
```

### responderHandlers

[RN docs](https://facebook.github.io/react-native/docs/view.html#responderhandlers)

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

[RN docs](https://facebook.github.io/react-native/docs/view.html#pointerevents)

```reason
pointerEvents: [
  | `auto
  | `boxNone
  | `boxOnly
  | `none
]=?
```

### removeClippedSubviews

[RN docs](https://facebook.github.io/react-native/docs/view.html#removeclippedsubviews)

```reason
removeClippedSubviews: bool=?
```

### style

[RN docs](https://facebook.github.io/react-native/docs/view.html#style)

```reason
style: Style.t=?
```

### testID

[RN docs](https://facebook.github.io/react-native/docs/view.html#testid)

```reason
testID: string=?
```

### accessibilityComponentType

[RN docs](https://facebook.github.io/react-native/docs/view.html#accessibilitycomponenttype)

```reason
accessibilityComponentType: [
  | `button
  | `none
  | `radiobutton_checked
  | `radiobutton_unchecked
]=?
```

### accessibilityLiveRegion

[RN docs](https://facebook.github.io/react-native/docs/view.html#accessibilityliveregion)

```reason
accessibilityLiveRegion: [
  | `assertive
  | `none
  | `polite
]=?
```

### collapsable

[RN docs](https://facebook.github.io/react-native/docs/view.html#collapsable)

```reason
collapsable: bool=?
```

### importantForAccessibility

[RN docs](https://facebook.github.io/react-native/docs/view.html#importantforaccessibility)

```reason
importantForAccessibility: [
  | `auto
  | `no
  | `noHideDescendants
  | `yes
]=?
```

### needsOffscreenAlphaCompositing

[RN docs](https://facebook.github.io/react-native/docs/view.html#needsoffscreenalphacompositing)

```reason
needsOffscreenAlphaCompositing: bool=?
```

### renderToHardwareTextureAndroid

[RN docs](https://facebook.github.io/react-native/docs/view.html#rendertohardwaretextureandroid)

```reason
renderToHardwareTextureAndroid: bool=?
```

### accessibilityTraits

[RN docs](https://facebook.github.io/react-native/docs/view.html#accessibilitytraits)

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

[RN docs](https://facebook.github.io/react-native/docs/view.html#accessibilityviewismodal)

```reason
accessibilityViewIsModal: bool=?
```

### shouldRasterizeIOS

[RN docs](https://facebook.github.io/react-native/docs/view.html#shouldrasterizeios)

```reason
shouldRasterizeIOS: bool=?
```
