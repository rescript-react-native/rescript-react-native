type point = {x: float, y: float};

let scrollTo: ReactRe.reactRef => x::int => y::int => animated::bool => unit;

let scrollToEnd: ReactRe.reactRef => animated::bool => unit;

let createElement:
  accessibleLeft::ReactRe.reactElement? =>
  accessible::bool? =>
  hitSlop::Js.t {. left : int, right : int, top : int, bottom : int}? =>
  onAccessibilityTap::(unit => unit)? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onMagicTap::(unit => unit)? =>
  onMoveShouldSetResponder::(RNEvent.NativeEvent.t => bool)? =>
  onMoveShouldSetResponderCapture::(RNEvent.NativeEvent.t => bool)? =>
  onResponderGrant::(RNEvent.NativeEvent.t => unit)? =>
  onResponderMove::(RNEvent.NativeEvent.t => unit)? =>
  onResponderReject::(RNEvent.NativeEvent.t => unit)? =>
  onResponderRelease::(RNEvent.NativeEvent.t => unit)? =>
  onResponderTerminate::(RNEvent.NativeEvent.t => unit)? =>
  onResponderTerminationRequest::(RNEvent.NativeEvent.t => unit)? =>
  onStartShouldSetResponder::(RNEvent.NativeEvent.t => bool)? =>
  onStartShouldSetResponderCapture::(RNEvent.NativeEvent.t => bool)? =>
  pointerEvents::[ | `auto | `none | `boxNone | `boxOnly]? =>
  removeClippedSubviews::bool? =>
  style::Style.t? =>
  testID::string? =>
  accessibilityComponentType::[ | `none | `button | `radiobutton_checked | `radiobutton_unchecked]? =>
  accessibilityLiveRegion::[ | `none | `polite | `assertive]? =>
  collapsable::bool? =>
  importantForAccessibility::[ | `auto | `yes | `no | `noHideDescendants]? =>
  needsOffscreenAlphaCompositing::bool? =>
  renderToHardwareTextureAndroid::bool? =>
  accessibilityTraits::
    list [
      | `none
      | `button
      | `link
      | `header
      | `search
      | `image
      | `selected
      | `plays
      | `key
      | `text
      | `summary
      | `disabled
      | `frequentUpdates
      | `startsMedia
      | `adjustable
      | `allowsDirectInteraction
      | `pageTurn
    ]? =>
  accessibilityViewIsModal::bool? =>
  shouldRasterizeIOS::bool? =>
  contentContainerStyle::Style.t? =>
  horizontal::bool? =>
  keyboardDismissMode::[ | `none | `interactive | `onDrag]? =>
  keyboardShouldPersistTaps::[ | `always | `never | `handled]? =>
  onContentSizeChange::((float, float) => unit)? =>
  onScroll::(unit => unit)? =>
  pagingEnabled::bool? =>
  refreshControl::ReactRe.reactElement? =>
  scrollEnabled::bool? =>
  showsHorizontalScrollIndicator::bool? =>
  showsVerticalScrollIndicator::bool? =>
  stickyHeaderIndices::list int? =>
  overScrollMode::[ | `always | `never | `auto]? =>
  scrollPerfTag::string? =>
  alwaysBounceHorizontal::bool? =>
  alwaysBounceVertical::bool? =>
  automaticallyAdjustContentInsets::bool? =>
  bounces::bool? =>
  canCancelContentTouches::bool? =>
  centerContent::bool? =>
  contentInset::Js.t {. left : int, right : int, top : int, bottom : int}? =>
  contentOffset::point? =>
  decelerationRate::[ | `fast | `normal]? =>
  directionalLockEnabled::bool? =>
  indicatorStyle::[ | `default | `black | `white]? =>
  maximumZoomScale::float? =>
  mimimumZoomScale::float? =>
  onScrollAnimationEnd::(unit => unit)? =>
  scrollEventThrottle::int? =>
  scrollIndicatorInsets::Js.t {. left : int, right : int, top : int, bottom : int}? =>
  scrollsToTop::bool? =>
  snapToAlignment::[ | `center | `start | `end_]? =>
  zoomScale::float? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;