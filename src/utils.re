let from_opt = Js.Undefined.from_opt;

let to_js_boolean = Js.Boolean.to_js_boolean;

let option_map fn opt_value =>
  switch opt_value {
  | None => None
  | Some value => Some (fn value)
  };

let (<<) f g x => f (g x);