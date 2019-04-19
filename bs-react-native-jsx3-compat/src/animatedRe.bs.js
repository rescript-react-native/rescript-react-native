

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";

function start(t, callback, param) {
  t.start(Js_undefined.fromOption(callback));
  return /* () */0;
}

function extrapolateString(param) {
  switch (param) {
    case 0 : 
        return "extend";
    case 1 : 
        return "clamp";
    case 2 : 
        return "identity";
    
  }
}

function interpolate(value, inputRange, outputRange, easing, extrapolate, extrapolateLeft, extrapolateRight, param) {
  var tmp = {
    inputRange: $$Array.of_list(inputRange),
    outputRange: $$Array.of_list(outputRange[1])
  };
  if (easing !== undefined) {
    tmp.easing = Caml_option.valFromOption(easing);
  }
  var tmp$1 = Belt_Option.map(extrapolate, extrapolateString);
  if (tmp$1 !== undefined) {
    tmp.extrapolate = Caml_option.valFromOption(tmp$1);
  }
  var tmp$2 = Belt_Option.map(extrapolateLeft, extrapolateString);
  if (tmp$2 !== undefined) {
    tmp.extrapolateLeft = Caml_option.valFromOption(tmp$2);
  }
  var tmp$3 = Belt_Option.map(extrapolateRight, extrapolateString);
  if (tmp$3 !== undefined) {
    tmp.extrapolateRight = Caml_option.valFromOption(tmp$3);
  }
  return value.interpolate(tmp);
}

function resetAnimation(value, callback, param) {
  value.resetAnimation(Js_undefined.fromOption(callback));
  return /* () */0;
}

function stopAnimation(value, callback, param) {
  value.stopAnimation(Js_undefined.fromOption(callback));
  return /* () */0;
}

function animate(value, velocity, deceleration, isInteraction, useNativeDriver, onComplete, iterations, param) {
  var tmp = {
    velocity: velocity
  };
  if (deceleration !== undefined) {
    tmp.deceleration = Caml_option.valFromOption(deceleration);
  }
  if (isInteraction !== undefined) {
    tmp.isInteraction = Caml_option.valFromOption(isInteraction);
  }
  if (useNativeDriver !== undefined) {
    tmp.useNativeDriver = Caml_option.valFromOption(useNativeDriver);
  }
  if (onComplete !== undefined) {
    tmp.onComplete = Caml_option.valFromOption(onComplete);
  }
  if (iterations !== undefined) {
    tmp.iterations = Caml_option.valFromOption(iterations);
  }
  return ReactNative.Animated.decay(value, tmp);
}

var Decay = /* module */[/* animate */animate];

function animate$1(value, toValue, restDisplacementThreshold, overshootClamping, restSpeedThreshold, velocity, bounciness, speed, tension, friction, stiffness, mass, damping, isInteraction, useNativeDriver, onComplete, iterations, param) {
  var tmp = {
    toValue: toValue[1]
  };
  if (restDisplacementThreshold !== undefined) {
    tmp.restDisplacementThreshold = Caml_option.valFromOption(restDisplacementThreshold);
  }
  if (overshootClamping !== undefined) {
    tmp.overshootClamping = Caml_option.valFromOption(overshootClamping);
  }
  if (restSpeedThreshold !== undefined) {
    tmp.restSpeedThreshold = Caml_option.valFromOption(restSpeedThreshold);
  }
  if (velocity !== undefined) {
    tmp.velocity = Caml_option.valFromOption(velocity);
  }
  if (bounciness !== undefined) {
    tmp.bounciness = Caml_option.valFromOption(bounciness);
  }
  if (speed !== undefined) {
    tmp.speed = Caml_option.valFromOption(speed);
  }
  if (tension !== undefined) {
    tmp.tension = Caml_option.valFromOption(tension);
  }
  if (friction !== undefined) {
    tmp.friction = Caml_option.valFromOption(friction);
  }
  if (stiffness !== undefined) {
    tmp.stiffness = Caml_option.valFromOption(stiffness);
  }
  if (mass !== undefined) {
    tmp.mass = Caml_option.valFromOption(mass);
  }
  if (damping !== undefined) {
    tmp.damping = Caml_option.valFromOption(damping);
  }
  if (isInteraction !== undefined) {
    tmp.isInteraction = Caml_option.valFromOption(isInteraction);
  }
  if (useNativeDriver !== undefined) {
    tmp.useNativeDriver = Caml_option.valFromOption(useNativeDriver);
  }
  if (onComplete !== undefined) {
    tmp.onComplete = Caml_option.valFromOption(onComplete);
  }
  if (iterations !== undefined) {
    tmp.iterations = Caml_option.valFromOption(iterations);
  }
  return ReactNative.Animated.spring(value, tmp);
}

var Spring = /* module */[/* animate */animate$1];

