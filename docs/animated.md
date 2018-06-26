---
id: animated
title: Animated
sidebar_label: Animated
---

## Example of use

`Animated` allows to create declarative animations that are fluid, powerful and easy to build.

### basic

The simplest animation starts with creating an animated value and using one of the built-in animations to change its value over time.

The following example demonstrates use of `Animated.Timing` in order to animate an animated value throughout given period of time.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let animation =
  Animated.timing(
    ~value=animatedValue,
    ~toValue=`raw(1.0),
    ~duration=100.0,
    (),
  );

Animated.start(animation, ());
```

### multiple

Animations can be also combined together in complex ways using composition functions.

The following example demonstrates use of `Animated.sequence` in order to run animations in a sequence, one by one.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let animation =
  Animated.sequence([|
    Animated.timing(
      ~value=animatedValue,
      ~toValue=`raw(1.0),
      ~duration=100.0,
      (),
    ),
    Animated.timing(
      ~value=animatedValue,
      ~toValue=`raw(0.0),
      ~duration=100.0,
      (),
    ),
  |]);

Animated.start(animation, ());
```

### calculation

You can combine two animated values via addition, multiplication, division, or modulo to make a new animated value.

The following example demonstrates use of `Animated.multiply` in order to reverse the value of the `animatedValue`.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let newAnimatedValue = Animated.multiply(animatedValue, Animated.Value.create(-1.0));
```

Keep in mind that calculated values (such as `newAnimatedValue` from the snippet above) cannot be animated. Trying to pass them to any of the animated functions will result in a type error.

### interpolation

You can interpolate an animated value in order to bind to its value and change the output.

The following example demonstrates interpolation in order to map values of an animated value to the opacity of a container.

```reason
let animatedValue = Animated.Value.create(100.0);

let animatedOpacity =
  Animated.Value.interpolate(
    animatedValue,
    ~inputRange=[0.0, 100.0],
    ~outputRange=`float([0.0, 1.0]),
    ~extrapolate=Animated.Interpolation.Clamp,
    (),
  );
```

### styling

Animated values can be passed to an animated component in order to change its apperance as the animated value changes.

The example below demonstrates animating opacity of a component.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let component = ReasonReact.statelessComponent("MyComponent");

let containerStyle = Style.(
  style([
    opacity(Animated(animatedValue))
    flex(1.0)
  ])
);

let make = _children => {
  ...component,
  didMount: _self => {
    Animated.start(
      Animated.timing(
        ~value=animatedValue,
        ~toValue=`raw(1.0),
        ~duration=100.0,
        (),
      ),
      ~callback=_didFinish => (),
      ()
    );
  },
  render: _self => <Animated.View style=containerStyle />,
};
```

### event

### custom component

## Animations

Animated provides three types of animation types. Each animation type provides a particular animation curve that controls how your values animate from their initial value to the final value.

### Configuration

Below is the list of common configuration options applicable to all below animations.

#### toValue

```reason
~toValue: [ | `raw(float) | `animated(Animated.value))]
```

#### value

```reason
~value: Animated.value
```

#### useNativeDriver

```reason
~useNativeDriver: bool=?
```

#### iterations

```reason
~iterations: int=?
```

#### isInteraction

```reason
~isInteraction: bool=?
```

### spring

Provides a simple spring physics model.

```reason
let animatedValue = Animated.Value.create(0.0);

let animation = Animated.spring(
  ~value=animatedValue,
  ~toValue=`raw(1.0),
  ~bounciness=5.0,
  (),
);

Animated.start(animation, ());
```

See available configuration below:

#### restDisplacementThreshold

```reason
~restDisplacementThreshold: float=?
```

#### overshootClamping

```reason
~overshootClamping: bool=?
```

#### restSpeedThreshold

```reason
~restSpeedThreshold: float=?
```

#### velocity

```reason
~velocity: float=?
```

#### bounciness

```reason
~bounciness: float=?
```

#### speed

```reason
~speed: float=?
```

#### tension

```reason
~tension: float=?
```

#### friction

```reason
~friction: float=?
```

#### stiffness

```reason
~stiffness: float=?
```

#### mass

```reason
~mass: float=?
```

#### damping

```reason
~damping: float=?
```

### Timing

Animates a value over time using easing functions.

```reason
let animatedValue = Animated.Value.create(0.0);

let animation = Animated.timing(
  ~value=animatedValue,
  ~toValue=`raw(1.0),
  ~duration=100.0,
  (),
);

Animated.start(animation, ());
```

See available configuration below:

#### easing

```reason
~easing: Easing.t=?
```

Easing function. See [Easing](/docs/easing.html) for available options.

#### duration

```reason
~duration: float=?
```

#### delay

```reason
~delay: float=?
```

### decay

Starts with an initial velocity and gradually slows to a stop.

```reason
let animatedValue = Animated.Value.create(0.0);

