---
id: apis/LogBox
title: LogBox
officialDoc: https://reactnative.dev/docs/debugging#logbox
---

Errors and warnings in development builds are displayed in LogBox inside your app.

> LogBox is automatically disabled in release (production) builds.

### [`ignoreLogs`](https://reactnative.dev/docs/debugging#console-errors-and-warnings)


Console errors and warnings are displayed as on-screen notifications with a red or yellow badge, and the number of errors or warning in the console respectively. To view a console error or warnings, tap the notification to view the full screen information about the log and to paginiate through all of the logs in the console.

> type signature

```reason
ignoreLogs: array(string) => unit
```

> example

```reason
open ReactNative;

LogBox.ignoreLogs([
  "Require cycle:",
  "Remote debugger",
  "Accessing view manager configs",
  "Warning: componentWillReceiveProps",
  "Warning: componentWillMount",
]);
```

### [`ignoreAllLogs`](https://reactnative.dev/docs/debugging#console-errors-and-warnings)

These notifications can be hidden using `ReactNative.LogBox.ignoreAllLogs()`. This is useful when giving product demos, for example. Additionally, notifications can be hidden on a per-log basis via `ReactNative.LogBox.ignoreLogs([|"Require cycle:"|])`. This is useful when there's a noisy warning that cannot be fixed, like those in a third-party dependency.

**Ignore logs as a last resort and create a task to fix any logs that are ignored.**

> type signature

```reason
ignoreAllLogs: unit => unit
```

> example

```reason
open ReactNative;

LogBox.ignoreAllLogs();
```
