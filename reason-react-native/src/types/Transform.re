type angle;

let deg: float => angle = num => (num->Js.Float.toString ++ "deg")->Obj.magic;
let rad: float => angle = num => (num->Js.Float.toString ++ "rad")->Obj.magic;

type t;
[@bs.obj] external perspective: (~perspective: float) => t = "";
[@bs.obj] external rotate: (~rotate: angle) => t = "";
[@bs.obj] external rotateX: (~rotateX: angle) => t = "";
[@bs.obj] external rotateY: (~rotateY: angle) => t = "";
[@bs.obj] external rotateZ: (~rotateZ: angle) => t = "";
[@bs.obj] external scale: (~scale: float) => t = "";
[@bs.obj] external scaleX: (~scaleX: float) => t = "";
[@bs.obj] external scaleY: (~scaleY: float) => t = "";
[@bs.obj] external translateX: (~translateX: float) => t = "";
[@bs.obj] external translateY: (~translateY: float) => t = "";
[@bs.obj] external skewX: (~skewX: angle) => t = "";
[@bs.obj] external skewY: (~skewY: angle) => t = "";
