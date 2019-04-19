/**
You can read more on [ImagePickerIOS] API usage in official docs: {{:https://facebook.github.io/react-native/docs/imagepickerios}}
{3 Methods}
{4 canRecordVideos }
{[
  ImagePickerIOS.canRecordVideos(() => Js.log("We can record videos!"));
]}
{4 canUseCamera }
{[
  ImagePickerIOS.canUseCamera(() => Js.log("We can use camera!"));
]}
{4 openSelectDialog }
{[
  ImagePickerIOS.openSelectDialog(
    ~showImages=true,
    ~showVideos=true,
    imageUri => Js.log(imageUri)),
    error => Js.log(error)
  );
]}
{4 openCameraDialog }
{[
  ImagePickerIOS.openCameraDialog(
    ~videoMode=true,
    imageUri => Js.log(imageUri)),
    error => Js.log(error)
  );
]}
{3 Function parameters }
{4 canRecordVideos && canUseCamera}
{[
  unit => unit
]}
{4 openSelectDialog }
{[
  (
    ~showImages: bool,
    ~showVideos: bool,
    string => unit,
    error => unit
  ) => unit
]}
reference:
{[
  type error = {
    .
    "code": int,
    "message": string,
  };
]}
{4 openCameraDialog}
{[
  (
    ~videoMode: bool,
    string => unit,
    error => unit
  ) => unit
]}
reference:

{[
  type error = {
    .
    "code": int,
    "message": string,
  };
]}
*/

let canUseCamera: (unit => unit) => unit;

let canRecordVideos: (unit => unit) => unit;

type error = {
  .
  "code": int,
  "message": string,
};

let openCameraDialog:
  (~videoMode: bool, ~onSuccess: unit => unit, ~onError: error => unit) => unit;

let openSelectDialog:
  (
    ~showImages: bool,
    ~showVideos: bool,
    ~onSuccess: string => unit,
    ~onError: error => unit
  ) =>
  unit;
