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

type image = {
  filename: string,
  uri: string,
  height: float,
  width: float,
  isStored: option(bool),
  playableDuration: float,
};

type location = {
  latitude: option(float),
  longitude: option(float),
  altitude: option(float),
  heading: option(float),
  speed: option(float),
};

type node = {
  [@bs.as "type"]
  _type: string,
  group_name: string,
  image,
  timestamp: float,
  location: option(location),
};

type photoIdentifier = {node};

type page_info = {
  has_next_page: bool,
  start_cursor: option(string),
  end_cursor: option(string),
};

type photoIdentifiersPage = {
  edges: array(photoIdentifier),
  page_info,
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
