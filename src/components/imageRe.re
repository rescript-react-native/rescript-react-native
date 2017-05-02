open Utils;

external image : ReactRe.reactClass = "Image" [@@bs.module "react-native"];

type imageURISource;

external imageURISource :
  uri::string =>
  bundle::string? =>
  method::string? =>
  headers::list (string, string)? =>
  body::string? =>
  cache::string? =>
  scale::float? =>
  width::float =>
  height::float =>
  unit =>
  imageURISource =
  "" [@@bs.obj];

type imageSource 'a =
  | URI imageURISource
  | Require 'a
  | Multiple (list imageURISource);

type defaultURISource;

external defaultURISource :
  uri::string => scale::float? => width::float => height::float => defaultURISource =
  "" [@@bs.obj];

type defaultSource 'a =
  | URI defaultURISource
  | Require 'a;

type rawImageSourceJS;

external rawImageSourceJS : 'a => rawImageSourceJS = "";

module Event = {
  type t;
  type error;
  type _progress = Js.t {. loaded : float, total : float};
  external _progress : t => _progress = "nativeEvent" [@@bs.get];
  type progress = {loaded: float, total: float};
  let progress (x: _progress) => {loaded: x##loaded, total: x##total};
};

let createElement
    ::onError=?
    ::onLayout=?
    ::onLoad=?
    ::onLoadEnd=?
    ::onLoadStart=?
    ::resizeMode=?
    ::source=?
    ::style=?
    ::testID=?
    ::resizeMethod=?
    ::accessibilityLabel=?
    ::accessible=?
    ::blurRadius=?
    ::capInsets=?
    ::defaultSource=?
    ::onPartialLoad=?
    ::onProgress=? =>
  ReactRe.wrapPropsShamelessly
    image
    {
      "onLayout": from_opt onLayout,
      "onError": from_opt onError,
      "onLoad": from_opt onLoad,
      "onLoadEnd": from_opt onLoadEnd,
      "onLoadStart": from_opt onLoadStart,
      "resizeMode":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `cover => "cover"
                | `contain => "contain"
                | `stretch => "stretch"
                | `repeat => "repeat"
                | `center => "center"
                }
            )
            resizeMode
        ),
      "source":
        from_opt (
          option_map
            (
              fun (x: imageSource 'a) =>
                switch x {
                | URI x => rawImageSourceJS x
                | Require x => rawImageSourceJS x
                | Multiple x => rawImageSourceJS (Array.of_list x)
                }
            )
            source
        ),
      "style": from_opt style,
      "testID": from_opt testID,
      "resizeMethod":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `auto => "auto"
                | `resize => "resize"
                | `scale => "scale"
                }
            )
            resizeMethod
        ),
      "accessibilityLabel": from_opt accessibilityLabel,
      "accessible": from_opt (option_map to_js_boolean accessible),
      "blurRadius": from_opt blurRadius,
      "capInsets": from_opt capInsets,
      "defaultSource":
        from_opt (
          option_map
            (
              fun (x: defaultSource 'a) =>
                switch x {
                | URI x => rawImageSourceJS x
                | Require x => rawImageSourceJS x
                }
            )
            defaultSource
        ),
      "onPartialLoad": from_opt onPartialLoad,
      "onProgress": from_opt (option_map (fun x y => x (Event.progress y)) onProgress)
    };
