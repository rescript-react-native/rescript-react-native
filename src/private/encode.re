/** [string s] makes a JSON string of the [string] [s] */
external string : string => Js.Json.t = "%identity"; /* [string s] makes a JSON string of the [string] [s] */

/** [float n] makes a JSON number of the [float] [n] */
external float : float => Js.Json.t = "%identity"; /* [float n] makes a JSON number of the [float] [n] */

/** [int n] makes a JSON number of the [int] [n] */
external int : int => Js.Json.t = "%identity"; /* [int n] makes a JSON number of the [int] [n] */

/** [boolean b] makes a JSON boolean of the [bool] [b] */
external boolean : bool => Js.Json.t = "%identity"; /* [boolean b] makes a JSON boolean of the [bool] [b] */

/** [object_ dict] makes a JSON objet of the [Js.Dict.t] [dict] */
external object_ : Js_dict.t(Js.Json.t) => Js.Json.t = "%identity"; /* [object_ dict] makes a JSON objet of the [Js.Dict.t] [dict] */

external array : array(Js.Json.t) => Js.Json.t = "%identity";

external animatedValue : AnimatedRe.Value.t => Js.Json.t = "%identity";

external interpolatedValue : AnimatedRe.Interpolation.t => Js.Json.t =
  "%identity";

let pct = pct => string(Printf.sprintf("%.2f%%", pct));