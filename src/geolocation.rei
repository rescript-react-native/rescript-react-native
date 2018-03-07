type watchId = int;

let setRNConfiguration: (~skipPermissionRequests: Js.boolean=?, unit) => unit;

let requestAuthorization: unit => unit;

let stopObserving: unit => unit;

let clearWatch: watchId => unit;

let getCurrentPosition:
  (
    ~success: unit => unit,
    ~error: unit => unit,
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: Js.boolean=?,
    unit
  ) =>
  unit;

let watchPosition:
  (
    ~success: unit => unit,
    ~error: unit => unit,
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: Js.boolean=?,
    ~distanceFilter: int=?,
    ~useSignificantChanges: Js.boolean=?,
    unit
  ) =>
  watchId;
