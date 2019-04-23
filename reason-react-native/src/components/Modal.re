type element;
type ref = React.Ref.t(Js.nullable(element));

module Orientation = {
  type t;

  external fromString: string => t = "%identity";

  let landscape = "landscape"->fromString;
  let landscapeLeft = "landscape-left"->fromString;
  let landscapeRight = "landscape-right"->fromString;
  let portrait = "portrait"->fromString;
  let portraitUpsideDown = "portrait-upside-down"->fromString;
};

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Modal props
    ~animationType: [@bs.string] [ | `none | `slide | `fade]=?,
    ~hardwareAccelerated: bool=?,
    ~onDismiss: unit => unit=?,
    ~onOrientationChange: unit => unit=?,
    ~onRequestClose: unit => unit=?,
    ~onShow: unit => unit=?,
    ~presentationStyle: [@bs.string] [
                          | `fullScreen
                          | `pageSheet
                          | `formSheet
                          | `overFullScreen
                        ]
                          =?,
    ~supportedOrientations: array(Orientation.t)=?,
    ~transparent: bool=?,
    ~visible: bool=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Modal";
