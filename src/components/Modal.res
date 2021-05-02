include NativeElement

module Orientation = Modal_Orientation

type orientationChange = [#landscape | #portrait]

module OrientationChangeEvent = {
  type payload = {orientation: orientationChange}

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type orientationChangeEvent = OrientationChangeEvent.t

type animationType = [#none | #slide | #fade]

type presentationStyle = [
  | #fullScreen
  | #pageSheet
  | #formSheet
  | #overFullScreen
]

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // Modal props
  ~animationType: animationType=?,
  ~hardwareAccelerated: bool=?,
  ~onDismiss: unit => unit=?,
  ~onOrientationChange: orientationChangeEvent => unit=?,
  ~onRequestClose: unit => unit=?,
  ~onShow: unit => unit=?,
  ~presentationStyle: presentationStyle=?,
  ~statusBarTranslucent: bool=?,
  ~supportedOrientations: array<Orientation.t>=?,
  ~transparent: bool=?,
  ~visible: bool=?,
  ~children: React.element=?,
) => React.element = "Modal"
