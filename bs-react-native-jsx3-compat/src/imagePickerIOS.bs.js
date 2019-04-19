

import * as ReactNative from "react-native";

function openCameraDialog(videoMode, onSuccess, onError) {
  ReactNative.ImagePickerIOS.openCameraDialog({
        videoMode: videoMode
      }, onSuccess, onError);
  return /* () */0;
}

function openSelectDialog(showImages, showVideos, onSuccess, onError) {
  ReactNative.ImagePickerIOS.openSelectDialog({
        showImages: showImages,
        showVideos: showVideos
      }, onSuccess, onError);
  return /* () */0;
}

function canUseCamera(prim) {
  ReactNative.ImagePickerIOS.canUseCamera(prim);
  return /* () */0;
}

function canRecordVideos(prim) {
  ReactNative.ImagePickerIOS.canRecordVideos(prim);
  return /* () */0;
}

export {
  canUseCamera ,
  canRecordVideos ,
  openCameraDialog ,
  openSelectDialog ,
  
}
/* react-native Not a pure module */
