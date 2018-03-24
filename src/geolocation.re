type rnConfig;

type currentPositionConfig;

type watchPositionConfig;

type watchId = int;

type position = {
  .
  "coords": coords,
  "timestamp": float,
}
and coords = {
  .
  "speed": int,
  "longitude": float,
  "latitude": float,
  "accuracy": int,
  "heading": int,
};

type error = {
  .
  "code": int,
  "message": string,
};

[@bs.obj]
external makeRnConfig : (~skipPermissionRequests: Js.boolean=?) => rnConfig =
  "";

[@bs.obj]
external makeCurrentPositionConfig :
  (~timeout: int=?, ~maximumAge: int=?, ~enableHighAccuracy: Js.boolean=?) =>
  currentPositionConfig =
  "";

[@bs.obj]
external makeWatchPositionConfig :
  (
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: Js.boolean=?,
    ~distanceFilter: int=?,
    ~useSignificantChanges: Js.boolean=?
  ) =>
  watchPositionConfig =
  "";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external _setRNConfiguration : rnConfig => unit = "";

let setRNConfiguration = (~skipPermissionRequests=?, ()) =>
  _setRNConfiguration(makeRnConfig(~skipPermissionRequests?));

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external requestAuthorization : unit => unit = "";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external stopObserving : unit => unit = "";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external _getCurrentPosition :
  (position => unit, error => unit, currentPositionConfig) => unit =
  "";

let getCurrentPosition =
    (~timeout=?, ~maximumAge=?, ~enableHighAccuracy=?, success, error) =>
  _getCurrentPosition(
    success,
    error,
    makeCurrentPositionConfig(~timeout?, ~maximumAge?, ~enableHighAccuracy?),
  );

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external _watchPosition :
  (position => unit, error => unit, watchPositionConfig) => watchId =
  "";

let watchPosition =
    (
      ~timeout=?,
      ~maximumAge=?,
      ~enableHighAccuracy=?,
      ~distanceFilter=?,
      ~useSignificantChanges=?,
      success,
      error,
    ) =>
  _watchPosition(
    success,
    error,
    makeWatchPositionConfig(
      ~timeout?,
      ~maximumAge?,
      ~enableHighAccuracy?,
      ~distanceFilter?,
      ~useSignificantChanges?,
    ),
  );

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external clearWatch : watchId => unit = "";
