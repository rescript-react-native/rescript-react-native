---
title: ImagePickerIOS
---

## Example of use

### canRecordVideos

```reason
ImagePickerIOS.canRecordVideos(() => Js.log("We can record videos!"));
```

### canUseCamera

```reason
ImagePickerIOS.canUseCamera(() => Js.log("We can use camera!"));
```

### openSelectDialog

```reason
ImagePickerIOS.openSelectDialog(
  ~showImages=true,
  ~showVideos=true,
  imageUri => Js.log(imageUri)),
  error => Js.log(error)
);
```

### openCameraDialog

```reason
ImagePickerIOS.openCameraDialog(
  ~videoMode=true,
  imageUri => Js.log(imageUri)),
  error => Js.log(error)
);
```

## Function parameters

### canRecordVideos && canUseCamera

```reason
unit => unit
```

### openSelectDialog

```reason
(
  ~showImages: bool,
  ~showVideos: bool,
  string => unit,
  error => unit
) => unit
```

_reference:_

```reason
type error = {
  .
  "code": int,
  "message": string,
};
```

### openCameraDialog

```reason
(
  ~videoMode: bool,
  string => unit,
  error => unit
) => unit
```

_reference:_

```reason
type error = {
  .
  "code": int,
  "message": string,
};
```
