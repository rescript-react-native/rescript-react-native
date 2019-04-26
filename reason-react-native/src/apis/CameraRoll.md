---
id: apis/CameraRoll
title: CameraRoll
wip: true
---

```reason
type getPhotosParams;

[@bs.obj]
external getPhotosParams:
  (
    ~first: int,
    ~after: string=?,
    ~groupTypes: [@bs.string] [
                   | `Album
                   | `All
                   | `Event
                   | `Faces
                   | `Library
                   | `PhotoStream
                   | `SavedPhotos
                 ]
                   =?,
    ~groupName: string=?,
    ~assetType: [@bs.string] [ | `All | `Videos | `Photos]=?,
    ~mimeTypes: array(string)=?,
    unit
  ) =>
  getPhotosParams =
  "";

type photoIdentifier = {
  .
  "node": {
    .
    "_type": string,
    "group_name": string,
    "image": {
      .
      "filename": string,
      "uri": string,
      "height": float,
      "width": float,
      "isStored": Js.Nullable.t(bool),
      "playableDuration": float,
    },
    "timestamp": float,
    "location":
      Js.Nullable.t({
        .
        "latitude": Js.Nullable.t(float),
        "longitude": Js.Nullable.t(float),
        "altitude": Js.Nullable.t(float),
        "heading": Js.Nullable.t(float),
        "speed": Js.Nullable.t(float),
      }),
  },
};

type photoIdentifiersPage = {
  .
  "edges": array(photoIdentifier),
  "page_info": {
    .
    "has_next_page": bool,
    "start_cursor": Js.Nullable.t(string),
    "end_cursor": Js.Nullable.t(string),
  },
};

[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external saveToCameraRoll:
  (string, ~_type: [@bs.string] [ | `photo | `video]=?, unit) =>
  Js.Promise.t(string) =
  "";

[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external getPhotos: getPhotosParams => Js.Promise.t(photoIdentifiersPage) =
  "";


```