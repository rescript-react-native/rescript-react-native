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
  getPhotosParams;

type photoIdentifier = {note}
and note = {
  [@bs.as "type"]
  _type: string,
  [@bs.as "group_name"]
  groupName: string,
  image,
  timestamp: float,
  location: Js.Nullable.t(location),
}
and image = {
  filename: string,
  uri: string,
  height: float,
  width: float,
  isStored: Js.Nullable.t(bool),
  playableDuration: float,
}
and location = {
  latitude: Js.Nullable.t(float),
  longitude: Js.Nullable.t(float),
  altitude: Js.Nullable.t(float),
  heading: Js.Nullable.t(float),
  speed: Js.Nullable.t(float),
};

type photoIdentifiersPage = {
  edges: array(photoIdentifier),
  [@bs.as "page_info"]
  pageInfo,
}
and pageInfo = {
  [@bs.as "has_next_page"]
  hasNextPage: bool,
  [@bs.as "start_cursor"]
  startCursor: Js.Nullable.t(string),
  [@bs.as "end_curson"]
  endCursor: Js.Nullable.t(string),
};

// multiple externals
[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external saveToCameraRoll: string => Js.Promise.t(string) =
  "saveToCameraRoll";

// multiple externals
[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external saveToCameraRollWithType:
  (string, ~_type: [@bs.string] [ | `photo | `video]) => Js.Promise.t(string) =
  "saveToCameraRoll";

[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external getPhotos: getPhotosParams => Js.Promise.t(photoIdentifiersPage) =
  "getPhotos";
