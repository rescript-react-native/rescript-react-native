let option_map = (fn, opt_value) =>
  switch (opt_value) {
  | None => None
  | Some(value) => Some(fn(value))
  };

[@bs.val]
external objAssign2: (Js.t({..}), Js.t({..}), Js.t({..})) => Js.t({..}) =
  "Object.assign";

let (<<) = (f, g, x) => f(g(x));
