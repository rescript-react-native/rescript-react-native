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

/***
 * The following is taken from bs-json (https://github.com/BuckleTypes/bs-json) converted to reason syntax
 */
let dictEntries = dict => {
  let keys = Js.Dict.keys(dict);
  let l = Js.Array.length(keys);
  let values = Obj.magic(Array.make(l, 0));
  for (i in 0 to l - 1) {
    let key = Array.unsafe_get(keys, i);
    values[i] = (key, Js.Dict.unsafeGet(dict, key));
  };
  values;
}; /* external values : 'a t -> 'a array = "Object.values" [@@bs.val] (* ES2017 *) */

let dictValues = dict => {
  let keys = Js.Dict.keys(dict);
  let l = Js.Array.length(keys);
  let values = Obj.magic(Array.make(l, 0));
  for (i in 0 to l - 1) {
    values[i] = Js.Dict.unsafeGet(dict, Array.unsafe_get(keys, i));
  };
  values;
};

let dictFromList = entries => {
  let dict = Js.Dict.empty();
  let rec loop =
    fun
    | [] => dict
    | [(key, value), ...rest] => {
        Js.Dict.set(dict, key, value);
        loop(rest);
      };
  loop(entries);
};

let dictFromArray = entries => {
  let dict = Js.Dict.empty();
  let l = Js_array.length(entries);
  for (i in 0 to l - 1) {
    let (key, value) = Array.unsafe_get(entries, i);
    Js.Dict.set(dict, key, value);
  };
  dict;
};