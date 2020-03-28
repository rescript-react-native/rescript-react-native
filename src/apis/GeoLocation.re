type coords = {
  speed: float,
  longitude: float,
  latitude: float,
  accuracy: float,
  heading: float,
};

type position = {
  coords,
  timestamp: float,
};

type error = {
  code: int,
  message: string,
};

type config;
[@bs.obj] external config: (~skipPermissionRequests: bool=?, unit) => config;

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external setRNConfiguration: config => unit = "setRNConfiguration";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external requestAuthorization: unit => unit = "requestAuthorization";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external stopObserving: unit => unit = "stopObserving";

type currentPositionOptions;
[@bs.obj]
external currentPositionOptions:
  (
    ~timeout: float=?,
    ~maximumAge: float=?,
    ~enableHighAccuracy: bool=?,
    unit
  ) =>
  currentPositionOptions;

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external getCurrentPosition:
  (
    position => unit,
    ~onError: error => unit=?,
    ~options: currentPositionOptions=?,
    unit
  ) =>
  unit =
  "getCurrentPosition";

type watchId;

type watchPositionOptions;
[@bs.obj]
external watchPositionOptions:
  (
    ~timeout: float=?,
    ~maximumAge: float=?,
    ~enableHighAccuracy: bool=?,
    ~distanceFilter: float=?,
    ~useSignificantChanges: bool=?,
    unit
  ) =>
  watchPositionOptions;

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external watchPosition:
  (
    position => unit,
    ~onError: error => unit=?,
    ~options: watchPositionOptions=?,
    unit
  ) =>
  watchId =
  "watchPosition";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external clearWatch: watchId => unit = "clearWatch";
