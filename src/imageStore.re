type error;

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external hasImageForTag : (string, bool => unit) => unit = "";

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external removeImageForTag : string => unit = "";

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external addImageFromBase64 : (string, string => unit, error => unit) => string =
  "";

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external getBase64ForTag : (string, string => unit, error => unit) => unit =
  "";