type imageUri = string;

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canUseCamera: (bool => unit) => unit = "canUseCamera";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canRecordVideos: (bool => unit) => unit = "canRecordVideos";

type cameraDialogConfig;
[@bs.obj]
external cameraDialogConfig: (~videoMode: bool=?, unit) => cameraDialogConfig;

type selectDialogConfig;
[@bs.obj]
external selectDialogConfig:
  (~showImages: bool=?, ~showVideos: bool=?, unit) => selectDialogConfig;

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openCameraDialog:
  (
    ~config: cameraDialogConfig,
    ~onSuccess: (imageUri, ~height: float, ~width: float, unit) => unit,
    ~onError: 'error => unit
  ) =>
  unit =
  "openCameraDialog";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openSelectDialog:
  (
    ~config: selectDialogConfig,
    ~onSuccess: (imageUri, ~height: float, ~width: float, unit) => unit,
    ~onError: 'error => unit
  ) =>
  unit =
  "openSelectDialog";
