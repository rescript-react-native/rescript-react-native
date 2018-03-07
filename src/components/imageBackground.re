open Image;

[@bs.module "react-native"]
external view : ReasonReact.reactClass = "ImageBackground";

module Event = {
  type t;
  type error;
  type progress = {
    loaded: float,
    total: float,
  };
  [@bs.get] external progress : t => progress = "nativeEvent";
};

type rawImageSourceJS;

external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";

let make =
    (
      ~onError=?,
      ~onLayout=?,
      ~onLoad=?,
      ~onLoadEnd=?,
      ~onLoadStart=?,
      ~resizeMode=?,
      ~source=?,
      ~style=?,
      ~imageStyle=?,
      ~testID=?,
      ~resizeMethod=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~blurRadius=?,
      ~capInsets=?,
      ~defaultSource=?,
      ~onPartialLoad=?,
      ~onProgress=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Js.Undefined.(
        {
          "onLayout": fromOption(onLayout),
          "onError": fromOption(onError),
          "onLoad": fromOption(onLoad),
          "onLoadEnd": fromOption(onLoadEnd),
          "onLoadStart": fromOption(onLoadStart),
          "resizeMode":
            fromOption(
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `cover => "cover"
                  | `contain => "contain"
                  | `stretch => "stretch"
                  | `repeat => "repeat"
                  | `center => "center"
                  },
                resizeMode,
              ),
            ),
          "source":
            fromOption(
              UtilsRN.option_map(
                (x: Image.imageSource) =>
                  switch (x) {
                  | URI(x) => rawImageSourceJS(x)
                  | Required(x) => rawImageSourceJS(x)
                  | Multiple(x) => rawImageSourceJS(Array.of_list(x))
                  },
                source,
              ),
            ),
          "style": fromOption(style),
          "imageStyle": fromOption(imageStyle),
          "testID": fromOption(testID),
          "resizeMethod":
            fromOption(
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `auto => "auto"
                  | `resize => "resize"
                  | `scale => "scale"
                  },
                resizeMethod,
              ),
            ),
          "accessibilityLabel": fromOption(accessibilityLabel),
          "accessible":
            fromOption(UtilsRN.optBoolToOptJsBoolean(accessible)),
          "blurRadius": fromOption(blurRadius),
          "capInsets": fromOption(capInsets),
          "defaultSource":
            fromOption(
              UtilsRN.option_map(
                (x: Image.defaultSource) =>
                  switch (x) {
                  | URI(x) => rawImageSourceJS(x)
                  | Required(x) => rawImageSourceJS(x)
                  },
                defaultSource,
              ),
            ),
          "onPartialLoad": fromOption(onPartialLoad),
          "onProgress":
            fromOption(
              UtilsRN.option_map(
                (x, y) => x(Event.progress(y)),
                onProgress,
              ),
            ),
        }
      ),
  );
