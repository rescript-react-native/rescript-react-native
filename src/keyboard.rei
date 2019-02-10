/**
Keyboard module to control keyboard events.

{3 Usage}
The Keyboard module allows you to listen for native events and react to them, as well as make changes to the keyboard, like dismissing it.


You can read more on [Keyboard] API usage in official docs: {{:https://facebook.github.io/react-native/docs/keyboard}}

{3 Types}
{4 subscription}
{[
  type subscription;
]}
{4 event}
{[
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

]}
{4 listener}
{[
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
]}
{4 keyboardEvent}
{[
  type keyboardEvent =
  | KeyboardWillShow
  | KeyboardDidShow
  | KeyboardWillHide
  | KeyboardDidHide
  | KeyboardWillChangeFrame
  | KeyboardDidChangeFrame;
]}
{3 Methods}
{4 dismiss}
{[
  dismiss: unit => unit = "";
]}
{4 addListener}
{[
  let addListener:
    (
      keyboardEvent,
      listener({
        ..
        "endCoordinates": {
          .
          "height": float,
          "screenX": float,
          "screenY": float,
          "width": float,
        },
      })
    ) =>
    subscription;
]}
{4 removeListener}
{[
  let removeListener:
    (
      keyboardEvent,
      listener({
        ..
        "endCoordinates": {
          .
          "height": float,
          "screenX": float,
          "screenY": float,
          "width": float,
        },
      })
    ) =>
    unit;
]}
{4 removeAllListeners}
{[
  let removeAllListeners: keyboardEvent => unit;
]}
*/

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
external dismiss: unit => unit = "";

let addListener:
  (
    keyboardEvent,
    listener({
      ..
      "endCoordinates": {
        .
        "height": float,
        "screenX": float,
        "screenY": float,
        "width": float,
      },
    })
  ) =>
  subscription;

let removeAllListeners: keyboardEvent => unit;

let removeListener:
  (
    keyboardEvent,
    listener({
      ..
      "endCoordinates": {
        .
        "height": float,
        "screenX": float,
        "screenY": float,
        "width": float,
      },
    })
  ) =>
  unit;

module Subscription: {let remove: subscription => unit;};
