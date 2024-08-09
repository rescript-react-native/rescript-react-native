type imageUri = string

@module("react-native") @scope("ImagePickerIOS")
external canUseCamera: (bool => unit) => unit = "canUseCamera"

@module("react-native") @scope("ImagePickerIOS")
external canRecordVideos: (bool => unit) => unit = "canRecordVideos"

type cameraDialogConfig = {videoMode?: bool}

@deprecated("Directly create record instead") @obj
external cameraDialogConfig: (~videoMode: bool=?, unit) => cameraDialogConfig = ""

type selectDialogConfig = {
  showImages?: bool,
  showVideos?: bool,
}

@deprecated("Directly create record instead") @obj
external selectDialogConfig: (
  ~showImages: bool=?,
  ~showVideos: bool=?,
  unit,
) => selectDialogConfig = ""

@module("react-native") @scope("ImagePickerIOS")
external openCameraDialog: (
  ~config: cameraDialogConfig,
  ~onSuccess: (imageUri, ~height: float, ~width: float, unit) => unit,
  ~onError: 'error => unit,
) => unit = "openCameraDialog"

@module("react-native") @scope("ImagePickerIOS")
external openSelectDialog: (
  ~config: selectDialogConfig,
  ~onSuccess: (imageUri, ~height: float, ~width: float, unit) => unit,
  ~onError: 'error => unit,
) => unit = "openSelectDialog"
