let get: string => string;

let set: Js.Dict.t(string) => unit;

type watchToken;

let watchKeys: (list(string), unit => unit) => watchToken;

let clearWatch: watchToken => unit;