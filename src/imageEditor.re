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
external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";

let encodeSource = (imageSource: imageSource) =>
  switch (imageSource) {
  | `URI(imageSource) => rawImageSourceJS(imageSource)
  | `Required(imageSource) => rawImageSourceJS(imageSource)
  };

[@bs.module "react-native"] [@bs.scope "ImageEditor"]
external _cropImage :
  (
    ~source: rawImageSourceJS,
    ~cropData: cropDataT,
    ~success: string => unit,
    ~failure: error => unit
  ) =>
  unit =
  "cropImage";

let cropImage =
    (
      ~uri: imageSource,
      ~offset: offset,
      ~size: size,
      ~displaySize: option(size)=?,
      ~resizeMode: option(resizeModeT)=?,
      ~success: string => unit,
      ~failure: error => unit,
      (),
    ) => {
  let source = encodeSource(uri);
  let displaySize =
    switch (displaySize) {
    | Some(displaySize) =>
      Some(sizeT(~width=displaySize.width, ~height=displaySize.height))
    | None => None
    };

  let resizeMode =
    switch (resizeMode) {
    | Some(resizeMode) => Some(resizeModeTToJs(resizeMode))
    | None => None
    };

  let cropData =
    cropDataT(
      ~offset=offsetT(~x=offset.x, ~y=offset.y),
      ~size=sizeT(~width=size.width, ~height=size.height),
      ~displaySize=Js.Nullable.fromOption(displaySize),
      ~resizeMode=Js.Nullable.fromOption(resizeMode),
    );

  _cropImage(~source, ~cropData, ~success, ~failure);
};
