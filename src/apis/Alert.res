type options

@obj
external options: (~cancelable: bool=?, ~onDismiss: unit => unit=?, unit) => options = ""

type button

type style = [#default | #cancel | #destructive]

@obj
external button: (~text: string=?, ~onPress: unit => unit=?, ~style: style=?, unit) => button = ""

@scope("Alert") @module("react-native")
external alert: (
  ~title: string,
  ~message: string=?,
  ~buttons: array<button>=?,
  ~options: options=?,
  unit,
) => unit = "alert"

@scope("Alert") @module("react-native")
external prompt: (
  ~title: string,
  ~message: string=?,
  ~callbackOrButtons: @unwrap
  [
    | #callback(string => unit)
    | #buttons(array<button>)
  ]=?,
  ~type_: @string
  [
    | #default
    | @as("plain-text") #plainText
    | @as("secure-text") #secureText
    | @as("login-password") #loginPassword
  ]=?,
  ~defaultValue: string=?,
  ~keyboardType: string=?,
  unit,
) => unit = "prompt"
