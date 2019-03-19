type type_ = [ | `default | `plainText | `secureText | `loginPassword];

type options = {
  cancelable: option(bool),
  onDismiss: option(unit => unit),
};

type button = {
  text: option(string),
  onPress: option(unit => unit),
  style: option([ | `default | `cancel | `destructive]),
};

[@bs.scope "Alert"] [@bs.module "react-native"]
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
    Js.Undefined.t({
      .
      "cancelable": Js.Undefined.t(bool),
      "onDismiss": Js.Undefined.t(unit => unit),
    }),
    Js.Undefined.t(string)
  ) =>
  unit =
  "alert";

let alert = (~title, ~message=?, ~buttons=?, ~options=?, ~type_=?, ()) => {
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
               style->Belt.Option.map(
                 fun
                 | `default => "default"
                 | `cancel => "cancel"
                 | `destructive => "destructive",
               ),
             ),
         }
       );
  let bts = buttons->Belt.Option.map(transformButtons)->fromOption;
  let opts =
    options
    ->Belt.Option.map(({cancelable, onDismiss}) =>
        {
          "cancelable": fromOption(cancelable),
          "onDismiss": fromOption(onDismiss),
        }
      )
    ->fromOption;
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

  _alert(title, msg, bts, opts, t_);
};
