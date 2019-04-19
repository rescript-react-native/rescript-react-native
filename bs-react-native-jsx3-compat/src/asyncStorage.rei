/**
[AsyncStorage] is a simple, unencrypted, asynchronous, persistent, key-value storage system that is global to the app. It should be used instead of LocalStorage.

It is recommended that you use an abstraction on top of [AsyncStorage] instead of [AsyncStorage] directly for anything more than light usage since it operates globally.

On iOS, [AsyncStorage] is backed by native code that stores small values in a serialized dictionary and larger values in separate files. On Android, [AsyncStorage] will use either RocksDB or SQLite based on what is available.

The [AsyncStorage] JavaScript code is a simple facade that provides a clear JavaScript API, real Error objects, and simple non-multi functions. Each method in the API returns a [JS.Promise].

You can read more on [AsyncStorage] API usage in official docs: {{:https://facebook.github.io/react-native/docs/asyncstorage}}

{3 Methods}
{4 getItem}
{[
  let getItem:
  (string, ~callback: (option(error), option(string)) => unit=?, unit) =>
  Js.Promise.t(option(string));
]}
  Fetches an item for a key provided as first argument and invokes a callback upon completion.
{4 setItem}
{[
  let setItem:
  (string, string, ~callback: option(error) => unit=?, unit) =>
  Js.Promise.t(unit);
]}
Sets the value for a  key provided as first argument and invokes a callback upon completion.
  {4 removeItem}
  {[
    let removeItem:
  (string, ~callback: option(error) => unit=?, unit) => Js.Promise.t(unit);
  ]}
  Removes an item for a  key provided as first argument and invokes a callback upon completion.
  {4 mergeItem}
  {[
    let mergeItem:
  (string, string, ~callback: option(error) => unit=?, unit) =>
  Js.Promise.t(unit);
  ]}
    Merges an existing key provided as first argument with an input value, assuming both values are stringified JSON.
  {4 clear}
  {[
    let clear: (~callback: option(error) => unit=?, unit) => Js.Promise.t(unit);
  ]}
  Erases all AsyncStorage for all clients, libraries, etc. You probably don't want to call this; use [removeItem] or [multiRemove] to clear only your app's keys.
  {4 getAllKeys}
  {[
    let getAllKeys:
  (~callback: (option(error), option(array(string))) => unit=?, unit) =>
  Js.Promise.t(option(array(string)));
  ]}
   Gets all keys known to your app; for all callers, libraries, etc.
  {4 flushGetRequests}
  {[
    [@bs.scope "AsyncStorage"] [@bs.module "react-native"]
external flushGetRequests: unit => unit = "";
  ]}
  Flushes any pending requests using a single batch call to get the data.
  {4 multiGet}
  {[
    let multiGet:
  (
    array(string),
    ~callback: (option(array(error)), option(array(array(string)))) =>
               unit
                 =?,
    unit
  ) =>
  Js.Promise.t(option(array(array(string))));
  ]}
    This allows you to batch the fetching of items given an array of key inputs. Your callback will be invoked with an array of corresponding key-value pairs found
  {4 multiSet}
  {[
    let multiSet:
  (
    array((string, string)),
    ~callback: option(array(error)) => unit=?,
    unit
  ) =>
  Js.Promise.t(unit);
  ]}
  Use this as a batch operation for storing multiple key-value pairs. When the operation completes you'll get a single callback with any errors:
  {4 multiRemove}
  {[
    let multiRemove:
  (array(string), ~callback: option(array(error)) => unit=?, unit) =>
  Js.Promise.t(unit);
  ]}
  Call this to batch the deletion of all keys in the keys array
  {4 multiMerge}
  {[
    let multiMerge:
  (
    array((string, string)),
    ~callback: option(array(error)) => unit=?,
    unit
  ) =>
  Js.Promise.t(unit);
  ]}
  Batch operation to merge in existing and new values for a given set of keys. This assumes that the values are stringified JSON

NOT SUPPORTED for all native implementations
*/
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
external flushGetRequests: unit => unit = "";

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
