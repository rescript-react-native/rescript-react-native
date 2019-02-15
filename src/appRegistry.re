type t;

[@bs.module "react-native"] external t: t = "AppRegistry";

[@bs.send]
external _registerComponent:
  (t, string, unit => ReasonReact.reactClass) => unit =
  "registerComponent";

let registerComponent = (name, comp) => _registerComponent(t, name, comp);
