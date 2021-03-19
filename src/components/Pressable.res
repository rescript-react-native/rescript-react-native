include NativeElement

type rippleConfig

@obj
external rippleConfig: (
  ~color: Color.t=?,
  ~borderless: bool=?,
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
  ~accessibilityActions: // Accessibility props
  array<Accessibility.actionInfo>=?,
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
  ~android_disableSound: // Pressable props
  bool=?,
  ~android_ripple: rippleConfig=?,
  ~children: interactionState => React.element=?,
  ~delayLongPress: int=?,
  ~disabled: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLongPress: Event.pressEvent => unit=?,
  ~onPress: Event.pressEvent => unit=?,
  ~onPressIn: Event.pressEvent => unit=?,
  ~onPressOut: Event.pressEvent => unit=?,
  ~pressRetentionOffset: View.edgeInsets=?,
  ~style: interactionState => Style.t=?,
  ~testID: string=?,
  ~testOnly_pressed: bool=?,
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
) => React.element = "Pressable"
