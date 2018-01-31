type subscription;

type event('a) =
  {
    ..
    "endCoordinates": {
      .
      "height": float,
      "screenX": float,
      "screenY": float,
      "width": float
    }
  } as 'a;

type listener('a) = event('a) => unit;

type keyboardEvent = [
  | `keyboardWillShow
  | `keyboardDidShow
  | `keyboardWillHide
  | `keyboardDidHide
  | `keyboardWillChangeFrame
  | `keyboardDidChangeFrame
];

let mapKeyboardEvent = keyboardEvent =>
  switch keyboardEvent {
  | `keyboardWillShow => "keyboardWillShow"
  | `keyboardDidShow => "keyboardDidShow"
  | `keyboardWillHide => "keyboardWillHide"
  | `keyboardDidHide => "keyboardDidHide"
  | `keyboardWillChangeFrame => "keyboardWillChangeFrame"
  | `keyboardDidChangeFrame => "keyboardDidChangeFrame"
  };

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external _addListener : (string, listener('a)) => subscription = "addListener";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external dismiss : unit => unit = "";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external _removeAllListeners : string => unit = "removeAllListeners";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external _removeListener : (string, listener('a)) => unit = "removeListener";

[@bs.send.pipe : subscription] external remove : unit => unit = "";

let addListener = (keyboardEvent, listener) =>
  _addListener(mapKeyboardEvent(keyboardEvent), listener);

let removeAllListeners = keyboardEvent =>
  _removeAllListeners(mapKeyboardEvent(keyboardEvent));

let removeListener = (keyboardEvent, listener) =>
  _removeListener(mapKeyboardEvent(keyboardEvent), listener);
