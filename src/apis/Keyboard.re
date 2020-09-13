module Easing = {
  type t = string;

  [@bs.inline]
  let easeIn = "easeIn";

  [@bs.inline]
  let easeInEaseOut = "easeInEaseOut";

  [@bs.inline]
  let easeOut = "easeOut";

  [@bs.inline]
  let linear = "linear";

  [@bs.inline]
  let keyboard = "keyboard";
};

type screenRect = {
  screenX: float,
  screenY: float,
  width: float,
  height: float,
};

type eventType = [
  | `keyboardWillShow
  | `keyboardDidShow
  | `keyboardWillHide
  | `keyboardDidHide
  | `keyboardWillChangeFrame
  | `keyboardDidChangeFrame
];

type keyboardEvent = {
  duration: float,
  easing: Easing.t,
  endCoordinates: screenRect,
  startCoordinates: screenRect,
  isEventFromThisApp: bool,
};

type listener = keyboardEvent => unit;

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external addListener: (eventType, listener) => EventSubscription.t =
  "addListener";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external removeAllListeners: eventType => unit = "removeAllListeners";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external removeListener: (eventType, listener) => unit = "removeListener";

[@bs.module "react-native"] [@bs.scope "Keyboard"]
external dismiss: unit => unit = "dismiss";
