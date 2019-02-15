type duration =
  | LONG
  | SHORT;

type gravity =
  | BOTTOM
  | CENTER
  | TOP;

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external long: int = "LONG";
[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external short: int = "SHORT";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external bottom: int = "BOTTOM";
[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external center: int = "CENTER";
[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external top: int = "TOP";

let getDuration = d =>
  switch (d) {
  | LONG => long
  | SHORT => short
  };

let getGravity = g =>
  switch (g) {
  | BOTTOM => bottom
  | TOP => top
  | CENTER => center
  };

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external _show: (string, int) => unit = "show";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external _showWithGravity: (string, int, int) => unit = "showWithGravity";

[@bs.module "react-native"] [@bs.scope "ToastAndroid"]
external _showWithGravityAndOffset: (string, int, int, int, int) => unit =
  "showWithGravityAndOffset";

let show = (message, ~duration, ~gravity=?, ~offset=?, ()) =>
  switch (gravity, offset) {
  | (None, None) => _show(message, getDuration(duration))
  | (Some(gravity), None) =>
    _showWithGravity(message, getDuration(duration), getGravity(gravity))
  | (Some(gravity), Some((x, y))) =>
    _showWithGravityAndOffset(
      message,
      getDuration(duration),
      getGravity(gravity),
      x,
      y,
    )
  | (None, Some((x, y))) =>
    _showWithGravityAndOffset(
      message,
      getDuration(duration),
      getGravity(BOTTOM),
      x,
      y,
    )
  };
