type type_ = [ | `default | `plainText | `secureText | `loginPassword];

type button = {
  text: option(string),
  onPress: option(unit => unit),
  style: option([ | `default | `cancel | `destructive]),
};

[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external _alert:
  (
    string,
    Js.Undefined.t(string),
    Js.Undefined.t(
      array({
        .
        "text": Js.Undefined.t(string),
        "onPress": Js.Undefined.t(unit => unit),
        "style": Js.Undefined.t(string),
      }),
    ),
    Js.Undefined.t(string)
  ) =>
  unit =
  "alert";

let alert = (~title, ~message=?, ~buttons=?, ~type_=?, ()) => {
  open Js.Undefined;
  let msg = fromOption(message);
  let transformButtons = xs =>
    Array.of_list(xs)
    |> Array.map(({text, onPress, style}) =>
         {
           "text": fromOption(text),
           "onPress": fromOption(onPress),
           "style":
             style
             ->Belt.Option.map(
                 fun
                 | `default => "default"
                 | `cancel => "cancel"
                 | `destructive => "destructive",
               )
             ->fromOption,
         }
       );
  let bts = buttons->Belt.Option.map(transformButtons)->fromOption;
  let t_ =
    type_
    ->Belt.Option.map(
        fun
        | `default => "default"
        | `plainText => "plain-text"
        | `secureText => "secure-text"
        | `loginPassword => "login-password",
      )
    ->fromOption;

  _alert(title, msg, bts, t_);
};

[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external _prompt:
  (
    string,
    Js.Undefined.t(string),
    Js.Undefined.t(
      array({
        .
        "text": Js.Undefined.t(string),
        "onPress": Js.Undefined.t(unit => unit),
        "style": Js.Undefined.t(string),
      }),
    ),
    Js.Undefined.t(string),
    Js.Undefined.t(string),
    Js.Undefined.t(string)
  ) =>
  unit =
  "prompt";

let prompt =
    (
      ~title,
      ~message=?,
      ~buttons=?,
      ~type_=?,
      ~defaultValue=?,
      ~keyboardType=?,
      (),
    ) => {
  open Js.Undefined;
  let msg = fromOption(message);
  let transformButtons = xs =>
    Array.of_list(xs)
    |> Array.map(({text, onPress, style}) =>
         {
           "text": fromOption(text),
           "onPress": fromOption(onPress),
           "style":
             style
             ->Belt.Option.map(
                 fun
                 | `default => "default"
                 | `cancel => "cancel"
                 | `destructive => "destructive",
               )
             ->fromOption,
         }
       );
  let bts = buttons->Belt.Option.map(transformButtons)->fromOption;
  let t_ =
    type_
    ->Belt.Option.map(
        fun
        | `default => "default"
        | `plainText => "plain-text"
        | `secureText => "secure-text"
        | `loginPassword => "login-password",
      )
    ->fromOption;
  let def_ = fromOption(defaultValue);
  let keyboardT =
    keyboardType
    ->Belt.Option.map(
        fun
        | `default => "default"
        | `emailAddress => "email-address"
        | `numeric => "numeric"
        | `phonePad => "phone-pad"
        | `asciiCapable => "ascii-capable"
        | `numbersAndPunctuation => "numbers-and-punctuation"
        | `url => "url"
        | `numberPad => "number-pad"
        | `namePhonePad => "name-phone-pad"
        | `decimalPad => "decimal-pad"
        | `twitter => "twitter"
        | `webSearch => "web-search",
      )
    ->fromOption;

  _prompt(title, msg, bts, t_, def_, keyboardT);
};
