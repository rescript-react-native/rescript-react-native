type type_ = [ | `default | `plainText | `secureText | `loginPassword];

type options = {cancelable: option bool, onDismiss: option (unit => unit)};

type button = {
  text: option string,
  onPress: option (unit => unit),
  style: option [ | `default | `cancel | `destructive]
};

external _alert :
  string =>
  Js.Undefined.t string =>
  Js.Undefined.t (
    array (
      Js.t {
        .
        text : Js.Undefined.t string,
        onPress : Js.Undefined.t (unit => unit),
        style : Js.Undefined.t string
      }
    )
  ) =>
  Js.Undefined.t (
    Js.t {. cancelable : Js.Undefined.t Js.boolean, onDismiss : Js.Undefined.t (unit => unit)}
  ) =>
  unit =
  "alert" [@@bs.scope "AlertIOS"] [@@bs.module "react-native"];

let alert ::title ::message=? ::buttons=? ::options=? () => {
  open Js.Undefined;
  let msg = from_opt message;
  let transformButtons xs =>
    Array.of_list xs |>
    Array.map (
      fun {text, onPress, style} => {
        "text": from_opt text,
        "onPress": from_opt onPress,
        "style":
          from_opt (
            UtilsRN.option_map
              (
                fun x =>
                  switch x {
                  | `default => "default"
                  | `cancel => "cancel"
                  | `destructive => "destructive"
                  }
              )
              style
          )
      }
    );
  let bts = from_opt (UtilsRN.option_map transformButtons buttons);
  let opts =
    from_opt (
      UtilsRN.option_map
        (
          fun {cancelable, onDismiss} => {
            "cancelable": from_opt (UtilsRN.optBoolToOptJsBoolean cancelable),
            "onDismiss": from_opt onDismiss
          }
        )
        options
    );
  _alert title msg bts opts
};

external _prompt :
  string =>
  Js.Undefined.t string =>
  Js.Undefined.t (
    array (
      Js.t {
        .
        text : Js.Undefined.t string,
        onPress : Js.Undefined.t (unit => unit),
        style : Js.Undefined.t string
      }
    )
  ) =>
  Js.Undefined.t (
    Js.t {. cancelable : Js.Undefined.t Js.boolean, onDismiss : Js.Undefined.t (unit => unit)}
  ) =>
  Js.Undefined.t string =>
  Js.Undefined.t string =>
  Js.Undefined.t string =>
  unit =
  "prompt" [@@bs.scope "AlertIOS"] [@@bs.module "react-native"];

let prompt
    ::title
    ::message=?
    ::buttons=?
    ::options=?
    ::type_=?
    ::defaultValue=?
    ::keyboardType=?
    () => {
  open Js.Undefined;
  let msg = from_opt message;
  let transformButtons xs =>
    Array.of_list xs |>
    Array.map (
      fun {text, onPress, style} => {
        "text": from_opt text,
        "onPress": from_opt onPress,
        "style":
          from_opt (
            UtilsRN.option_map
              (
                fun x =>
                  switch x {
                  | `default => "default"
                  | `cancel => "cancel"
                  | `destructive => "destructive"
                  }
              )
              style
          )
      }
    );
  let bts = from_opt (UtilsRN.option_map transformButtons buttons);
  let opts =
    from_opt (
      UtilsRN.option_map
        (
          fun {cancelable, onDismiss} => {
            "cancelable": from_opt (UtilsRN.optBoolToOptJsBoolean cancelable),
            "onDismiss": from_opt onDismiss
          }
        )
        options
    );
  let t_ =
    from_opt (
      UtilsRN.option_map
        (
          fun x =>
            switch x {
            | `default => "default"
            | `plainText => "plain-text"
            | `secureText => "sercure-text"
            | `loginPassword => "login-password"
            }
        )
        type_
    );
  let def_ = from_opt defaultValue;
  let keyboardT =
    from_opt (
      UtilsRN.option_map
        (
          fun x =>
            switch x {
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
            }
        )
        keyboardType
    );
  _prompt title msg bts opts t_ def_ keyboardT
};