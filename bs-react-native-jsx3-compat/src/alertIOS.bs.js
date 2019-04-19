

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";

function alert(title, message, buttons, type_, param) {
  var msg = Js_undefined.fromOption(message);
  var transformButtons = function (xs) {
    return $$Array.map((function (param) {
                  return {
                          text: Js_undefined.fromOption(param[/* text */0]),
                          onPress: Js_undefined.fromOption(param[/* onPress */1]),
                          style: Js_undefined.fromOption(Belt_Option.map(param[/* style */2], (function (param) {
                                      if (param !== 465819841) {
                                        if (param >= 942927226) {
                                          return "cancel";
                                        } else {
                                          return "destructive";
                                        }
                                      } else {
                                        return "default";
                                      }
                                    })))
                        };
                }), $$Array.of_list(xs));
  };
  var bts = Js_undefined.fromOption(Belt_Option.map(buttons, transformButtons));
  var t_ = Js_undefined.fromOption(Belt_Option.map(type_, (function (param) {
              if (param >= 780034244) {
                if (param >= 904380375) {
                  return "plain-text";
                } else {
                  return "secure-text";
                }
              } else if (param >= 465819841) {
                return "default";
              } else {
                return "login-password";
              }
            })));
  ReactNative.AlertIOS.alert(title, msg, bts, t_);
  return /* () */0;
}

function prompt(title, message, buttons, type_, defaultValue, keyboardType, param) {
  var msg = Js_undefined.fromOption(message);
  var transformButtons = function (xs) {
    return $$Array.map((function (param) {
                  return {
                          text: Js_undefined.fromOption(param[/* text */0]),
                          onPress: Js_undefined.fromOption(param[/* onPress */1]),
                          style: Js_undefined.fromOption(Belt_Option.map(param[/* style */2], (function (param) {
                                      if (param !== 465819841) {
                                        if (param >= 942927226) {
                                          return "cancel";
                                        } else {
                                          return "destructive";
                                        }
                                      } else {
                                        return "default";
                                      }
                                    })))
                        };
                }), $$Array.of_list(xs));
  };
  var bts = Js_undefined.fromOption(Belt_Option.map(buttons, transformButtons));
  var t_ = Js_undefined.fromOption(Belt_Option.map(type_, (function (param) {
              if (param >= 780034244) {
                if (param >= 904380375) {
                  return "plain-text";
                } else {
                  return "secure-text";
                }
              } else if (param >= 465819841) {
                return "default";
              } else {
                return "login-password";
              }
            })));
  var def_ = Js_undefined.fromOption(defaultValue);
  var keyboardT = Js_undefined.fromOption(Belt_Option.map(keyboardType, (function (param) {
              if (param >= 511059466) {
                if (param >= 734061261) {
                  if (param >= 965330242) {
                    if (param >= 1008346616) {
                      return "email-address";
                    } else {
                      return "decimal-pad";
                    }
                  } else if (param >= 776586867) {
                    return "twitter";
                  } else {
                    return "numeric";
                  }
                } else if (param >= 568483612) {
                  return "web-search";
                } else {
                  return "number-pad";
                }
              } else if (param >= -324562960) {
                if (param >= 217673051) {
                  if (param >= 465819841) {
                    return "default";
                  } else {
                    return "ascii-capable";
                  }
                } else if (param >= 5843823) {
                  return "url";
                } else {
                  return "name-phone-pad";
                }
              } else if (param >= -444948859) {
                return "phone-pad";
              } else {
                return "numbers-and-punctuation";
              }
            })));
  ReactNative.AlertIOS.prompt(title, msg, bts, t_, def_, keyboardT);
  return /* () */0;
}

export {
  alert ,
  prompt ,
  
}
/* react-native Not a pure module */
