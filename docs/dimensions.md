---
title: Dimensions
---

## Example of use

### get(`window)

```reason
let windowDimensions = Dimensions.get(`window);
Js.log(windowDimensions##width);
Js.log(windowDimensions##height);
Js.log(windowDimensions##scale);
Js.log(windowDimensions##fontScale);
```

### get(`screen)

```reason
let screenDimensions = Dimensions.get(`screen);
Js.log(screenDimensions##width);
Js.log(screenDimensions##height);
Js.log(screenDimensions##scale);
Js.log(screenDimensions##fontScale);
```

### addEventListener and removeEventListener

```reason
let handler = dimensions => Js.log(dimensions##screen##width);

Dimensions.addEventListener("change", handler);
Dimensions.removeEventListener("change", handler);
```

## Function parameters

### get

```reason
[< | `screen | `window] => dimensions
```

_reference:_

```reason
type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};
```

### addEventListener

```reason
(
  string,
  {
    .
    "screen": dimensions,
    "window": dimensions,
  } => unit
) => unit
```

_reference:_

```reason
type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};
```

### removeEventListener

```reason
(
  string,
  {
    .
    "screen": dimensions,
    "window": dimensions,
  } => unit
) => unit
```

_reference:_

```reason
type dimensions = {
  .
  "width": int,
  "height": int,
  "scale": float,
  "fontScale": float,
};
```
