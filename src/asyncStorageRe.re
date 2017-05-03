external _getItem : string => Js.Promise.t (Js.Null_undefined.t string) =
  "getItem" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let to_opt x => Js.Promise.resolve (Js.Null_undefined.to_opt x);

let getItem key => Js.Promise.then_ to_opt (_getItem key);

external setItem : string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external removeItem : string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external mergeItem : string => string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external clear : unit => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external _getAllKeys : unit => Js.Promise.t (Js.Null_undefined.t (array string)) =
  "getAllKeys" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let getAllKeys () => Js.Promise.then_ to_opt (_getAllKeys ());

external flushGetRequests : unit => unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external _multiGet : array string => Js.Promise.t (Js.Null_undefined.t (array (array string))) =
  "multiGet" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let multiGet keys => Js.Promise.then_ to_opt (_multiGet keys);

external multiSet : array string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external multiRemove : array string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external multiMerge : array (array string) => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];