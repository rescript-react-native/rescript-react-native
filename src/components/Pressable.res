include NativeElement

type rippleConfig

@bs.obj
external rippleConfig: (
  ~color: Color.t=?,
  ~borderless: bool=?,
  ~radius: float=?,
  unit,
) => rippleConfig = ""

@deprecated(
  "Please use `Pressable_` instead of `Pressable` to benefit of the full benefit of Pressable component (eg: pressed state in style props and children function). In next major release (0.64), `Pressable_` will become `Pressable`."
)
@react.component
@bs.module("react-native")
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
  ~importantForAccessibility: @bs.string
  [#auto | #yes | #no | @bs.as("no-hide-descendants") #noHideDescendants]=?,
  ~children: // Pressable props
  React.element=?,
  ~delayLongPress: int=?,
  ~disabled: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~pressRetentionOffset: View.edgeInsets=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLongPress: Event.pressEvent => unit=?,
  ~onPress: Event.pressEvent => unit=?,
  ~onPressIn: Event.pressEvent => unit=?,
  ~onPressOut: Event.pressEvent => unit=?,
  ~style: Style.t=?,
  ~testID: string=?,
  ~android_disableSound: bool=?,
  ~android_ripple: rippleConfig=?,
  ~testOnly_pressed: bool=?,
) => React.element = "Pressable"
