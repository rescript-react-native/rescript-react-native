type _imageURISource = ReactNative.Image.uriSource;
let _imageURISource:
  (
    ~uri: string,
    ~bundle: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    ~cache: [ | `default | `reload | `forceCache | `onlyIfCached]=?,
    ~scale: float=?,
    ~width: option(float)=?,
    ~height: option(float)=?,
    unit
  ) =>
  _imageURISource;

type imageURISource;
let imageURISource:
  (
    ~uri: string,
    ~bundle: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    ~cache: [ | `default | `reload | `forceCache | `onlyIfCached]=?,
    ~scale: float=?,
    ~width: Style.pt_only=?,
    ~height: Style.pt_only=?,
    unit
  ) =>
  _imageURISource;

type imageSource = [
  | `URI(_imageURISource)
  | `Required(Packager.required)
  | `Multiple(list(_imageURISource))
];
type _defaultURISource;
let _defaultURISource:
  (
    ~uri: string,
    ~scale: float=?,
    ~width: option(float)=?,
    ~height: option(float)=?,
    unit
  ) =>
  _defaultURISource;

type defaultURISource;
let defaultURISource:
  (
    ~uri: string,
    ~scale: float=?,
    ~width: Style.pt_only=?,
    ~height: Style.pt_only=?,
    unit
  ) =>
  _defaultURISource;

type defaultSource = [
  | `URI(_defaultURISource)
  | `Required(Packager.required)
];

module Event: {
  type error = ReactNative.Image.errorEvent;
  type progressT = ReactNative.Image.progressEvent;
  type progress = {
    loaded: float,
    total: float,
  };
  [@bs.get] external progress: progressT => progress = "nativeEvent";
};

let encodeSource: imageSource => ReactNative.Image.Source.t;
let encodeDefaultSource: defaultSource => ReactNative.Image.DefaultSource.t;

[@react.component]
let make:
  (
    ~onError: Event.error => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onLoad: unit => unit=?,
    ~onLoadEnd: unit => unit=?,
    ~onLoadStart: unit => unit=?,
    ~resizeMode: [ | `center | `contain | `cover | `repeat | `stretch]=?,
    ~source: imageSource,
    ~style: Style.t=?,
    ~testID: string=?,
    ~resizeMethod: [ | `auto | `resize | `scale]=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~blurRadius: float=?,
    ~capInsets: Types.insets=?,
    ~defaultSource: defaultSource=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: Event.progress => unit=?,
    unit
  ) =>
  React.element;

type asset = {
  .
  "uri": string,
  "width": int,
  "height": int,
};

type assetSource = [ | `URI(_imageURISource) | `Required(Packager.required)];

let resolveAssetSource: assetSource => asset;
