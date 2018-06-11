---
id: modal
title: Modal
sidebar_label: Modal
---

# Props

## animationType

```reason
animationType: [
  | `fade
  | `none
  | `slide
]=?
```

## onShow

```reason
onShow: unit => unit=?
```

## transparent

```reason
transparent: bool=?
```

## visible

```reason
visible: bool=?
```

## hardwareAccelerated

```reason
hardwareAccelerated: bool=?
```

## onRequestClose

```reason
onRequestClose: unit => unit=?
```

## onOrientationChange

```reason
onOrientationChange: unit => unit=?
```

## supportedOrientations

```reason
supportedOrientations: array(
  [
    | `landscape
    | `landscapeLeft
    | `landscapeRight
    | `portrait
    | `portraitUpsideDown
  ],
)=?
```
