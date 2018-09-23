/**
  {2 Guide}

  Animated allows to create declarative animations that are fluid, powerful and easy to build.

  {3 basic}

  The simplest animation starts with creating an animated value and using
  one of the built-in animations to change its value over time.

  The following example demonstrates use of Animated.Timing in order
  to animate an animated value throughout given period of time.

  {[open BsReactNative;

let animatedValue = Animated.Value.create(0.0);

let animation =
  Animated.timing(
    ~value=animatedValue,
    ~toValue=`raw(1.0),
    ~duration=100.0,
    (),
  );

Animated.start(animation, ());]}

  {3 multiple}

  Animations can be also combined together in complex ways using
  composition functions.

  The following example demonstrates use of Animated.sequence in order to run
  animations in a sequence, one by one.

  {[open BsReactNative;

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

Animated.start(animation, ());]}

  {3 calculation}

  You can combine two animated values via addition, multiplication, division, or modulo
  to make a new animated value.

  The following example demonstrates use of [Animated.multiply] in order to reverse
  the value of the [animatedValue].

  {[open BsReactNative;

let animatedValue = Animated.Value.create(0.0);

let newAnimatedValue = Animated.multiply(
  animatedValue,
  Animated.Value.create(-1.0)
);]}

  Keep in mind that calculated values (such as [newAnimatedValue] from the snippet above)
  cannot be animated. Trying to pass them to any of the animated functions will
  result in a type error.

  {3 interpolation}

  You can interpolate an animated value in order to bind to its value and change the output.

  The following example demonstrates interpolation in order to map values of an
  animated value to the opacity of a container.

  {[let animatedValue = Animated.Value.create(100.0);

let animatedOpacity =
  Animated.Value.interpolate(
    animatedValue,
    ~inputRange=[0.0, 100.0],
    ~outputRange=`float([0.0, 1.0]),
    ~extrapolate=Animated.Interpolation.Clamp,
    (),
  );]}

  {3 styling}

  Animated values can be passed to an animated component in order to change its apperance
  as the animated value changes.

  The example below demonstrates animating opacity of a component.

  {[open BsReactNative;

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
};]}

  {3 event}

  You can map gestures and other events state directly to an animated value directly
  with [Animated.event].

  {[let animatedValue = Animated.Value.create(0.0);

let handler =
  Animated.event(
    [|{
        "nativeEvent": {
          "contentOffset": {
            "x": animatedValue,
          },
        },
      }|],
    {"useNativeDriver": true},
  );

<ScrollView onScroll=handler />
  ]}

  {2 API reference}
  */
type calculated;

type regular;

/**
	Type of an Animated value.

	A [regular] value is a one created by calling {!Value.create}.

	A [calculated] is a value received as a result of performing {!Value.interpolate}, {!Value.add}, {!Value.divide} or {!Value.modulo}.

	{b Note:} Some operations are only allowed on either [regular] or [calculated] values.
 */
