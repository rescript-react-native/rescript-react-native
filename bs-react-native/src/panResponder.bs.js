

import * as List from "bs-platform/lib/es6/list.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";
import * as AnimatedRe$BsReactNative from "./animatedRe.bs.js";

function callback(x, $$event, state) {
  return Curry._2(x, $$event.nativeEvent, /* record */[
              /* stateID */state.stateID,
              /* moveX */state.moveX,
              /* moveY */state.moveY,
              /* x0 */state.x0,
              /* y0 */state.y0,
              /* dx */state.dx,
              /* dy */state.dy,
              /* vx */state.vx,
              /* vy */state.vy,
              /* numberActiveTouches */state.numberActiveTouches
            ]);
}

function animatedEvent(l) {
  var config = List.fold_left((function (x, y) {
          var variant = y[0];
          if (variant !== 89) {
            if (variant >= 19713) {
              var value = y[1];
              return Object.assign(x, {
                          dx: AnimatedRe$BsReactNative.ValueXY[/* getX */12](value),
                          dy: AnimatedRe$BsReactNative.ValueXY[/* getY */13](value)
                        });
            } else {
              return Object.assign(x, {
                          dx: y[1]
                        });
            }
          } else {
            return Object.assign(x, {
                        dy: y[1]
                      });
          }
        }), { }, l);
  return AnimatedRe$BsReactNative.$$event(/* array */[
              null,
              config
            ], {
              useNativeDriver: false
            });
}

function create(onMoveShouldSetPanResponder, onMoveShouldSetPanResponderCapture, onStartShouldSetPanResponder, onStartShouldSetPanResponderCapture, onPanResponderReject, onPanResponderGrant, onPanResponderStart, onPanResponderEnd, onPanResponderRelease, onPanResponderMove, onPanResponderTerminate, onPanResponderTerminationRequest, onShouldBlockNativeResponder, param) {
  var tmp;
  if (onPanResponderMove !== undefined) {
    var x = onPanResponderMove;
    tmp = x[0] >= 117802505 ? animatedEvent(x[1]) : x[1];
  } else {
    tmp = undefined;
  }
  return ReactNative.PanResponder.create({
              onMoveShouldSetPanResponder: Js_undefined.fromOption(onMoveShouldSetPanResponder),
              onMoveShouldSetPanResponderCapture: Js_undefined.fromOption(onMoveShouldSetPanResponderCapture),
              onStartShouldSetPanResponder: Js_undefined.fromOption(onStartShouldSetPanResponder),
              onStartShouldSetPanResponderCapture: Js_undefined.fromOption(onStartShouldSetPanResponderCapture),
              onPanResponderReject: Js_undefined.fromOption(onPanResponderReject),
              onPanResponderGrant: Js_undefined.fromOption(onPanResponderGrant),
              onPanResponderStart: Js_undefined.fromOption(onPanResponderStart),
              onPanResponderEnd: Js_undefined.fromOption(onPanResponderEnd),
              onPanResponderRelease: Js_undefined.fromOption(onPanResponderRelease),
              onPanResponderMove: tmp,
              onPanResponderTerminate: Js_undefined.fromOption(onPanResponderTerminate),
              onPanResponderTerminationRequest: Js_undefined.fromOption(onPanResponderTerminationRequest),
              onShouldBlockNativeResponder: Js_undefined.fromOption(onShouldBlockNativeResponder)
            });
}

function panHandlers(t) {
  var jsHandlers = t.panHandlers;
  return /* record */[
          /* onMoveShouldSetResponder */Caml_option.undefined_to_opt(jsHandlers.onMoveShouldSetResponder),
          /* onMoveShouldSetResponderCapture */Caml_option.undefined_to_opt(jsHandlers.onMoveShouldSetResponderCapture),
          /* onResponderGrant */Caml_option.undefined_to_opt(jsHandlers.onResponderGrant),
          /* onResponderMove */Caml_option.undefined_to_opt(jsHandlers.onResponderMove),
          /* onResponderReject */Caml_option.undefined_to_opt(jsHandlers.onResponderReject),
          /* onResponderRelease */Caml_option.undefined_to_opt(jsHandlers.onResponderRelease),
          /* onResponderTerminate */Caml_option.undefined_to_opt(jsHandlers.onResponderTerminate),
          /* onResponderTerminationRequest */Caml_option.undefined_to_opt(jsHandlers.onResponderTerminationRequest),
          /* onStartShouldSetResponder */Caml_option.undefined_to_opt(jsHandlers.onStartShouldSetResponder),
          /* onStartShouldSetResponderCapture */Caml_option.undefined_to_opt(jsHandlers.onStartShouldSetResponderCapture)
        ];
}

export {
  callback ,
  create ,
  panHandlers ,
  
}
/* react-native Not a pure module */
