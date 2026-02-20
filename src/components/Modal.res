include NativeElement

type orientation = [
  | #landscape
  | #"landscape-left"
  | #"landscape-right"
  | #portrait
  | #"portrait-upside-down"
]

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

type props = {
  ref?: ref,
  animationType?: animationType,
  backdropColor?: Color.t,
  hardwareAccelerated?: bool,
  navigationBarTranslucent?: bool,
  onDismiss?: unit => unit,
  onOrientationChange?: orientationChangeEvent => unit,
  onRequestClose?: unit => unit,
  onShow?: unit => unit,
  presentationStyle?: presentationStyle,
  statusBarTranslucent?: bool,
  supportedOrientations?: array<orientation>,
  transparent?: bool,
  visible?: bool,
  children?: React.element,
}

@module("react-native")
external make: React.component<props> = "Modal"
