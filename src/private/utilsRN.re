[@bs.val]
external objAssign2: (Js.t({..}), Js.t({..}), Js.t({..})) => Js.t({..}) =
  "Object.assign";

let (<<) = (f, g, x) => f(g(x));
