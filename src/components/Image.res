include NativeElement

type cache = [
  | #default
  | #reload
  | #"force-cache"
  | #"only-if-cached"
]

type uriSource = {
  uri: string,
  bundle?: string,
  method?: string,
  headers?: dict<string>,
  body?: string,
  cache?: cache,
  scale?: float,
  width?: float,
  height?: float,
}

module Source = {
  type t

  external fromRequired: Packager.required => t = "%identity"
  external fromUriSource: uriSource => t = "%identity"
  external fromUriSources: array<uriSource> => t = "%identity"
}

module ImageLoadEvent = {
  type source = {
    width: float,
    height: float,
    uri: string,
  }

  type payload = {
    uri: Js.Nullable.t<string>,
    source: source,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type imageLoadEvent = ImageLoadEvent.t

module ErrorEvent = {
  type payload = {error: string}

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type errorEvent = ErrorEvent.t

module ProgressEvent = {
  type payload = {
    loaded: float,
    total: float,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type progressEvent = ProgressEvent.t

type resizeMethod = [#auto | #resize | #scale]

type referrerPolicy = [
  | #"no-referrer"
  | #"no-referrer-when-downgrade"
  | #origin
  | #"origin-when-cross-origin"
  | #"same-origin"
  | #"strict-origin"
  | #"strict-origin-when-cross-origin"
  | #"unsafe-url"
]

type crossOrigin = [
  | #anonymous
  | #"use-credentials"
]

type imageProps = {
  accessibilityLabel?: string,
  accessible?: bool,
  alt?: string,
  blurRadius?: float,
  capInsets?: Rect.t,
  crossOrigin?: crossOrigin,
  defaultSource?: Source.t,
  fadeDuration?: float,
  height?: float,
  loadingIndicatorSource?: array<Source.t>,
  onError?: errorEvent => unit,
  onLayout?: Event.layoutEvent => unit,
  onLoad?: imageLoadEvent => unit,
  onLoadEnd?: unit => unit,
  onLoadStart?: unit => unit,
  onPartialLoad?: unit => unit,
  onProgress?: progressEvent => unit,
  progressiveRenderingEnabled?: bool,
  referrerPolicy?: referrerPolicy,
  resizeMethod?: resizeMethod,
  resizeMode?: Style.resizeMode,
  resizeMultiplier?: float,
  source: Source.t,
  srcSet?: string,
  style?: Style.t,
  testID?: string,
  tintColor?: Color.t,
  width?: float,
}

type props = {
  ref?: ref,
  ...imageProps,
}

@module("react-native")
external make: React.component<props> = "Image"

type sizeError

@module("react-native") @scope("Image")
external getSize: (
  ~uri: string,
  ~success: (~width: float, ~height: float) => unit,
  ~failure: sizeError => unit=?,
) => unit = "getSize"

type requestId

@module("react-native") @scope("Image")
external prefetch: (~uri: string) => requestId = "prefetch"

@module("react-native") @scope("Image")
external abortPrefetch: requestId => unit = "abortPrefetch"

@module("react-native") @scope("Image")
external queryCache: (~uris: array<string>) => unit = "queryCache"

type asset = {
  uri: string,
  width: float,
  height: float,
}

@module("react-native") @scope("Image")
external resolveAssetSource: Source.t => asset = "resolveAssetSource"
