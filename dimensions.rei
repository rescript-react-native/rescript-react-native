type dimensions = {. "fontScale": float, "height": int, "scale": float, "width": int};

let get: [< | `screen | `window] => dimensions;

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external addEventListener :
  (string, {. "screen": dimensions, "window": dimensions} => unit) => unit =
  "";

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external removeEventListener :
  (string, {. "screen": dimensions, "window": dimensions} => unit) => unit =
  "";
