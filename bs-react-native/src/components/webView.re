[@bs.module "react-native"] external view: ReasonReact.reactClass = "WebView";

module EventTypes = {
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

type source;

[@bs.obj]
external sourceUri:
  (
    ~uri: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    unit
  ) =>
  source =
  "";

[@bs.obj]
external sourceHtml: (~html: string=?, ~baseUrl: string=?, unit) => source =
  "";

let source = sourceUri;

[@bs.send] external goForward: ReasonReact.reactRef => unit = "";

[@bs.send] external goBack: ReasonReact.reactRef => unit = "";

[@bs.send] external reload: ReasonReact.reactRef => unit = "";

[@bs.send] external stopLoading: ReasonReact.reactRef => unit = "";

let make =
    (
      ~source=?,
      ~style=?,
      ~renderError=?,
      ~renderLoading=?,
      ~onError=?,
      ~onLoad=?,
      ~onLoadEnd=?,
      ~onLoadStart=?,
      ~automaticallyAdjustContentInsets=?,
      ~contentInsets=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityRole=?,
      ~accessibilityStates=?,
      ~accessibilityHint=?,
      ~accessibilityIgnoresInvertColors=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
      ~injectJavaScript=?,
      ~injectedJavaScript=?,
      ~mediaPlaybackRequiresUserAction=?,
      ~onMessage=?,
      ~onNavigationStateChange=?,
      ~scalesPageToFit=?,
      ~startInLoadingState=?,
      ~domStorageEnabled=?,
      ~javaScriptEnabled=?,
      ~mixedContentMode=?,
      ~thirdPartyCookiesEnabled=?,
      ~userAgent=?,
      ~allowsInlineMediaPlayback=?,
      ~bounces=?,
      ~dataDetectorTypes=?,
      ~decelerationRate=?,
      ~onShouldStartLoadWithRequest=?,
      ~scrollEnabled=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      ViewProps.extend(
        ~accessibilityLabel?,
        ~accessible?,
        ~hitSlop?,
        ~onAccessibilityTap?,
        ~onLayout?,
        ~onMagicTap?,
        ~responderHandlers?,
        ~pointerEvents?,
        ~removeClippedSubviews?,
        ~style?,
        ~testID?,
        ~accessibilityComponentType?,
        ~accessibilityLiveRegion?,
        ~collapsable?,
        ~importantForAccessibility?,
        ~needsOffscreenAlphaCompositing?,
        ~renderToHardwareTextureAndroid?,
        ~accessibilityTraits?,
        ~accessibilityRole?,
        ~accessibilityStates?,
        ~accessibilityHint?,
        ~accessibilityIgnoresInvertColors?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
        {
          "source": source,
          "style": style,
          "automaticallyAdjustContentInsets": automaticallyAdjustContentInsets,
          "contentInsets": contentInsets,
          "injectJavaScript": injectJavaScript,
          "injectedJavaScript": injectedJavaScript,
          "mediaPlaybackRequiresUserAction": mediaPlaybackRequiresUserAction,
          "onError": onError,
          "onLoad": onLoad,
          "onLoadEnd": onLoadEnd,
          "onLoadStart": onLoadStart,
          "onMessage": onMessage,
          "onNavigationStateChange": onNavigationStateChange,
          "renderError": renderError,
          "renderLoading": renderLoading,
          "scalesPageToFit": scalesPageToFit,
          "startInLoadingState": startInLoadingState,
          "domStorageEnabled": domStorageEnabled,
          "javaScriptEnabled": javaScriptEnabled,
          "mixedContentMode":
            mixedContentMode->Belt.Option.map(contentMode => {
              let to_string =
                fun
                | `never => "never"
                | `always => "always"
                | `compatibility => "compatibility";
              contentMode |> List.map(to_string) |> Array.of_list;
            }),
          "thirdPartyCookiesEnabled": thirdPartyCookiesEnabled,
          "userAgent": userAgent,
          "allowsInlineMediaPlayback": allowsInlineMediaPlayback,
          "bounces": bounces,
          "dataDetectorTypes":
            dataDetectorTypes->Belt.Option.map(dataDetectorType => {
              let to_string =
                fun
                | `phoneNumber => "phoneNumber"
                | `link => "link"
                | `address => "address"
                | `calendarEvent => "calendarEvent"
                | `none => "none"
                | `all => "all";
              dataDetectorType |> List.map(to_string) |> Array.of_list;
            }),
          "decelerationRate":
            decelerationRate->Belt.Option.map(rate => {
              let to_float =
                fun
                | `normal => 0.998
                | `fast => 0.99
                | `value(f) => f;
              rate |> List.map(to_float) |> Array.of_list;
            }),
          "onShouldStartLoadWithRequest": onShouldStartLoadWithRequest,
          "scrollEnabled": scrollEnabled,
        },
      ),
  );
