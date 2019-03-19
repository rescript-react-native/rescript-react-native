/**
[AppState] can tell you if the app is in the foreground or background, and notify you when the state changes.

[AppState] is frequently used to determine the intent and proper behavior when handling push notifications.


You can read more on [AppState] API usage in official docs: {{:https://facebook.github.io/react-native/docs/appstate}}

*/

type state =
  | Active
  | Background
  | Inactive;

let currentState: unit => state;

[@bs.scope "AppState"] [@bs.module "react-native"]
external addEventListener: (string, unit => unit) => unit = "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener: (string, unit => unit) => unit = "";
