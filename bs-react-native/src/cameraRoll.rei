/**
[CameraRoll] provides access to the local camera roll or photo library.

On [iOS], the [CameraRoll] API requires the [RCTCameraRoll] library to be linked

You can read more on [CameraRoll] API usage in official docs: {{:https://facebook.github.io/react-native/docs/cameraroll}}

{3 Types}
{4 cursor}
{[
  type cursor;
]}
{4 node}
{[
  type node = {
  .
  "_type": string,
  "group_name": string,
  "image": {
    .
    "filename": string,
    "height": int,
    "isStored": bool,
    "playableDuration": int,
    "uri": string,
    "width": int,
  },
  "location": {
    .
    "altitude": float,
    "heading": float,
    "latitude": float,
    "longitude": float,
    "speed": float,
  },
  "timestamp": float,
};
]}
{4 assets}
{[
  type assets = {
  .
  "edges": array({. "node": node}),
  "page_info": {
    .
    "end_cursor": cursor,
    "has_next_page": bool,
    "start_cursor": cursor,
  },
};
]}
{4 filetype}
{[
  type fileType =
  | Video
  | Photo;
]}
{4 groupType}
{[
  type groupType =
  | All
  | Album
  | Event
  | Faces
  | Library
  | PhotoStream
  | SavedPhotos;
]}
{4 assetType}
{[
  type assetType =
  | All
  | Videos
  | Photos;
]}
{3 Methods}
{4 saveToCameraRoll}
{[
  let saveToCameraRoll:
  (~uri: string, ~type_: fileType=?, unit) =>
  Js.Promise.t(Belt.Result.t(string, Js.Promise.error));
]}
{4 getPhotos}
{[
  let getPhotos:
  (
    ~first: int,
    ~after: cursor=?,
    ~groupTypes: groupType=?,
    ~groupName: string=?,
    ~assetType: assetType=?,
    ~mimeTypes: string=?,
    unit
  ) =>
  Js.Promise.t(assets);
]}
*/

type cursor;

type node = {
  .
  "_type": string,
  "group_name": string,
  "image": {
    .
    "filename": string,
    "height": int,
    "isStored": bool,
    "playableDuration": int,
    "uri": string,
    "width": int,
  },
  "location": {
    .
    "altitude": float,
    "heading": float,
    "latitude": float,
    "longitude": float,
    "speed": float,
  },
  "timestamp": float,
};

type assets = {
  .
  "edges": array({. "node": node}),
  "page_info": {
    .
    "end_cursor": cursor,
    "has_next_page": bool,
    "start_cursor": cursor,
  },
};

type fileType =
  | Video
  | Photo;

type groupType =
  | All
  | Album
  | Event
  | Faces
  | Library
  | PhotoStream
  | SavedPhotos;

type assetType =
  | All
  | Videos
  | Photos;

let saveToCameraRoll:
  (~uri: string, ~type_: fileType=?, unit) =>
  Js.Promise.t(Belt.Result.t(string, Js.Promise.error));

let getPhotos:
  (
    ~first: int,
    ~after: cursor=?,
    ~groupTypes: groupType=?,
    ~groupName: string=?,
    ~assetType: assetType=?,
    ~mimeTypes: string=?,
    unit
  ) =>
  Js.Promise.t(assets);
