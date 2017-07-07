module type WebViewComponent = {
  type webViewNavState;
  let webViewNavState:
    url::string? =>
    title::string? =>
    loading::bool? =>
    canGoBack::bool? =>
    canGoForward::bool? =>
    unit =>
    webViewNavState;
  type webViewIOSLoadRequestEvent;
  let webViewIOSLoadRequestEvent:
    target::int =>
    canGoBack::bool =>
    lockIdentifier::int =>
    loading::bool =>
    title::string =>
    canGoForward::bool =>
    navigationType::[ | `other | `click] =>
    url::string =>
    unit =>
    webViewIOSLoadRequestEvent;
  type webViewSource;
  let webViewSource:
    uri::string? => method::string? => headers::Js.t 'a? => body::string? => unit => webViewSource;
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
    accessibilityComponentType::
      [ | `none | `button | `radiobutton_checked | `radiobutton_unchecked]? =>
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
    onError::(webViewNavState => unit)? =>
    onLoad::(webViewNavState => unit)? =>
    onLoadEnd::(webViewNavState => unit)? =>
    onLoadStart::(webViewNavState => unit)? =>
    onMessage::(RNEvent.NativeEvent.t => unit)? =>
    onNavigationStateChange::(webViewNavState => unit)? =>
    renderError::(unit => ReasonReact.reactElement)? =>
    renderLoading::(unit => ReasonReact.reactElement)? =>
    scalesPageToFit::bool? =>
    source::webViewSource? =>
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
    onShouldStartLoadWithRequest::(webViewIOSLoadRequestEvent => bool)? =>
    scrollEnabled::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
};

module type Impl = {let webView: ReasonReact.reactClass;};

