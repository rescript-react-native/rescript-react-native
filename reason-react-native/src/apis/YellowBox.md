---
id: apis/YellowBox
title: YellowBox
wip: true
---

```reason
[@bs.module "react-native"] [@bs.scope "YellowBox"]
external ignoreWarnings: array(string) => unit = "";

```

## Example

```reason
YellowBox.ignoreWarnings([|
  "Possible Unhandled Promise Rejection",
  "Remote debugger",
|]);
```
