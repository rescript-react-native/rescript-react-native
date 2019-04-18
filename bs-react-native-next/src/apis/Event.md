---
id: apis/Event
title: Event
wip: true
---

```reason
// see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js

type event('a) = {. "nativeEvent": 'a};

type pressEventPayload = {
  .
  "changedTouches": array(pressEventPayload),
  "force": float,
  "identifier": int,
  "locationX": float,
  "locationY": float,
  "pageX": float,
  "pageY": float,
  "target": Js.Nullable.t(float),
  "timestamp": float,
  "touches": array(pressEventPayload),
};

type pressEvent = event(pressEventPayload);

type position = {
  .
  "y": float,
  "x": float,
};

type dimensions = {
  .
  "height": float,
  "width": float,
};

type scrollEvent =
  event({
    .
    "contentInset": {
      .
      "bottom": float,
      "left": float,
      "right": float,
      "top": float,
    },
    "contentOffset": position,
    "contentSize": dimensions,
    "layoutMeasurement": dimensions,
  });

type layoutEvent =
  event({
    .
    "layout": {
      .
      "x": float,
      "y": float,
      "width": float,
      "height": float,
    },
  });
    
```
