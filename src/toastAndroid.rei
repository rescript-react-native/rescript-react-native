type duration =
  | BOTTOM
  | CENTER
  | LONG
  | SHORT
  | TOP;

type gravity =
  | BOTTOM
  | CENTER
  | TOP;

let show: (string, duration) => unit;

let showWithGravity: (string, duration, gravity) => unit;

let showWithGravityAndOffset: (string, duration, gravity, int, int) => unit;