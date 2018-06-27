---
title: Image
---

## Example of use

`Image` component requires the `source` prop, here is the example usage. Note that you also need to specify the `width` and `height`, this can be done via `imageURISource` named arguments, or via `style` prop that is passed to `Image` component

### source from URI

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Image
      source=(
        URI(
          Image.(
            imageURISource(
              ~uri="https://bit.ly/2ya4e2o",
              ~width=320.,
              ~height=480.,
              (),
            )
          ),
        )
      )
    />,
};
```

### source from a file path

One thing to remember here is that the path is relative to the compiled code.

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <Image
      style=Style.(style([width(Pt(320.)), height(Pt(480.))]))
      source=(Required(Packager.require("./assets/panamera.png")))
    />,
};
```

## Props

### onError

```reason
onError: Event.error => unit=?
```

### onLayout

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

### onLoad

```reason
onLoad: unit => unit=?
```

### onLoadEnd

```reason
onLoadEnd: unit => unit=?
```

### onLoadStart

```reason
onLoadStart: unit => unit=?
```

### resizeMode

```reason
resizeMode: [<
  | `center
  | `contain
  | `cover
  | `repeat
  | `stretch
]=?
```

### source

```reason
source: imageSource
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

### style

```reason
style: Style.t=?
```

### testID

```reason
testID: string=?
```

### resizeMethod

```reason
resizeMethod: [<
  | `auto
  | `resize
  | `scale
]=?
```

### accessibilityLabel

```reason
accessibilityLabel: string=?
```

### accessible

```reason
accessible: bool=?
```

### blurRadius

```reason
blurRadius: float=?
```

### capInsets

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

### defaultSource

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

### onPartialLoad

```reason
onPartialLoad: unit => unit=?
```

### onProgress

```reason
onProgress: Event.progress => unit=?
```
