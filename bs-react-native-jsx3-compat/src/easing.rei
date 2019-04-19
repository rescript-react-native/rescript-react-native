/**
The [Easing] module implements common easing functions. This module is used by [Animated.timing()] to convey physically believable motion in animations.

You can find a visualization of some common easing functions at {{:http://easings.net/}}

You can read more on [Easing] API usage in official docs: {{:https://facebook.github.io/react-native/docs/easing}}

*/

type t = float => float;
let bounce: t;
let circle: t;
let cubic: t;
let ease: t;
let exp: t;
let linear: t;
let poly: float => t;
let quad: t;
let sin: t;
let step0: float => int;
let step1: float => int;
let back: float => t;
let elastic: float => t;
let in_: t => t;
let inOut: t => t;
let out: t => t;
let bezier: (float, float, float, float) => t;