module CreateComponent (Impl: Impl) :WebViewComponent => {
  type webViewNavState;
  external webViewNavState :
    url::string? =>
    title::string? =>
    loading::bool? =>
    canGoBack::bool? =>
    canGoForward::bool? =>
    unit =>
    webViewNavState =
    "" [@@bs.obj];
  type webViewIOSLoadRequestEvent;
  external webViewIOSLoadRequestEvent :
    target::int =>
    canGoBack::bool =>
    lockIdentifier::int =>
    loading::bool =>
    title::string =>
    canGoForward::bool =>
    navigationType::[ | `other | `click] [@bs.string] =>
    url::string =>
    unit =>
    webViewIOSLoadRequestEvent =
    "" [@@bs.obj];
  type webViewSource;
  external webViewSource :
    uri::string? => method::string? => headers::Js.t 'a? => body::string? => unit => webViewSource =
    "" [@@bs.obj];
  type webViewContentInsets;
  external webViewContentInsets :
    top::int? => left::int? => bottom::int? => right::int? => unit => webViewContentInsets =
    "" [@@bs.obj];
  let make
      ::accessibilityLabel=?
      ::accessible=?
      ::hitSlop=?
      ::onAccessibilityTap=?
      ::onLayout=?
      ::onMagicTap=?
      ::responderHandlers=?
      ::pointerEvents=?
      ::removeClippedSubviews=?
      ::style=?
      ::testID=?
      ::accessibilityComponentType=?
      ::accessibilityLiveRegion=?
      ::collapsable=?
      ::importantForAccessibility=?
      ::needsOffscreenAlphaCompositing=?
      ::renderToHardwareTextureAndroid=?
      ::accessibilityTraits=?
      ::accessibilityViewIsModal=?
      ::shouldRasterizeIOS=?
      ::automaticallyAdjustContentInsets=?
      ::contentInsets=?
      ::injectJavaScript=?
      ::injectedJavaScript=?
      ::mediaPlaybackRequiresUserAction=?
      ::onError=?
      ::onLoad=?
      ::onLoadEnd=?
      ::onLoadStart=?
      ::onMessage=?
      ::onNavigationStateChange=?
      ::renderError=?
      ::renderLoading=?
      ::scalesPageToFit=?
      ::source=?
      ::startInLoadingState=?
      ::domStorageEnabled=?
      ::javaScriptEnabled=?
      ::mixedContentMode=?
      ::thirdPartyCookiesEnabled=?
      ::userAgent=?
      ::allowsInlineMediaPlayback=?
      ::bounces=?
      ::dataDetectorTypes=?
      ::decelerationRate=?
      ::onShouldStartLoadWithRequest=?
      ::scrollEnabled=? =>
    ReasonReact.wrapJsForReason
      reactClass::Impl.webView
      props::
        Js.Undefined.(
          Props.extendView
            ::?accessibilityLabel
            ::?accessible
            ::?hitSlop
            ::?onAccessibilityTap
            ::?onLayout
            ::?onMagicTap
            ::?responderHandlers
            ::?pointerEvents
            ::?removeClippedSubviews
            ::?style
            ::?testID
            ::?accessibilityComponentType
            ::?accessibilityLiveRegion
            ::?collapsable
            ::?importantForAccessibility
            ::?needsOffscreenAlphaCompositing
            ::?renderToHardwareTextureAndroid
            ::?accessibilityTraits
            ::?accessibilityViewIsModal
            ::?shouldRasterizeIOS
            {
              "source": from_opt source,
              "style": from_opt style,
              "automaticallyAdjustContentInsets": from_opt automaticallyAdjustContentInsets,
              "contentInsets": from_opt contentInsets,
              "injectJavaScript": from_opt injectJavaScript,
              "injectedJavaScript": from_opt injectedJavaScript,
              "mediaPlaybackRequiresUserAction": from_opt mediaPlaybackRequiresUserAction,
              "onError": from_opt onError,
              "onLoad": from_opt onLoad,
              "onLoadEnd": from_opt onLoadEnd,
              "onLoadStart": from_opt onLoadStart,
              "onMessage": from_opt onMessage,
              "onNavigationStateChange": from_opt onNavigationStateChange,
              "renderError": from_opt renderError,
              "renderLoading": from_opt renderLoading,
              "scalesPageToFit": from_opt scalesPageToFit,
              "startInLoadingState": from_opt startInLoadingState,
              "domStorageEnabled": from_opt domStorageEnabled,
              "javaScriptEnabled": from_opt javaScriptEnabled,
              "mixedContentMode":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun contentMode => {
                        let to_string =
                          fun
                          | `never => "never"
                          | `always => "always"
                          | `compatibility => "compatibility";
                        contentMode |> List.map to_string |> Array.of_list
                      }
                    )
                    mixedContentMode
                ),
              "thirdPartyCookiesEnabled": from_opt thirdPartyCookiesEnabled,
              "userAgent": from_opt userAgent,
              "allowsInlineMediaPlayback": from_opt allowsInlineMediaPlayback,
              "bounces": from_opt bounces,
              "dataDetectorTypes":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun dataDetectorType => {
                        let to_string =
                          fun
                          | `phoneNumber => "phoneNumber"
                          | `link => "link"
                          | `address => "address"
                          | `calendarEvent => "calendarEvent"
                          | `none => "none"
                          | `all => "all";
                        dataDetectorType |> List.map to_string |> Array.of_list
                      }
                    )
                    dataDetectorTypes
                ),
              "decelerationRate":
                from_opt (
                  UtilsRN.option_map
                    (
                      fun rate => {
                        let to_float =
                          fun
                          | `normal => 0.998
                          | `fast => 0.99
                          | `value f => f;
                        rate |> List.map to_float |> Array.of_list
                      }
                    )
                    decelerationRate
                ),
              "onShouldStartLoadWithRequest": from_opt onShouldStartLoadWithRequest,
              "scrollEnabled": from_opt scrollEnabled
            }
        );
};

module WebView =
  CreateComponent {
    external webView : ReasonReact.reactClass = "WebView" [@@bs.module "react-native"];
  };