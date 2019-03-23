module Source = {
  type t;

  [@bs.obj]
  external fromUri:
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      ~cache: [@bs.string] [
                | `default
                | `reload
                | `forceCache
                | `onlyIfCached
              ]
                =?,
      ~scale: float=?,
      ~width: float=?,
      ~height: float=?,
      unit
    ) =>
    t =
    "";

  external fromRequired: Packager.required => t = "%identity";
  external fromArray: array(t) => t = "%identity";
};

module DefaultSource = {
  type t;

  [@bs.obj]
  external fromUri:
    (~uri: string, ~scale: float=?, ~width: float=?, ~height: float=?, unit) =>
    t =
    "";

  external fromRequired: Packager.required => t = "%identity";
};

type progress = {
  .
  "loaded": float,
  "total": float,
};

[@react.component] [@bs.module "react-native"]
external make:
  (
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
    ~source: Source.t,
    ~style: Style.t=?,
    ~testID: string=?,
    ~resizeMethod: [@bs.string] [ | `auto | `resize | `scale]=?,
    ~accessibilityLabel: React.element=?,
    ~accessible: bool=?,
    ~blurRadius: float=?,
    ~capInsets: Types.insets=?,
    ~defaultSource: DefaultSource.t=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: progress => unit=?
  ) =>
  React.element =
  "Image";
