---
id: apis/YellowBox
title: YellowBox
officialDoc: https://reactnative.dev/docs/debugging#warnings
---

Warning messages are displayed in white on a yellow background; which is known
as a YellowBox. Warnings may be trigged with the `Js.Console.warn` function
included in ReScript.

## Methods

### `ignoreWarnings`

Allows setting an array of prefixes to be ignored; any warning message which
begins with a string in that array will not be displayed in the YellowBox.

```rescript
ignoreWarnings: array(string) => unit
```

## Example

```rescript
YellowBox.ignoreWarnings([
  "Possible Unhandled Promise Rejection",
  "Remote debugger",
]);
```
