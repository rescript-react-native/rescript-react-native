

import * as List from "bs-platform/lib/es6/list.js";
import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

var EventTypes = /* module */[];

function source(prim, prim$1, prim$2, prim$3, prim$4) {
  var tmp = { };
  if (prim !== undefined) {
    tmp.uri = Caml_option.valFromOption(prim);
  }
  if (prim$1 !== undefined) {
    tmp.method = Caml_option.valFromOption(prim$1);
  }
  if (prim$2 !== undefined) {
    tmp.headers = Caml_option.valFromOption(prim$2);
  }
  if (prim$3 !== undefined) {
    tmp.body = Caml_option.valFromOption(prim$3);
  }
  return tmp;
}

function make(source, style, renderError, renderLoading, onError, onLoad, onLoadEnd, onLoadStart, automaticallyAdjustContentInsets, contentInsets, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, injectJavaScript, injectedJavaScript, mediaPlaybackRequiresUserAction, onMessage, onNavigationStateChange, scalesPageToFit, startInLoadingState, domStorageEnabled, javaScriptEnabled, mixedContentMode, thirdPartyCookiesEnabled, userAgent, allowsInlineMediaPlayback, bounces, dataDetectorTypes, decelerationRate, onShouldStartLoadWithRequest, scrollEnabled) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        source: source,
        style: style,
        automaticallyAdjustContentInsets: automaticallyAdjustContentInsets,
        contentInsets: contentInsets,
        injectJavaScript: injectJavaScript,
        injectedJavaScript: injectedJavaScript,
        mediaPlaybackRequiresUserAction: mediaPlaybackRequiresUserAction,
        onError: onError,
        onLoad: onLoad,
        onLoadEnd: onLoadEnd,
        onLoadStart: onLoadStart,
        onMessage: onMessage,
        onNavigationStateChange: onNavigationStateChange,
        renderError: renderError,
        renderLoading: renderLoading,
        scalesPageToFit: scalesPageToFit,
        startInLoadingState: startInLoadingState,
        domStorageEnabled: domStorageEnabled,
        javaScriptEnabled: javaScriptEnabled,
        mixedContentMode: Belt_Option.map(mixedContentMode, (function (contentMode) {
                var to_string = function (param) {
                  if (param !== -853883856) {
                    if (param >= 422592140) {
                      return "never";
                    } else {
                      return "always";
                    }
                  } else {
                    return "compatibility";
                  }
                };
                return $$Array.of_list(List.map(to_string, contentMode));
              })),
        thirdPartyCookiesEnabled: thirdPartyCookiesEnabled,
        userAgent: userAgent,
        allowsInlineMediaPlayback: allowsInlineMediaPlayback,
        bounces: bounces,
        dataDetectorTypes: Belt_Option.map(dataDetectorTypes, (function (dataDetectorType) {
                var to_string = function (param) {
                  if (param >= -922086728) {
                    if (param >= 4847905) {
                      if (param >= 487289268) {
                        return "address";
                      } else {
                        return "all";
                      }
                    } else if (param >= -119363460) {
                      return "calendarEvent";
                    } else {
                      return "none";
                    }
                  } else if (param >= -940571433) {
                    return "phoneNumber";
                  } else {
                    return "link";
                  }
                };
                return $$Array.of_list(List.map(to_string, dataDetectorType));
              })),
        decelerationRate: Belt_Option.map(decelerationRate, (function (rate) {
                var to_float = function (param) {
                  if (typeof param === "number") {
                    if (param >= 812216871) {
                      return 0.998;
                    } else {
                      return 0.99;
                    }
                  } else {
                    return param[1];
                  }
                };
                return $$Array.of_list(List.map(to_float, rate));
              })),
        onShouldStartLoadWithRequest: onShouldStartLoadWithRequest,
        scrollEnabled: scrollEnabled
      });
  var partial_arg$1 = ReactNative.WebView;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

function sourceUri(prim, prim$1, prim$2, prim$3, prim$4) {
  var tmp = { };
  if (prim !== undefined) {
    tmp.uri = Caml_option.valFromOption(prim);
  }
  if (prim$1 !== undefined) {
    tmp.method = Caml_option.valFromOption(prim$1);
  }
  if (prim$2 !== undefined) {
    tmp.headers = Caml_option.valFromOption(prim$2);
  }
  if (prim$3 !== undefined) {
    tmp.body = Caml_option.valFromOption(prim$3);
  }
  return tmp;
}

function sourceHtml(prim, prim$1, prim$2) {
  var tmp = { };
  if (prim !== undefined) {
    tmp.html = Caml_option.valFromOption(prim);
  }
  if (prim$1 !== undefined) {
    tmp.baseUrl = Caml_option.valFromOption(prim$1);
  }
  return tmp;
}

function goForward(prim) {
  prim.goForward();
  return /* () */0;
}

function goBack(prim) {
  prim.goBack();
  return /* () */0;
}

function reload(prim) {
  prim.reload();
  return /* () */0;
}

function stopLoading(prim) {
  prim.stopLoading();
  return /* () */0;
}

export {
  EventTypes ,
  sourceUri ,
  sourceHtml ,
  source ,
  goForward ,
  goBack ,
  reload ,
  stopLoading ,
  make ,
  
}
/* ReasonReact Not a pure module */
