include Image;

[@react.component] [@bs.module "react-native"] [@bs.scope "Animated"]
external make:
  (
    ~onLayout: Event.layoutEvent => unit=?,
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
    ~source: Source.t,
    ~style: Style.t=?,
    ~testID: string=?,
    ~resizeMethod: [@bs.string] [ | `auto | `resize | `scale]=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~blurRadius: float=?,
    ~capInsets: Types.insets=?,
    ~defaultSource: DefaultSource.t=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: progress => unit=?
  ) =>
  React.element =
  "Image";
