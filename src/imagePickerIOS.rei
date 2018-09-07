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