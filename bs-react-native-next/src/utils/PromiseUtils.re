let nullableToOption = stringOrNull =>
  Js.Promise.resolve(stringOrNull->Js.Null.toOption);
