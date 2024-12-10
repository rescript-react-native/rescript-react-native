type options = {
  cancelable?: bool,
  onDismiss?: unit => unit,
}

type style = [#default | #cancel | #destructive]

type button = {
  text?: string,
  onPress?: unit => unit,
  style?: style,
  isPreferred?: bool,
}

@scope("Alert") @module("react-native")
external alert: (
  ~title: string,
  ~message: string=?,
  ~buttons: array<button>=?,
  ~options: options=?,
  unit,
) => unit = "alert"

type type_ = [
  | #default
  | #"plain-text"
  | #"secure-text"
  | #"login-password"
]

@scope("Alert") @module("react-native")
external prompt: (
  ~title: string,
  ~message: string=?,
  ~callbackOrButtons: @unwrap
  [
    | #callback(string => unit)
    | #buttons(array<button>)
  ]=?,
  ~type_: type_=?,
  ~defaultValue: string=?,
  ~keyboardType: string=?,
  ~options: options=?,
  unit,
) => unit = "prompt"