function animate$2(value, toValue, easing, duration, delay, isInteraction, useNativeDriver, onComplete, iterations, param) {
  var tmp = {
    toValue: toValue[1]
  };
  if (easing !== undefined) {
    tmp.easing = Caml_option.valFromOption(easing);
  }
  if (duration !== undefined) {
    tmp.duration = Caml_option.valFromOption(duration);
  }
  if (delay !== undefined) {
    tmp.delay = Caml_option.valFromOption(delay);
  }
  if (isInteraction !== undefined) {
    tmp.isInteraction = Caml_option.valFromOption(isInteraction);
  }
  if (useNativeDriver !== undefined) {
    tmp.useNativeDriver = Caml_option.valFromOption(useNativeDriver);
  }
  if (onComplete !== undefined) {
    tmp.onComplete = Caml_option.valFromOption(onComplete);
  }
  if (iterations !== undefined) {
    tmp.iterations = Caml_option.valFromOption(iterations);
  }
  return ReactNative.Animated.timing(value, tmp);
}

var Timing = /* module */[/* animate */animate$2];

function create(x, y) {
  return new (ReactNative.Animated.ValueXY)({
              x: x,
              y: y
            });
}

function setValue(t, x, y) {
  t.setValue({
        x: x,
        y: y
      });
  return /* () */0;
}

function setOffset(t, x, y) {
  t.setOffset({
        x: x,
        y: y
      });
  return /* () */0;
}

function animate$3(value, velocity, deceleration, isInteraction, useNativeDriver, onComplete, iterations, param) {
  var tmp = {
    velocity: velocity
  };
  if (deceleration !== undefined) {
    tmp.deceleration = Caml_option.valFromOption(deceleration);
  }
  if (isInteraction !== undefined) {
    tmp.isInteraction = Caml_option.valFromOption(isInteraction);
  }
  if (useNativeDriver !== undefined) {
    tmp.useNativeDriver = Caml_option.valFromOption(useNativeDriver);
  }
  if (onComplete !== undefined) {
    tmp.onComplete = Caml_option.valFromOption(onComplete);
  }
  if (iterations !== undefined) {
    tmp.iterations = Caml_option.valFromOption(iterations);
  }
  return ReactNative.Animated.decay(value, tmp);
}

var Decay$1 = /* module */[/* animate */animate$3];

function animate$4(value, toValue, restDisplacementThreshold, overshootClamping, restSpeedThreshold, velocity, bounciness, speed, tension, friction, stiffness, mass, damping, isInteraction, useNativeDriver, onComplete, iterations, param) {
  var tmp = {
    toValue: toValue[1]
  };
  if (restDisplacementThreshold !== undefined) {
    tmp.restDisplacementThreshold = Caml_option.valFromOption(restDisplacementThreshold);
  }
  if (overshootClamping !== undefined) {
    tmp.overshootClamping = Caml_option.valFromOption(overshootClamping);
  }
  if (restSpeedThreshold !== undefined) {
    tmp.restSpeedThreshold = Caml_option.valFromOption(restSpeedThreshold);
  }
  if (velocity !== undefined) {
    tmp.velocity = Caml_option.valFromOption(velocity);
  }
  if (bounciness !== undefined) {
    tmp.bounciness = Caml_option.valFromOption(bounciness);
  }
  if (speed !== undefined) {
    tmp.speed = Caml_option.valFromOption(speed);
  }
  if (tension !== undefined) {
    tmp.tension = Caml_option.valFromOption(tension);
  }
  if (friction !== undefined) {
    tmp.friction = Caml_option.valFromOption(friction);
  }
  if (stiffness !== undefined) {
    tmp.stiffness = Caml_option.valFromOption(stiffness);
  }
  if (mass !== undefined) {
    tmp.mass = Caml_option.valFromOption(mass);
  }
  if (damping !== undefined) {
    tmp.damping = Caml_option.valFromOption(damping);
  }
  if (isInteraction !== undefined) {
    tmp.isInteraction = Caml_option.valFromOption(isInteraction);
  }
  if (useNativeDriver !== undefined) {
    tmp.useNativeDriver = Caml_option.valFromOption(useNativeDriver);
  }
  if (onComplete !== undefined) {
    tmp.onComplete = Caml_option.valFromOption(onComplete);
  }
  if (iterations !== undefined) {
    tmp.iterations = Caml_option.valFromOption(iterations);
  }
  return ReactNative.Animated.spring(value, tmp);
}

var Spring$1 = /* module */[/* animate */animate$4];

function animate$5(value, toValue, easing, duration, delay, isInteraction, useNativeDriver, onComplete, iterations, param) {
  var tmp = {
    toValue: toValue[1]
  };
  if (easing !== undefined) {
    tmp.easing = Caml_option.valFromOption(easing);
  }
  if (duration !== undefined) {
    tmp.duration = Caml_option.valFromOption(duration);
  }
  if (delay !== undefined) {
    tmp.delay = Caml_option.valFromOption(delay);
  }
  if (isInteraction !== undefined) {
    tmp.isInteraction = Caml_option.valFromOption(isInteraction);
  }
  if (useNativeDriver !== undefined) {
    tmp.useNativeDriver = Caml_option.valFromOption(useNativeDriver);
  }
  if (onComplete !== undefined) {
    tmp.onComplete = Caml_option.valFromOption(onComplete);
  }
  if (iterations !== undefined) {
    tmp.iterations = Caml_option.valFromOption(iterations);
  }
  return ReactNative.Animated.timing(value, tmp);
}

