type source;

let source:
  uri::string? => method::string? => headers::Js.t 'a? => body::string? => unit => source;

type iOSLoadRequestEvent =
  Js.t {
    .
    target : int,
    canGoBack : bool,
    lockIdentifier : int,
    loading : bool,
    title : string,
    canGoForward : bool,
    navigationType : string,
    url : string
  };

type webViewContentInsets;

let webViewContentInsets:
  top::int? => left::int? => bottom::int? => right::int? => unit => webViewContentInsets;

let make:
  accessibilityLabel::ReasonReact.reactElement? =>
  accessible::bool? =>
  hitSlop::TypesRN.insets? =>
  onAccessibilityTap::(unit => unit)? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onMagicTap::(unit => unit)? =>
  responderHandlers::Props.touchResponderHandlers? =>
  pointerEvents::[ | `auto | `none | `boxNone | `boxOnly]? =>
  removeClippedSubviews::bool? =>
  style::StyleRe.t? =>
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
  automaticallyAdjustContentInsets::bool? =>
  contentInsets::webViewContentInsets? =>
  injectJavaScript::(string => unit)? =>
  injectedJavaScript::string? =>
  mediaPlaybackRequiresUserAction::bool? =>
  onError::
    (
      Js.t {
        .
        url : option string,
        title : option string,
        loading : option bool,
        canGoBack : option bool,
        canGoForward : option bool
      } =>
      unit
    )? =>
  onLoad::
    (
      Js.t {
        .
        url : option string,
        title : option string,
        loading : option bool,
        canGoBack : option bool,
        canGoForward : option bool
      } =>
      unit
    )? =>
  onLoadEnd::
    (
      Js.t {
        .
        url : option string,
        title : option string,
        loading : option bool,
        canGoBack : option bool,
        canGoForward : option bool
      } =>
      unit
    )? =>
  onLoadStart::
    (
      Js.t {
        .
        url : option string,
        title : option string,
        loading : option bool,
        canGoBack : option bool,
        canGoForward : option bool
      } =>
      unit
    )? =>
  onMessage::(RNEvent.NativeEvent.t => unit)? =>
  onNavigationStateChange::
    (
      Js.t {
        .
        url : option string,
        title : option string,
        loading : option bool,
        canGoBack : option bool,
        canGoForward : option bool
      } =>
      unit
    )? =>
  renderError::(unit => ReasonReact.reactElement)? =>
  renderLoading::(unit => ReasonReact.reactElement)? =>
  scalesPageToFit::bool? =>
  source::source? =>
  startInLoadingState::bool? =>
  domStorageEnabled::bool? =>
  javaScriptEnabled::bool? =>
  mixedContentMode::list [ | `never | `always | `compatibility]? =>
  thirdPartyCookiesEnabled::bool? =>
  userAgent::string? =>
  allowsInlineMediaPlayback::bool? =>
  bounces::bool? =>
  dataDetectorTypes::list [ | `phoneNumber | `link | `address | `calendarEvent | `none | `all]? =>
  decelerationRate::list [ | `normal | `fast | `value float]? =>
  onShouldStartLoadWithRequest::(iOSLoadRequestEvent => bool)? =>
  scrollEnabled::bool? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;