let animation = Animated.decay(
  ~value=animatedValue,
  ~toValue=`raw(1.0),
  ~velocity=100.0,
  (),
);

Animated.start(animation, ());
```

See available configuration below:

#### velocity

```reason
~velocity: float
```

#### deceleration

```reason
~deceleration: float=?
```

### Composition

Animations presented in the previous section can be combined all together in many complex ways using the following API.

### parallel

```reason
let parallel:
  (array(Animation.t), {. "stopTogether": bool}) =>
  Animation.t;
```

Runs an array of animations in parallel.

#### Example

```reason
let fooValue = Animated.Value.create(0.0);
let barValue = Animated.Value.create(0.0);

let animation =
  Animated.parallel(
    [|
      Animated.timing(
        ~value=fooValue,
        ~toValue=`raw(1.0),
        ~duration=100.0,
        (),
      ),
      Animated.timing(
        ~value=barValue,
        ~toValue=`raw(0.0),
        ~duration=100.0,
        (),
      ),
    |],
    {"stopTogether": false},
  );

Animated.start(animation, ());
```

When `stopTogether` is set to `true`, `callback` passed to `Animated.start` will get executed only once, after all animations within the array have finished. Otherwise, it may get executed many times. You should check for the value of `didFinish` boolean that is the first argument to the callback function.

### stagger

```reason
let stagger: (float, array(Animation.t)) => Animation.t;
```

Array of animations may run in parallel (overlap), but are started in sequence with successive delays.

#### Example

```reason
let fooValue = Animated.Value.create(0.0);
let barValue = Animated.Value.create(0.0);

let animation =
  Animated.stagger(
    50.0,
    [|
      Animated.timing(
        ~value=fooValue,
        ~toValue=`raw(1.0),
        ~duration=100.0,
        (),
      ),
      Animated.timing(
        ~value=barValue,
        ~toValue=`raw(0.0),
        ~duration=100.0,
        (),
      ),
    |],
  );

Animated.start(animation, ());
```

### delay

```reason
let delay: float => Animation.t;
```

Helper function to delay execution of the animation. To be used with other Animated functions, as demonstrated at the below example.

#### Example

```reason
let barValue = Animated.Value.create(0.0);

let animation =
  Animated.sequence(
    [|
      Animated.delay(500),
      Animated.timing(
        ~value=barValue,
        ~toValue=`raw(0.0),
        ~duration=100.0,
        (),
      ),
    |],
    {"stopTogether": false},
  );

Animated.start(animation, ());
```

The above example will delay the `barValue` animation by 500 milliseconds.

### sequence

```reason
let sequence: array(Animation.t) => Animation.t;
```

Starts an array of animations in order, waiting for each to complete before starting the next. If the current running animation is stopped, no following animations will be started.

#### Example

See the example [in the previous section](#delay).

### loop

```reason
let loop:
  (~iterations: int=?, ~animation: Animation.t, unit) =>
  Animation.t;
```

Loops a given animation continuously, so that each time it reaches the end, it resets and begins again from the start.

You can specify the number of interations explicitly here or use [iterations](#iterations) property when defining animation.

#### Example

```reason
let fooValue = Animated.Value.create(0.0);

let animation =
  Animated.loop(
    ~animation=Animated.timing(
      ~value=fooValue,
      ~toValue=`raw(0.0),
      ~iterations=4,
      ~duration=100.0,
      (),
    ),
    (),
  );

Animated.start(animation, ());
```

## Animated.Value

There are few types of Animated values present in React Native codebase. Not all operations are permitted on all of them.

To prevent mistakes in user land and provide type safety, Rebolt uses phantom types to distinguish between different types of values:

- `Animated.value(regular)` - created with `Animated.Value.create`. Can be animated, interpolated as well as used for math operations

- `Animated.value(calculated)` - dynamic value created either by interpolating another animated value or by using math operations. Cannot be animated, because it's not a root animated value.

In the below documentation, `Animated.value('a)` means that any animated value can be used.

### create

```reason
let create: float => Animated.Value.t;
```

Creates a new animated value.

### add

```reason
let add : (Animated.value('a), Animated.value('b)) => Animated.value(calculated);
```

### divide

```reason
let divide : (Animated.value('a), Animated.value('b)) => Animated.value(calculated) = "";
```

### multiply

```reason
let multiply : (Animated.value('a), Animated.value('b)) => Animated.value(calculated) = "";
```

### diffClamp

```reason
let diffClamp : (Animated.value('a), float, float) => Animated.value(calculated) = "";
```

### modulo

```reason
let diffClamp : (Animated.value('a), float) => Animated.value(calculated) = "";
```

### interpolate

Shorthand for [Animated.Interpolation.interpolate](#interpolation).

### setValue

```reason
let setValue: (t, float) => unit;
```

### setOffset

```reason
let setOffset: (t, float) => unit;
```

### flattenOffset

```reason
let flattenOffset: t => unit;
```

### extractOffset

```reason
let extractOffset: t => unit;
```

### addListener

```reason
let addListener: (t, callback) => string;
```

### removeListener

```reason
let removeListener: (t, string) => unit;
```

### removeAllListeners

```reason
let removeAllListeners: t => unit;
```

### stopTracking

```reason
let removeAllListeners: t => unit;
```

### track

```reason
let track: t => unit;
```

## Interpolation

### interpolate

```reason
let interpolate:
  (
    Animated.value('a),
    ~inputRange: list(float),
    ~outputRange: [< | `float(list(float)) | `string(list(string))],
    ~easing: Easing.t=?,
    ~extrapolate: Interpolation.extrapolate=?,
    ~extrapolateLeft: Interpolation.extrapolate=?,
    ~extrapolateRight: Interpolation.extrapolate=?,
    unit
  ) =>
 Animated.value(calculated)
```

### extrapolate

```reason
type extrapolate =
  | Extend
  | Clamp
  | Identity;
```

## Animating

Following API can be used to control the animations.

## start

```reason
let start: (Animation.t, ~callback: Animation.endCallback=?, unit) => unit;
```

Starts an animation.

## stop

```reason
let stop: (Animation.t) => unit;
```

Stops an animation

## reset

```reason
let reset: (Animation.t) => unit;
```

Resets an animation

## Easing

This module is exposed under `Animated` for historical reasons. Please see [`Easing`](/docs/easing.html) module instead.
