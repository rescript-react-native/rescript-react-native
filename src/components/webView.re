[@bs.module "react-native"] external view : ReasonReact.reactClass = "WebView";

module EventTypes = {
  [@bs.deriving abstract]
  type t = {
    url: string,
    title: string,
    loading: bool,
    canGoBack: bool,
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
external sourceUri :
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
external sourceHtml : (~html: string=?, ~baseUrl: string=?, unit) => source =
  "";

let source = sourceUri;

type contentInsets;

[@bs.obj]
external contentInsets :
  (~top: int=?, ~left: int=?, ~bottom: int=?, ~right: int=?, unit) =>
  contentInsets =
  "";

[@bs.send] external goForward : ReasonReact.reactRef => unit = "";

[@bs.send] external goBack : ReasonReact.reactRef => unit = "";

[@bs.send] external reload : ReasonReact.reactRef => unit = "";

[@bs.send] external stopLoading : ReasonReact.reactRef => unit = "";

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