type nativeElement

include NativeElement.Impl({type t = nativeElement})

// @todo in 0.71.0
// after adding `aria-*` props, make sure `aria-checked` can be true, false or "mixed"

type importantForAccessibility = Accessibility.importantForAccessibility

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

// W3C pointer handlers (excludes onClick — covered by webClickProps).
type pointerEventProps = {
  onGotPointerCapture?: Event.pointerEvent => unit,
  onGotPointerCaptureCapture?: Event.pointerEvent => unit,
  onLostPointerCapture?: Event.pointerEvent => unit,
  onLostPointerCaptureCapture?: Event.pointerEvent => unit,
  onPointerCancel?: Event.pointerEvent => unit,
  onPointerCancelCapture?: Event.pointerEvent => unit,
  onPointerDown?: Event.pointerEvent => unit,
  onPointerDownCapture?: Event.pointerEvent => unit,
  onPointerEnter?: Event.pointerEvent => unit,
  onPointerEnterCapture?: Event.pointerEvent => unit,
  onPointerLeave?: Event.pointerEvent => unit,
  onPointerLeaveCapture?: Event.pointerEvent => unit,
  onPointerMove?: Event.pointerEvent => unit,
  onPointerMoveCapture?: Event.pointerEvent => unit,
  onPointerOut?: Event.pointerEvent => unit,
  onPointerOutCapture?: Event.pointerEvent => unit,
  onPointerOver?: Event.pointerEvent => unit,
  onPointerOverCapture?: Event.pointerEvent => unit,
  onPointerUp?: Event.pointerEvent => unit,
  onPointerUpCapture?: Event.pointerEvent => unit,
}

type accessibilityProps = Accessibility.viewProps


type iosProps = {shouldRasterizeIOS?: bool}

@unboxed
type tabIndex = | @as(0) Focusable | @as(-1) NotFocusable

type androidProps = {
  renderToHardwareTextureAndroid?: bool,
  focusable?: bool,
  tabIndex?: tabIndex,
}

type webLinkProps = {
  href?: string,
  hrefAttrs?: Web.hrefAttrs,
}

type webClickProps = {
  onClick?: ReactEvent.Mouse.t => unit,
  onClickCapture?: ReactEvent.Mouse.t => unit,
  onContextMenu?: ReactEvent.Mouse.t => unit,
}

type webFocusProps = {
  onFocus?: ReactEvent.Focus.t => unit,
  onBlur?: ReactEvent.Focus.t => unit,
}

type webKeyboardProps = {
  onKeyDown?: ReactEvent.Keyboard.t => unit,
  onKeyDownCapture?: ReactEvent.Keyboard.t => unit,
  onKeyUp?: ReactEvent.Keyboard.t => unit,
  onKeyUpCapture?: ReactEvent.Keyboard.t => unit,
}

type webMouseForwardedProps = {
  onMouseDown?: ReactEvent.Mouse.t => unit,
  onMouseEnter?: ReactEvent.Mouse.t => unit,
  onMouseLeave?: ReactEvent.Mouse.t => unit,
  onMouseMove?: ReactEvent.Mouse.t => unit,
  onMouseOut?: ReactEvent.Mouse.t => unit,
  onMouseOver?: ReactEvent.Mouse.t => unit,
  onMouseUp?: ReactEvent.Mouse.t => unit,
}

type webProps = {
  ...webLinkProps,
  ...webClickProps,
  ...webFocusProps,
  ...webKeyboardProps,
  ...webMouseForwardedProps,
}

type corePropsWithoutChildren = {
  hitSlop?: Rect.t,
  nativeID?: string,
  id?: string,
  needsOffscreenAlphaCompositing?: bool,
  onLayout?: Event.layoutEvent => unit,
  pointerEvents?: pointerEvents,
  removeClippedSubviews?: bool,
  collapsable?: bool,
  collapsableChildren?: bool,
  style?: Style.t,
  testID?: string,
}

type coreProps = {
  ...corePropsWithoutChildren,
  children?: React.element,
}

type viewPropsWithoutChildren = {
  ...gestureResponderHandlersProps,
  ...pointerEventProps,
  ...accessibilityProps,
  ...iosProps,
  ...androidProps,
  ...webProps,
  ...corePropsWithoutChildren,
}

type viewProps = {
  ...viewPropsWithoutChildren,
  children?: React.element,
}

type props = {
  ref?: ref,
  ...viewProps,
}

@module("react-native")
external make: React.component<props> = "View"
