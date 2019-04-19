type source;

module EventTypes: {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    url: string,
    [@bs.optional]
    title: string,
    [@bs.optional]
    loading: bool,
    [@bs.optional]
    canGoBack: bool,
    [@bs.optional]
    canGoForward: bool,
  };
};

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

type iOSLoadRequestEvent = {
  .
  "target": int,
  "canGoBack": bool,
  "lockIdentifier": int,
  "loading": bool,
  "title": string,
  "canGoForward": bool,
  "navigationType": string,
  "url": string,
};

let goForward: ReasonReact.reactRef => unit;

let goBack: ReasonReact.reactRef => unit;

let reload: ReasonReact.reactRef => unit;

let stopLoading: ReasonReact.reactRef => unit;

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
    ~accessibilityLabel: ReasonReact.reactElement=?,
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
    ~onMessage: RNEvent.t => unit=?,
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
    ~scrollEnabled: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );