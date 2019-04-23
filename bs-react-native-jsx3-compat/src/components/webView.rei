type source = ReactNative.WebView.Source.t;

module EventTypes: {type t = ReactNative.WebView.webViewEvent;};

let sourceUri:
  (
    ~uri: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    unit
  ) =>
  source;

let sourceHtml: (~html: string=?, ~baseUrl: string=?, unit) => source;

[@deprecated "Please use WebView.sourceUri instead"]
let source:
  (
    ~uri: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    unit
  ) =>
  source;

type iOSLoadRequestEvent = ReactNative.WebView.request;

let goForward: ReasonReact.reactRef => unit;

let goBack: ReasonReact.reactRef => unit;

let reload: ReasonReact.reactRef => unit;

let stopLoading: ReasonReact.reactRef => unit;

[@react.component]
let make:
  (
    ~source: source=?,
    ~style: Style.t=?,
    ~renderError: unit => ReasonReact.reactElement=?,
    ~renderLoading: unit => ReasonReact.reactElement=?,
    ~onError: EventTypes.t => unit=?,
    ~onLoad: EventTypes.t => unit=?,
    ~onLoadEnd: EventTypes.t => unit=?,
    ~onLoadStart: EventTypes.t => unit=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~contentInsets: Types.insets=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: Types.pointerEvents=?,
    ~removeClippedSubviews: bool=?,
    ~testID: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityLiveRegion: Types.accessibilityLiveRegion=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: Types.importantForAccessibility=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~injectJavaScript: string => unit=?,
    ~injectedJavaScript: string=?,
    ~mediaPlaybackRequiresUserAction: bool=?,
    ~onMessage: ReactNative.WebView.messageEvent => unit=?,
    ~onNavigationStateChange: EventTypes.t => unit=?,
    ~scalesPageToFit: bool=?,
    ~startInLoadingState: bool=?,
    ~domStorageEnabled: bool=?,
    ~javaScriptEnabled: bool=?,
    ~mixedContentMode: list([ | `never | `always | `compatibility])=?,
    ~thirdPartyCookiesEnabled: bool=?,
    ~userAgent: string=?,
    ~allowsInlineMediaPlayback: bool=?,
    ~bounces: bool=?,
    ~dataDetectorTypes: list(
                          [
                            | `phoneNumber
                            | `link
                            | `address
                            | `calendarEvent
                            | `none
                            | `all
                          ],
                        )
                          =?,
    ~decelerationRate: list([ | `normal | `fast | `value(float)])=?,
    ~onShouldStartLoadWithRequest: iOSLoadRequestEvent => bool=?,
    ~scrollEnabled: bool=?
  ) =>
  React.element;
