---
title: ToastAndroid
---

ToastAndroid module provides simple feedback in the small popup.

## Example of use

### default

```reason
ToastAndroid.show("A pikachu appeared nearby !", ToastAndroid.SHORT);
```

### show with gravity

````reason
ToastAndroid.showWithGravity(
  "All Your Base Are Belong To Us",
  ToastAndroid.SHORT,
  ToastAndroid.CENTER
);

### show with gravity and add offset

```reason
ToastAndroid.showWithGravityAndOffset(
  "A wild toast appeared!",
  ToastAndroid.LONG,
  ToastAndroid.BOTTOM,
  25,
  50
);
````

## Methods

### show

```reason
type duration =
  | BOTTOM
  | CENTER;
  | LONG
  | SHORT
  | TOP

(string, duration) => unit;
```

### showWithGravity

```reason
type gravity =
  | BOTTOM
  | CENTER;
  | TOP


let showWithGravity: (string, duration, gravity) => unit;
```

### showGravityAndOffset

```reason
type gravity =
 | BOTTOM
 | CENTER;
 | TOP

let showWithGravityAndOffset: (string, duration, gravity, int, int) => unit;
```

## Properties

- `BOTTOM`

```reason
  ToastAndroid.BOTTOM
```

- `CENTER`

```reason
  ToastAndroid.CENTER
```

- `LONG`

```reason
  ToastAndroid.LONG
```

- `SHORT`

```reason
  ToastAndroid.SHORT
```

- `TOP`

```reason
  ToastAndroid.TOP
```
