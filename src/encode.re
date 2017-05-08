external string : string => Js.Json.t =
  "%identity"
  [@@ocaml.doc
    " [string s] makes a JSON string of the [string] [s] "
  ]; /* [string s] makes a JSON string of the [string] [s] */

external float : float => Js.Json.t =
  "%identity"
  [@@ocaml.doc
    " [float n] makes a JSON number of the [float] [n] "
  ]; /* [float n] makes a JSON number of the [float] [n] */

external int : int => Js.Json.t =
  "%identity"
  [@@ocaml.doc
    " [int n] makes a JSON number of the [int] [n] "
  ]; /* [int n] makes a JSON number of the [int] [n] */

external boolean : Js.boolean => Js.Json.t =
  "%identity"
  [@@ocaml.doc
    " [boolean b] makes a JSON boolean of the [Js.boolean] [b] "
  ]; /* [boolean b] makes a JSON boolean of the [Js.boolean] [b] */

external object_ : Js_dict.t Js.Json.t => Js.Json.t =
  "%identity"
  [@@ocaml.doc
    " [object_ dict] makes a JSON objet of the [Js.Dict.t] [dict] "
  ]; /* [object_ dict] makes a JSON objet of the [Js.Dict.t] [dict] */

external array : array Js.Json.t => Js.Json.t = "%identity";

external animatedValue : AnimatedRe.Value.t => Js.Json.t = "%identity";
external interpolatedValue : AnimatedRe.Interpolation.t => Js.Json.t = "%identity";
