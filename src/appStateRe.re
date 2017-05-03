type state =
  | Active
  | Background
  | Inactive;

external _currentState : string =
  "currentState" [@@bs.scope "AppState"] [@@bs.module "react-native"];

let currentState () => {
  let currState = _currentState;
  switch currState {
  | "active" => Active
  | "background" => Background
  | _ => Inactive
  }
};

external addEventListener : string => (unit => unit) => unit =
  "" [@@bs.scope "AppState"] [@@bs.module "react-native"];

external removeEventListener : string => (unit => unit) => unit =
  "" [@@bs.scope "AppState"] [@@bs.module "react-native"];