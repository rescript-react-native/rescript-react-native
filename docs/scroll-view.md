---
title: ScrollView
---

## Props

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
  | `boxNone
  | `boxOnly
  | `none
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
  | `button
  | `none
  | `radiobutton_checked
  | `radiobutton_unchecked
]=?
```

### accessibilityLiveRegion

```reason
accessibilityLiveRegion: [
  | `assertive
  | `none
  | `polite
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
  | `no
  | `noHideDescendants
  | `yes
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

### contentContainerStyle

```reason
contentContainerStyle: Style.t=?
```

### horizontal

```reason
horizontal: bool=?
```

### keyboardDismissMode

```reason
keyboardDismissMode: [
  | `interactive
  | `none
  | `onDrag
]=?
```

### keyboardShouldPersistTaps

```reason
keyboardShouldPersistTaps: [
  | `always
  | `handled
  | `never
]=?
```

### onContentSizeChange

```reason
onContentSizeChange: ((float, float)) => unit=?
```

### onScroll

```reason
onScroll: RNEvent.NativeScrollEvent.t => unit=?
```

_reference:_

**RNEvent.rei**

```reason
module NativeScrollEvent: {
  type t;
  type point = {
    x: float,
    y: float
  };
  type size = {
    width: float,
    height: float
  };
  type contentInset = {
    bottom: float,
    top: float,
    left: float,
    right: float
  };
  let contentOffset: t => point;
  let contentSize: t => size;
  let contentInset: t => contentInset;
  let layoutMeasurement: t => size;
};
```

### pagingEnabled

```reason
pagingEnabled: bool=?
```

### refreshControl

```reason
refreshControl: ReasonReact.reactElement=?
```

### scrollEnabled

```reason
scrollEnabled: bool=?
```

### showsHorizontalScrollIndicator

```reason
showsHorizontalScrollIndicator: bool=?
```

### showsVerticalScrollIndicator

```reason
showsVerticalScrollIndicator: bool=?
```

### stickyHeaderIndices

```reason
stickyHeaderIndices: list(int)=?
```

### overScrollMode

```reason
overScrollMode: [
  | `always
  | `auto
  | `never
]=?
```

### scrollPerfTag

```reason
scrollPerfTag: string=?
```

### alwaysBounceHorizontal

```reason
alwaysBounceHorizontal: bool=?
```

### alwaysBounceVertical

```reason
alwaysBounceVertical: bool=?
```

### automaticallyAdjustContentInsets

```reason
automaticallyAdjustContentInsets: bool=?
```

### bounces

```reason
bounces: bool=?
```

### canCancelContentTouches

```reason
canCancelContentTouches: bool=?
```

### centerContent

```reason
centerContent: bool=?
```

### contentInset

```reason
contentInset: Types.insets=?
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

### contentOffset

```reason
contentOffset: point=?
```

_reference:_

```reason
type point = {
  x: float,
  y: float
};
```

### decelerationRate

```reason
decelerationRate: [
  | `fast
  | `normal
]=?
```

### directionalLockEnabled

```reason
directionalLockEnabled: bool=?
```

### indicatorStyle

```reason
indicatorStyle: [
  | `black
  | `default
  | `white
]=?
```

### maximumZoomScale

```reason
maximumZoomScale: float=?
```

### minimumZoomScale

```reason
minimumZoomScale: float=?
```

### onScrollAnimationEnd

```reason
onScrollAnimationEnd: unit => unit=?
```

### scrollEventThrottle

```reason
scrollEventThrottle: int=?
```

### scrollIndicatorInsets

```reason
scrollIndicatorInsets: Types.insets=?
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

### scrollsToTop

```reason
scrollsToTop: bool=?
```

### snapToAlignment

```reason
snapToAlignment: [
  | `center
  | `end_
  | `start
]=?
```

### zoomScale

```reason
zoomScale: float=?
```
