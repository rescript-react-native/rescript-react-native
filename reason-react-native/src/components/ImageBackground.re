include NativeElement;

type imageStyle;

[@bs.obj]
external imageStyle:
  (
    ~backfaceVisibility: [@bs.string] [ | `visible | `hidden]=?,
    ~backgroundColor: Color.t=?,
    ~borderColor: Color.t=?,
    ~borderRadius: float=?,
    ~borderBottomLeftRadius: float=?,
    ~borderBottomRightRadius: float=?,
    ~borderTopLeftRadius: float=?,
    ~borderTopRightRadius: float=?,
    ~borderWidth: float=?,
    ~opacity: float=?,
    ~overflow: [@bs.string] [ | `visible | `hidden]=?,
    ~resizeMode: [@bs.string] [
                   | `cover
                   | `contain
                   | `stretch
                   | `repeat
                   | `center
                 ]
                   =?,
    ~overlayColor: Color.t=?,
    ~tintColor: Color.t=?,
    unit
  ) =>
  imageStyle =
  "";

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // ImageBackground props
    ~imageRef: Image.ref=?,
    ~imageStyle: imageStyle=?,
    // Image props
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~blurRadius: float=?,
    ~capInsets: Types.edgeInsets=?,
    ~defaultSource: Image.DefaultSource.t=?,
    ~fadeDuration: float=?,
    ~loadingIndicatorSource: array(Image.Source.t)=?,
    ~onError: Image.errorEvent => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onLoad: unit => unit=?,
    ~onLoadEnd: unit => unit=?,
    ~onLoadStart: unit => unit=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: Image.progressEvent => unit=?,
    ~progressiveRenderingEnabled: bool=?,
    ~resizeMethod: [@bs.string] [ | `auto | `resize | `scale]=?,
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
    ~testID: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "ImageBackground";
