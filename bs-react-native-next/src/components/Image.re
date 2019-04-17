type uriSource;

[@bs.obj]
external uriSource:
  (
    ~uri: string,
    ~bundle: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    ~cache: [@bs.string] [
              | `default
              | `reload
              | [@bs.as "force-cache"] `forceCache
              | [@bs.as "only-if-cached"] `onlyIfCached
            ]
              =?,
    ~scale: float=?,
    ~width: float=?,
    ~height: float=?,
    unit
  ) =>
  uriSource =
  "";

module Source = {
  type t;

  external fromRequired: Packager.required => t = "%identity";
  external fromUriSource: uriSource => t = "%identity";
  external fromUriSources: array(uriSource) => t = "%identity";
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

type error;

[@bs.module "react-native"] [@bs.scope "Image"]
external getSize:
  (
    ~uri: string,
    ~success: (~width: float, ~height: float) => unit,
    ~failure: error => unit=?,
    unit
  ) =>
  unit =
  "getSize";

type requestId;

[@bs.module "react-native"] [@bs.scope "Image"]
external prefetch: (~uri: string) => requestId = "prefetch";

[@bs.module "react-native"] [@bs.scope "Image"]
external abortPrefetch: requestId => unit = "abortPrefetch";

[@bs.module "react-native"] [@bs.scope "Image"]
external queryCache: (~uris: array(string)) => unit = "queryCache";

type asset = {
  .
  "uri": string,
  "width": float,
  "height": float,
};

[@bs.module "react-native"] [@bs.scope "Image"]
external resolveAssetSource: Source.t => asset = "resolveAssetSource";
