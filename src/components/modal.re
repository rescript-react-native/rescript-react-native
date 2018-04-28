[@bs.module "react-native"] external modal : ReasonReact.reactClass = "Modal";

let encodeAnimationType = x =>
  switch (x) {
  | `none => "none"
  | `slide => "slide"
  | `fade => "fade"
  };

let encodeSupportedOrientations = xs =>
  Array.map(
    x =>
      switch (x) {
      | `portrait => "portrait"
      | `portraitUpsideDown => "portrait-upside-down"
      | `landscape => "landscape"
      | `landscapeLeft => "landscape-left"
      | `landscapeRight => "landscape-right"
      },
    xs,
  );

let make =
    (
      ~animationType=?,
      ~onShow=?,
      ~transparent=?,
      ~visible=?,
      ~hardwareAccelerated=?,
      ~onRequestClose=?,
      ~onOrientationChange=?,
      ~supportedOrientations=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props=
      Js.Undefined.(
        {
          "animationType":
            fromOption(
              UtilsRN.option_map(encodeAnimationType, animationType),
            ),
          "onShow": fromOption(onShow),
          "transparent":
            fromOption(UtilsRN.optBoolToOptJsBoolean(transparent)),
          "visible": fromOption(UtilsRN.optBoolToOptJsBoolean(visible)),
          "hardwareAccelerated":
            fromOption(UtilsRN.optBoolToOptJsBoolean(hardwareAccelerated)),
          "onRequestClose": fromOption(onRequestClose),
          "onOrientationChange": fromOption(onOrientationChange),
          "supportedOrientations":
            fromOption(
              UtilsRN.option_map(
                encodeSupportedOrientations,
                supportedOrientations,
              ),
            ),
        }
      ),
  );

