---
id: apis/Event
title: Event
officialDoc: https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js
---

These are the types of objects returned in `Event` callbacks. Types are
instances of `syntheticEvent<'a>` and `responderSyntheticEvent<'a>`.

## Parametrised Types

### `syntheticEvent<'a>`

```rescript
type syntheticEvent<'a> = {
  bubbles: Js.Nullable.t<bool>,
  cancelable: Js.Nullable.t<bool>,
  currentTarget: float,
  defaultPrevented: Js.Nullable.t<bool>,
  dispatchConfig: registrationName,
  eventPhase: Js.Nullable.t<float>,
  isTrusted: Js.Nullable.t<bool>,
  nativeEvent: T._payload,
  target: Js.Nullable.t<float>,
  timeStamp: float,
  _type: Js.Nullable.t<string>,
}
```

### `responderSyntheticEvent<'a>`

`responderSyntheticEvent<'a>` adds the `touchHistory` key to
`syntheticEvent<'a>`

```rescript
type responderSyntheticEvent<'a> = {
  bubbles: Js.Nullable.t<bool>,
  cancelable: Js.Nullable.t<bool>,
  currentTarget: float,
  defaultPrevented: Js.Nullable.t<bool>,
  dispatchConfig: registrationName,
  eventPhase: Js.Nullable.t<float>,
  isTrusted: Js.Nullable.t<bool>,
  nativeEvent: T._payload,
  target: Js.Nullable.t<float>,
  timeStamp: float,
  _type: Js.Nullable.t<string>,
  touchHistory: touchHistory,
}
```

## Types

### `layoutEvent`

```rescript
type layoutEvent = syntheticEvent<layout>
```

where `layout` is defined as

```rescript
type layout = {
  x: float,
  y: float,
  width: float,
  height: float,
}
```

### `pressEvent`

```rescript
type pressEvent = responderSyntheticEvent<pressEventPayload>
```

where `pressEventPayload` is defined as

```rescript
type pressEventPayload = {
  changedTouches: array(pressEventPayload),
  force: float,
  identifier: int,
  locationX: float,
  locationY: float,
  pageX: float,
  pageY: float,
  target: Js.Nullable.t(float),
  timestamp: float,
  touches: array(pressEventPayload),
}
```

### `scrollEvent`

```rescript
type scrollEvent = syntheticEvent<scrollEventPayload>
```

where `scrollEventPayload` is defined as

```rescript
type scrollEventPayload = {
  contentInset,
  contentOffset,
  contentSize: dimensions,
  layoutMeasurement: dimensions,
}
```

and `contentInset`, `contentOffset` and `dimensions` are defined as

```rescript
type contentInset = {
  bottom: float,
  left: float,
  right: float,
  top: float,
}
```

```rescript
type contentOffset = {
  x: float,
  y: float,
}
```

```rescript
type dimensions = {
  height: float,
  width: float,
}
```

### `switchChangeEvent`

```rescript
type switchChangeEvent = syntheticEvent<switchChangePayload>
```

where `switchChangePayload` is defined as

```rescript
type switchChangePayload = {value: bool}
```

### `targetEvent`

```rescript
type targetEvent = syntheticEvent<targetPayload>
```

where `targetPayload` is defined as

```rescript
type targetPayload = {target: int}
```

### `textLayoutEvent`

```rescript
type textLayoutEvent = syntheticEvent<textLayouts>
```

where `textLayouts` and `textLayout` are defined as

```rescript
type textLayouts = {lines: array(textLayout)}
```

and

```rescript
type textLayout = {
  x: float,
  y: float,
  width: float,
  height: float,
  ascender: float, // verify
  capHeight: float, // verify
  descender: float, // verify
  text: string,
  xHeight: float // verify
}
```
