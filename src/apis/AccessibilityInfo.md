---
id: apis/AccessibilityInfo
title: AccessibilityInfo
officialDoc: https://reactnative.dev/docs/accessibilityinfo
---

## Types

### `announcementResult`

Passed to the handler of the `` `announcementFinished `` event.

```reason
type announcementResult = {
  .
  "announcement": string,
  "success": bool,
}
```

where `announcement` is the string announced by the screen reader and `success`
is a `bool` indicating whether the announcement was successfully made.

## Methods

### `isBoldTextEnabled`

_iOS only_

To query whether bold text is currently enabled. Promise resolves to `true` when
bold text is enabled and `false` otherwise.

```reason
isBoldTextEnabled: unit => Js.Promise.t(bool)
```

### `isGrayscaleEnabled`

_iOS only_

To query whether grayscale is currently enabled. Promise resolves to `true` when
grayscale is enabled and `false` otherwise.

```reason
isGrayscaleEnabled: unit => Js.Promise.t(bool)
```

### `isInvertColorsEnabled`

_iOS only_

To query whether invert colors is currently enabled. Promise resolves to `true`
when invert colors is enabled and `false` otherwise.

```reason
isInvertColorsEnabled: unit => Js.Promise.t(bool)
```

### `isReduceMotionEnabled`

To query whether reduce motion is currently enabled. Promise resolves to `true`
when reduce motion is enabled and `false` otherwise.

```reason
[@bs.scope "AccesibilityInfo"] [@bs.module "react-native"]
external isReduceMotionEnabled: unit => Js.Promise.t(bool) = "isReduceMotionEnabled";
```

### `isReduceTransparencyEnabled`

_iOS only_

To query whether reduce transparency is currently enabled. Promise resolves to
`true` when reduce transparency is enabled and `false` otherwise.

```reason
[@bs.scope "AccesibilityInfo"] [@bs.module "react-native"]
external isReduceTransparencyEnabled: unit => Js.Promise.t(bool) = "isReduceTransparencyEnabled";
```

### `isScreenReaderEnabled`

To query whether screen reader is currently enabled. Promise resolves to `true`
when screen reader is enabled and `false` otherwise.

```reason
[@bs.scope "AccesibilityInfo"] [@bs.module "react-native"]
external isScreenReaderEnabled: unit => Js.Promise.t(bool) = "isScreenReaderEnabled";
```

### `setAccessibilityFocus`

To set accessibility focus to a React component, identified by its `nodeHandle`.
On Android, this is equivalent to
`UIManager.sendAccessibilityEvent(reactTag, UIManager.AccessibilityEventTypes.typeViewFocused)`;

```reason
setAccessibilityFocus: NativeTypes.nodeHandle => unit
```

### `announceForAccessibility`

To post a string to be announced by the screen reader.

```reason
announceForAccessibility: string => unit
```

### `addEventListener`

Add an event handler.

```reason
addEventListener: [
    | `boldTextChanged(bool => unit)
    | `grayscaleChanged(bool => unit)
    | `invertColorsChanged(bool => unit)
    | `reduceMotionChanged(bool => unit)
    | `screenReaderChanged(bool => unit)
    | `reduceTransparencyChanged(bool => unit)
    | `announcementFinished(announcementResult => unit)
  ] => unit
```

Supported events:

- `boldTextChanged(bool => unit)`: _iOS only_. Fires when state of the bold text
  toggle changes. The argument to the event handler is a `bool` which is `true`
  when bold text is enabled and `false` otherwise.
- `grayscaleChanged(bool => unit)`: _iOS only_. Fires when state of the gray
  scale toggle changes. The argument to the event handler is a `bool` which is
  `true` when gray scale is enabled and `false` otherwise.
- `invertColorsChanged(bool => unit)`: _iOS only_. Fires when state of the
  invert colors toggle changes. The argument to the event handler is a `bool`
  which is `true` when invert colors is enabled and `false` otherwise.
- `reduceMotionChanged(bool => unit)`: Fires when state of the reduce motion
  toggle changes. The argument to the event handler is a `bool` which is `true`
  when reduce motion is enabled (or when "Transition Animation Scale" in
  "Developer options" is "Animation off") and `false` otherwise.
- `screenReaderChanged(bool => unit)`: Fires when state of the screen reader
  changes. The argument to the event handler is a `bool` which is `true` when a
  screen reader is enabled and `false` otherwise.
- `reduceTransparencyChanged(bool => unit)`: _iOS only_. Fires when state of the
  reduce transparency toggle changes. The argument to the event handler is a
  `bool` which is `true` when reduce transparency is enabled and `false`
  otherwise.
- `announcementFinished(announcementResult => unit)`: _iOS only_. Fires when the
  screen reader has finished making an announcement. The argument to the event
  handler is of type [`announcementResult`](#announcementResult).

### `removeEventListener`

To remove an event handler.

```reason
addEventListener: [
    | `boldTextChanged(bool => unit)
    | `grayscaleChanged(bool => unit)
    | `invertColorsChanged(bool => unit)
    | `reduceMotionChanged(bool => unit)
    | `screenReaderChanged(bool => unit)
    | `reduceTransparencyChanged(bool => unit)
    | `announcementFinished(announcementResult => unit)
  ] => unit
```

See [`addEventListener`](#addEventListener) for more details on supported
events.
