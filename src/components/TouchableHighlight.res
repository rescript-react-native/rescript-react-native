type nativeElement

include NativeElement.Impl({type t = nativeElement})

type props = {
  ref?: ref,
  ...TouchableWithoutFeedback.coreProps,
  activeOpacity?: float,
  @deprecated("Use `focusable` instead.") hasTVPreferredFocus?: bool,
  onHideUnderlay?: unit => unit,
  onShowUnderlay?: unit => unit,
  style?: Style.t,
  tvParallaxProperties?: TV.parallax,
  underlayColor?: Color.t,
}

@module("react-native")
external make: React.component<props> = "TouchableHighlight"
