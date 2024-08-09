include NativeElement

// @todo in 0.71.0
// after adding `aria-*` props, make sure `aria-checked` can be true, false or "mixed"

@deprecated("Use `Rect.t` type instead")
type edgeInsets = Rect.t

@deprecated("Directly Use `Rect.t` record instead") @obj
external edgeInsets: (
  ~left: float=?,
  ~right: float=?,
  ~top: float=?,
  ~bottom: float=?,
  unit,
) => Rect.t = ""

type importantForAccessibility = [
  | #auto
  | #yes
  | #no
  | #"no-hide-descendants"
]

type pointerEvents = [
  | #auto
  | #none
  | #"box-none"
  | #"box-only"
]

type gestureResponderHandlersProps = {
  onMoveShouldSetResponder?: Event.pressEvent => bool,
  onMoveShouldSetResponderCapture?: Event.pressEvent => bool,
  onResponderEnd?: Event.pressEvent => unit,
  onResponderGrant?: Event.pressEvent => unit,
  onResponderMove?: Event.pressEvent => unit,
  onResponderReject?: Event.pressEvent => unit,
  onResponderRelease?: Event.pressEvent => unit,
  onResponderStart?: Event.pressEvent => unit,
  onResponderTerminate?: Event.pressEvent => unit,
  onResponderTerminationRequest?: Event.pressEvent => bool,
  onStartShouldSetResponder?: Event.pressEvent => bool,
  onStartShouldSetResponderCapture?: Event.pressEvent => bool,
}

type viewAccessibilityProps = {
  accessible?: bool,
  accessibilityActions?: array<Accessibility.actionInfo>,
  accessibilityElementsHidden?: bool,
  accessibilityHint?: string,
  accessibilityIgnoresInvertColors?: bool,
  accessibilityLabel?: string,
  accessibilityLabelledBy?: array<string>,
  accessibilityLanguage?: string,
  accessibilityLiveRegion?: Accessibility.liveRegion,
  accessibilityRole?: Accessibility.role,
  // `role` has precedence over the accessibilityRole prop
  role?: Role.t,
  accessibilityState?: Accessibility.state,
  accessibilityValue?: Accessibility.value,
  accessibilityViewIsModal?: bool,
  importantForAccessibility?: importantForAccessibility,
  onAccessibilityAction?: Accessibility.actionEvent => unit,
  onAccessibilityEscape?: unit => unit,
  onAccessibilityTap?: unit => unit,
  onMagicTap?: unit => unit,
}

type viewIOSProps = {shouldRasterizeIOS?: bool}

type viewAndroidProps = {collapsable?: bool, renderToHardwareTextureAndroid?: bool}

type viewWebLinkProps = {
  href?: string,
  hrefAttrs?: Web.hrefAttrs,
}

type viewWebClickProps = {
  onClick?: ReactEvent.Mouse.t => unit,
  onClickCapture?: ReactEvent.Mouse.t => unit,
  onContextMenu?: ReactEvent.Mouse.t => unit,
}

type viewWebFocusProps = {
  onFocus?: ReactEvent.Focus.t => unit,
  onBlur?: ReactEvent.Focus.t => unit,
}

type viewWebKeyboardProps = {
  onKeyDown?: ReactEvent.Keyboard.t => unit,
  onKeyDownCapture?: ReactEvent.Keyboard.t => unit,
  onKeyUp?: ReactEvent.Keyboard.t => unit,
  onKeyUpCapture?: ReactEvent.Keyboard.t => unit,
}

type viewWebMouseForwardedProps = {
  onMouseDown?: ReactEvent.Mouse.t => unit,
  onMouseEnter?: ReactEvent.Mouse.t => unit,
  onMouseLeave?: ReactEvent.Mouse.t => unit,
  onMouseMove?: ReactEvent.Mouse.t => unit,
  onMouseOut?: ReactEvent.Mouse.t => unit,
  onMouseOver?: ReactEvent.Mouse.t => unit,
  onMouseUp?: ReactEvent.Mouse.t => unit,
}

type viewWebProps = {
  ...viewWebLinkProps,
  ...viewWebClickProps,
  ...viewWebFocusProps,
  ...viewWebKeyboardProps,
  ...viewWebMouseForwardedProps,
}

type viewCoreProps = {
  hitSlop?: Rect.t,
  nativeID?: string,
  needsOffscreenAlphaCompositing?: bool,
  onLayout?: Event.layoutEvent => unit,
  pointerEvents?: pointerEvents,
  removeClippedSubviews?: bool,
  style?: Style.t,
  testID?: string,
  children?: React.element,
}

type viewProps = {
  ...gestureResponderHandlersProps,
  ...viewAccessibilityProps,
  ...viewIOSProps,
  ...viewAndroidProps,
  ...viewWebProps,
  ...viewCoreProps,
}

type viewPropsWithRef = {
  ref?: ref,
  ...viewProps,
}

@react.component(: viewPropsWithRef) @module("react-native")
external make: viewPropsWithRef => React.element = "View"
