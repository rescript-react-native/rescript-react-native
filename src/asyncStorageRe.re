type error;

let to_opt x => Js.Promise.resolve (Js.Null_undefined.to_opt x);

let map_cb cb err value => cb (Js.Null.to_opt err) (Js.Null_undefined.to_opt value);

let map_cb_err_only cb err => cb (Js.Null.to_opt err);

external _getItem :
  string =>
  Js.Undefined.t (Js.Null.t error => Js.Null_undefined.t string => unit) =>
  Js.Promise.t (Js.Null_undefined.t string) =
  "getItem" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let getItem key ::callback=? () =>
  switch callback {
  | None => Js.Promise.then_ to_opt (_getItem key Js.undefined)
  | Some cb => Js.Promise.then_ to_opt (_getItem key (Js.Undefined.return (map_cb cb)))
  };

external _setItem :
  string => string => Js.Undefined.t (Js.Null.t error => unit) => Js.Promise.t unit =
  "setItem" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let setItem key value ::callback=? () =>
  switch callback {
  | None => _setItem key value Js.undefined
  | Some cb => _setItem key value (Js.Undefined.return (map_cb_err_only cb))
  };

external _removeItem : string => Js.Undefined.t (Js.Null.t error => unit) => Js.Promise.t unit =
  "removeItem" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let removeItem key ::callback=? () =>
  switch callback {
  | None => _removeItem key Js.undefined
  | Some cb => _removeItem key (Js.Undefined.return (map_cb_err_only cb))
  };

external _mergeItem :
  string => string => Js.Undefined.t (Js.Null.t error => unit) => Js.Promise.t unit =
  "mergeItem" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let mergeItem key value ::callback=? () =>
  switch callback {
  | None => _mergeItem key value Js.undefined
  | Some cb => _mergeItem key value (Js.Undefined.return (map_cb_err_only cb))
  };

external _clear : Js.Undefined.t (Js.Null.t error => unit) => Js.Promise.t unit =
  "clear" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let clear ::callback=? () =>
  switch callback {
  | None => _clear Js.undefined
  | Some cb => _clear (Js.Undefined.return (map_cb_err_only cb))
  };

external _getAllKeys :
  Js.Undefined.t (Js.Null.t error => Js.Null_undefined.t (array string) => unit) =>
  Js.Promise.t (Js.Null_undefined.t (array string)) =
  "getAllKeys" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let getAllKeys ::callback=? () =>
  switch callback {
  | None => Js.Promise.then_ to_opt (_getAllKeys Js.undefined)
  | Some cb => Js.Promise.then_ to_opt (_getAllKeys (Js.Undefined.return (map_cb cb)))
  };

external flushGetRequests : unit => unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external _multiGet :
  array string =>
  Js.Undefined.t (Js.Null.t (array error) => Js.Null_undefined.t (array (array string)) => unit) =>
  Js.Promise.t (Js.Null_undefined.t (array (array string))) =
  "multiGet" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let multiGet keys ::callback=? () =>
  switch callback {
  | None => Js.Promise.then_ to_opt (_multiGet keys Js.undefined)
  | Some cb => Js.Promise.then_ to_opt (_multiGet keys (Js.Undefined.return (map_cb cb)))
  };

external _multiSet :
  array (array string) => Js.Undefined.t (Js.Null.t (array error) => unit) => Js.Promise.t unit =
  "multiSet" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let multiSet keyValues ::callback=? () => {
  let combine (key, value) => [|key, value|];
  switch callback {
  | None => _multiSet (Array.map combine keyValues) Js.undefined
  | Some cb => _multiSet (Array.map combine keyValues) (Js.Undefined.return (map_cb_err_only cb))
  }
};

external _multiRemove :
  array string => Js.Undefined.t (Js.Null.t (array error) => unit) => Js.Promise.t unit =
  "multiRemove" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let multiRemove keys ::callback=? () =>
  switch callback {
  | None => _multiRemove keys Js.undefined
  | Some cb => _multiRemove keys (Js.Undefined.return (map_cb_err_only cb))
  };

external _multiMerge :
  array (array string) => Js.Undefined.t (Js.Null.t (array error) => unit) => Js.Promise.t unit =
  "multiMerge" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let multiMerge keyValues ::callback=? () => {
  let combine (key, value) => [|key, value|];
  switch callback {
  | None => _multiMerge (Array.map combine keyValues) Js.undefined
  | Some cb => _multiMerge (Array.map combine keyValues) (Js.Undefined.return (map_cb_err_only cb))
  }
};