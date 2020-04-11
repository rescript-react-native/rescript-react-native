---
id: apis/Event
title: Event
officialDoc: https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js
---

These are the types of objects returned in `Event` callbacks. Types are
instances of `syntheticEvent('a)` and `responderSyntheticEvent('a)`.

## Parametrised Types

### `syntheticEvent('a)`

```reason
type syntheticEvent('a) = {
  .
  "bubbles": Js.Nullable.t(bool),
  "cancelable": Js.Nullable.t(bool),
  "currentTarget": float,
  "defaultPrevented": Js.Nullable.t(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": Js.Nullable.t(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": Js.Nullable.t(float),
  "timeStamp": float,
  "_type": Js.Nullable.t(string),
};
```

### `responderSyntheticEvent('a)`

`responderSyntheticEvent('a)` adds the `touchHistory` key to
`syntheticEvent('a)`

```reason
type responderSyntheticEvent('a) = {
  .
  // synthethicEvent keys
  "bubbles": Js.Nullable.t(bool),
  "cancelable": Js.Nullable.t(bool),
  "currentTarget": float,
  "defaultPrevented": Js.Nullable.t(bool),
  "dispatchConfig": {. "registrationName": string},
  "eventPhase": Js.Nullable.t(float),
  [@bs.meth] "preventDefault": unit => unit,
  [@bs.meth] "isDefaultPrevented": unit => bool,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "isPropagationStopped": unit => bool,
  "isTrusted": Js.Nullable.t(bool),
  "nativeEvent": 'a,
  [@bs.meth] "persist": unit => unit,
  "target": Js.Nullable.t(float),
  "timeStamp": float,
  "_type": Js.Nullable.t(string),
  "touchHistory": {
    .
    "indexOfSingleActiveTouch": float,
    "mostRecentTimeStamp": float,
    "numberActiveTouches": float,
    "touchBank":
      array({
        .
        "touchActive": bool,
        "startPageX": float,
        "startPageY": float,
        "startTimeStamp": float,
        "currentPageX": float,
        "currentPageY": float,
        "currentTimeStamp": float,
        "previousPageX": float,
        "previousPageY": float,
        "previousTimeStamp": float,
      }),
  },
};
```

## Types

### `layoutEvent`

```reason
type layoutEvent = syntheticEvent(layout)
```

where `layout` is defined as

```reason
type layout = {
  x: float,
  y: float,
  width: float,
  height: float,
};
```

### `pressEvent`

```reason
type pressEvent = responderSyntheticEvent(pressEventPayload);
```

where `pressEventPayload` is defined as

```reason
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
};
```

### `scrollEvent`

```reason
type scrollEvent = syntheticEvent(scrollEventPayload)
```

where `scrollEventPayload` is defined as

```reason
type scrollEventPayload = {
  contentInset,
  contentOffset,
  contentSize: dimensions,
  layoutMeasurement: dimensions,
}
```

and `contentInset`, `contentOffset` and `dimensions` are defined as

```reason
type contentInset = {
  bottom: float,
  left: float,
  right: float,
  top: float,
};
```

```reason
type contentOffset = {
  x: float,
  y: float,
};
```

```reason
type dimensions = {
  height: float,
  width: float,
};
```

### `switchChangeEvent`

```reason
type switchChangeEvent = syntheticEvent(switchChangePayload)
```

where `switchChangePayload` is defined as

```reason
type switchChangePayload = {value: bool};
```

### `targetEvent`

```reason
type targetEvent = syntheticEvent(targetPayload)
```

where `targetPayload` is defined as

```reason
type targetPayload = {target: int};
```

### `textLayoutEvent`

```reason
type textLayoutEvent = syntheticEvent(textLayouts);
```

where `textLayouts` and `textLayout` are defined as

```reason
type textLayouts = {lines: array(textLayout)};
```

and

```reason
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
};
```
