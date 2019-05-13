module EventTypes = {
  type t = ReactNative.WebView.webViewEvent;
};

type iOSLoadRequestEvent = ReactNative.WebView.request;

type source = ReactNative.WebView.Source.t;

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

[@react.component]
let make =
    (
      ~source: option(source)=?,
      ~style: option(Style.t)=?,
      ~renderError: option(unit => ReasonReact.reactElement)=?,
      ~renderLoading: option(unit => ReasonReact.reactElement)=?,
      ~onError: option(EventTypes.t => unit)=?,
      ~onLoad: option(EventTypes.t => unit)=?,
      ~onLoadEnd: option(EventTypes.t => unit)=?,
      ~onLoadStart: option(EventTypes.t => unit)=?,
      ~automaticallyAdjustContentInsets: option(bool)=?,
      ~contentInsets: option(Types.insets)=?,
      ~accessibilityLabel: option(string)=?,
      ~accessible: option(bool)=?,
      ~hitSlop: option(Types.insets)=?,
      ~onAccessibilityTap: option(unit => unit)=?,
      ~onLayout: option(RNEvent.NativeLayoutEvent.t => unit)=?,
      ~onMagicTap: option(unit => unit)=?,
      ~responderHandlers: option(Types.touchResponderHandlers)=?,
      ~pointerEvents: option(Types.pointerEvents)=?,
      ~removeClippedSubviews: option(bool)=?,
      ~testID: option(string)=?,
      ~accessibilityComponentType: option(Types.accessibilityComponentType)=?,
      ~accessibilityLiveRegion: option(Types.accessibilityLiveRegion)=?,
      ~collapsable: option(bool)=?,
      ~importantForAccessibility: option(Types.importantForAccessibility)=?,
      ~needsOffscreenAlphaCompositing: option(bool)=?,
      ~renderToHardwareTextureAndroid: option(bool)=?,
      ~accessibilityTraits: option(list(Types.accessibilityTrait))=?,
      ~accessibilityRole: option(Types.accessibilityRole)=?,
      ~accessibilityStates: option(list(Types.accessibilityState))=?,
      ~accessibilityHint: option(string)=?,
      ~accessibilityIgnoresInvertColors: option(bool)=?,
      ~accessibilityViewIsModal: option(bool)=?,
      ~shouldRasterizeIOS: option(bool)=?,
      ~injectJavaScript: option(string => unit)=?,
      ~injectedJavaScript: option(string)=?,
      ~mediaPlaybackRequiresUserAction: option(bool)=?,
      ~onMessage: option(ReactNative.WebView.messageEvent => unit)=?,
      ~onNavigationStateChange: option(EventTypes.t => unit)=?,
      ~scalesPageToFit: option(bool)=?,
      ~startInLoadingState: option(bool)=?,
      ~domStorageEnabled: option(bool)=?,
      ~javaScriptEnabled: option(bool)=?,
      ~mixedContentMode: option(list([ | `never | `always | `compatibility]))=?,
      ~thirdPartyCookiesEnabled: option(bool)=?,
      ~userAgent: option(string)=?,
      ~allowsInlineMediaPlayback: option(bool)=?,
      ~bounces: option(bool)=?,
      ~dataDetectorTypes:
         option(
           list(
             [
               | `phoneNumber
               | `link
               | `address
               | `calendarEvent
               | `none
               | `all
             ],
           ),
         )=?,
      ~decelerationRate: option(list([ | `normal | `fast | `value(float)]))=?,
      ~onShouldStartLoadWithRequest: option(iOSLoadRequestEvent => bool)=?,
      ~scrollEnabled: option(bool)=?,
    ) =>
  <ReactNative.WebView
    ?source
    ?automaticallyAdjustContentInsets
    contentInsets=?{Types.toEdgeInsets(contentInsets)}
    ?injectJavaScript
    ?injectedJavaScript
    ?mediaPlaybackRequiresUserAction
    ?onError
    ?onLoad
    ?onLoadEnd
    ?onLoadStart
    ?onMessage
    ?onNavigationStateChange
    renderError=?{renderError->Belt.Option.map((cb, _) => cb())}
    ?renderLoading
    ?scalesPageToFit
    ?startInLoadingState
    ?domStorageEnabled
    ?javaScriptEnabled
    mixedContentMode=?{
      mixedContentMode->Belt.Option.flatMap(mixedContentMode =>
        mixedContentMode->Belt.List.head
      )
    }
    ?thirdPartyCookiesEnabled
    ?userAgent
    ?allowsInlineMediaPlayback
    ?bounces
    dataDetectorTypes=?{
      dataDetectorTypes->Belt.Option.map(dataDetectorTypes =>
        dataDetectorTypes
        ->Belt.List.map(
            fun
            | `address => ReactNative.WebView.DataDetectorTypes.address
            | `all => ReactNative.WebView.DataDetectorTypes.all
            | `calendarEvent => ReactNative.WebView.DataDetectorTypes.calendarEvent
            | `link => ReactNative.WebView.DataDetectorTypes.link
            | `none => ReactNative.WebView.DataDetectorTypes.none
            | `phoneNumber => ReactNative.WebView.DataDetectorTypes.phoneNumber,
          )
        ->Belt.List.toArray
      )
    }
    decelerationRate=?{
      decelerationRate->Belt.Option.flatMap(decelerationRate =>
        decelerationRate
        ->Belt.List.map(
            fun
            | `fast => ReactNative.WebView.DecelerationRate.fast
            | `normal => ReactNative.WebView.DecelerationRate.normal
            | `value(f) => ReactNative.WebView.DecelerationRate.value(f),
          )
        ->Belt.List.head
      )
    }
    ?onShouldStartLoadWithRequest
    ?scrollEnabled
    ?accessibilityLabel
    ?accessible
    hitSlop=?{Types.toEdgeInsets(hitSlop)}
    ?onAccessibilityTap
    ?onLayout
    ?onMagicTap
    onMoveShouldSetResponder=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onMoveShouldSetResponder->Belt.Option.map((g, x) => g(x))
        )
      )
    onMoveShouldSetResponderCapture=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onMoveShouldSetResponderCapture
          ->Belt.Option.map((g, x) => g(x))
        )
      )
    onResponderGrant=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderGrant
        )
      )
    onResponderMove=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderMove
        )
      )
    onResponderReject=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderReject
        )
      )
    onResponderRelease=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderRelease
        )
      )
    onResponderTerminate=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderTerminate
        )
      )
    onResponderTerminationRequest=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderTerminationRequest
        )
      )
    onStartShouldSetResponder=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onStartShouldSetResponder->Belt.Option.map((g, x) => g(x))
        )
      )
    onStartShouldSetResponderCapture=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onStartShouldSetResponderCapture
          ->Belt.Option.map((g, x) => g(x))
        )
      )
    ?pointerEvents
    ?removeClippedSubviews
    ?style
    ?testID
    ?accessibilityComponentType
    ?accessibilityLiveRegion
    ?collapsable
    ?importantForAccessibility
    ?needsOffscreenAlphaCompositing
    ?renderToHardwareTextureAndroid
    accessibilityTraits=?{
      accessibilityTraits->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityRole
    accessibilityStates=?{
      accessibilityStates->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityHint
    ?accessibilityIgnoresInvertColors
    ?accessibilityViewIsModal
    ?shouldRasterizeIOS
  />;
