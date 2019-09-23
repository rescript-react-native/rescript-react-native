---
id: components/WebView
title: WebView
wip: true
---

```reason
include WebViewElement;

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

class type webViewBaseEvent = {
  pub url: string;
  pub title: string;
  pub loading: bool;
  pub canGoBack: bool;
  pub canGoForward: bool;
  pub lockIdentifier: int;
};

class type virtual webViewNavigation = {
  as 'self;
  constraint 'self = #webViewBaseEvent;
  pub navigationType: string;
  pub mainDocumentURL: option(string);
};

class type virtual webViewError = {
  as 'self;
  constraint 'self = #webViewBaseEvent;
  pub domain: option(string);
  pub code: int;
  pub description: string;
};

class type virtual webViewErrorOrNavigation = {
  as 'self;
  constraint 'self = #webViewBaseEvent;
  pub domain: option(string);
  pub code: option(int);
  pub description: string;
  pub navigationType: string;
  pub mainDocumentURL: option(string);
};

class type virtual webViewMessage = {
  as 'self;
  constraint 'self = #webViewBaseEvent;
  pub data: string;
};

type webViewErrorEvent = Event.syntheticEvent(Js.t(webViewError));
type webViewNavigationEvent = Event.syntheticEvent(Js.t(webViewNavigation));
type webViewErrorOrNavigationEvent =
  Event.syntheticEvent(Js.t(webViewErrorOrNavigation));
type webViewMessageEvent = Event.syntheticEvent(Js.t(webViewMessage));
type webViewEvent = Js.t(webViewBaseEvent);

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
    ~contentInsets: View.edgeInsets=?,
    ~dataDetectorTypes: array(DataDetectorTypes.t)=?,
    ~decelerationRate: DecelerationRate.t=?,
    ~domStorageEnabled: bool=?,
    ~geolocationEnabled: bool=?,
    ~injectedJavaScript: string=?,
    ~injectJavaScript: string => unit=?,
    ~javaScriptEnabled: bool=?,
    ~mediaPlaybackRequiresUserAction: bool=?,
    ~mixedContentMode: [@bs.string] [ | `never | `always | `compatibility]=?,
    ~onError: webViewErrorEvent => unit=?,
    ~onLoad: webViewNavigationEvent => unit=?,
    ~onLoadEnd: webViewErrorOrNavigation => unit=?,
    ~onLoadStart: webViewNavigationEvent => unit=?,
    ~onMessage: webViewMessageEvent => unit=?,
    ~onNavigationStateChange: webViewEvent => unit=?,
    ~onShouldStartLoadWithRequest: request => bool=?,
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
    ~hitSlop: View.edgeInsets=?,
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
    ~onAccessibilityEscape: unit => unit=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderEnd: Event.pressEvent => unit=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderStart: Event.pressEvent => unit=?,
    ~onResponderTerminate: Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: Event.pressEvent => bool=?,
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

```
