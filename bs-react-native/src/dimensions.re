type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external _get: string => dimensions = "get";

let get = key => {
  let strKey =
    switch (key) {
    | `window => "window"
    | `screen => "screen"
    };
  _get(strKey);
};

[@bs.scope "Dimensions"] [@bs.module "react-native"]
external addEventListener:
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
external removeEventListener:
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
