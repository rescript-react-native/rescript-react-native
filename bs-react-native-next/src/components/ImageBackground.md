---
id: components/ImageBackground
title: ImageBackground
wip: true
---

```reason
type element;
type ref = React.Ref.t(Js.nullable(element));

type t;

[@bs.obj]
external style:
  (
    ~backfaceVisibility: [@bs.string] [ | `visible | `hidden ]=?,
    ~backgroundColor: Style.color=?,
    ~borderColor: Style.color=?,
    ~borderRadius: float=?,
    ~borderBottomLeftRadius: float=?,
    ~borderBottomRightRadius: float=?,
    ~borderTopLeftRadius: float=?,
    ~borderTopRightRadius: float=?,
    ~borderWidth: float=?,
    ~opacity: float=?,
    ~overflow: [@bs.string] [ | `visible | `hidden ]=?,
    ~resizeMode: [@bs.string] [ | `cover | `contain | `stretch | `repeat | `center ]=?,
    ~overlayColor: Style.color=?,
    ~tintColor: Style.color=?,
    unit
  ) =>
  t =
  "";

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~imageRef: ref=?,
    ~onLayout: Event.NativeLayoutEvent.t => unit=?,
    ~onLoad: unit => unit=?,
    ~onLoadEnd: unit => unit=?,
    ~onLoadStart: unit => unit=?,
    ~resizeMode: [@bs.string] [
                   | `center
                   | `contain
                   | `cover
                   | `repeat
                   | `stretch
                 ]
                   =?,
    ~source: Image.Source.t,
    ~style: Style.t=?,
    ~imageStyle: t=?,
    ~testID: string=?,
    ~resizeMethod: [@bs.string] [ | `auto | `resize | `scale]=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~blurRadius: float=?,
    ~capInsets: Types.insets=?,
    ~defaultSource: Image.DefaultSource.t=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: Image.progress => unit=?,
    ~fadeDuration: float=?,
    ~progressiveRenderingEnabled: bool=?,
    ~children: React.element=?
  ) =>
  React.element =
  "ImageBackground";
```
