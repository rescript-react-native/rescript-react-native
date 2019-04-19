type config;

type cursor;

type node = {
  .
  "_type": string,
  "group_name": string,
  "image": {
    .
    "filename": string,
    "playableDuration": int,
    "uri": string,
    "height": int,
    "width": int,
    "isStored": bool,
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
    "has_next_page": bool,
    "start_cursor": cursor,
    "end_cursor": cursor,
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

let mapFileType = fileType =>
  switch (fileType) {
  | Photo => "photo"
  | Video => "video"
  };

let mapGroupType = (groupType: groupType) =>
  switch (groupType) {
  | All => "All"
  | Album => "Album"
  | Event => "Event"
  | Faces => "Faces"
  | Library => "Library"
  | PhotoStream => "PhotoStream"
  | SavedPhotos => "SavedPhotos"
  };

let mapAssetType = (assetType: assetType) =>
  switch (assetType) {
  | All => "All"
  | Videos => "Videos"
  | Photos => "Photos"
  };

[@bs.obj]
external makeConfig:
  (
    ~first: int,
    ~after: cursor=?,
    ~groupTypes: string,
    ~groupName: string=?,
    ~assetType: string,
    ~mimeTypes: string=?
  ) =>
  config =
  "";

[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external _saveToCameraRoll:
  (string, Js.Undefined.t(string)) => Js.Promise.t(string) =
  "saveToCameraRoll";

[@bs.module "react-native"] [@bs.scope "CameraRoll"]
external _getPhotos: config => Js.Promise.t(assets) = "getPhotos";

let saveToCameraRoll = (~uri, ~type_=?, ()) => {
  let fileType = type_->Belt.Option.map(mapFileType)->Js.Undefined.fromOption;
  _saveToCameraRoll(uri, fileType)
  |> Js.Promise.then_(uri => Js.Promise.resolve(Belt.Result.Ok(uri)))
  |> Js.Promise.catch(error => Js.Promise.resolve(Belt.Result.Error(error)));
};

let getPhotos =
    (
      ~first,
      ~after=?,
      ~groupTypes=SavedPhotos,
      ~groupName=?,
      ~assetType=Photos,
      ~mimeTypes=?,
      (),
    ) => {
  let groupTypes = mapGroupType(groupTypes);
  let assetType = mapAssetType(assetType);
  let config =
    makeConfig(
      ~first,
      ~after?,
      ~groupTypes,
      ~groupName?,
      ~assetType,
      ~mimeTypes?,
    );
  _getPhotos(config);
};