type value('a);

/**
	Type of a vector Animated value. See {!module:ValueXY} module for details. Unlike {!value}, it cannot be interpolated or subject to math operations.
 */
type valueXY;

/**
	Configured animation as created by calling {!timing}, {!spring} or {!decay}
 */
module Animation: {
  type t;
  type endResult = {. "finished": bool};
  type endCallback = endResult => unit;
};

/**
	Allows mapping input ranges of an Animated {!value} to different output ranges. By default, it will extrapolate the curve beyond the ranges given,
	but you can also have it clamp the output value.

	It uses lineal interpolation by default but also supports easing functions.
	*/
module Interpolation: {
  type t = value(calculated);
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let interpolate:
    (
      value('a),
      ~inputRange: list(float),
      ~outputRange: [< | `float(list(float)) | `string(list(string))],
      ~easing: Easing.t=?,
      ~extrapolate: extrapolate=?,
      ~extrapolateLeft: extrapolate=?,
      ~extrapolateRight: extrapolate=?,
      unit
    ) =>
    t;
};

/**
  Standard value for driving animations. One [Animated.Value] can drive multiple properties in a synchronized fashion, but can only be driven
	by one mechanism at a time. Using a new mechanism (e.g. starting a new animation, or calling [setValue]) will stop any previous ones.

	Typically initialized with [Animated.Value.create(0.0);]
*/
module Value: {
  type t = value(regular);
  type jsValue = {. "value": float};
  type callback = jsValue => unit;
  let create: float => t;
  let setValue: (t, float) => unit;
  let setOffset: (t, float) => unit;
  let flattenOffset: t => unit;
  let extractOffset: t => unit;
  let addListener: (t, callback) => string;
  let removeListener: (t, string) => unit;
  let removeAllListeners: t => unit;
  let resetAnimation: (t, ~callback: callback=?, unit) => unit;
	let stopAnimation: (t, ~callback: callback=?, unit) => unit;
  let animate: (t, Animation.t, Animation.endCallback) => unit;
  let stopTracking: t => unit;
  let track: t => unit;
  module Timing: {
    type config;
    let animate:
      (
        ~value: value(regular),
        ~toValue: [ | `raw(float) | `animated(value(regular))],
        ~easing: Easing.t=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  module Spring: {
    type config;
    let animate:
      (
        ~value: value(regular),
        ~toValue: [ | `raw(float) | `animated(value(regular))],
        ~restDisplacementThreshold: float=?,
        ~overshootClamping: bool=?,
        ~restSpeedThreshold: float=?,
        ~velocity: float=?,
        ~bounciness: float=?,
        ~speed: float=?,
        ~tension: float=?,
        ~friction: float=?,
        ~stiffness: float=?,
        ~mass: float=?,
        ~damping: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  module Decay: {
    type config;
    let animate:
      (
        ~value: value(regular),
        ~velocity: float,
        ~deceleration: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  let add: (value('a), value('b)) => value(calculated);
  let divide: (value('a), value('b)) => value(calculated);
  let multiply: (value('a), value('b)) => value(calculated);
  let modulo: (value('a), float) => value(calculated);
	let diffClamp: (value('a), float, float) => value(calculated);
	/**
	  Allows mapping input ranges of an Animated {!value} to different output ranges. See {!Animated.Interpolation.interpolate} for details.
	 */
  let interpolate:
    (
      value('a),
      ~inputRange: list(float),
      ~outputRange: [< | `float(list(float)) | `string(list(string))],
      ~easing: Easing.t=?,
      ~extrapolate: Interpolation.extrapolate=?,
      ~extrapolateLeft: Interpolation.extrapolate=?,
      ~extrapolateRight: Interpolation.extrapolate=?,
      unit
    ) =>
    value(calculated);
};

/**
	2D Value for driving 2D animations, such as pan gestures. Almost identical API to normal {!value}, but multiplexed. Contains two regular
	[Animated.Values] under the hood.
 */
module ValueXY: {
  type t = valueXY;
  type jsValue = {
    .
    "x": float,
    "y": float,
  };
  type callback = jsValue => unit;
  type translateTransform = {
    .
    "translateX": Value.t,
    "translateY": Value.t,
  };
  type layout = {
    .
    "left": Value.t,
    "top": Value.t,
  };
  let create: (~x: float, ~y: float) => t;
  let setValue: (t, ~x: float, ~y: float) => unit;
  let setOffset: (t, ~x: float, ~y: float) => unit;
  let flattenOffset: t => unit;
  let extractOffset: t => unit;
  let resetAnimation: (t, option(callback)) => unit;
  let stopAnimation: (t, option(callback)) => unit;
  let addListener: (t, callback) => string;
  let removeListener: (t, string) => unit;
  let removeAllListeners: t => unit;
  let getLayout: t => layout;
  let getTranslateTransform: t => translateTransform;
  let getX: t => Value.t;
  let getY: t => Value.t;
  module Timing: {
    type config;
    let animate:
      (
        ~value: valueXY,
        ~toValue: [ | `raw(jsValue) | `animated(valueXY)],
        ~easing: Easing.t=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  module Spring: {
    type config;
    let animate:
      (
        ~value: valueXY,
        ~toValue: [ | `raw(jsValue) | `animated(valueXY)],
        ~restDisplacementThreshold: float=?,
        ~overshootClamping: bool=?,
        ~restSpeedThreshold: float=?,
        ~velocity: jsValue=?,
        ~bounciness: float=?,
        ~speed: float=?,
        ~tension: float=?,
        ~friction: float=?,
        ~stiffness: float=?,
        ~mass: float=?,
        ~damping: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
  module Decay: {
    type config;
    let animate:
      (
        ~value: valueXY,
        ~velocity: jsValue,
        ~deceleration: float=?,
        ~isInteraction: bool=?,
        ~useNativeDriver: bool=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?,
        unit
      ) =>
      Animation.t;
  };
};

/**
  Event handler that maps values to {!value}. See next section for example use.
 */
type animatedEvent;

/**
  You can map gestures and other events state directly to an animated value directly with
  Animated.event.

  {4 Example}

  {[let animatedValue = Animated.Value.create(0.0);

let handler =
  Animated.event(
    [|{
        "nativeEvent": {
          "contentOffset": {
            "x": animatedValue,
          },
        },
      }|],
    {"useNativeDriver": true},
  );

<ScrollView onScroll=handler />]}
 */
let event: (array('a), 'b) => animatedEvent;

/**
  Helper function to delay execution of the animation. To be used with other Animated functions,
  as demonstrated at the below example.

  {4 Example}

  {[let barValue = Animated.Value.create(0.0);

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

Animated.start(animation, ());]}

  The above example will delay the [barValue] animation by 500 milliseconds.
*/
let delay: float => Animation.t;

/**
  Starts an array of animations in order, waiting for each to complete before starting the next.
	If the current running animation is stopped, no following animations will be started.

	{4 Example}

	See {!delay} example above.
 */
let sequence: array(Animation.t) => Animation.t;

/**
  Runs an array of animations in parallel.

  {4 Example}

  {[let fooValue = Animated.Value.create(0.0);
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

Animated.start(animation, ());]}

  When [stopTogether] is set to true, callback passed to {{!start} Animated.start} will get executed only once,
  after all animations within the array have finished. Otherwise, it may get executed many times.

  You should check for the value of [didFinish] boolean that is the first argument to the callback
  function.
 */
let parallel: (array(Animation.t), {. "stopTogether": bool}) => Animation.t;

/**
  Array of animations may run in parallel (overlap), but are started in sequence with
  successive delays.

  {4 Example}

  {[let fooValue = Animated.Value.create(0.0);
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

Animated.start(animation, ());]}
 */
let stagger: (float, array(Animation.t)) => Animation.t;

/**
  Loops a given animation continuously, so that each time it reaches the end, it resets and
  begins again from the start.

  You can specify the number of interations explicitly here or use iterations property when
  defining animation.

  {4 Example}

  {[let fooValue = Animated.Value.create(0.0);

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

Animated.start(animation, ());]}
 */
let loop: (~iterations: int=?, ~animation: Animation.t, unit) => Animation.t;

/** Make any React component Animatable */
let createAnimatedComponent: ReasonReact.reactClass => ReasonReact.reactClass;

/**
	Animates a value over time using Easing functions.

	{4 Example}

  {[let animatedValue = Animated.Value.create(0.0);

let animation = Animated.timing(
  ~value=animatedValue,
  ~toValue=`raw(1.0),
  ~duration=100.0,
  (),
);

Animated.start(animation, ());]}

  Check {{:https://facebook.github.io/react-native/docs/animated#timing} React Native documentation}
  for details.
 */
let timing:
  (
    ~value: value(regular),
    ~toValue: [ | `raw(float) | `animated(value(regular))],
    ~easing: Easing.t=?,
    ~duration: float=?,
    ~delay: float=?,
    ~isInteraction: bool=?,
    ~useNativeDriver: bool=?,
    ~onComplete: Animation.endCallback=?,
    ~iterations: int=?,
    unit
  ) =>
  Animation.t;

/**
 Provides a simple spring physics model.

 {4 Example}

 {[let animatedValue = Animated.Value.create(0.0);

let animation = Animated.spring(
  ~value=animatedValue,
  ~toValue=`raw(1.0),
  ~bounciness=5.0,
  (),
);

Animated.start(animation, ());]}

  Check {{:https://facebook.github.io/react-native/docs/animated#spring} React Native documentation}
  for details.
 */
let spring:
  (
    ~value: value(regular),
    ~toValue: [ | `raw(float) | `animated(value(regular))],
    ~restDisplacementThreshold: float=?,
    ~overshootClamping: bool=?,
    ~restSpeedThreshold: float=?,
    ~velocity: float=?,
    ~bounciness: float=?,
    ~speed: float=?,
    ~tension: float=?,
    ~friction: float=?,
    ~stiffness: float=?,
    ~mass: float=?,
    ~damping: float=?,
    ~isInteraction: bool=?,
    ~useNativeDriver: bool=?,
    ~onComplete: Animation.endCallback=?,
    ~iterations: int=?,
    unit
  ) =>
  Animation.t;

/**
	Starts with an initial velocity and gradually slows to a stop.

	{4 Example}

  {[let animatedValue = Animated.Value.create(0.0);

let animation = Animated.decay(
  ~value=animatedValue,
  ~toValue=`raw(1.0),
  ~velocity=100.0,
  (),
);

Animated.start(animation, ());]}

  Check {{:https://facebook.github.io/react-native/docs/animated#decay} React Native documentation}
  for details.
  */
let decay:
  (
    ~value: value(regular),
    ~velocity: float,
    ~deceleration: float=?,
    ~isInteraction: bool=?,
    ~useNativeDriver: bool=?,
    ~onComplete: Animation.endCallback=?,
    ~iterations: int=?,
    unit
  ) =>
  Animation.t;

/**
	Stops an animation
*/
let stop: Animation.t => unit;

/**
	Starts an animation
*/
let start: (Animation.t, ~callback: Animation.endCallback=?, unit) => unit;

/**
	Resets an animation
*/
let reset: Animation.t => unit;

[@deprecated "Please use Easing module instead"]
module Easing = Easing;

[@deprecated
  "Please use Animated.start, Animated.stop or Animated.reset instead"
]
module CompositeAnimation = Animation;

[@deprecated "Please use Animated.timing instead"]
module Timing = Value.Timing;

[@deprecated "Please use Animated.ValueXY.Timing instead"]
module TimingXY = ValueXY.Timing;

[@deprecated "Please use Animated.spring instead"]
module Spring = Value.Spring;

[@deprecated "Please use Animated.ValueXY.Spring instead"]
module SpringXY = ValueXY.Spring;

[@deprecated "Please use Animated.decay instead"]
module Decay = Value.Decay;

[@deprecated "Please use Animated.ValueXY.Decay instead"]
module DecayXY = ValueXY.Decay;
