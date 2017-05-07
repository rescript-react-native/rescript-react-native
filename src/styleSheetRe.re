type t;

external t : t = "StyleSheet" [@@bs.module "react-native"];

external _create : t => Js.t 'a => Js.t 'a = "create" [@@bs.send];

let create: Js.t 'a => Js.t 'a = fun a => _create t a;

external _hairlineWidth : t => int = "hairlineWidth" [@@bs.get];

let hairlineWidth = _hairlineWidth t;

external _absoluteFill : t => StyleRe.t = "absoluteFill" [@@bs.get];

let absoluteFill = _absoluteFill t;

external _absoluteFillObject : t => StyleRe.t = "absoluteFillObject" [@@bs.get];

let absoluteFillObject = _absoluteFillObject t;

external _flatten : t => array StyleRe.t => StyleRe.t = "flatted" [@@bs.send];

let flatten styles => _flatten t (Array.of_list styles);