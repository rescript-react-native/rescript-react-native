module Easing = {
  type t;

  external fromString: string => t = "%identity";

  let easeIn = "easeIn"->fromString;
  let easeInEaseOut = "easeInEaseOut"->fromString;
  let easeOut = "easeOut"->fromString;
  let linear = "linear"->fromString;
  let keyboard = "keyboard"->fromString;
};

type screenRect = {
  .
  "screenX": float,
  "screenY": float,
  "width": float,
  "height": float,
};

type keyboardEvent = {
  .
  "duration": float,
  "easing": Easing.t,
  "endCoordinates": screenRect,
  "startCoordinates": screenRect,
  "isEventFromThisApp": bool,
};

type listener = keyboardEvent => unit;

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external addListener:
  (
    [@bs.string] [
      | `keyboardWillShow
      | `keyboardDidShow
      | `keyboardWillHide
      | `keyboardDidHide
      | `keyboardWillChangeFrame
      | `keyboardDidChangeFrame
    ],
    listener
  ) =>
  EventSubscription.t =
  "addListener";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external removeAllListeners:
  (
  [@bs.string]
  [
    | `keyboardWillShow
    | `keyboardDidShow
    | `keyboardWillHide
    | `keyboardDidHide
    | `keyboardWillChangeFrame
    | `keyboardDidChangeFrame
  ]
  ) =>
  unit =
  "removeAllListeners";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external removeListener:
  (
    [@bs.string] [
      | `keyboardWillShow
      | `keyboardDidShow
      | `keyboardWillHide
      | `keyboardDidHide
      | `keyboardWillChangeFrame
      | `keyboardDidChangeFrame
    ],
    listener
  ) =>
  unit =
  "removeListener";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external dismiss: unit => unit = "";
