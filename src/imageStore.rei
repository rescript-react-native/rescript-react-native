type error;

type base64Image = string;

let hasImageForTag: (string, bool => unit) => unit;

let removeImageForTag: string => unit;

let addImageFromBase64: (base64Image, string => unit, error => unit) => unit;

let getBase64ForTag: (string, base64Image => unit, error => unit) => unit;