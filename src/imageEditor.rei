type imageSource = [ | `URI(string) | `Required(Packager.required)];

type offset = {
  x: int,
  y: int,
};

type size = {
  width: int,
  height: int,
};

[@bs.deriving jsConverter]
type resizeModeT = [
  | [@bs.as "contain"] `Contain
  | [@bs.as "cover"] `Cover
  | [@bs.as "stretch"] `Stretch
];

[@bs.deriving abstract]
type offsetT = {
  x: int,
  y: int,
};

[@bs.deriving abstract]
type sizeT = {
  width: int,
  height: int,
};

[@bs.deriving abstract]
type cropDataT = {
  offset: offsetT,
  size: sizeT,
  displaySize: Js.Nullable.t(sizeT),
  resizeMode: Js.Nullable.t(string),
};

[@bs.deriving abstract]
type error = {
  code: int,
  message: string,
};

type rawImageSourceJS;
external rawImageSourceJS: 'a => rawImageSourceJS = "%identity";

let encodeSource: imageSource => rawImageSourceJS;

[@bs.module "react-native"] [@bs.scope "ImageEditor"]
external _cropImage:
  (
    ~source: rawImageSourceJS,
    ~cropData: cropDataT,
    ~success: string => unit,
    ~failure: error => unit
  ) =>
  unit =
  "cropImage";

let cropImage:
  (
    ~uri: imageSource,
    ~offset: offset,
    ~size: size,
    ~displaySize: size=?,
    ~resizeMode: resizeModeT=?,
    ~success: string => unit,
    ~failure: error => unit,
    unit
  ) =>
  unit;
