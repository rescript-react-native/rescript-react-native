let getItem: string => Js.Promise.t (option string);

external setItem : string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external removeItem : string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external mergeItem : string => string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let getAllKeys: unit => Js.Promise.t (option (array string));

external clear : unit => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external flushGetRequests : unit => unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

let multiGet: array string => Js.Promise.t (option (array (array string)));

external multiSet : array string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external multiRemove : array string => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];

external multiMerge : array (array string) => Js.Promise.t unit =
  "" [@@bs.scope "AsyncStorage"] [@@bs.module "react-native"];