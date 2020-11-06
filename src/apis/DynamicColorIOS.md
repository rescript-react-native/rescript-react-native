---
id: apis/DynamicColorIOS
title: DynamicColorIOS
officialDoc: https://reactnative.dev/docs/dynamiccolorios
---

DynamicColorIOS takes a single argument as an record with two keys: dark and light. These correspond to the colors you want to use for "light mode" and "dark mode" on iOS.

## Types

```reason
type t = {
  dark: Color.t,
  light: Color.t
};
```

## Methods

### `make`

`make` takes an record with `dark` and `light`, and returns a color corresponding to the user's dark mode configuration.

```reason
make: t => Color.t;
```

## Example

```reason
open ReactNative;

let labelColor = DynamicColorIOS.make({ light: "black", dark: "white" });
```
