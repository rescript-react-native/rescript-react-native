[@bs...] external view: ReasonReact.reactClass = "WebView";
type navigationType =
    [ `backforward | `click | `formresubmit | `formsubmit | `other | `reload ];
let navigationTypeToJs: navigationType => string;
let navigationTypeFromJs: string => option(navigationType);
type iOSOnShouldStartLoadWithRequestEvent =
    {. "canGoBack": bool, "canGoForward": bool, "loading": bool,
      "navigationType": string, "title": string, "url": string};
type source;
[@bs...] external sourceUri:
  (~uri: string=?, ~method: string=?, ~headers: Js.t('a)=?, ~body: string=?,
  unit) => source = "";
[@bs...] external sourceHtml:
  (~html: string=?, ~baseUrl: string=?, unit) => source = "";
let source:
  (~uri: string=?, ~method: string=?, ~headers: Js.t('a)=?, ~body: string=?,
  unit) => source;
type contentInsets;
[@bs...] external contentInsets:
  (~top: int=?, ~left: int=?, ~bottom: int=?, ~right: int=?, unit) =>
  contentInsets = "";
[@bs...] external goForward: ReasonReact.reactRef => unit = "";
[@bs...] external goBack: ReasonReact.reactRef => unit = "";
[@bs...] external reload: ReasonReact.reactRef => unit = "";
[@bs...] external stopLoading: ReasonReact.reactRef => unit = "";
let make:
  (~source: 'a=?, ~style: 'b=?, ~renderError: 'c=?, ~renderLoading: 'd=?,
  ~onError: {. "canGoBack": bool, "canGoForward": bool, "code": float,
              "description": string, "domain": Js.Nullable.t(string),
              "loading": bool, "title": string, "url": string} =>
            unit=?,
  ~onLoad: {. "canGoBack": bool, "canGoForward": bool, "loading": bool,
             "target": Js.Nullable.t(float), "title": string, "url": 
             string} =>
           unit=?,
  ~onLoadEnd: {. "canGoBack": bool, "canGoForward": bool, "loading": 
                bool, "target": Js.Nullable.t(float), "title": string,
                "url": string} =>
              unit=?,
  ~onLoadStart: {. "canGoBack": bool, "canGoForward": bool, "loading": 
                  bool, "navigationType": Js.Nullable.t(string),
                  "target": Js.Nullable.t(float), "title": string,
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
