[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canUseCamera : (unit => unit) => unit = "";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canRecordVideos : (unit => unit) => unit = "";

[@bs.deriving abstract]
type error = {
  code: int,
  message: string,
};

type cameraDialogConfig = {. "videoMode": bool};

[@bs.obj]
external makeCameraDialogConfig : (~videoMode: bool) => cameraDialogConfig =
  "";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openCameraDialog :
  (cameraDialogConfig, string => unit, error => unit) => unit =
  "";

let openCameraDialog = (~videoMode, success, error) =>
  openCameraDialog(makeCameraDialogConfig(~videoMode), success, error);

[@bs.deriving abstract]
type selectDialogConfig = {
  showImages: bool,
  showVideos: bool,
};

[@bs.obj]
external makeSelectDialogConfig :
  (~showImages: bool, ~showVideos: bool) => selectDialogConfig =
  "";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openSelectDialog :
  (selectDialogConfig, string => unit, error => unit) => unit =
  "";

let openSelectDialog = (~showImages, ~showVideos, success, error) =>
  openSelectDialog(
    makeSelectDialogConfig(~showImages, ~showVideos),
    success,
    error,
  );