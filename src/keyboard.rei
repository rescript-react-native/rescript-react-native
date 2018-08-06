type subscription;

type event('a) = 'a
constraint 'a =
  Js.t(
    {
      ..
      endCoordinates: {
        .
        "height": float,
        "screenX": float,
        "screenY": float,
        "width": float,
      },
    } as 'b,
  );

type listener('a) = event('a) => unit
constraint 'a =
  Js.t(
    {
      ..
      endCoordinates: {
        .
        "height": float,
        "screenX": float,
        "screenY": float,
        "width": float,
      },
    } as 'b,
  );

type keyboardEvent =
  | KeyboardWillShow
  | KeyboardDidShow
  | KeyboardWillHide
  | KeyboardDidHide
  | KeyboardWillChangeFrame
  | KeyboardDidChangeFrame;

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external dismiss : unit => unit = "";

let addListener:
  (
    keyboardEvent,
    listener(
      {
        ..
        "endCoordinates": {
          .
          "height": float,
          "screenX": float,
          "screenY": float,
          "width": float,
        },
      },
    )
  ) =>
  subscription;

let removeAllListeners: keyboardEvent => unit;

let removeListener:
  (
    keyboardEvent,
    listener(
      {
        ..
        "endCoordinates": {
          .
          "height": float,
          "screenX": float,
          "screenY": float,
          "width": float,
        },
      },
    )
  ) =>
  unit;

module Subscription: {let remove: subscription => unit;};