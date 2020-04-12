---
id: apis/PanResponder
title: PanResponder
officialDoc: https://reactnative.dev/docs/panresponder
---

`PanResponder` allows more fine-grained control of the
[_Gesture Responder System_](https://reactnative.dev/docs/gesture-responder-system),
as the handlers can depend also on `gestureState`, in addition to the
`Event.pressEvent` which are passed to the _Gesture Responder System_ handlers.
In essence, by means of a custom `PanResponder`, _Gesture Responder System_
handlers are extended to also depend upon the `gestureState`.

## Types

### `Event.pressEvent`

see [`Event`](../Event/#pressevent)

### `gestureState`

`gestureState` contains additional information on the state of the \_Gesture
Responder System\_

```reason
type gestureState = {
  stateID: float,
  moveX: float,
  moveY: float,
  x0: float,
  y0: float,
  dx: float,
  dy: float,
  vx: float,
  vy: float,
  numberActiveTouches: int,
}
```

### `t`

`t` is the abstract type for a `PanResponder`, which can be created by means of
the `create` method, given a `config` object

### `config`

`config` is the abstract type for a custom `PanResponder` configuration; it can
be created by means of the `config` constructor

```reason
config:
  (
    ~onMoveShouldSetPanResponder: (Event.pressEvent, gestureState) => bool=?,
    ~onMoveShouldSetPanResponderCapture: (Event.pressEvent, gestureState) =>
                                         bool
                                           =?,
    ~onStartShouldSetPanResponder: (Event.pressEvent, gestureState) => bool=?,
    ~onStartShouldSetPanResponderCapture: (Event.pressEvent, gestureState) =>
                                          bool
                                            =?,
    ~onPanResponderReject: (Event.pressEvent, gestureState) => unit=?,
    ~onPanResponderGrant: (Event.pressEvent, gestureState) => unit=?,
    ~onPanResponderStart: (Event.pressEvent, gestureState) => unit=?,
    ~onPanResponderEnd: (Event.pressEvent, gestureState) => unit=?,
    ~onPanResponderRelease: (Event.pressEvent, gestureState) => unit=?,
    ~onPanResponderMove: (Event.pressEvent, gestureState) => unit=?,
    ~onPanResponderTerminate: (Event.pressEvent, gestureState) => unit=?,
    ~onPanResponderTerminationRequest: (Event.pressEvent, gestureState) => bool
                                         =?,
    ~onShouldBlockNativeResponder: (Event.pressEvent, gestureState) => bool=?,
    unit
  ) => config
```

### `panHandlers`

`panHandlers` is the abstract type for `panHandlers` of a `PanResponder`, which
can be accessed by means of the getter method `panHandlers`

### `callback('a)`

`callback('a)` is the type of the usual callback function specified for each
_Gesture Responder System_ handler defined as

```reason
type callback('a) = Event.pressEvent => 'a
```

where `'a` is either `bool` or `unit`

## Methods

### `create`

`create` allows creation of a `PanResponder` given a `config`

```reason
create: config => t
```

### `panHandlers`

`panHandlers` is a getter method to access `panHandlers` within a `PanResponder`

```reason
panHandlers: t => panHandlers
```

### `onMoveShouldSetResponder`

`onMoveShouldSetResponder` is a getter method to access the
`onMoveShouldSetResponder` callback of a `panHandlers` object

```reason
onMoveShouldSetResponder: panHandlers => callback(bool)
```

### `onMoveShouldSetResponderCapture`

`onMoveShouldSetResponderCapture` is a getter method to access the
`onMoveShouldSetResponderCapture` callback of a `panHandlers` object

```reason
onMoveShouldSetResponderCapture: panHandlers => callback(bool)
```

### `onStartShouldSetResponder`

`onStartShouldSetResponder` is a getter method to access the
`onStartShouldSetResponder` callback of a `panHandlers` object

```reason
onStartShouldSetResponder: panHandlers => callback(bool)
```

### `onStartShouldSetResponderCapture`

`onStartShouldSetResponderCapture` is a getter method to access the
`onStartShouldSetResponderCapture` callback of a `panHandlers` object

```reason
onStartShouldSetResponderCapture: panHandlers => callback(bool)
```

### `onResponderReject`

`onResponderReject` is a getter method to access the `onResponderReject`
callback of a `panHandlers` object

```reason
onResponderReject: panHandlers => callback(unit)
```

### `onResponderGrant`

`onResponderGrant` is a getter method to access the `onResponderGrant` callback
of a `panHandlers` object

```reason
onResponderGrant: panHandlers => callback(unit)
```

### `onResponderRelease`

`onResponderRelease` is a getter method to access the `onResponderRelease`
callback of a `panHandlers` object

```reason
onResponderRelease: panHandlers => callback(unit)
```

### `onResponderMove`

`onResponderMove` is a getter method to access the `onResponderMove` callback of
a `panHandlers` object

```reason
onResponderMove: panHandlers => callback(unit)
```

### `onResponderTerminate`

`onResponderTerminate` is a getter method to access the `onResponderTerminate`
callback of a `panHandlers` object

```reason
onResponderTerminate: panHandlers => callback(unit)
```

### `onResponderStart`

`onResponderStart` is a getter method to access the `onResponderStart` callback
of a `panHandlers` object

```reason
onResponderStart: panHandlers => callback(unit)
```

### `onResponderTerminationRequest`

`onResponderTerminationRequest` is a getter method to access the
`onResponderTerminationRequest` callback of a `panHandlers` object

```reason
onResponderTerminationRequest: panHandlers => callback(bool)
```

### `onResponderEnd`

`onResponderEnd` is a getter method to access the `onResponderEnd` callback of a
`panHandlers` object

```reason
onResponderEnd: panHandlers => callback(unit)
```

## Example

As props spread is not possible with the ReasonML JSX 3 syntax, each _Gesture
Responder System_ callback needs to be separately specified, with the relevant
value obtained by means of the associated getter.

While props spread may not be available, copy-paste is probably supported by
your editor...

```reason
onMoveShouldSetResponder={
  panHandlers->PanResponder.onMoveShouldSetResponder
}
onMoveShouldSetResponderCapture={
  panHandlers->PanResponder.onMoveShouldSetResponderCapture
}
onStartShouldSetResponder={
  panHandlers->PanResponder.onStartShouldSetResponder
}
onStartShouldSetResponderCapture={
  panHandlers->PanResponder.onStartShouldSetResponderCapture
}
onResponderReject={panHandlers->PanResponder.onResponderReject}
onResponderGrant={panHandlers->PanResponder.onResponderGrant}
onResponderRelease={panHandlers->PanResponder.onResponderRelease}
onResponderMove={panHandlers->PanResponder.onResponderMove}
onResponderTerminate={panHandlers->PanResponder.onResponderTerminate}
onResponderStart={panHandlers->PanResponder.onResponderStart}
onResponderTerminationRequest={
  panHandlers->PanResponder.onResponderTerminationRequest
}
onResponderEnd={panHandlers->PanResponder.onResponderEnd}
```

Then, the custom `PanResponder` can be used as below:

```reason
open ReactNative;

let windowHeight = Dimensions.get(`window).height;
let windowWidth = Dimensions.get(`window).width;

let containerStyle =
  Style.(
    style(
      ~width=windowWidth->dp,
      ~height=windowHeight->dp,
      ~justifyContent=`center,
      ~alignItems=`center,
      (),
    )
  );

let config =
  PanResponder.config(
    ~onMoveShouldSetPanResponder=(_e, _g) => true,
    ~onPanResponderRelease=
      (_e, g) =>
        g##dx > 0.
          ? "You swiped right"->Js.Console.warn
          : "You swiped left"->Js.Console.warn,
    (),
  );

let panResponder = PanResponder.create(config);

let panHandlers = panResponder->PanResponder.panHandlers;

[@react.component]
let make = () => {
  <View
    style=containerStyle
    onMoveShouldSetResponder={
      panHandlers->PanResponder.onMoveShouldSetResponder
    }
    onMoveShouldSetResponderCapture={
      panHandlers->PanResponder.onMoveShouldSetResponderCapture
    }
    onStartShouldSetResponder={
      panHandlers->PanResponder.onStartShouldSetResponder
    }
    onStartShouldSetResponderCapture={
      panHandlers->PanResponder.onStartShouldSetResponderCapture
    }
    onResponderReject={panHandlers->PanResponder.onResponderReject}
    onResponderGrant={panHandlers->PanResponder.onResponderGrant}
    onResponderRelease={panHandlers->PanResponder.onResponderRelease}
    onResponderMove={panHandlers->PanResponder.onResponderMove}
    onResponderTerminate={panHandlers->PanResponder.onResponderTerminate}
    onResponderStart={panHandlers->PanResponder.onResponderStart}
    onResponderTerminationRequest={
      panHandlers->PanResponder.onResponderTerminationRequest
    }
    onResponderEnd={panHandlers->PanResponder.onResponderEnd}>
    <Text> "Please swipe"->React.string </Text>
  </View>;
};

```
