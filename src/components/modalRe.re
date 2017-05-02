open Utils;

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
    {
      "animationType":
        from_opt (
          option_map
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
      "transparent": from_opt (option_map to_js_boolean transparent),
      "visible": from_opt (option_map to_js_boolean visible),
      "hardwareAccelerated": from_opt (option_map to_js_boolean hardwareAccelerated),
      "onRequestClose": from_opt onRequestClose,
      "onOrientationChange": from_opt onOrientationChange,
      "supportedOrientations":
        from_opt (
          option_map
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
    };