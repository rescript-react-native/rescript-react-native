[@bs.module "react-native"] external modal: ReasonReact.reactClass = "Modal";

let encodeAnimationType =
  fun
  | `none => "none"
  | `slide => "slide"
  | `fade => "fade";

let encodeSupportedOrientations = xs =>
  xs->Belt.Array.map(
    fun
    | `portrait => "portrait"
    | `portraitUpsideDown => "portrait-upside-down"
    | `landscape => "landscape"
    | `landscapeLeft => "landscape-left"
    | `landscapeRight => "landscape-right",
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
    ~props={
      "animationType": animationType->Belt.Option.map(encodeAnimationType),
      "onShow": onShow,
      "transparent": transparent,
      "visible": visible,
      "hardwareAccelerated": hardwareAccelerated,
      "onRequestClose": onRequestClose,
      "onOrientationChange": onOrientationChange,
      "supportedOrientations":
        supportedOrientations->Belt.Option.map(encodeSupportedOrientations),
    },
  );
