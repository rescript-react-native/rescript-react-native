type rnConfig;

type currentPositionConfig;

type watchPositionConfig;

type watchId = int;

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

[@bs.module "react-native"] [@bs.scope "Geolocation"]
external _setRNConfiguration : rnConfig => unit = "setRNConfiguration";

let setRNConfiguration = (~skipPermissionRequests=?, ()) =>
  _setRNConfiguration(makeRnConfig(~skipPermissionRequests?));

[@bs.module "react-native"] [@bs.scope "Geolocation"]
external requestAuthorization : unit => unit = "";

[@bs.module "react-native"] [@bs.scope "Geolocation"]
external stopObserving : unit => unit = "";

[@bs.module "react-native"] [@bs.scope "Geolocation"]
external _getCurrentPosition :
  (unit => unit, unit => unit, currentPositionConfig) => unit =
  "getCurrentPosition";

[@bs.module "react-native"] [@bs.scope "Geolocation"]
external _watchPosition :
  (unit => unit, unit => unit, watchPositionConfig) => watchId =
  "watchPosition";

[@bs.module "react-native"] [@bs.scope "Geolocation"]
external clearWatch : watchId => unit = "";

let getCurrentPosition =
    (~success, ~error, ~timeout=?, ~maximumAge=?, ~enableHighAccuracy=?, ()) =>
  _getCurrentPosition(
    success,
    error,
    makeCurrentPositionConfig(~timeout?, ~maximumAge?, ~enableHighAccuracy?),
  );

let watchPosition =
    (
      ~success,
      ~error,
      ~timeout=?,
      ~maximumAge=?,
      ~enableHighAccuracy=?,
      ~distanceFilter=?,
      ~useSignificantChanges=?,
      (),
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
