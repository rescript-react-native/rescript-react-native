---
id: components/WebView
title: WebView
wip: true
---

```reason
type element;
type ref = React.Ref.t(Js.nullable(element));

module Source = {
  type t;

  [@bs.obj]
  external uri:
    (
      ~uri: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      unit
    ) =>
    t =
    "";

  [@bs.obj]
  external html: (~html: string=?, ~baseUrl: string=?, unit) => t = "";
};

module DataDetectorTypes = WebView_DataDetectorTypes;
module DecelerationRate = WebView_DecelerationRate;

type messageEvent = Event.syntheticEvent({. "data": string});

type webViewEvent =
  Event.syntheticEvent({
    .
    "url": string,
    "title": string,
    "loading": bool,
    "canGoBack": bool,
    "canGoForward": bool,
  });

type request = {
  .
  "url": string,
  "title": string,
  "loading": bool,
  "canGoBack": bool,
  "canGoForward": bool,
  "lockIdentifier": string,
  "navigationType": string,
};

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // WebView props
    ~allowFileAccess: bool=?,
    ~allowsInlineMediaPlayback: bool=?,
    ~allowUniversalAccessFromFileURLs: bool=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~bounces: bool=?,
    ~contentInsets: Types.edgeInsets=?,
    ~dataDetectorTypes: array(DataDetectorTypes.t)=?,
    ~decelerationRate: DecelerationRate.t=?,
    ~domStorageEnabled: bool=?,
    ~geolocationEnabled: bool=?,
    ~injectedJavaScript: string=?,
    ~injectJavaScript: string => unit=?,
    ~javaScriptEnabled: bool=?,
    ~mediaPlaybackRequiresUserAction: bool=?,
    ~mixedContentMode: [@bs.string] [ | `never | `always | `compatibility]=?,
    ~onError: webViewEvent => unit=?,
    ~onLoad: webViewEvent => unit=?,
    ~onLoadEnd: webViewEvent => unit=?,
    ~onLoadStart: webViewEvent => unit=?,
    ~onMessage: messageEvent => unit=?,
    ~onNavigationStateChange: webViewEvent => unit=?,
    ~onShouldStartLoadWithRequest: request => unit=?,
    ~originWhitelist: array(string)=?,
    ~renderError: string => React.element=?,
    ~renderLoading: unit => React.element=?,
    ~scalesPageToFit: bool=?,
    ~scrollEnabled: bool=?,
    ~source: Source.t=?,
    ~startInLoadingState: bool=?,
    ~thirdPartyCookiesEnabled: bool=?,
    ~userAgent: string=?,
    ~useWebKit: bool=?,
    // View props
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]=?,
    ~accessibilityRole: [@bs.string] [
                          | `none
                          | `button
                          | `link
                          | `search
                          | `image
                          | `keyboardkey
                          | `text
                          | `adjustable
                          | `header
                          | `summary
                          | `imagebutton
                        ]
                          =?,
    ~accessibilityStates: array(AccessibilityState.t)=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: Types.edgeInsets=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~nativeID: string=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderTerminate: Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: Event.pressEvent => unit=?,
    ~onStartShouldSetResponder: Event.pressEvent => bool=?,
    ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~pointerEvents: [@bs.string] [
                      | `auto
                      | `none
                      | [@bs.as "box-none"] `boxNone
                      | [@bs.as "box-only"] `boxOnly
                    ]
                      =?,
    ~removeClippedSubviews: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~style: Style.t=?,
    ~testID: string=?
  ) =>
  React.element =
  "WebView";

// Methods
// static extraNativeComponentConfig() ??
[@bs.send] external goForward: element => unit = "";
[@bs.send] external goBack: element => unit = "";
[@bs.send] external reload: element => unit = "";
[@bs.send] external stopLoading: element => unit = "";
```
