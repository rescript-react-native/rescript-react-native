

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReactNative from "react-native";

function toOption(x) {
  return Promise.resolve((x == null) ? undefined : Caml_option.some(x));
}

function map_cb(cb, err, value) {
  return Curry._2(cb, err === null ? undefined : Caml_option.some(err), (value == null) ? undefined : Caml_option.some(value));
}

function getItem(key, callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.getItem(key, (function (param, param$1) {
                    return map_cb(cb, param, param$1);
                  })).then(toOption);
  } else {
    return ReactNative.AsyncStorage.getItem(key, undefined).then(toOption);
  }
}

function setItem(key, value, callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.setItem(key, value, (function (param) {
                  return Curry._1(cb, param === null ? undefined : Caml_option.some(param));
                }));
  } else {
    return ReactNative.AsyncStorage.setItem(key, value, undefined);
  }
}

function removeItem(key, callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.removeItem(key, (function (param) {
                  return Curry._1(cb, param === null ? undefined : Caml_option.some(param));
                }));
  } else {
    return ReactNative.AsyncStorage.removeItem(key, undefined);
  }
}

function mergeItem(key, value, callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.mergeItem(key, value, (function (param) {
                  return Curry._1(cb, param === null ? undefined : Caml_option.some(param));
                }));
  } else {
    return ReactNative.AsyncStorage.mergeItem(key, value, undefined);
  }
}

function clear(callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.clear((function (param) {
                  return Curry._1(cb, param === null ? undefined : Caml_option.some(param));
                }));
  } else {
    return ReactNative.AsyncStorage.clear(undefined);
  }
}

function getAllKeys(callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.getAllKeys((function (param, param$1) {
                    return map_cb(cb, param, param$1);
                  })).then(toOption);
  } else {
    return ReactNative.AsyncStorage.getAllKeys(undefined).then(toOption);
  }
}

function multiGet(keys, callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.multiGet(keys, (function (param, param$1) {
                    return map_cb(cb, param, param$1);
                  })).then(toOption);
  } else {
    return ReactNative.AsyncStorage.multiGet(keys, undefined).then(toOption);
  }
}

function multiSet(keyValues, callback, param) {
  var combine = function (param) {
    return /* array */[
            param[0],
            param[1]
          ];
  };
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.multiSet($$Array.map(combine, keyValues), (function (param) {
                  return Curry._1(cb, param === null ? undefined : Caml_option.some(param));
                }));
  } else {
    return ReactNative.AsyncStorage.multiSet($$Array.map(combine, keyValues), undefined);
  }
}

function multiRemove(keys, callback, param) {
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.multiRemove(keys, (function (param) {
                  return Curry._1(cb, param === null ? undefined : Caml_option.some(param));
                }));
  } else {
    return ReactNative.AsyncStorage.multiRemove(keys, undefined);
  }
}

function multiMerge(keyValues, callback, param) {
  var combine = function (param) {
    return /* array */[
            param[0],
            param[1]
          ];
  };
  if (callback !== undefined) {
    var cb = callback;
    return ReactNative.AsyncStorage.multiMerge($$Array.map(combine, keyValues), (function (param) {
                  return Curry._1(cb, param === null ? undefined : Caml_option.some(param));
                }));
  } else {
    return ReactNative.AsyncStorage.multiMerge($$Array.map(combine, keyValues), undefined);
  }
}

export {
  getItem ,
  setItem ,
  removeItem ,
  mergeItem ,
  clear ,
  getAllKeys ,
  multiGet ,
  multiSet ,
  multiRemove ,
  multiMerge ,
  
}
/* react-native Not a pure module */
