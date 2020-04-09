---
id: apis/ImagePickerIOS
title: ImagePickerIOS
officialDoc: https://reactnative.dev/docs/imagepickerios
---

## Note

This API will be removed from React Native as part of the
[_Lean Core_](https://github.com/facebook/react-native/issues/23313) effort.
Please refer to the
[community package](https://github.com/react-native-community/react-native-image-picker-ios)
if you wish to use this component.

However note that more current packages such as •
[`react-native-image-picker`](https://github.com/react-native-community/react-native-image-picker)
for which [bindings](https://github.com/reason-react-native/image-picker) are
available, or •
[`expo-image-picker`](https://docs.expo.io/versions/latest/sdk/imagepicker/) are
recommended instead.

---

Before you may use this API, you need to link the `RCTCameraRoll` library to
your app and provide a description for your use of the Photo Library.

- you need to add `RCTCameraRoll.xcodeproj` (located in the
  `node_modules/react-native/Libraries/CameraRoll` subdirectory of your app) to
  your project's Libraries tree in XCode, then
- you need to specify `libRCTCameraRoll.a` under _Link Binary with Libraries_ in
  your app's _Build Phases_ tab.
- you also need to set the _Privacy - Photo Library Usage Description_ (or
  _NSPhotoLibraryUsageDescription_) key under _Custom iOS Target Properties_ in
  your apps' _Info_ tab.

## Types

### `imageUri`

An alias for the `string` type

```reason
type imageUri = string
```

### `cameraDialogConfig`

An abstract type which can be created using the constructor of the same name.
You may call the constructor as `cameraDialogConfig()` to use the default
values.

```reason
cameraDialogConfig: (~videoMode: bool=?, unit) => cameraDialogConfig
```

### `selectDialogConfig`

An abstract type which can be created using the constructor of the same name.
You may call the constructor as `selectDialogConfig()` to use the default
values.

```reason
selectDialogConfig:
  (~showImages: bool=?, ~showVideos: bool=?, unit) => selectDialogConfig
```

## Methods

### `canUseCamera`

Method to check whether the app has permissions to use the camera, takes a
callback of type `bool => unit`.

```reason
canUseCamera: (bool => unit) => unit
```

### `canRecordVideos`

Method to check whether the app has permissions to record videos, takes a
callback of type `bool => unit`.

```reason
canRecordVideos: (bool => unit) => unit
```

### `openCameraDialog`

Method to request the Camera dialog given a config (of type
[`cameraDialogConfig`](#cameraDialogConfig)) to specify whether the camera is
launched in video mode. When an image or video is captured, `onSuccess` callback
is passed the returned `imageUri`, `height` and `width`; `onError` callback is
applied otherwise. As`'error` is an abstract type

```reason
openCameraDialog:
  (
    ~config: cameraDialogConfig,
    ~onSuccess: (imageUri, ~height: float, ~width: float, unit) => unit,
    ~onError: 'error => unit
  ) =>
  unit
```

### `openSelectDialog`

Method to request the Image Gallery given a config (of type
[`openSelectDialog`](#openSelectDialog)) to specify whether images and/or videos
should be listed. When an image or video is selected, `onSuccess` callback is
passed the returned `imageUri`, `height` and `width`; `onError` callback is
executed otherwise. As`'error` is an abstract type

```reason
openSelectDialog:
  (
    ~config: selectDialogConfig,
    ~onSuccess: (imageUri, ~height: float, ~width: float, unit) => unit,
    ~onError: 'error => unit
  ) =>
  unit
```
