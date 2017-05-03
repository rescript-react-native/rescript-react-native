module Animation: {
  type t;
  type endResult = Js.t {. finished : Js.boolean};
  type endCallback = endResult => unit;
};

module CompositeAnimation: {
  type t;
  let stop : t => unit;
  let start : t => unit;
};

module Interpolation: {
  type t;
  type outputRange;
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let extrapolateString: extrapolate => string;
  type config;
  let createConfig:
    inputRange::list float =>
    outputRange::[< | `float (list float) | `string (list string)] =>
    easing::(float => float)? =>
    extrapolate::extrapolate? =>
    extrapolateLeft::extrapolate? =>
    extrapolateRight::extrapolate? =>
    unit =>
    config;
  let interpolate : t => config => t ;
};

module Value: {
  type t;
  type callback = float => unit;
  let create : float => t;
  let setValue : t => float => unit;
  let setOffset : t => float => unit;
  let flattenOffset : t => unit;
  let extractOffset : t => unit;
  let addListener : t => callback => string;
  let removeListener : t => string => unit;
  let removeAllListeners : t => unit;
  let resetAnimation : t => option callback => unit;
  let stopAnimation : t => option callback => unit;
  let interpolate : t => Interpolation.config => Interpolation.t;
  let animate : t => Animation.t => Animation.endCallback => unit;
  let stopTracking : t => unit;
  let track : t => unit;
  let modulo : t => float => t;
  let diffClamp : t => float => float => t;
  type value = t;
  let add : value => value => value;
  let divide : value => value => value;
  let multiply : value => value => value;
  module Timing: {
    type toValue;
    type config;
    let config:
      easing::(float => float)? =>
      duration::float? =>
      delay::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      toValue::toValue =>
      config;
    let toValueFloat : float => toValue;
    let toValueAnimated : value => toValue;
    let timing: value::value => config::config => CompositeAnimation.t;
  };
  module Spring: {
    type toValue;
    type config;
    let config:
      restDisplacementThreshold::float? =>
      overshootClamping::Js.boolean? =>
      restSpeedThreshold::float? =>
      velocity::float? =>
      bounciness::float? =>
      speed::float? =>
      tension::float? =>
      friction::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      toValue::toValue =>
      config;
    let toValueFloat : float => toValue;
    let toValueAnimated : value => toValue;
    let spring: value::value => config::config => CompositeAnimation.t;
  };
  module Decay: {
    type config;
    let config:
      deceleration::'a? =>
      isInteraction::bool? =>
      useNativeDriver::bool? =>
      onComplete::'b? =>
      iterations::'c? =>
      velocity::'d =>
      Js.t {
        .
        deceleration : Js.Undefined.t 'a,
        isInteraction : Js.Undefined.t Js.boolean,
        iterations : Js.Undefined.t 'c,
        onComplete : Js.Undefined.t 'b,
        useNativeDriver : Js.Undefined.t Js.boolean,
        velocity : 'd
      };
    let decay: value::value => config::config => CompositeAnimation.t;
  };
};

module ValueXY: {
  type t;
  type jsValue = Js.t {. x : float, y : float};
  type callback = jsValue => unit;
  type translateTransform = Js.t {. translateX : Value.t, translateY : Value.t};
  type layout = Js.t {. left : Value.t, top : Value.t};
  let create: x::float => y::float => t;
  let setValue: t => x::float => y::float => unit;
  let setOffset: t => x::float => y::float => unit;
  let flattenOffset : t => unit;
  let extractOffset : t => unit;
  let resetAnimation : t => option callback => unit;
  let stopAnimation : t => option callback => unit;
  let addListener : t => callback => string;
  let removeListener : t => string => unit;
  let removeAllListeners : t => unit;
  let getLayout : t => translateTransform;
  let getTranslateTransform : t => translateTransform;
  type value = t;
  let add : value => value => value;
  let divide : value => value => value;
  let multiply : value => value => value;
  module Timing: {
    type toValue;
    type config;
    let config:
      easing::(float => float)? =>
      duration::float? =>
      delay::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      toValue::toValue =>
      config;
    let toValueFloat : jsValue => toValue;
    let toValueAnimated : value => toValue;
    let timing: value::value => config::config => CompositeAnimation.t;
  };
  module Spring: {
    type toValue;
    type config;
    let config:
      restDisplacementThreshold::float? =>
      overshootClamping::Js.boolean? =>
      restSpeedThreshold::float? =>
      velocity::jsValue? =>
      bounciness::float? =>
      speed::float? =>
      tension::float? =>
      friction::float? =>
      isInteraction::Js.boolean? =>
      useNativeDriver::Js.boolean? =>
      onComplete::Animation.endCallback? =>
      iterations::int? =>
      toValue::toValue =>
      config;
    let toValueFloat : jsValue => toValue;
    let toValueAnimated : value => toValue;
    let spring: value::value => config::config => CompositeAnimation.t;
  };
  module Decay: {
    type config;
    let config:
      deceleration::'a? =>
      isInteraction::bool? =>
      useNativeDriver::bool? =>
      onComplete::'b? =>
      iterations::'c? =>
      velocity::'d =>
      Js.t {
        .
        deceleration : Js.Undefined.t 'a,
        isInteraction : Js.Undefined.t Js.boolean,
        iterations : Js.Undefined.t 'c,
        onComplete : Js.Undefined.t 'b,
        useNativeDriver : Js.Undefined.t Js.boolean,
        velocity : 'd
      };
    let decay: value::value => config::config => CompositeAnimation.t;
  };
};

