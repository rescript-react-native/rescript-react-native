type nativeElement

include NativeElement.Impl({type t = nativeElement})

type cache = [
  | #default
  | #reload
  | #"force-cache"
  | #"only-if-cached"
]

type imageURISource = {
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
  @unboxed
  type t =
    | Require(Packager.required)
    | URISource(imageURISource)
    | URISources(array<imageURISource>)
}

module ImageLoadEvent = {
  type payload = {
    source: {
      ...Layout.size,
      uri: string,
    },
  }

  include Event.SyntheticEvent({type _payload = payload})
}

type imageLoadEvent = ImageLoadEvent.t

module ErrorEvent = {
  type payload = {error: string}

  include Event.SyntheticEvent({type _payload = payload})
}

type errorEvent = ErrorEvent.t

module ProgressEvent = {
  type payload = {
    loaded: float,
    total: float,
  }

  include Event.SyntheticEvent({type _payload = payload})
}

type progressEvent = ProgressEvent.t

type resizeMethod = [#auto | #resize | #scale | #none]

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

type iosProps = {
  defaultSource?: Source.t,
  onPartialLoad?: unit => unit,
  onProgress?: progressEvent => unit,
}

type androidProps = {
  fadeDuration?: float,
  loadingIndicatorSource?: Source.t,
  progressiveRenderingEnabled?: bool,
  resizeMethod?: resizeMethod,
  resizeMultiplier?: float,
}

type imageProps = {
  ...View.viewPropsWithoutChildren,
  ...iosProps,
  ...androidProps,
  alt?: string,
  blurRadius?: float,
  capInsets?: Rect.t,
  crossOrigin?: crossOrigin,
  height?: float,
  onError?: errorEvent => unit,
  onLoad?: imageLoadEvent => unit,
  onLoadEnd?: unit => unit,
  onLoadStart?: unit => unit,
  referrerPolicy?: referrerPolicy,
  resizeMode?: Style.resizeMode,
  source: Source.t,
  srcSet?: string,
  tintColor?: Color.t,
  width?: float,
}

type props = {
  ref?: ref,
  ...imageProps,
}

@module("react-native")
external make: React.component<props> = "Image"

type imageSize = Layout.size

@module("react-native") @scope("Image")
external getSize: (~uri: string) => promise<imageSize> = "getSize"

@module("react-native") @scope("Image")
external getSizeWithHeaders: (~uri: string, ~header: dict<string>) => promise<imageSize> =
  "getSizeWithHeaders"

type requestId

@module("react-native") @scope("Image")
external prefetch: (~uri: string, ~callback: requestId => unit=?) => promise<bool> = "prefetch"

@module("react-native") @scope("Image")
external prefetchWithMetadata: (
  ~uri: string,
  ~queryRootName: string,
  ~rootTag: float=?,
  ~callback: requestId => unit=?,
) => promise<bool> = "prefetchWithMetadata"

@module("react-native") @scope("Image")
external abortPrefetch: requestId => unit = "abortPrefetch"

@module("react-native") @scope("Image")
external queryCache: (~uris: array<string>) => unit = "queryCache"

type asset = {
  ...Layout.size,
  uri: string,
}

@module("react-native") @scope("Image")
external resolveAssetSource: Source.t => asset = "resolveAssetSource"
