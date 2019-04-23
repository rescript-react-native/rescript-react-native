let encode_pt_only: Style.pt_only => float =
  value =>
    switch (value) {
    | Style.Pt(value) => value
    };

type _imageURISource = ReactNative.Image.uriSource;
[@bs.obj]
external _imageURISource:
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
    ~width: option(float)=?,
    ~height: option(float)=?,
    unit
  ) =>
  _imageURISource =
  "";

type imageURISource = ReactNative.Image.Source.t;
let imageURISource =
    (
      ~uri,
      ~bundle=?,
      ~method=?,
      ~headers=?,
      ~body=?,
      ~cache=?,
      ~scale=?,
      ~width=?,
      ~height=?,
      unit,
    ) =>
  _imageURISource(
    ~uri,
    ~bundle?,
    ~method?,
    ~headers?,
    ~body?,
    ~cache?,
    ~scale?,
    ~width=width->Belt.Option.map(encode_pt_only),
    ~height=height->Belt.Option.map(encode_pt_only),
    unit,
  );

type imageSource = [
  | `URI(_imageURISource)
  | `Required(Packager.required)
  | `Multiple(list(_imageURISource))
];

type _defaultURISource = ReactNative.Image.DefaultSource.t;
[@bs.obj]
external _defaultURISource:
  (
    ~uri: string,
    ~scale: float=?,
    ~width: option(float)=?,
    ~height: option(float)=?,
    unit
  ) =>
  _defaultURISource =
  "";

type defaultURISource;
let defaultURISource = (~uri, ~scale=?, ~width=?, ~height=?, unit) =>
  _defaultURISource(
    ~uri,
    ~scale?,
    ~width=width->Belt.Option.map(encode_pt_only),
    ~height=height->Belt.Option.map(encode_pt_only),
    unit,
  );

type defaultSource = [
  | `URI(_defaultURISource)
  | `Required(Packager.required)
];

module Event = {
  type error = ReactNative.Image.errorEvent;
  type progressT = ReactNative.Image.progressEvent;
  type progress = {
    loaded: float,
    total: float,
  };
  [@bs.get] external progress: progressT => progress = "nativeEvent";
};

let encodeSource = (x: imageSource) =>
  switch (x) {
  | `URI(x) => ReactNative.Image.Source.fromUriSource(x)
  | `Required(x) => ReactNative.Image.Source.fromRequired(x)
  | `Multiple(x) => ReactNative.Image.Source.fromUriSources(Array.of_list(x))
  };

let encodeDefaultSource = (x: defaultSource) =>
  switch (x) {
  | `URI(x) => x
  | `Required(x) => ReactNative.Image.DefaultSource.fromRequired(x)
  };

[@react.component]
let make =
    (
      ~onError=?,
      ~onLayout=?,
      ~onLoad=?,
      ~onLoadEnd=?,
      ~onLoadStart=?,
      ~resizeMode=?,
      ~source,
      ~style=?,
      ~testID=?,
      ~resizeMethod=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~blurRadius=?,
      ~capInsets=?,
      ~defaultSource=?,
      ~onPartialLoad=?,
      ~onProgress=?,
      _,
    ) =>
  <ReactNative.Image
    ?onError
    ?onLayout
    onLoad=?{onLoad->Belt.Option.map((cb, _) => cb())}
    ?onLoadEnd
    ?onLoadStart
    ?resizeMode
    source={encodeSource(source)}
    ?style
    ?testID
    ?resizeMethod
    ?accessibilityLabel
    ?accessible
    ?blurRadius
    ?capInsets
    defaultSource=?{defaultSource->Belt.Option.map(encodeDefaultSource)}
    ?onPartialLoad
    onProgress=?{
      onProgress->Belt.Option.map((cb, e) => cb(Event.progress(e)))
    }
  />;

type asset = {
  .
  "uri": string,
  "width": int,
  "height": int,
};

type assetSource = [ | `URI(_imageURISource) | `Required(Packager.required)];

[@bs.scope "Image"] [@bs.module "react-native"]
external resolveAssetSource: assetSource => asset = "";
