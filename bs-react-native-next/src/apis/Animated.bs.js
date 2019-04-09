

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";

function start(t, callback, param) {
  t.start(Js_undefined.fromOption(callback));
  return /* () */0;
}

var Animation = /* module */[/* start */start];

function ValueAnimations(Val) {
  var animate = function (value, velocity, deceleration, isInteraction, useNativeDriver, onComplete, iterations, param) {
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
  };
  var Decay = /* module */[/* animate */animate];
  var animate$1 = function (value, toValue, restDisplacementThreshold, overshootClamping, restSpeedThreshold, velocity, bounciness, speed, tension, friction, stiffness, mass, damping, isInteraction, useNativeDriver, onComplete, iterations, param) {
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
  };
  var Spring = /* module */[/* animate */animate$1];
  var animate$2 = function (value, toValue, easing, duration, delay, isInteraction, useNativeDriver, onComplete, iterations, param) {
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
  };
  var Timing = /* module */[/* animate */animate$2];
  return /* module */[
          /* Decay */Decay,
          /* Spring */Spring,
          /* Timing */Timing
        ];
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

var Interpolation = /* module */[
  /* extrapolateString */extrapolateString,
  /* interpolate */interpolate
];

var ValueOperations = /* module */[/* interpolate */interpolate];

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

var Value = /* module */[
  /* resetAnimation */resetAnimation,
  /* stopAnimation */stopAnimation,
  /* Decay */Decay,
  /* Spring */Spring,
  /* Timing */Timing,
  /* interpolate */interpolate
];

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

var ValueXY = /* module */[
  /* create */create,
  /* setValue */setValue,
  /* setOffset */setOffset,
  /* Decay */Decay$1,
  /* Spring */Spring$1,
  /* Timing */Timing$1
];

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

var timing = animate$2;

var spring = animate$1;

var decay = animate;

export {
  Animation ,
  ValueAnimations ,
  Interpolation ,
  ValueOperations ,
  Value ,
  ValueXY ,
  loop ,
  timing ,
  spring ,
  decay ,
  start ,
  stop ,
  reset ,
  
}
/* react-native Not a pure module */
