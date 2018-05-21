[@bs.module "react-native"] external view : ReasonReact.reactClass = "WebView";

type navigationType = [
  | [@bs.as "click"] `click
  | [@bs.as "formsubmit"] `formsubmit
  | [@bs.as "backforward"] `backforward
  | [@bs.as "reload"] `reload
  | [@bs.as "formresubmit"] `formresubmit
  | [@bs.as "other"] `other
];

type iOSOnShouldStartLoadWithRequestEvent = {
  .
  "url": string,
  "title": string,
  "loading": bool,
  "canGoBack": bool,
  "canGoForward": bool,
  "navigationType": navigationType,
};

type source;

[@bs.obj]
external source :
  (
    ~uri: string=?,
    ~method: string=?,
    ~headers: Js.t('a)=?,
    ~body: string=?,
    unit
  ) =>
  source =
  "";

type contentInsets;

[@bs.obj]
external contentInsets :
  (~top: int=?, ~left: int=?, ~bottom: int=?, ~right: int=?, unit) =>
  contentInsets =
  "";

let make =
    (
      ~source=?,
      ~style=?,
      ~renderError=?,
      ~renderLoading=?,
      ~onError:
         option(
           {
             .
             "url": string,
             "title": string,
             "loading": bool,
             "canGoBack": bool,
             "canGoForward": bool,
             /* iOS only */
             "domain": Js.Null_undefined.t(string),
             "code": float,
             "description": string,
           } =>
           unit,
         )=?,
      ~onLoad:
         option(
           {
             .
             "target": Js.Null_undefined.t(float),
             "url": string,
             "title": string,
             "loading": bool,
             "canGoBack": bool,
             "canGoForward": bool,
           } =>
           unit,
         )=?,
      ~onLoadEnd:
         option(
           {
             .
             "target": Js.Null_undefined.t(float),
             "url": string,
             "title": string,
             "loading": bool,
             "canGoBack": bool,
             "canGoForward": bool,
           } =>
           unit,
         )=?,
      ~onLoadStart:
         option(
           {
             .
             "target": Js.Null_undefined.t(float),
             "url": string,
             "title": string,
             "loading": bool,
             "canGoBack": bool,
             "canGoForward": bool,
             /* iOS only */
             "navigationType": Js.Null_undefined.t(navigationType)
           } =>
           unit,
         )=?,
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
      ~onShouldStartLoadWithRequest:
         option(iOSOnShouldStartLoadWithRequestEvent => bool)=?,
      ~scrollEnabled=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Js.Undefined.(
        Props.extendView(
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
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
          {
            "source": fromOption(source),
            "style": fromOption(style),
            "automaticallyAdjustContentInsets":
              fromOption(automaticallyAdjustContentInsets),
            "contentInsets": fromOption(contentInsets),
            "injectJavaScript": fromOption(injectJavaScript),
            "injectedJavaScript": fromOption(injectedJavaScript),
            "mediaPlaybackRequiresUserAction":
              fromOption(mediaPlaybackRequiresUserAction),
            "onError": fromOption(onError),
            "onLoad": fromOption(onLoad),
            "onLoadEnd": fromOption(onLoadEnd),
            "onLoadStart": fromOption(onLoadStart),
            "onMessage": fromOption(onMessage),
            "onNavigationStateChange": fromOption(onNavigationStateChange),
            "renderError": fromOption(renderError),
            "renderLoading": fromOption(renderLoading),
            "scalesPageToFit": fromOption(scalesPageToFit),
            "startInLoadingState": fromOption(startInLoadingState),
            "domStorageEnabled": fromOption(domStorageEnabled),
            "javaScriptEnabled": fromOption(javaScriptEnabled),
            "mixedContentMode":
              fromOption(
                UtilsRN.option_map(
                  contentMode => {
                    let to_string =
                      fun
                      | `never => "never"
                      | `always => "always"
                      | `compatibility => "compatibility";
                    contentMode |> List.map(to_string) |> Array.of_list;
                  },
                  mixedContentMode,
                ),
              ),
            "thirdPartyCookiesEnabled": fromOption(thirdPartyCookiesEnabled),
            "userAgent": fromOption(userAgent),
            "allowsInlineMediaPlayback":
              fromOption(allowsInlineMediaPlayback),
            "bounces": fromOption(bounces),
            "dataDetectorTypes":
              fromOption(
                UtilsRN.option_map(
                  dataDetectorType => {
                    let to_string =
                      fun
                      | `phoneNumber => "phoneNumber"
                      | `link => "link"
                      | `address => "address"
                      | `calendarEvent => "calendarEvent"
                      | `none => "none"
                      | `all => "all";
                    dataDetectorType |> List.map(to_string) |> Array.of_list;
                  },
                  dataDetectorTypes,
                ),
              ),
            "decelerationRate":
              fromOption(
                UtilsRN.option_map(
                  rate => {
                    let to_float =
                      fun
                      | `normal => 0.998
                      | `fast => 0.99
                      | `value(f) => f;
                    rate |> List.map(to_float) |> Array.of_list;
                  },
                  decelerationRate,
                ),
              ),
            "onShouldStartLoadWithRequest":
              fromOption(onShouldStartLoadWithRequest),
            "scrollEnabled": fromOption(scrollEnabled),
          },
        )
      ),
  );
