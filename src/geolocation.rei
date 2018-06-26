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

let setRNConfiguration: (~skipPermissionRequests: bool=?, unit) => unit;

let requestAuthorization: unit => unit;

let stopObserving: unit => unit;

let getCurrentPosition:
  (
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: bool=?,
    position => unit,
    error => unit
  ) =>
  unit;

let watchPosition:
  (
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: bool=?,
    ~distanceFilter: int=?,
    ~useSignificantChanges: bool=?,
    position => unit,
    error => unit
  ) =>
  watchId;

let clearWatch: watchId => unit;