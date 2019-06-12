/* encoders to json for react-native */
module Encoder = {
  external string: string => Js.Json.t = "%identity";

  external float: float => Js.Json.t = "%identity";

  external int: int => Js.Json.t = "%identity";

  external boolean: bool => Js.Json.t = "%identity";

  external object_: Js_dict.t(Js.Json.t) => Js.Json.t = "%identity";

  external array: array(Js.Json.t) => Js.Json.t = "%identity";

  external animatedValue: AnimatedRe.value('a) => Js.Json.t = "%identity";

  let pct = f => string(Printf.sprintf("%.2f%%", f));

  let deg = f => string(Printf.sprintf("%.2f", f) ++ "deg");
};
