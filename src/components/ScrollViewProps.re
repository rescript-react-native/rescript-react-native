[@bs.deriving jsConverter]
type overScrollMode = [ | `auto | `always | `never];

[@bs.deriving jsConverter]
type contentInsetAdjustmentBehavior = [
  | `automatic
  | `scrollableAxes
  | `never
  | `always
];

[@bs.deriving jsConverter]
type decelerationRate = [ | `fast | `normal];

[@bs.deriving jsConverter]
type indicatorStyle = [ | `default | `black | `white];

[@bs.deriving jsConverter]
type snapToAlignment = [ | `center | `start | [@bs.as "end"] `end_];

[@bs.deriving jsConverter]
type keyboardDismissMode = [
  | `interactive
  | `none
  | [@bs.as "on-drag"] `onDrag
];

[@bs.deriving jsConverter]
type keyboardShouldPersistTaps = [ | `always | `never | `handled];
