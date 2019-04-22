type edgeInsets;

[@bs.obj]
external edgeInsets:
  (~left: float=?, ~right: float=?, ~top: float=?, ~bottom: float=?, unit) =>
  edgeInsets =
  "";

type point;
[@bs.obj] external point: (~x: float, ~y: float) => point = "";
