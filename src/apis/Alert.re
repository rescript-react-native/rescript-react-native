type options;

[@bs.obj]
external options:
  (~cancelable: bool=?, ~onDismiss: unit => unit=?, unit) => options;

type button;

[@bs.obj]
external button:
  (
    ~text: string=?,
    ~onPress: unit => unit=?,
    ~style: [@bs.string] [ | `default | `cancel | `destructive]=?,
    unit
  ) =>
  button;

[@bs.scope "Alert"] [@bs.module "react-native"]
external alert:
  (
    ~title: string,
    ~message: string=?,
    ~buttons: array(button)=?,
    ~options: options=?,
    unit
  ) =>
  unit =
  "alert";

[@bs.scope "Alert"] [@bs.module "react-native"]
external prompt:
  (
    ~title: string,
    ~message: string=?,
    ~callbackOrButtons: [@bs.unwrap] [
                          | `callback(string => unit)
                          | `buttons(array(button))
                        ]
                          =?,
    ~type_: [@bs.string] [
              | `default
              | [@bs.as "plain-text"] `plainText
              | [@bs.as "secure-text"] `secureText
              | [@bs.as "login-password"] `loginPassword
            ]
              =?,
    ~defaultValue: string=?,
    ~keyboardType: string=?,
    unit
  ) =>
  unit =
  "prompt";
