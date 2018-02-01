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
    "width": int
  },
  "location": {
    .
    "altitude": float,
    "heading": float,
    "latitude": float,
    "longitude": float,
    "speed": float
  },
  "timestamp": float
};

type result = {
  .
  "edges": array({. "node": node}),
  "page_info": {
    .
    "end_cursor": bool,
    "has_next_page": bool,
    "start_cursor": bool
  }
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
  (~uri: string, ~type_: fileType=?, unit) => Js.Promise.t(string);

let getPhotos:
  (
    ~first: int,
    ~after: string=?,
    ~groupTypes: groupType=?,
    ~groupName: string=?,
    ~assetType: assetType=?,
    ~mimeTypes: string=?,
    unit
  ) =>
  Js.Promise.t(result);
