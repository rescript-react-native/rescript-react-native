type state =
  | Active
  | Background
  | Inactive;

[@bs.scope "AppState"] [@bs.module "react-native"]
external _currentState: string = "currentState";

let currentState = () => {
  let currState = _currentState;
  switch (currState) {
  | "active" => Active
  | "background" => Background
  | _ => Inactive
  };
};

[@bs.scope "AppState"] [@bs.module "react-native"]
external addEventListener: (string, unit => unit) => unit = "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener: (string, unit => unit) => unit = "";
