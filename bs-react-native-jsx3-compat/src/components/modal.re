type supportedOrientation = [
  | `landscape
  | `landscapeLeft
  | `landscapeRight
  | `portrait
  | `portraitUpsideDown
];

let encodeSuppoOr: supportedOrientation => ReactNative.Modal.Orientation.t =
  fun
  | `landscape => ReactNative.Modal.Orientation.landscape
  | `landscapeLeft => ReactNative.Modal.Orientation.landscapeLeft
  | `landscapeRight => ReactNative.Modal.Orientation.landscapeRight
  | `portrait => ReactNative.Modal.Orientation.portrait
  | `portraitUpsideDown => ReactNative.Modal.Orientation.portraitUpsideDown;

[@react.component]
let make =
    (
      ~animationType: option([ | `none | `slide | `fade])=?,
      ~onShow: option(unit => unit)=?,
      ~transparent: option(bool)=?,
      ~visible: option(bool)=?,
      ~hardwareAccelerated: option(bool)=?,
      ~onRequestClose: option(unit => unit)=?,
      ~onOrientationChange: option(unit => unit)=?,
      ~supportedOrientations: option(array(supportedOrientation))=?,
      ~children: option(React.element)=?,
      _,
    ) => {
  let so =
    supportedOrientations->Belt.Option.map(a =>
      a->Belt.Array.map(encodeSuppoOr)
    );
  <ReactNative.Modal
    ?animationType
    ?onShow
    ?transparent
    ?visible
    ?hardwareAccelerated
    ?onRequestClose
    onOrientationChange=?{
      onOrientationChange->Belt.Option.map((onOrientationChange, _) =>
        onOrientationChange()
      )
    }
    supportedOrientations=?so>
    {children->Belt.Option.getWithDefault(React.null)}
  </ReactNative.Modal>;
};
