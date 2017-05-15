external modal : ReactRe.reactClass = "Modal" [@@bs.module "react-native"];
let createElement
    ::animationType=?
    ::onShow=?
    ::transparent=?
    ::visible=?
    ::hardwareAccelerated=?
    ::onRequestClose=?
    ::onOrientationChange=?
    ::supportedOrientations=? =>
  ReactRe.wrapPropsShamelessly
    modal
    Js.Undefined.({
      "animationType":
        from_opt (
          UtilsRN.option_map
            (
              fun x =>
                switch x {
                | `none => "none"
                | `slide => "slide"
                | `fade => "fade"
                }
            )
            animationType
        ),
      "onShow": from_opt onShow,
      "transparent": from_opt (UtilsRN.optBoolToOptJsBoolean transparent),
      "visible": from_opt (UtilsRN.optBoolToOptJsBoolean visible),
      "hardwareAccelerated": from_opt (UtilsRN.optBoolToOptJsBoolean hardwareAccelerated),
      "onRequestClose": from_opt onRequestClose,
      "onOrientationChange": from_opt onOrientationChange,
      "supportedOrientations":
        from_opt (
          UtilsRN.option_map
            (
              fun x =>
                switch x {
                | `portrait => "portrait"
                | `portraitUpsideDown => "portrait-upside-down"
                | `landscape => "landscape"
                | `landscapeLeft => "landscape-left"
                | `landscapeRight => "landscape-right"
                }
            )
            supportedOrientations
        )
    });