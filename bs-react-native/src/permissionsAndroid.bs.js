

import * as List from "bs-platform/lib/es6/list.js";
import * as ArrayLabels from "bs-platform/lib/es6/arrayLabels.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReactNative from "react-native";

function getPermission(value) {
  switch (value) {
    case 0 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.READ_CALENDAR;
    case 1 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.WRITE_CALENDAR;
    case 2 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.CAMERA;
    case 3 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.READ_CONTACTS;
    case 4 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.WRITE_CONTACTS;
    case 5 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.GET_ACCOUNTS;
    case 6 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.ACCESS_FINE_LOCATION;
    case 7 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.ACCESS_COARSE_LOCATION;
    case 8 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.RECORD_AUDIO;
    case 9 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.READ_PHONE_STATE;
    case 10 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.CALL_PHONE;
    case 11 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.READ_CALL_LOG;
    case 12 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.WRITE_CALL_LOG;
    case 13 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS["permission.ADD_VOICEMAIL"];
    case 14 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.USE_SIP;
    case 15 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.PROCESS_OUTGOING_CALLS;
    case 16 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.BODY_SENSORS;
    case 17 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.SEND_SMS;
    case 18 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.RECEIVE_SMS;
    case 19 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.READ_SMS;
    case 20 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.RECEIVE_WAP_PUSH;
    case 21 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.RECEIVE_MMS;
    case 22 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.READ_EXTERNAL_STORAGE;
    case 23 : 
        return ReactNative.PermissionsAndroid.PERMISSIONS.WRITE_EXTERNAL_STORAGE;
    
  }
}

function getResult(r) {
  if (r === ReactNative.PermissionsAndroid.GRANTED) {
    return /* GRANTED */0;
  } else if (r === ReactNative.PermissionsAndroid.DENIED || r !== ReactNative.PermissionsAndroid.NEVER_ASK_AGAIN) {
    return /* DENIED */1;
  } else {
    return /* NEVER_ASK_AGAIN */2;
  }
}

function check(permission) {
  return ReactNative.PermissionsAndroid.check(getPermission(permission));
}

function request(permission, rationale, param) {
  if (rationale !== undefined) {
    return ReactNative.PermissionsAndroid.request(getPermission(permission), Caml_option.valFromOption(rationale)).then((function (res) {
                  return Promise.resolve(getResult(res));
                }));
  } else {
    return ReactNative.PermissionsAndroid.request(getPermission(permission), undefined).then((function (res) {
                  return Promise.resolve(getResult(res));
                }));
  }
}

function requestMultiple(permissions) {
  var permissions$1 = ArrayLabels.of_list(List.map(getPermission, permissions));
  return ReactNative.PermissionsAndroid.requestMultiple(permissions$1).then((function (result) {
                return Promise.resolve(result);
              }));
}

var Permission = [];

export {
  Permission ,
  check ,
  request ,
  requestMultiple ,
  
}
/* react-native Not a pure module */
