type watchId = int;

type position = {
  .
  "coords": coords,
  "timestamp": float,
}
and coords = {
  .
  "accuracy": int,
  "heading": int,
  "latitude": float,
  "longitude": float,
  "speed": int,
};

type error = {
  .
  "code": int,
  "message": string,
};

let setRNConfiguration: (~skipPermissionRequests: Js.boolean=?, unit) => unit;

let requestAuthorization: unit => unit;

let stopObserving: unit => unit;

let getCurrentPosition:
  (
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: Js.boolean=?,
    position => unit,
    error => unit
  ) =>
  unit;

let watchPosition:
  (
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: Js.boolean=?,
    ~distanceFilter: int=?,
    ~useSignificantChanges: Js.boolean=?,
    position => unit,
    error => unit
  ) =>
  watchId;

let clearWatch: watchId => unit;
