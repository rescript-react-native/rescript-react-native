include NativeElement

type rippleConfig

@obj
external rippleConfig: (
  ~borderless: bool=?,
  ~color: Color.t=?,
  ~foreground: bool=?,
  ~radius: float=?,
  unit,
) => rippleConfig = ""

type interactionState = {
  pressed: bool,
  // React Native Web
  hovered: option<bool>,
  focused: option<bool>,
}

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // Accessibility props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityElementsHidden: bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityIgnoresInvertColors: bool=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLiveRegion: Accessibility.liveRegion=?,
  ~accessibilityRole: Accessibility.role=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessibilityValue: Accessibility.value=?,
  ~accessibilityViewIsModal: bool=?,
  ~accessible: bool=?,
  ~focusable: bool=?,
  ~importantForAccessibility: @string
  [
    | #auto
    | #yes
    | #no
    | @as("no-hide-descendants") #noHideDescendants
  ]=?,
  // Pressable props
  ~android_disableSound: bool=?,
  ~android_ripple: rippleConfig=?,
  ~children: interactionState => React.element=?,
  ~delayLongPress: int=?,
  ~disabled: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~onBlur: Event.blurEvent => unit=?,
  ~onFocus: Event.focusEvent => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLongPress: Event.pressEvent => unit=?,
  ~onPress: Event.pressEvent => unit=?,
  ~onPressIn: Event.pressEvent => unit=?,
  ~onPressOut: Event.pressEvent => unit=?,
  ~pressRetentionOffset: View.edgeInsets=?,
  ~style: interactionState => Style.t=?,
  ~testID: string=?,
  ~testOnly_pressed: bool=?,
  ~unstable_pressDelay: int=?,
  // react-native-web 0.16 Pressable (View) props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  // react-native-web 0.16 Pressable props
  ~onHoverIn: ReactEvent.Mouse.t => unit=?,
  ~onHoverOut: ReactEvent.Mouse.t => unit=?,
) => React.element = "Pressable"
