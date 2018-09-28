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

type contentInsets;

let contentInsets:
  (~top: int=?, ~left: int=?, ~bottom: int=?, ~right: int=?, unit) =>
  contentInsets;

let goForward: ReasonReact.reactRef => unit;

let goBack: ReasonReact.reactRef => unit;

let reload: ReasonReact.reactRef => unit;

let stopLoading: ReasonReact.reactRef => unit;

let make:
  (
    ~source: source=?,
    ~style: RN_style.t=?,
    ~renderError: unit => ReasonReact.reactElement=?,
    ~renderLoading: unit => ReasonReact.reactElement=?,
    ~onError: RN_Event.t => unit=?,
    ~onLoad: RN_Event.t => unit=?,
    ~onLoadEnd: RN_Event.t => unit=?,
    ~onLoadStart: RN_Event.t => unit=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~contentInsets: contentInsets=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: RN_types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: RN_types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
                            [
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
                            ],
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~injectJavaScript: string => unit=?,
    ~injectedJavaScript: string=?,
    ~mediaPlaybackRequiresUserAction: bool=?,
    ~onMessage: RN_Event.t => unit=?,
    ~onNavigationStateChange: RN_Event.t => unit=?,
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