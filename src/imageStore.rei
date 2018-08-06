type error;

let hasImageForTag: (string, bool => unit) => unit;

let removeImageForTag: string => unit;

let addImageFromBase64: (string, string => unit, error => unit) => string;

let getBase64ForTag: (string, string => unit, error => unit) => unit;