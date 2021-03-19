include NativeElement

type uriSource

@obj
external uriSource: (
  ~uri: string,
  ~bundle: string=?,
  ~method: string=?,
  ~headers: Js.Dict.t<string>=?,
  ~body: string=?,
  ~cache: @string
  [
    | #default
    | #reload
    | @as("force-cache") #forceCache
    | @as("only-if-cached") #onlyIfCached
  ]=?,
  ~scale: float=?,
  ~width: float=?,
  ~height: float=?,
  unit,
) => uriSource = ""

module Source = {
  type t

  external fromRequired: Packager.required => t = "%identity"
  external fromUriSource: uriSource => t = "%identity"
  external fromUriSources: array<uriSource> => t = "%identity"
}

module DefaultSource = {
  type t

  @obj
  external fromUri: (~uri: string, ~scale: float=?, ~width: float=?, ~height: float=?, unit) => t =
    ""

  external fromRequired: Packager.required => t = "%identity"
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

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  ~accessibilityLabel: // Image props
  string=?,
  ~accessible: bool=?,
  ~blurRadius: float=?,
  ~capInsets: View.edgeInsets=?,
  ~defaultSource: DefaultSource.t=?,
  ~fadeDuration: float=?,
  ~loadingIndicatorSource: array<Source.t>=?,
  ~onError: errorEvent => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLoad: imageLoadEvent => unit=?,
  ~onLoadEnd: unit => unit=?,
  ~onLoadStart: unit => unit=?,
  ~onPartialLoad: unit => unit=?,
  ~onProgress: progressEvent => unit=?,
  ~progressiveRenderingEnabled: bool=?,
  ~resizeMethod: resizeMethod=?,
  ~resizeMode: Style.resizeMode=?,
  ~source: Source.t,
  ~style: Style.t=?,
  ~testID: string=?,
) => React.element = "Image"

type sizeError

@module("react-native") @scope("Image")
external getSize: (
  ~uri: string,
  ~success: (~width: float, ~height: float) => unit,
  ~failure: sizeError => unit=?,
  unit,
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