module View: ViewRe.ViewComponent;

module Image: ImageRe.ImageComponent;

module Text: TextRe.TextComponent;

module ScrollView: {
  let onScrollUpdater: x::'a? => y::'b? => native::bool? => unit => unit;
  type point = {x: float, y: float};
  let scrollTo: ReactRe.reactRef => x::int => y::int => animated::bool => unit;
  let scrollToEnd: ReactRe.reactRef => animated::bool => unit;
  let createElement:
    accessibleLeft::ReactRe.reactElement? =>
    accessible::bool? =>
    hitSlop::Types.insets? =>
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
    pointerEvents::[ | `auto | `boxNone | `boxOnly | `none]? =>
    removeClippedSubviews::bool? =>
    style::Style.t? =>
    testID::string? =>
    accessibilityComponentType::
      [ | `button | `none | `radiobutton_checked | `radiobutton_unchecked]? =>
    accessibilityLiveRegion::[ | `assertive | `none | `polite]? =>
    collapsable::bool? =>
    importantForAccessibility::[ | `auto | `no | `noHideDescendants | `yes]? =>
    needsOffscreenAlphaCompositing::bool? =>
    renderToHardwareTextureAndroid::bool? =>
    accessibilityTraits::
      list [
        | `adjustable
        | `allowsDirectInteraction
        | `button
        | `disabled
        | `frequentUpdates
        | `header
        | `image
        | `key
        | `link
        | `none
        | `pageTurn
        | `plays
        | `search
        | `selected
        | `startsMedia
        | `summary
        | `text
      ]? =>
    accessibilityViewIsModal::bool? =>
    shouldRasterizeIOS::bool? =>
    contentContainerStyle::Style.t? =>
    horizontal::bool? =>
    keyboardDismissMode::[ | `interactive | `none | `onDrag]? =>
    keyboardShouldPersistTaps::[ | `always | `handled | `never]? =>
    onContentSizeChange::((float, float) => unit)? =>
    onScroll::(unit => unit)? =>
    pagingEnabled::bool? =>
    refreshControl::ReactRe.reactElement? =>
    scrollEnabled::bool? =>
    showsHorizontalScrollIndicator::bool? =>
    showsVerticalScrollIndicator::bool? =>
    stickyHeaderIndices::list int? =>
    overScrollMode::[ | `always | `auto | `never]? =>
    scrollPerfTag::string? =>
    alwaysBounceHorizontal::bool? =>
    alwaysBounceVertical::bool? =>
    automaticallyAdjustContentInsets::bool? =>
    bounces::bool? =>
    canCancelContentTouches::bool? =>
    centerContent::bool? =>
    contentInset::Types.insets? =>
    contentOffset::point? =>
    decelerationRate::[ | `fast | `normal]? =>
    directionalLockEnabled::bool? =>
    indicatorStyle::[ | `black | `default | `white]? =>
    maximumZoomScale::float? =>
    mimimumZoomScale::float? =>
    onScrollAnimationEnd::(unit => unit)? =>
    scrollEventThrottle::int? =>
    scrollIndicatorInsets::Types.insets? =>
    scrollsToTop::bool? =>
    snapToAlignment::[ | `center | `end_ | `start]? =>
    zoomScale::float? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

let event : 'a => 'b => unit => unit;

let delay : float => CompositeAnimation.t;

let sequence : array CompositeAnimation.t => CompositeAnimation.t;

let parallel :
  array CompositeAnimation.t => Js.t {. stopTogether : Js.boolean} => CompositeAnimation.t;

let stagger : float => array CompositeAnimation.t => CompositeAnimation.t;

let loop: iterations::int? => animation::CompositeAnimation.t => CompositeAnimation.t;
