---
title: TouchableOpacity
---

## Props

### accessible

```reason
accessible: bool=?
```

### accessibilityLabel

```reason
accessibilityLabel: string=?
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

### delayLongPress

```reason
delayLongPress: int=?
```

### delayPressIn

```reason
delayPressIn: int=?
```

### delayPressOut

```reason
delayPressOut: int=?
```

### disabled

```reason
disabled: bool=?
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

### style

```reason
style: Style.t=?
```

### onLayout

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

### onPress

```reason
onPress: unit => unit=?
```

### onLongPress

```reason
onLongPress: unit => unit=?
```

### onPressIn

```reason
onPressIn: unit => unit=?
```

### onPressOut

```reason
onPressOut: unit => unit=?
```

### pressRetentionOffset

```reason
pressRetentionOffset: Types.insets=?
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

### activeOpacity

```reason
activeOpacity: float=?
```

### focusedOpacity

```reason
focusedOpacity: float=?
```

### tvParallaxProperties

```reason
tvParallaxProperties: Js.t({.})=?
```
