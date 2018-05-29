type source;

let sourceUri:
  (~uri: string=?, ~method: string=?, ~headers: Js.t('a)=?, ~body: string=?, unit) => source;

let sourceHtml:
(~html: string=?, ~baseUrl: string=?, unit) => source;

[@deprecated "Please use WebView.sourceUri instead"]
let source: (~uri: string=?, ~method: string=?, ~headers: Js.t('a)=?, ~body: string=?, unit) => source;

type iOSLoadRequestEvent = {
  .
  "target": int,
  "canGoBack": bool,
  "lockIdentifier": int,
  "loading": bool,
  "title": string,
  "canGoForward": bool,
  "navigationType": string,
  "url": string
};

type contentInsets;

let contentInsets:
  (~top: int=?, ~left: int=?, ~bottom: int=?, ~right: int=?, unit) => contentInsets;

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
    ~onError: {
                .
                "url": Js.Nullable.t(string),
                "title": Js.Nullable.t(string),
                "loading": Js.Nullable.t(bool),
                "canGoBack": Js.Nullable.t(bool),
                "canGoForward": Js.Nullable.t(bool)
              } =>
              unit
                =?,
    ~onLoad: {
               .
               "url": Js.Nullable.t(string),
               "title": Js.Nullable.t(string),
               "loading": Js.Nullable.t(bool),
               "canGoBack": Js.Nullable.t(bool),
               "canGoForward": Js.Nullable.t(bool)
             } =>
             unit
               =?,
    ~onLoadEnd: {
                  .
                  "url": Js.Nullable.t(string),
                  "title": Js.Nullable.t(string),
                  "loading": Js.Nullable.t(bool),
                  "canGoBack": Js.Nullable.t(bool),
                  "canGoForward": Js.Nullable.t(bool)
                } =>
                unit
                  =?,
    ~onLoadStart: {
                    .
                    "url": Js.Nullable.t(string),
                    "title": Js.Nullable.t(string),
                    "loading": Js.Nullable.t(bool),
                    "canGoBack": Js.Nullable.t(bool),
                    "canGoForward": Js.Nullable.t(bool)
                  } =>
                  unit
                    =?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~contentInsets: contentInsets=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
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
                            ]
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~injectJavaScript: string => unit=?,
    ~injectedJavaScript: string=?,
    ~mediaPlaybackRequiresUserAction: bool=?,
    ~onMessage: RNEvent.NativeEvent.t => unit=?,
    ~onNavigationStateChange: {
                                .
                                "url": Js.Nullable.t(string),
                                "title": Js.Nullable.t(string),
                                "loading": Js.Nullable.t(bool),
                                "canGoBack": Js.Nullable.t(bool),
                                "canGoForward": Js.Nullable.t(bool)
                              } =>
                              unit
                                =?,
    ~scalesPageToFit: bool=?,
    ~startInLoadingState: bool=?,
    ~domStorageEnabled: bool=?,
    ~javaScriptEnabled: bool=?,
    ~mixedContentMode: list([ | `never | `always | `compatibility])=?,
    ~thirdPartyCookiesEnabled: bool=?,
    ~userAgent: string=?,
    ~allowsInlineMediaPlayback: bool=?,
    ~bounces: bool=?,
    ~dataDetectorTypes: list([ | `phoneNumber | `link | `address | `calendarEvent | `none | `all])
                          =?,
    ~decelerationRate: list([ | `normal | `fast | `value(float)])=?,
    ~onShouldStartLoadWithRequest: iOSLoadRequestEvent => bool=?,
    ~scrollEnabled: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);
