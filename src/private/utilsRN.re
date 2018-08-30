let option_map = (fn, opt_value) =>
  switch (opt_value) {
  | None => None
  | Some(value) => Some(fn(value))
  };

let optBoolToOptJsBoolean =
  fun
  | None => None
  | Some(v) => Some(v);

[@bs.val]
external objAssign2 : (Js.t({..}), Js.t({..}), Js.t({..})) => Js.t({..}) =
  "Object.assign";

let (<<) = (f, g, x) => f(g(x));

let dictEntries = Js.Dict.entries;

let dictValues = Js.Dict.values;

let dictFromList = Js.Dict.fromList;

let dictFromArray = Js.Dict.fromArray;
