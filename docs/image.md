---
id: image
title: Image
sidebar_label: Image
---

# Props

## onError

```reason
onError: Event.error => unit=?
```

## onLayout

```reason
onLayout: RNEvent.NativeLayoutEvent.t => unit=?
```

_reference:_

**RNEvent.rei**

```reason
module NativeLayoutEvent: {
  type t;
  type layout = {
    x: float,
    y: float,
    width: float,
    height: float
  };
  let layout: t => layout;
};
```

## onLoad

```reason
onLoad: unit => unit=?
```

## onLoadEnd

```reason
onLoadEnd: unit => unit=?
```

## onLoadStart

```reason
onLoadStart: unit => unit=?
```

## resizeMode

```reason
resizeMode: [<
  | `center
  | `contain
  | `cover
  | `repeat
  | `stretch
]=?
```

## source

```reason
source: imageSource=?
```

_reference:_

```reason
type imageSource =
  | URI(imageURISource)
  | Required(Packager.required)
  | Multiple(list(imageURISource));
```

```reason
let imageURISource:
  (
    ~uri: string,
    ~bundle: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    ~cache: [
      | `default
      | `reload
      | `forceCache
      | `onlyIfCached
    ]=?,
    ~scale: float=?,
    ~width: float=?,
    ~height: float=?,
    unit
  ) =>
  imageURISource;
```

## style

```reason
style: Style.t=?
```

## testID

```reason
testID: string=?
```

## resizeMethod

```reason
resizeMethod: [<
  | `auto
  | `resize
  | `scale
]=?
```

## accessibilityLabel

```reason
accessibilityLabel: string=?
```

## accessible

```reason
accessible: bool=?
```

## blurRadius

```reason
blurRadius: float=?
```

## capInsets

```reason
capInsets: Types.insets=?
```

_reference:_

**Types.rei**

```reason
type insets = {
  .
  "left": int,
  "right": int,
  "top": int,
  "bottom": int,
};
```

## defaultSource

```reason
defaultSource: defaultSource=?
```

_reference:_

```reason
type defaultSource =
  | URI(defaultURISource)
  | Required(Packager.required);
```

```reason
let defaultURISource:
  (~uri: string, ~scale: float=?, ~width: float=?, ~height: float=?, unit) => defaultURISource;
```

## onPartialLoad

```reason
onPartialLoad: unit => unit=?
```

## onProgress

```reason
onProgress: Event.progress => unit=?
```
