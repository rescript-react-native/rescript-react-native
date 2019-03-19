/**
The Geolocation API extends the Geolocation web spec: {{:https://developer.mozilla.org/en-US/docs/Web/API/Geolocation}}.

As a browser polyfill, this API is available through the [navigator.geolocation] global - you do not need to import it.

You can read more on [GeoLocation] API usage in official docs: {{:https://facebook.github.io/react-native/docs/geolocation}}

*/

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
