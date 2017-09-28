open ImageRe;

external view : ReasonReact.reactClass = "ImageBackground" [@@bs.module "react-native"];

module Event = {
  type t;
  type error;
  type progress = {
    loaded: float,
    total: float
  };
  external progress : t => progress = "nativeEvent" [@@bs.get];
};

type rawImageSourceJS;

external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";

let make
    ::onError=?
    ::onLayout=?
    ::onLoad=?
    ::onLoadEnd=?
    ::onLoadStart=?
    ::resizeMode=?
    ::source=?
    ::style=?
    ::imageStyle=?
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
    reactClass::view
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
                  fun (x: Image.imageSource) =>
                    switch x {
                    | URI x => rawImageSourceJS x
                    | Required x => rawImageSourceJS x
                    | Multiple x => rawImageSourceJS (Array.of_list x)
                    }
                )
                source
            ),
          "style": from_opt style,
          "imageStyle": from_opt imageStyle,
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
                  fun (x: Image.defaultSource) =>
                    switch x {
                    | URI x => rawImageSourceJS x
                    | Required x => rawImageSourceJS x
                    }
                )
                defaultSource
            ),
          "onPartialLoad": from_opt onPartialLoad,
          "onProgress": from_opt (UtilsRN.option_map (fun x y => x (Event.progress y)) onProgress)
        }
      );
