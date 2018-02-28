[@bs.module "react-native"] external view : ReasonReact.reactClass = "WebView";

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
      ~scrollEnabled=?
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
            "onError": fromOption(UtilsRN.option_map((callback) => {
              (params) => {
                callback({
                  "url": params##url |> Js.toOption,
                  "title": params##title |> Js.toOption,
                  "loading": params##loading |> Js.toOption,
                  "canGoBack": params##canGoBack |> Js.toOption,
                  "canGoForward": params##canGoForward |> Js.toOption
                });
              }
            }, onError)),
            "onLoad": fromOption(UtilsRN.option_map((callback) => {
              (params) => {
                callback({
                  "url": params##url |> Js.toOption,
                  "title": params##title |> Js.toOption,
                  "loading": params##loading |> Js.toOption,
                  "canGoBack": params##canGoBack |> Js.toOption,
                  "canGoForward": params##canGoForward |> Js.toOption
                });
              }
            }, onLoad)),
            "onLoadEnd": fromOption(UtilsRN.option_map((callback) => {
              (params) => {
                callback({
                  "url": params##url |> Js.toOption,
                  "title": params##title |> Js.toOption,
                  "loading": params##loading |> Js.toOption,
                  "canGoBack": params##canGoBack |> Js.toOption,
                  "canGoForward": params##canGoForward |> Js.toOption
                });
              }
            }, onLoadEnd)),
            "onLoadStart": fromOption(UtilsRN.option_map((callback) => {
              (params) => {
                callback({
                  "url": params##url |> Js.toOption,
                  "title": params##title |> Js.toOption,
                  "loading": params##loading |> Js.toOption,
                  "canGoBack": params##canGoBack |> Js.toOption,
                  "canGoForward": params##canGoForward |> Js.toOption
                });
              }
            }, onLoadStart)),
            "onMessage": fromOption(onMessage),
            "onNavigationStateChange": fromOption(UtilsRN.option_map((callback) => {
              (params) => {
                callback({
                  "url": params##url |> Js.toOption,
                  "title": params##title |> Js.toOption,
                  "loading": params##loading |> Js.toOption,
                  "canGoBack": params##canGoBack |> Js.toOption,
                  "canGoForward": params##canGoForward |> Js.toOption
                });
              }
            }, onNavigationStateChange)),
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
                  mixedContentMode
                )
              ),
            "thirdPartyCookiesEnabled": fromOption(thirdPartyCookiesEnabled),
            "userAgent": fromOption(userAgent),
            "allowsInlineMediaPlayback": fromOption(allowsInlineMediaPlayback),
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
                  dataDetectorTypes
                )
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
                  decelerationRate
                )
              ),
            "onShouldStartLoadWithRequest":
              fromOption(onShouldStartLoadWithRequest),
            "scrollEnabled": fromOption(scrollEnabled)
          }
        )
      )
  );
