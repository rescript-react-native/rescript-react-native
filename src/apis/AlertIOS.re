type button;
[@bs.obj]
external button:
  (
    ~text: string=?,
    ~onPress: option(string) => unit=?,
    ~style: [@bs.string] [ | `default | `cancel | `destructive]=?,
    unit
  ) =>
  button =
  "";

// multiple externals
[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external alert:
  (~title: string, ~message: string=?, ~buttons: array(button)=?, unit) =>
  unit =
  "";

// multiple externals
[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external alertWithOKButton:
  (~title: string, ~message: string=?, ~callback: unit => unit=?, unit) => unit =
  "alert";

// multiple externals
[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external prompt:
  (
    ~title: string,
    ~message: string=?,
    ~buttons: array(button)=?,
    ~_type: [@bs.string] [
              | `default
              | [@bs.as "plain-text"] `plainText
              | [@bs.as "secure-text"] `secureText
              | [@bs.as "login-password"] `loginPassword
            ]
              =?,
    ~defaultValue: string=?,
    ~keyboardType: [@bs.string] [
                     | `default
                     | [@bs.as "number-pad"] `numberPad
                     | [@bs.as "decimal-pad"] `decimalPad
                     | `numeric
                     | [@bs.as "email-address"] `emailAddress
                     | [@bs.as "phone-pad"] `phonePad
                     | [@bs.as "ascii-capable"] `asciiCapable
                     | [@bs.as "numbers-and-punctuation"]
                       `numbersAndPunctuation
                     | `url
                     | [@bs.as "name-phone-pad"] `namePhonePad
                     | `twitter
                     | [@bs.as "web-search"] `webSearch
                     | [@bs.as "visible-password"] `visiblePassword
                   ]
                     =?,
    unit
  ) =>
  unit =
  "";

// multiple externals
[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external promptWithOKButton:
  (
    ~title: string,
    ~message: string=?,
    ~callback: string => unit=?,
    ~_type: [@bs.string] [
              | `default
              | [@bs.as "plain-text"] `plainText
              | [@bs.as "secure-text"] `secureText
              | [@bs.as "login-password"] `loginPassword
            ]
              =?,
    ~defaultValue: string=?,
    ~keyboardType: [@bs.string] [
                     | `default
                     | [@bs.as "number-pad"] `numberPad
                     | [@bs.as "decimal-pad"] `decimalPad
                     | `numeric
                     | [@bs.as "email-address"] `emailAddress
                     | [@bs.as "phone-pad"] `phonePad
                     | [@bs.as "ascii-capable"] `asciiCapable
                     | [@bs.as "numbers-and-punctuation"]
                       `numbersAndPunctuation
                     | `url
                     | [@bs.as "name-phone-pad"] `namePhonePad
                     | `twitter
                     | [@bs.as "web-search"] `webSearch
                     | [@bs.as "visible-password"] `visiblePassword
                   ]
                     =?,
    unit
  ) =>
  unit =
  "prompt";
