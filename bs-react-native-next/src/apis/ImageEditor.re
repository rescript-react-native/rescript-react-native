type source;

external fromRequired: Packager.required => source = "%identity";
external fromUriSource: string => source = "%identity";

type offset;

[@bs.obj] external offset: (~x: int, ~y: int) => offset = "";

type size;

[@bs.obj] external size: (~width: int, ~height: int) => size = "";

type cropData;

[@bs.obj]
external cropData:
  (
    ~offset: offset,
    ~size: size,
    ~displaySize: size=?,
    ~resizeMode: [@bs.string] [ | `contain | `cover | `stretch]=?,
    unit
  ) =>
  cropData =
  "";

[@bs.module "react-native"] [@bs.scope "ImageEditor"]
external cropImage:
  (
    ~uri: source,
    ~cropData: cropData,
    ~success: string => unit,
    ~failure: (~code: int, ~message: string) => unit,
    unit
  ) =>
  unit =
  "cropImage";