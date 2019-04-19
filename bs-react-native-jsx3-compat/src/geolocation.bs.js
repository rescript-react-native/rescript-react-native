

import * as Caml_option from "bs-platform/lib/es6/caml_option.js";

function setRNConfiguration(skipPermissionRequests, param) {
  var tmp = { };
  if (skipPermissionRequests !== undefined) {
    tmp.skipPermissionRequests = Caml_option.valFromOption(skipPermissionRequests);
  }
  navigator.geolocation.setRNConfiguration(tmp);
  return /* () */0;
}

function getCurrentPosition(timeout, maximumAge, enableHighAccuracy, success, error) {
  var tmp = { };
  if (timeout !== undefined) {
    tmp.timeout = Caml_option.valFromOption(timeout);
  }
  if (maximumAge !== undefined) {
    tmp.maximumAge = Caml_option.valFromOption(maximumAge);
  }
  if (enableHighAccuracy !== undefined) {
    tmp.enableHighAccuracy = Caml_option.valFromOption(enableHighAccuracy);
  }
  navigator.geolocation.getCurrentPosition(success, error, tmp);
  return /* () */0;
}

function watchPosition(timeout, maximumAge, enableHighAccuracy, distanceFilter, useSignificantChanges, success, error) {
  var tmp = { };
  if (timeout !== undefined) {
    tmp.timeout = Caml_option.valFromOption(timeout);
  }
  if (maximumAge !== undefined) {
    tmp.maximumAge = Caml_option.valFromOption(maximumAge);
  }
  if (enableHighAccuracy !== undefined) {
    tmp.enableHighAccuracy = Caml_option.valFromOption(enableHighAccuracy);
  }
  if (distanceFilter !== undefined) {
    tmp.distanceFilter = Caml_option.valFromOption(distanceFilter);
  }
  if (useSignificantChanges !== undefined) {
    tmp.useSignificantChanges = Caml_option.valFromOption(useSignificantChanges);
  }
  return navigator.geolocation.watchPosition(success, error, tmp);
}

function requestAuthorization(prim) {
  navigator.geolocation.requestAuthorization();
  return /* () */0;
}

function stopObserving(prim) {
  navigator.geolocation.stopObserving();
  return /* () */0;
}

function clearWatch(prim) {
  navigator.geolocation.clearWatch(prim);
  return /* () */0;
}

export {
  setRNConfiguration ,
  requestAuthorization ,
  stopObserving ,
  getCurrentPosition ,
  watchPosition ,
  clearWatch ,
  
}
/* No side effect */
