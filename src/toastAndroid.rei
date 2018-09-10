type duration =
  | LONG
  | SHORT;

type gravity =
  | BOTTOM
  | CENTER
  | TOP;

let show: (string, ~duration: duration) => unit;

let showWithGravity: (string, ~duration: duration, ~gravity: gravity) => unit;

let showWithGravityAndOffset: (string, ~duration: duration, ~gravity: gravity, ~xOffset: int, ~yOffset: int) => unit;
