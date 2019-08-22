---
id: apis/YellowBox
title: YellowBox
officialDoc: https://facebook.github.io/react-native/docs/debugging#warnings
---

Warning messages are displayed in white on a yellow background; which is known
as a YellowBox. Warnings may be trigged with the `warn` method already included
the BuckleScript module `Js.Console`. This module relates to the `YellowBox`
module in React Native.

## Methods

### `ignoreWarnings`

Allows setting an array of prefixes to be ignored; any warning message which
begins with a string in that array will not be displayed in the YellowBox.

```reason
ignoreWarnings: array(string) => unit
```

## Example

```reason
YellowBox.ignoreWarnings([|
  "Possible Unhandled Promise Rejection",
  "Remote debugger",
|]);
```
