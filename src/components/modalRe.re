external modal : ReasonReact.reactClass = "Modal" [@@bs.module "react-native"];

let encodeAnimationType x =>
  switch x {
  | `none => "none"
  | `slide => "slide"
  | `fade => "fade"
  };

let encodeSupportedOrientations x =>
  switch x {
  | `portrait => "portrait"
  | `portraitUpsideDown => "portrait-upside-down"
  | `landscape => "landscape"
  | `landscapeLeft => "landscape-left"
  | `landscapeRight => "landscape-right"
  };

let make
    ::animationType=?
    ::onShow=?
    ::transparent=?
    ::visible=?
    ::hardwareAccelerated=?
    ::onRequestClose=?
    ::onOrientationChange=?
    ::supportedOrientations=? =>
  ReasonReact.wrapJsForReason
    reactClass::modal
    props::
      Js.Undefined.(
        {
          "animationType": from_opt (UtilsRN.option_map encodeAnimationType animationType),
          "onShow": from_opt onShow,
          "transparent": from_opt (UtilsRN.optBoolToOptJsBoolean transparent),
          "visible": from_opt (UtilsRN.optBoolToOptJsBoolean visible),
          "hardwareAccelerated": from_opt (UtilsRN.optBoolToOptJsBoolean hardwareAccelerated),
          "onRequestClose": from_opt onRequestClose,
          "onOrientationChange": from_opt onOrientationChange,
          "supportedOrientations":
            from_opt (UtilsRN.option_map encodeSupportedOrientations supportedOrientations)
        }
      );