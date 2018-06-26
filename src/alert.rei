type type_ = [ | `default | `loginPassword | `plainText | `secureText];

type options = {
  cancelable: option(bool),
  onDismiss: option(unit => unit),
};

type button = {
  text: option(string),
  onPress: option(unit => unit),
  style: option([ | `cancel | `default | `destructive]),
};

let alert:
  (
    ~title: string,
    ~message: string=?,
    ~buttons: list(button)=?,
    ~options: options=?,
    ~type_: [< | `default | `loginPassword | `plainText | `secureText]=?,
    unit
  ) =>
  unit;