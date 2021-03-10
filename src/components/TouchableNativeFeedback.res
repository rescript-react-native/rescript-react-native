include NativeElement

module Background = {
  type t

  @bs.module("react-native") @bs.scope("TouchableNativeFeedback")
  external selectableBackground: unit => t = "SelectableBackground"

  @bs.module("react-native") @bs.scope("TouchableNativeFeedback")
  external selectableBackgroundBorderless: unit => t = "SelectableBackgroundBorderless"

  @bs.module("react-native") @bs.scope("TouchableNativeFeedback")
  external canUseNativeForeground: unit => bool = "canUseNativeForeground"

  @bs.module("react-native") @bs.scope("TouchableNativeFeedback")
  external ripple: (string, bool) => t = "Ripple"
}

@react.component @bs.module("react-native")
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
  ~importantForAccessibility: @bs.string
  [#auto | #yes | #no | @bs.as("no-hide-descendants") #noHideDescendants]=?,
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
  @bs.string
  [
    | #alternate
    | #author
    | @bs.as("dns-prefetch")
    #dnsPrefetch
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
