include NativeElement

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // TouchableHighlight props
  ~activeOpacity: float=?,
  ~hasTVPreferredFocus: bool=?,
  ~onHideUnderlay: unit => unit=?,
  ~onShowUnderlay: unit => unit=?,
  ~style: Style.t=?,
  ~tvParallaxProperties: TV.parallax=?,
  ~underlayColor: string=?,
  // TouchableWithoutFeedback props
  ~accessible: bool=?,
  ~accessibilityElementsHidden: bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityIgnoresInvertColors: bool=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLiveRegion: Accessibility.liveRegion=?,
  ~accessibilityRole: Accessibility.role=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessibilityValue: Accessibility.value=?,
  ~accessibilityViewIsModal: bool=?,
  ~delayLongPress: int=?,
  ~delayPressIn: int=?,
  ~delayPressOut: int=?,
  ~disabled: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~importantForAccessibility: @string
  [
    | #auto
    | #yes
    | #no
    | @as("no-hide-descendants") #noHideDescendants
  ]=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLongPress: Event.pressEvent => unit=?,
  ~onPress: Event.pressEvent => unit=?,
  ~onPressIn: Event.pressEvent => unit=?,
  ~onPressOut: Event.pressEvent => unit=?,
  ~pressRetentionOffset: View.edgeInsets=?,
  ~testID: string=?,
  ~touchSoundDisabled: bool=?,
  ~children: React.element=?,
  // react-native-web 0.16 Touchable (View) props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~onMouseOver: ReactEvent.Mouse.t => unit=?,
  ~onMouseOut: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
) => React.element = "TouchableHighlight"
