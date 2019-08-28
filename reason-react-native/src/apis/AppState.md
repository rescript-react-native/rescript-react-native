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
  (
  [@bs.string]
  [
    | `change(t => unit)
    | `focus(unit => unit)
    | `blur(unit => unit)
    | `memoryWarning(unit => unit)
  ]
  ) =>
  unit =
  "";

[@bs.scope "AppState"] [@bs.module "react-native"]
external removeEventListener:
  (
  [@bs.string]
  [
    | `change(t => unit)
    | `focus(unit => unit)
    | `blur(unit => unit)
    | `memoryWarning(unit => unit)
  ]
  ) =>
  unit =
  "";

```

# Example

The example below illustrates rendering to the ui based on the value returned from the `AppState` API.

```reason
[@react.component]
  let make = () => {
    let (appState, setAppState) = React.useState(_ => AppState.currentState);

    let handleAppStateChange = nextAppState => {
      switch (appState, nextAppState) {
      | (_, state) when state === AppState.background =>
        Js.log("App has come to the background!")
      | (_, state) when state === AppState.active =>
        Js.log("App has come to the foreground!")
      | _ => ()
      };
      setAppState(_ => nextAppState);
    };

    React.useEffect(() => {
      AppState.addEventListener(
        `change(state => handleAppStateChange(state)),
      )
      Some(
        () =>
          AppState.removeEventListener(
            `change(state => handleAppStateChange(state)),
          ),
      );
    });

    let renderAppState =
      switch (appState) {
      | appState when appState === AppState.active => "active"
      | appState when appState === AppState.background => "background"
      | appState when appState === AppState.inactive => "inactive"
      | _ => "unknown"
      };
    <Text> {"Current state is: " ++ renderAppState |> React.string} </Text>;
  };
```
