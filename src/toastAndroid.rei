type duration =
  | LONG
  | SHORT;

type gravity =
  | BOTTOM
  | CENTER
  | TOP;

let show: (string, duration) => unit;

let showWithGravity: (string, duration, gravity) => unit;

let showWithGravityAndOffset: (string, duration, gravity, int, int) => unit;