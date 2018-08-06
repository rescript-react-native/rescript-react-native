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
    Js.Undefined.t(
      {
        .
        "cancelable": Js.Undefined.t(bool),
        "onDismiss": Js.Undefined.t(unit => unit),
      },
    ),
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
  let opts =
    fromOption(
      UtilsRN.option_map(
        ({cancelable, onDismiss}) => {
          "cancelable":
            fromOption(UtilsRN.optBoolToOptJsBoolean(cancelable)),
          "onDismiss": fromOption(onDismiss),
        },
        options,
      ),
    );
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
  _alert(title, msg, bts, opts, t_);
};