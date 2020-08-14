---
id: apis/LogBox
title: LogBox
officialDoc: https://reactnative.dev/docs/debugging#warnings
---

Warning messages are displayed in white on a yellow background; which is known
as a LogBox. Warnings may be trigged with the `Js.Console.warn` function
included in BuckleScript.

## Methods

### `ignoreLogs`

Allows setting an array of prefixes to be ignored; any warning message which
begins with a string in that array will not be displayed in the LogBox.

```reason
ignoreLogs: array(string) => unit
```
### `ignoreAllLogs`

Allows setting an array of prefixes to be ignored; any warning message which
begins with a string in that array will not be displayed in the LogBox.

```reason
ignoreAllLogs: unit => unit
```

## Example

```reason
LogBox.ignoreLogs([
  "Require cycle:",
  "Remote debugger",
  "Accessing view manager configs",
  "Warning: componentWillReceiveProps",
  "Warning: componentWillMount",
]);
// Ignore all log notifications:
LogBox.ignoreAllLogs();

LogBox.install()
LogBox.uninstall()
```
