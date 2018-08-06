type type_ = [ | `default | `plainText | `secureText | `loginPassword];

type button = {
  text: option(string),
  onPress: option(unit => unit),
  style: option([ | `default | `cancel | `destructive]),
};

[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external _alert :
  (
    string,
    Js.Undefined.t(string),
    Js.Undefined.t(
      array(
        {
          .
          "text": Js.Undefined.t(string),
          "onPress": Js.Undefined.t(unit => unit),
          "style": Js.Undefined.t(string),
        },
      ),
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
             fromOption(
               UtilsRN.option_map(
                 x =>
                   switch (x) {
                   | `default => "default"
                   | `cancel => "cancel"
                   | `destructive => "destructive"
                   },
                 style,
               ),
             ),
         }
       );
  let bts = fromOption(UtilsRN.option_map(transformButtons, buttons));
  let t_ =
    fromOption(
      UtilsRN.option_map(
        x =>
          switch (x) {
          | `default => "default"
          | `plainText => "plain-text"
          | `secureText => "secure-text"
          | `loginPassword => "login-password"
          },
        type_,
      ),
    );
  _alert(title, msg, bts, t_);
};

[@bs.scope "AlertIOS"] [@bs.module "react-native"]
external _prompt :
  (
    string,
    Js.Undefined.t(string),
    Js.Undefined.t(
      array(
        {
          .
          "text": Js.Undefined.t(string),
          "onPress": Js.Undefined.t(unit => unit),
          "style": Js.Undefined.t(string),
        },
      ),
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
             fromOption(
               UtilsRN.option_map(
                 x =>
                   switch (x) {
                   | `default => "default"
                   | `cancel => "cancel"
                   | `destructive => "destructive"
                   },
                 style,
               ),
             ),
         }
       );
  let bts = fromOption(UtilsRN.option_map(transformButtons, buttons));
  let t_ =
    fromOption(
      UtilsRN.option_map(
        x =>
          switch (x) {
          | `default => "default"
          | `plainText => "plain-text"
          | `secureText => "secure-text"
          | `loginPassword => "login-password"
          },
        type_,
      ),
    );
  let def_ = fromOption(defaultValue);
  let keyboardT =
    fromOption(
      UtilsRN.option_map(
        x =>
          switch (x) {
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
          | `webSearch => "web-search"
          },
        keyboardType,
      ),
    );
  _prompt(title, msg, bts, t_, def_, keyboardT);
};