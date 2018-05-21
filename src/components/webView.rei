[@bs...] external view: ReasonReact.reactClass = "WebView";
type navigationType =
    [ `backforward | `click | `formresubmit | `formsubmit | `other | `reload ];
type iOSOnShouldStartLoadWithRequestEvent =
    {. "canGoBack": bool, "canGoForward": bool, "loading": bool,
      "navigationType": navigationType, "title": string, "url": string};
type source;
[@bs...] external source:
  (~uri: string=?, ~method: string=?, ~headers: Js.t('a)=?, ~body: string=?,
  unit) => source = "";
type contentInsets;
[@bs...] external contentInsets:
  (~top: int=?, ~left: int=?, ~bottom: int=?, ~right: int=?, unit) =>
  contentInsets = "";
let make:
  (~source: 'a=?, ~style: 'b=?, ~renderError: 'c=?, ~renderLoading: 'd=?,
  ~onError: {. "canGoBack": bool, "canGoForward": bool, "code": float,
              "description": string, "domain": Js.Null_undefined.t(string),
              "loading": bool, "title": string, "url": string} =>
            unit=?,
  ~onLoad: {. "canGoBack": bool, "canGoForward": bool, "loading": bool,
             "target": Js.Null_undefined.t(float), "title": string,
             "url": string} =>
           unit=?,
  ~onLoadEnd: {. "canGoBack": bool, "canGoForward": bool, "loading": 
                bool, "target": Js.Null_undefined.t(float), "title": 
                string, "url": string} =>
              unit=?,
  ~onLoadStart: {. "canGoBack": bool, "canGoForward": bool, "loading": 
                  bool,
                  "navigationType": Js.Null_undefined.t(navigationType),
                  "target": Js.Null_undefined.t(float), "title": string,
                  "url": string} =>
                unit=?,
  ~automaticallyAdjustContentInsets: 'e=?, ~contentInsets: 'f=?,
  ~accessibilityLabel: 'g=?, ~accessible: 'h=?, ~hitSlop: 'i=?,
  ~onAccessibilityTap: 'j=?, ~onLayout: 'k=?, ~onMagicTap: 'l=?,
  ~responderHandlers: BsReactNative.Types.touchResponderHandlers=?,
  ~pointerEvents: [< `auto | `boxNone | `boxOnly | `none ]=?,
  ~removeClippedSubviews: 'm=?, ~testID: 'n=?,
  ~accessibilityComponentType: [< `button
                                | `none
                                | `radiobutton_checked
                                | `radiobutton_unchecked ]=?,
  ~accessibilityLiveRegion: [< `assertive | `none | `polite ]=?,
  ~collapsable: 'o=?,
  ~importantForAccessibility: [< `auto | `no | `noHideDescendants | `yes ]=?,
  ~needsOffscreenAlphaCompositing: 'p=?,
  ~renderToHardwareTextureAndroid: 'q=?,
  ~accessibilityTraits: list([< `adjustable
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
                              | `text ])=?,
  ~accessibilityViewIsModal: 'r=?, ~shouldRasterizeIOS: 's=?,
  ~injectJavaScript: 't=?, ~injectedJavaScript: 'u=?,
  ~mediaPlaybackRequiresUserAction: 'v=?, ~onMessage: 'w=?,
  ~onNavigationStateChange: 'x=?, ~scalesPageToFit: 'y=?,
  ~startInLoadingState: 'z=?, ~domStorageEnabled: 'a1=?,
  ~javaScriptEnabled: 'b1=?,
  ~mixedContentMode: list([< `always | `compatibility | `never ])=?,
  ~thirdPartyCookiesEnabled: 'c1=?, ~userAgent: 'd1=?,
  ~allowsInlineMediaPlayback: 'e1=?, ~bounces: 'f1=?,
  ~dataDetectorTypes: list([< `address
                            | `all
                            | `calendarEvent
                            | `link
                            | `none
                            | `phoneNumber ])=?,
  ~decelerationRate: list([< `fast | `normal | `value(float) ])=?,
  ~onShouldStartLoadWithRequest: iOSOnShouldStartLoadWithRequestEvent => bool=?,
  ~scrollEnabled: 'g1=?, 'h1) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps,
                         ReasonReact.actionless);
