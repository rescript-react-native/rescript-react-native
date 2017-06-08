module type ImageComponent = {
  type imageURISource;
  let imageURISource:
    uri::string =>
    bundle::string? =>
    method::string? =>
    headers::Js.t 'a? =>
    body::string? =>
    cache::[ | `default | `reload | `forceCache | `onlyIfCached]? =>
    scale::float? =>
    width::float? =>
    height::float? =>
    unit =>
    imageURISource;
  type imageSource =
    | URI imageURISource
    | Required PackagerRe.required
    | Multiple (list imageURISource);
  type defaultURISource;
  let defaultURISource:
    uri::string => scale::float? => width::float? => height::float? => unit => defaultURISource;
  type defaultSource =
    | URI defaultURISource
    | Required PackagerRe.required;
  module Event: {type error; type progress = {loaded: float, total: float};};
  let make:
    onError::(Event.error => unit)? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onLoad::(unit => unit)? =>
    onLoadEnd::(unit => unit)? =>
    onLoadStart::(unit => unit)? =>
    resizeMode::[< | `center | `contain | `cover | `repeat | `stretch]? =>
    source::imageSource? =>
    style::StyleRe.t? =>
    testID::string? =>
    resizeMethod::[< | `auto | `resize | `scale]? =>
    accessibilityLabel::string? =>
    accessible::bool? =>
    blurRadius::float? =>
    capInsets::TypesRN.insets? =>
    defaultSource::defaultSource? =>
    onPartialLoad::(unit => unit)? =>
    onProgress::(Event.progress => unit)? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless;
};

module CreateComponent (Impl: ViewRe.Impl) :ImageComponent => {
  type imageURISource;
  external imageURISource :
    uri::string =>
    bundle::string? =>
    method::string? =>
    headers::Js.t 'a? =>
    body::string? =>
    /*
     * Be careful not to refmt this away !!!
     * https://github.com/facebook/reason/issues/821 (resolved, not released yet)
     */
    cache::[ | `default | `reload | `forceCache | `onlyIfCached] [@bs.string]? =>
    scale::float? =>
    width::float? =>
    height::float? =>
    unit =>
    imageURISource =
    "" [@@bs.obj];
  type imageSource =
    | URI imageURISource
    | Required PackagerRe.required
    | Multiple (list imageURISource);
  type defaultURISource;
  external defaultURISource :
    uri::string => scale::float? => width::float? => height::float? => unit => defaultURISource =
    "" [@@bs.obj];
  type defaultSource =
    | URI defaultURISource
    | Required PackagerRe.required;
  type rawImageSourceJS;
  external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";
  module Event = {
    type t;
    type error;
    type progress = {loaded: float, total: float};
    external progress : t => progress = "nativeEvent" [@@bs.get];
  };
  let make
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
    ReasonReact.wrapJsForReason
      reactClass::Impl.view
      props::
        Js.Undefined.(
          {
            "onLayout": from_opt onLayout,
            "onError": from_opt onError,
            "onLoad": from_opt onLoad,
            "onLoadEnd": from_opt onLoadEnd,
            "onLoadStart": from_opt onLoadStart,
            "resizeMode":
              from_opt (
                UtilsRN.option_map
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
                UtilsRN.option_map
                  (
                    fun (x: imageSource) =>
                      switch x {
                      | URI x => rawImageSourceJS x
                      | Required x => rawImageSourceJS x
                      | Multiple x => rawImageSourceJS (Array.of_list x)
                      }
                  )
                  source
              ),
            "style": from_opt style,
            "testID": from_opt testID,
            "resizeMethod":
              from_opt (
                UtilsRN.option_map
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
            "accessible": from_opt (UtilsRN.optBoolToOptJsBoolean accessible),
            "blurRadius": from_opt blurRadius,
            "capInsets": from_opt capInsets,
            "defaultSource":
              from_opt (
                UtilsRN.option_map
                  (
                    fun (x: defaultSource) =>
                      switch x {
                      | URI x => rawImageSourceJS x
                      | Required x => rawImageSourceJS x
                      }
                  )
                  defaultSource
              ),
            "onPartialLoad": from_opt onPartialLoad,
            "onProgress":
              from_opt (UtilsRN.option_map (fun x y => x (Event.progress y)) onProgress)
          }
        );
};

module Image =
  CreateComponent {
    external view : ReasonReact.reactClass = "Image" [@@bs.module "react-native"];
  };