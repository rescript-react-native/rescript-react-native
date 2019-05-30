---
id: apis/PanResponder
title: PanResponder
officialDoc: http://facebook.github.io/react-native/docs/panresponder
---

`PanResponder` allows more fine-grained control of the
[_Gesture Responder System_](http://facebook.github.io/react-native/docs/gesture-responder-system),
as the handlers can depend also on `gestureState`, in addition to the
`Event.pressEvent` which are passed to the _Gesture Responder System_ handlers.
In essence, by means of a custom `PanResponder`, _Gesture Responder System_
handlers are extended to also depend upon the `gestureState`.

## Types

### `Event.pressEvent`
see [`Event`](../Event/#pressEvent)

### `gestureState`
`gestureState` contains additional information on the state of the \_Gesture
Responder System\_

```reason
type gestureState = {
  .
  "stateID": float,
  "moveX": float,
  "moveY": float,
  "x0": float,
  "y0": float,
  "dx": float,
  "dy": float,
  "vx": float,
  "vy": float,
  "numberActiveTouches": int,
}
```

### `t`
`t` is the abstract type for a `PanResponder`, which can be created by means
of the `create` method, given a `config` object

### `config`
`config` is the abstract type for a custom `PanResponder` configuration; it
can be created by means of the `config` constructor

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
  )
```

### `panHandlers`
`panHandlers` is the abstract type for `panHandlers` of a `PanResponder`,
which can be accessed by means of the getter method `panHandlers`

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
create(config)
```

### `panHandlers`
`panHandlers` is a getter method to access `panHandlers` within a

`PanResponder`

```reason
panHandlers(t)
```

### `onMoveShouldSetResponder`
`onMoveShouldSetResponder` is a getter method to access the
`onMoveShouldSetResponder` callback of a `panHandlers` object

```reason
onMoveShouldSetResponder(panHandlers)
```

### `onMoveShouldSetResponderCapture`
`onMoveShouldSetResponderCapture` is a getter method to access the
`onMoveShouldSetResponderCapture` callback of a `panHandlers` object

```reason
onMoveShouldSetResponderCapture(panHandlers)
```

### `onStartShouldSetResponder`
`onStartShouldSetResponder` is a getter method to access the
`onStartShouldSetResponder` callback of a `panHandlers` object

```reason
onStartShouldSetResponder(panHandlers)
```

### `onStartShouldSetResponderCapture`
`onStartShouldSetResponderCapture` is a getter method to access the
`onStartShouldSetResponderCapture` callback of a `panHandlers` object

```reason
onStartShouldSetResponderCapture(panHandlers)
```

### `onResponderReject`
`onResponderReject` is a getter method to access the `onResponderReject`
callback of a `panHandlers` object

```reason
onResponderReject(panHandlers)
```

### `onResponderGrant`
`onResponderGrant` is a getter method to access the `onResponderGrant`
callback of a `panHandlers` object

```reason
onResponderGrant(panHandlers)
```

### `onResponderRelease`
`onResponderRelease` is a getter method to access the `onResponderRelease`
callback of a `panHandlers` object

```reason
onResponderRelease(panHandlers)
```

### `onResponderMove`
`onResponderMove` is a getter method to access the `onResponderMove` callback
of a `panHandlers` object

```reason
onResponderMove(panHandlers)
```

### `onResponderTerminate`
`onResponderTerminate` is a getter method to access the `onResponderTerminate`
callback of a `panHandlers` object

```reason
onResponderTerminate(panHandlers)
```

### `onResponderStart`
`onResponderStart` is a getter method to access the `onResponderStart`
callback of a `panHandlers` object

```reason
onResponderStart(panHandlers)
```

### `onResponderTerminationRequest`
`onResponderTerminationRequest` is a getter method to access the
`onResponderTerminationRequest` callback of a `panHandlers` object

```reason
onResponderTerminationRequest(panHandlers)
```

### `onResponderEnd`
`onResponderEnd` is a getter method to access the `onResponderEnd` callback of
a `panHandlers` object

```reason
onResponderEnd(panHandlers)
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

let windowHeight = Dimensions.get(`window)##height->float_of_int;
let windowWidth = Dimensions.get(`window)##width->float_of_int;

let containerStyle =
  Style.(
    style(
      ~width=windowWidth->pt,
      ~height=windowHeight->pt,
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
