---
id: apis/AppState
title: AppState
wip: true
---

```reason
type t;

[@bs.inline "active"]
let active: t;

[@bs.inline "background"]
let background: t;

[@bs.inline "inactive"]
let inactive: t;

[@bs.scope "AppState"] [@bs.module "react-native"]
external currentState: t = "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external addEventListener:
  ([@bs.string] [ | `change(t => unit) | `memoryWarning(unit => unit)]) =>
  EventSubscription.t =
  "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener:
  ([@bs.string] [ | `change(t => unit) | `memoryWarning(unit => unit)]) =>
  unit =
  "";

```

## Example

The example below illustrates how to call the `AppState` api. It is the [react-native](https://react-native.org/doc/appstate.html) `AppState` example converted to reason. 

```reason
open ReactNative;

[@react.component]
let make = () => {
  let (appState, setAppState) = React.useState(() => AppState.currentState);
  Js.log(appState);

  let handleAppStateChange = (nextAppState: AppState.t) => {
    Js.log2("nextAppState: ", nextAppState);
    Js.log2("appState: ", appState);
    switch (appState,nextAppState) {
    | (_background, _active) =>
      Js.log(
        "App has come to the foreground!",
      );
    | (_inactive, _active) =>
      Js.log(
        "App has come to the foreground!",
      );
    | _ => ()
    };
    setAppState(_ => nextAppState);
  };

  React.useEffect(() => {
    AppState.addEventListener(`change(state => handleAppStateChange(state)))
    |> ignore;
    Some(
      () =>
        AppState.removeEventListener(
          `change(state => handleAppStateChange(state)),
        ),
    );
  });

  let renderAppState =
    switch (appState) {
    | _active => "active"
    | _background => "background"
    | _inactive => "inactive"
    };
  <Text> {"Current state is: " ++ renderAppState |> React.string} </Text>;
};
```

