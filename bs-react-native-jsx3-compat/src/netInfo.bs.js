

import * as Pervasives from "bs-platform/lib/es6/pervasives.js";
import * as ReactNative from "react-native";

function connectionType(connectionType$1) {
  switch (connectionType$1) {
    case "bluetooth" : 
        return /* Bluetooth */4;
    case "cellular" : 
        return /* Cellular */2;
    case "ethernet" : 
        return /* Ethernet */5;
    case "none" : 
        return /* None */0;
    case "unknown" : 
        return /* Unknown */3;
    case "wifi" : 
        return /* WiFi */1;
    case "wimax" : 
        return /* WiMax */6;
    default:
      return Pervasives.failwith("NetInfo, unexpected `connection` type: " + connectionType$1);
  }
}

function effectiveConnectionType(effectiveConnectionType$1) {
  switch (effectiveConnectionType$1) {
    case "2g" : 
        return /* Net2G */0;
    case "3g" : 
        return /* Net3G */1;
    case "4g" : 
        return /* Net4G */2;
    case "unknown" : 
        return /* Unknown */3;
    default:
      return Pervasives.failwith("NetInfo, unexpected `effectiveConnection` type: " + effectiveConnectionType$1);
  }
}

function addEventListener(listener) {
  ReactNative.NetInfo.isConnected.addEventListener("connectionChange", listener);
  return /* () */0;
}

function removeEventListener(listener) {
  ReactNative.NetInfo.isConnected.removeEventListener("connectionChange", listener);
  return /* () */0;
}

function $$fetch(param) {
  return ReactNative.NetInfo.isConnected.fetch();
}

var IsConnected = /* module */[
  /* addEventListener */addEventListener,
  /* removeEventListener */removeEventListener,
  /* fetch */$$fetch
];

function addEventListener$1(prim) {
  ReactNative.NetInfo.addEventListener("connectionChange", prim);
  return /* () */0;
}

function removeEventListener$1(prim) {
  ReactNative.NetInfo.removeEventListener("connectionChange", prim);
  return /* () */0;
}

function isConnectionExpensive(prim) {
  return ReactNative.NetInfo.isConnectionExpensive();
}

function getConnectionInfo(prim) {
  return ReactNative.NetInfo.getConnectionInfo();
}

export {
  connectionType ,
  effectiveConnectionType ,
  addEventListener$1 as addEventListener,
  removeEventListener$1 as removeEventListener,
  isConnectionExpensive ,
  getConnectionInfo ,
  IsConnected ,
  
}
/* react-native Not a pure module */
