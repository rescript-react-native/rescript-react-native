type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asTextElement: DOMAPI.anyElement => element = "%identity"

type android_hyphenationFrequency = [
  | #normal
  | #none
  | #full
]
type dataDetectorType = [
  | #phoneNumber
  | #link
  | #email
  | #none
  | #all
]

type ellipsizeMode = [#clip | #head | #middle | #tail]

type dynamicTypeRamp = [
  | #caption2
  | #caption1
  | #footnote
  | #subheadline
  | #callout
  | #body
  | #headline
  | #title3
  | #title2
  | #title1
  | #largeTitle
]

type textBreakStrategy = [#simple | #highQuality | #balanced]

type lineBreakStrategyIOS = [
  | #none
  | #standard
  | #"hangul-word"
  | #"push-out"
]

type accessibilityProps = {
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
  ref?: ref,
  ...accessibilityProps,
  ...View.gestureResponderHandlersProps,
  ...View.webProps,
  // view props
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
  dataDetectorType?: dataDetectorType,
  disabled?: bool,
  dynamicTypeRamp?: dynamicTypeRamp,
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
