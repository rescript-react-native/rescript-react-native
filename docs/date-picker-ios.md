---
title: DatePickerIOS
---

## Example of use

`DatePickerIOS` requires `date` and `onDateChange` props to be rendered:

### default

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <DatePickerIOS
      date=(Js.Date.fromString("February 12, 1990 17:40"))
      onDateChange=(date => Js.log(date))
    />,
};
```

Here you can find BuckleScript's [`Js.Date` API](https://bucklescript.github.io/bucklescript/api/Js_date.html).

[The JavaScript Date API](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date) might also be a useful resource.

### mode

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <DatePickerIOS
      date=(Js.Date.fromString("February 12, 1990 17:40"))
      onDateChange=(date => Js.log(date))
      mode=`date
    />,
};
```

## Props

### date

```reason
date: Js.Date.t
```

### onDateChange

```reason
onDateChange: Js.Date.t => unit
```

### maximumDate

```reason
maximumDate: Js.Date.t=?
```

### minimumDate

```reason
minimumDate: Js.Date.t=?
```

### mode

```reason
mode: [
  | `date
  | `datetime
  | `time
]=?
```

### minuteInterval

```reason
minuteInterval: int=?
```

### timeZoneOffsetInMinutes

```reason
timeZoneOffsetInMinutes: int=?
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
