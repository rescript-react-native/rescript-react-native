include NativeElement

type android_hyphenationFrequency = [
  | #normal
  | #none
  | #full
]
type dataDetectorType = [
  | #phoneNumber
  | #link
  | #address
  | #calendarEvent
  | #none
  | #all
]

type ellipsizeMode = [#clip | #head | #middle | #tail]

type textBreakStrategy = [#simple | #highQuality | #balanced]

type lineBreakStrategyIOS = [
  | #none
  | #standard
  | #"hangul-word"
  | #"push-out"
]

type textAccessibilityProps = {
  accessible?: bool,
  accessibilityActions?: array<Accessibility.actionInfo>,
  accessibilityHint?: string,
  accessibilityLabel?: string,
  accessibilityLanguage?: string,
  accessibilityRole?: Accessibility.role,
  // `role` has precedence over the accessibilityRole prop
  role?: Role.t,
  accessibilityState?: Accessibility.state,
  onAccessibilityAction?: Accessibility.actionEvent => unit,
}

type props = {
  ...textAccessibilityProps,
  ...View.gestureResponderHandlersProps,
  ...View.viewWebProps,
  // view props
  ref?: ref,
  nativeID?: string,
  onLayout?: Event.layoutEvent => unit,
  style?: Style.t,
  testID?: string,
  children?: React.element,
  // text props
  adjustsFontSizeToFit?: bool,
  allowFontScaling?: bool,
  android_hyphenationFrequency?: android_hyphenationFrequency,
  ariaLevel?: int,
  dataDetectorTypes?: array<dataDetectorType>,
  disabled?: bool,
  ellipsizeMode?: ellipsizeMode,
  lineBreakStrategyIOS?: lineBreakStrategyIOS,
  maxFontSizeMultiplier?: int,
  minimumFontScale?: float,
  numberOfLines?: int,
  onLongPress?: Event.pressEvent => unit,
  onPress?: Event.pressEvent => unit,
  onPressIn?: Event.pressEvent => unit,
  onPressOut?: Event.pressEvent => unit,
  onTextLayout?: Event.textLayoutEvent => unit,
  pressRetentionOffset?: Rect.t,
  selectable?: bool,
  selectionColor?: string,
  suppressHighlighting?: bool,
  textBreakStrategy?: textBreakStrategy,
  value?: string,
}

@module("react-native")
external make: React.component<props> = "Text"
