include NativeElement;

module Orientation = Modal_Orientation;
module OrientationChange = Modal_OrientationChange;

module OrientationChangeEvent = {
  include Event.SyntheticEvent;

  type t = t_(payload)
  and payload = {orientation: OrientationChange.t};
};

type orientationChange = OrientationChangeEvent.t;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Modal props
    ~animationType: [@bs.string] [ | `none | `slide | `fade]=?,
    ~hardwareAccelerated: bool=?,
    ~onDismiss: unit => unit=?,
    ~onOrientationChange: OrientationChangeEvent.t => unit=?,
    ~onRequestClose: unit => unit=?,
    ~onShow: unit => unit=?,
    ~presentationStyle: [@bs.string] [
                          | `fullScreen
                          | `pageSheet
                          | `formSheet
                          | `overFullScreen
                        ]
                          =?,
    ~statusBarTranslucent: bool=?,
    ~supportedOrientations: array(Orientation.t)=?,
    ~transparent: bool=?,
    ~visible: bool=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Modal";
