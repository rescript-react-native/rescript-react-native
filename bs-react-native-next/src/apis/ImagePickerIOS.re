type imageUri = string;

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canUseCamera: (bool => unit) => unit = "";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canRecordVideos: (bool => unit) => unit = "";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openCameraDialog:
  (
    {. "videoMode": bool},
    ~onSuccess: imageUri => unit,
    ~onError: 'error => unit
  ) =>
  unit =
  "";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openSelectDialog:
  (
    {
      .
      "showImages": bool,
      "showVideos": bool,
    },
    ~onSuccess: imageUri => unit,
    ~onError: 'error => unit
  ) =>
  unit =
  "";
