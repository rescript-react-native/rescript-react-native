type error;

let getItem:
  (string, ~callback: (option(error), option(string)) => unit=?, unit) =>
  Js.Promise.t(option(string));

let setItem:
  (string, string, ~callback: option(error) => unit=?, unit) =>
  Js.Promise.t(unit);

let removeItem:
  (string, ~callback: option(error) => unit=?, unit) => Js.Promise.t(unit);

let mergeItem:
  (string, string, ~callback: option(error) => unit=?, unit) =>
  Js.Promise.t(unit);

let clear: (~callback: option(error) => unit=?, unit) => Js.Promise.t(unit);

let getAllKeys:
  (~callback: (option(error), option(array(string))) => unit=?, unit) =>
  Js.Promise.t(option(array(string)));

[@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external flushGetRequests : unit => unit = "";

let multiGet:
  (
    array(string),
    ~callback: (option(array(error)), option(array(array(string)))) =>
               unit
                 =?,
    unit
  ) =>
  Js.Promise.t(option(array(array(string))));

let multiSet:
  (
    array((string, string)),
    ~callback: option(array(error)) => unit=?,
    unit
  ) =>
  Js.Promise.t(unit);

let multiRemove:
  (array(string), ~callback: option(array(error)) => unit=?, unit) =>
  Js.Promise.t(unit);

let multiMerge:
  (
    array((string, string)),
    ~callback: option(array(error)) => unit=?,
    unit
  ) =>
  Js.Promise.t(unit);