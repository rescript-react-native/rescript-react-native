

import * as ReactNative from "react-native";

function get(prim) {
  return ReactNative.PixelRatio.get();
}

function getFontScale(prim) {
  return ReactNative.PixelRatio.getFontScale();
}

function getPixelSizeForLayoutSize(prim) {
  return ReactNative.PixelRatio.getPixelSizeForLayoutSize(prim);
}

function roundToNearestPixel(prim) {
  return ReactNative.PixelRatio.roundToNearestPixel(prim);
}

export {
  get ,
  getFontScale ,
  getPixelSizeForLayoutSize ,
  roundToNearestPixel ,
  
}
/* react-native Not a pure module */