var Timing$1 = /* module */[/* animate */animate$5];

function loop($staropt$star, animation, param) {
  var iterations = $staropt$star !== undefined ? $staropt$star : -1;
  return ReactNative.Animated.loop(animation, {
              iterations: iterations
            });
}

function stop(prim) {
  prim.stop();
  return /* () */0;
}

function reset(prim) {
  prim.reset();
  return /* () */0;
}

function Animation_000(prim) {
  prim.stop();
  return /* () */0;
}

function Animation_002(prim) {
  prim.reset();
  return /* () */0;
}

var Animation = [
  Animation_000,
  start,
  Animation_002
];

var Interpolation = [interpolate];

function Value_000(prim) {
  return new (ReactNative.Animated.Value)(prim);
}

function Value_001(prim, prim$1) {
  prim.setValue(prim$1);
  return /* () */0;
}

function Value_002(prim, prim$1) {
  prim.setOffset(prim$1);
  return /* () */0;
}

function Value_003(prim) {
  prim.flattenOffset();
  return /* () */0;
}

function Value_004(prim) {
  prim.extractOffset();
  return /* () */0;
}

function Value_005(prim, prim$1) {
  return prim.addListener(prim$1);
}

function Value_006(prim, prim$1) {
  prim.removeListener(prim$1);
  return /* () */0;
}

function Value_007(prim) {
  prim.removeAllListeners();
  return /* () */0;
}

function Value_013(prim, prim$1) {
  return ReactNative.Animated.add(prim, prim$1);
}

function Value_014(prim, prim$1) {
  return ReactNative.Animated.divide(prim, prim$1);
}

function Value_015(prim, prim$1) {
  return ReactNative.Animated.subtract(prim, prim$1);
}

function Value_016(prim, prim$1) {
  return ReactNative.Animated.multiply(prim, prim$1);
}

function Value_017(prim, prim$1) {
  return ReactNative.Animated.modulo(prim, prim$1);
}

function Value_018(prim, prim$1, prim$2) {
  return ReactNative.Animated.diffClamp(prim, prim$1, prim$2);
}

var Value = [
  Value_000,
  Value_001,
  Value_002,
  Value_003,
  Value_004,
  Value_005,
  Value_006,
  Value_007,
  resetAnimation,
  stopAnimation,
  Timing,
  Spring,
  Decay,
  Value_013,
  Value_014,
  Value_015,
  Value_016,
  Value_017,
  Value_018,
  interpolate
];

function ValueXY_003(prim) {
  prim.flattenOffset();
  return /* () */0;
}

function ValueXY_004(prim) {
  prim.extractOffset();
  return /* () */0;
}

function ValueXY_005(prim, prim$1) {
  prim.resetAnimation(prim$1);
  return /* () */0;
}

function ValueXY_006(prim, prim$1) {
  prim.stopAnimation(prim$1);
  return /* () */0;
}

function ValueXY_007(prim, prim$1) {
  return prim.addListener(prim$1);
}

function ValueXY_008(prim, prim$1) {
  prim.removeListener(prim$1);
  return /* () */0;
}

function ValueXY_009(prim) {
  prim.removeAllListeners();
  return /* () */0;
}

function ValueXY_010(prim) {
  return prim.getLayout();
}

function ValueXY_011(prim) {
  return prim.getTranslateTransform();
}

function ValueXY_012(prim) {
  return prim.x;
}

function ValueXY_013(prim) {
  return prim.y;
}

var ValueXY = [
  create,
  setValue,
  setOffset,
  ValueXY_003,
  ValueXY_004,
  ValueXY_005,
  ValueXY_006,
  ValueXY_007,
  ValueXY_008,
  ValueXY_009,
  ValueXY_010,
  ValueXY_011,
  ValueXY_012,
  ValueXY_013,
  Timing$1,
  Spring$1,
  Decay$1
];

function $$event(prim, prim$1) {
  return ReactNative.Animated.event(prim, prim$1);
}

function delay(prim) {
  return ReactNative.Animated.delay(prim);
}

function sequence(prim) {
  return ReactNative.Animated.sequence(prim);
}

function parallel(prim, prim$1) {
  return ReactNative.Animated.parallel(prim, prim$1);
}

function stagger(prim, prim$1) {
  return ReactNative.Animated.stagger(prim, prim$1);
}

function createAnimatedComponent(prim) {
  return ReactNative.Animated.createAnimatedComponent(prim);
}

var timing = animate$2;

var spring = animate$1;

var decay = animate;

export {
  Animation ,
  Interpolation ,
  Value ,
  ValueXY ,
  $$event ,
  delay ,
  sequence ,
  parallel ,
  stagger ,
  loop ,
  createAnimatedComponent ,
  timing ,
  spring ,
  decay ,
  stop ,
  start ,
  reset ,
  
}
/* react-native Not a pure module */
