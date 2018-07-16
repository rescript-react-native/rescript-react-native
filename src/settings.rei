let get: string => string;

let set: Js.Dict.t(string) => unit;

let watchKeys: (list(string), unit => unit) => int;

let clearWatch: int => unit;