let createElement:
  animationType::[ | `fade | `none | `slide]? =>
  onShow::(unit => unit)? =>
  transparent::bool? =>
  visible::bool? =>
  hardwareAccelerated::bool? =>
  onRequestClose::(unit => unit)? =>
  onOrientationChange::(unit => unit)? =>
  supportedOrientations::
    [ | `landscape | `landscapeLeft | `landscapeRight | `portrait | `portraitUpsideDown]? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;