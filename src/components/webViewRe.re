external view : ReasonReact.reactClass = "WebView" [@@bs.module "react-native"];

type source;

external source :
  uri::string? => method::string? => headers::Js.t 'a? => body::string? => unit => source =
  "" [@@bs.obj];

type contentInsets;

external contentInsets :
  top::int? => left::int? => bottom::int? => right::int? => unit => contentInsets =
  "" [@@bs.obj];

let make
    ::accessibilityLabel=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::responderHandlers=?
    ::pointerEvents=?
    ::removeClippedSubviews=?
    ::style=?
    ::testID=?
    ::accessibilityComponentType=?
    ::accessibilityLiveRegion=?
    ::collapsable=?
    ::importantForAccessibility=?
    ::needsOffscreenAlphaCompositing=?
    ::renderToHardwareTextureAndroid=?
    ::accessibilityTraits=?
    ::accessibilityViewIsModal=?
    ::shouldRasterizeIOS=?
    ::automaticallyAdjustContentInsets=?
    ::contentInsets=?
    ::injectJavaScript=?
    ::injectedJavaScript=?
    ::mediaPlaybackRequiresUserAction=?
    ::onError=?
    ::onLoad=?
    ::onLoadEnd=?
    ::onLoadStart=?
    ::onMessage=?
    ::onNavigationStateChange=?
    ::renderError=?
    ::renderLoading=?
    ::scalesPageToFit=?
    ::source=?
    ::startInLoadingState=?
    ::domStorageEnabled=?
    ::javaScriptEnabled=?
    ::mixedContentMode=?
    ::thirdPartyCookiesEnabled=?
    ::userAgent=?
    ::allowsInlineMediaPlayback=?
    ::bounces=?
    ::dataDetectorTypes=?
    ::decelerationRate=?
    ::onShouldStartLoadWithRequest=?
    ::scrollEnabled=? =>
  ReasonReact.wrapJsForReason
    reactClass::view
    props::
      Js.Undefined.(
        Props.extendView
          ::?accessibilityLabel
          ::?accessible
          ::?hitSlop
          ::?onAccessibilityTap
          ::?onLayout
          ::?onMagicTap
          ::?responderHandlers
          ::?pointerEvents
          ::?removeClippedSubviews
          ::?style
          ::?testID
          ::?accessibilityComponentType
          ::?accessibilityLiveRegion
          ::?collapsable
          ::?importantForAccessibility
          ::?needsOffscreenAlphaCompositing
          ::?renderToHardwareTextureAndroid
          ::?accessibilityTraits
          ::?accessibilityViewIsModal
          ::?shouldRasterizeIOS
          {
            "source": from_opt source,
            "style": from_opt style,
            "automaticallyAdjustContentInsets": from_opt automaticallyAdjustContentInsets,
            "contentInsets": from_opt contentInsets,
            "injectJavaScript": from_opt injectJavaScript,
            "injectedJavaScript": from_opt injectedJavaScript,
            "mediaPlaybackRequiresUserAction": from_opt mediaPlaybackRequiresUserAction,
            "onError": from_opt onError,
            "onLoad": from_opt onLoad,
            "onLoadEnd": from_opt onLoadEnd,
            "onLoadStart": from_opt onLoadStart,
            "onMessage": from_opt onMessage,
            "onNavigationStateChange": from_opt onNavigationStateChange,
            "renderError": from_opt renderError,
            "renderLoading": from_opt renderLoading,
            "scalesPageToFit": from_opt scalesPageToFit,
            "startInLoadingState": from_opt startInLoadingState,
            "domStorageEnabled": from_opt domStorageEnabled,
            "javaScriptEnabled": from_opt javaScriptEnabled,
            "mixedContentMode":
              from_opt (
                UtilsRN.option_map
                  (
                    fun contentMode => {
                      let to_string =
                        fun
                        | `never => "never"
                        | `always => "always"
                        | `compatibility => "compatibility";
                      contentMode |> List.map to_string |> Array.of_list
                    }
                  )
                  mixedContentMode
              ),
            "thirdPartyCookiesEnabled": from_opt thirdPartyCookiesEnabled,
            "userAgent": from_opt userAgent,
            "allowsInlineMediaPlayback": from_opt allowsInlineMediaPlayback,
            "bounces": from_opt bounces,
            "dataDetectorTypes":
              from_opt (
                UtilsRN.option_map
                  (
                    fun dataDetectorType => {
                      let to_string =
                        fun
                        | `phoneNumber => "phoneNumber"
                        | `link => "link"
                        | `address => "address"
                        | `calendarEvent => "calendarEvent"
                        | `none => "none"
                        | `all => "all";
                      dataDetectorType |> List.map to_string |> Array.of_list
                    }
                  )
                  dataDetectorTypes
              ),
            "decelerationRate":
              from_opt (
                UtilsRN.option_map
                  (
                    fun rate => {
                      let to_float =
                        fun
                        | `normal => 0.998
                        | `fast => 0.99
                        | `value f => f;
                      rate |> List.map to_float |> Array.of_list
                    }
                  )
                  decelerationRate
              ),
            "onShouldStartLoadWithRequest": from_opt onShouldStartLoadWithRequest,
            "scrollEnabled": from_opt scrollEnabled
          }
      );