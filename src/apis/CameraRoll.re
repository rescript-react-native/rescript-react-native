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

type photoIdentifier = {node}
and node = {
  [@bs.as "type"]
  _type: string,
  group_name: string,
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
  page_info,
}
and page_info = {
  has_next_page: bool,
  start_cursor: Js.Nullable.t(string),
  end_cursor: Js.Nullable.t(string),
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
