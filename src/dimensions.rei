type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};

let get: [< | `screen | `window] => dimensions;

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external addEventListener :
  (
    string,
    {
      .
      "screen": dimensions,
      "window": dimensions,
    } =>
    unit
  ) =>
  unit =
  "";

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external removeEventListener :
  (
    string,
    {
      .
      "screen": dimensions,
      "window": dimensions,
    } =>
    unit
  ) =>
  unit =
  "";