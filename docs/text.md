---
title: Text
---

## Props

### accessible

```reason
accessible: bool=?
```

### allowFontScaling

```reason
allowFontScaling: bool=?
```

### ellipsizeMode

```reason
ellipsizeMode: [
  | `clip
  | `head
  | `middle
  | `tail
]=?
```

### numberOfLines

```reason
numberOfLines: int=?
```

### onLayout

```reason
onLayout: RNEvent.NativeLayoutEvent.t => unit=?
```

### onLongPress

```reason
onLongPress: unit => unit=?
```

### onPress

```reason
onPress: unit => unit=?
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

### selectable

```reason
selectable: bool=?
```

### style

```reason
style: Style.t=?
```

### testID

```reason
testID: string=?
```

### selectionColor

```reason
selectionColor: string=?
```

### textBreakStrategy

```reason
textBreakStrategy: [
  | `balanced
  | `highQuality
  | `simple
]=?
```

### adjustsFontSizeToFit

```reason
adjustsFontSizeToFit: bool=?
```

### minimumFontScale

```reason
minimumFontScale: float=?
```

### suppressHighlighting

```reason
suppressHighlighting: bool=?
```

### value

```reason
value: string=?
```
