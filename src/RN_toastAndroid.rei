type duration =
  | LONG
  | SHORT;

type gravity =
  | BOTTOM
  | CENTER
  | TOP;

let show: (string, ~duration: duration, ~gravity: gravity=?, ~offset: (int, int)=?, unit) => unit;
