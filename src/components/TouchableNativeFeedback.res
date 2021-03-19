include NativeElement

module Background = {
  type t

  @module("react-native") @scope("TouchableNativeFeedback")
  external selectableBackground: unit => t = "SelectableBackground"

  @module("react-native") @scope("TouchableNativeFeedback")
  external selectableBackgroundBorderless: unit => t = "SelectableBackgroundBorderless"

  @module("react-native") @scope("TouchableNativeFeedback")
  external canUseNativeForeground: unit => bool = "canUseNativeForeground"

  @module("react-native") @scope("TouchableNativeFeedback")
  external ripple: (string, bool) => t = "Ripple"
}

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  ~background: // TouchableNativeFeedback props
  Background.t=?,
  ~useForeground: bool=?,
  ~accessible: // TouchableWithoutFeedback props
  bool=?,
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
  ~rel: // React Native Web Props
  @string
  [
    | #alternate
    | #author
    | @as("dns-prefetch") #dnsPrefetch
    | #icon
    | #license
    | #next
    | #pingback
    | #preconnect
    | #prefetch
    | #preload
    | #prerender
    | #prev
    | #search
    | #stylesheet
  ]=?,
  ~href: string=?,
  ~target: Web.target=?,
) => React.element = "TouchableNativeFeedback"
