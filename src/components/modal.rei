let make:
  (
    ~animationType: [ | `fade | `none | `slide]=?,
    ~onShow: unit => unit=?,
    ~transparent: bool=?,
    ~visible: bool=?,
    ~hardwareAccelerated: bool=?,
    ~onRequestClose: unit => unit=?,
    ~onOrientationChange: unit => unit=?,
    ~supportedOrientations: array(
                              [
                                | `landscape
                                | `landscapeLeft
                                | `landscapeRight
                                | `portrait
                                | `portraitUpsideDown
                              ],
                            )
                              =?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);

