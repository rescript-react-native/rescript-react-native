type type_ = [ | `default | `loginPassword | `plainText | `secureText];

type options = {
  cancelable: option(bool),
  onDismiss: option((unit => unit))
};

type button = {
  text: option(string),
  onPress: option((unit => unit)),
  style: option([ | `cancel | `default | `destructive])
};

let alert:
  (~title: string, ~message: string=?, ~buttons: list(button)=?, ~options: options=?, unit) => unit;

let prompt:
  (
    ~title: string,
    ~message: string=?,
    ~buttons: list(button)=?,
    ~options: options=?,
    ~type_: [< | `default | `loginPassword | `plainText | `secureText]=?,
    ~defaultValue: string=?,
    ~keyboardType: [<
                     | `asciiCapable
                     | `decimalPad
                     | `default
                     | `emailAddress
                     | `namePhonePad
                     | `numberPad
                     | `numbersAndPunctuation
                     | `numeric
                     | `phonePad
                     | `twitter
                     | `url
                     | `webSearch
                   ]
                     =?,
    unit
  ) =>
  unit;
