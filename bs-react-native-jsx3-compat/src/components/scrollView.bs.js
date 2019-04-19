

import * as Belt_List from "bs-platform/lib/es6/belt_List.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";
import * as ScrollViewProps$BsReactNative from "./ScrollViewProps.bs.js";

function CreateComponent(Impl) {
  var scrollTo = function (ref, x, y, animated) {
    ref.scrollTo({
          x: x,
          y: y,
          animated: animated
        });
    return /* () */0;
  };
  var scrollToEnd = function (ref, animated) {
    ref.scrollToEnd({
          animated: animated
        });
    return /* () */0;
  };
  var make = function (accessibilityLabel, accessible, contentInsetAdjustmentBehavior, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, contentContainerStyle, horizontal, keyboardDismissMode, keyboardShouldPersistTaps, onContentSizeChange, onScroll, onScrollBeginDrag, onScrollEndDrag, onMomentumScrollBegin, onMomentumScrollEnd, pagingEnabled, refreshControl, scrollEnabled, showsHorizontalScrollIndicator, showsVerticalScrollIndicator, stickyHeaderIndices, overScrollMode, scrollPerfTag, alwaysBounceHorizontal, alwaysBounceVertical, automaticallyAdjustContentInsets, bounces, canCancelContentTouches, centerContent, contentInset, contentOffset, decelerationRate, directionalLockEnabled, indicatorStyle, maximumZoomScale, minimumZoomScale, scrollEventThrottle, scrollIndicatorInsets, scrollsToTop, snapToInterval, snapToAlignment, zoomScale) {
    var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
          contentContainerStyle: contentContainerStyle,
          contentInsetAdjustmentBehavior: Belt_Option.map(contentInsetAdjustmentBehavior, ScrollViewProps$BsReactNative.contentInsetAdjustmentBehaviorToJs),
          horizontal: horizontal,
          keyboardDismissMode: Belt_Option.map(keyboardDismissMode, ScrollViewProps$BsReactNative.keyboardDismissModeToJs),
          keyboardShouldPersistTaps: Belt_Option.map(keyboardShouldPersistTaps, ScrollViewProps$BsReactNative.keyboardShouldPersistTapsToJs),
          onContentSizeChange: onContentSizeChange,
          onScroll: onScroll,
          onScrollBeginDrag: onScrollBeginDrag,
          onScrollEndDrag: onScrollEndDrag,
          onMomentumScrollBegin: onMomentumScrollBegin,
          onMomentumScrollEnd: onMomentumScrollEnd,
          pagingEnabled: pagingEnabled,
          refreshControl: refreshControl,
          scrollEnabled: scrollEnabled,
          showsHorizontalScrollIndicator: showsHorizontalScrollIndicator,
          showsVerticalScrollIndicator: showsVerticalScrollIndicator,
          stickyHeaderIndices: Belt_Option.map(stickyHeaderIndices, Belt_List.toArray),
          overScrollMode: Belt_Option.map(overScrollMode, ScrollViewProps$BsReactNative.overScrollModeToJs),
          scrollPerfTag: scrollPerfTag,
          alwaysBounceHorizontal: alwaysBounceHorizontal,
          alwaysBounceVertical: alwaysBounceVertical,
          automaticallyAdjustContentInsets: automaticallyAdjustContentInsets,
          bounces: bounces,
          canCancelContentTouches: canCancelContentTouches,
          centerContent: centerContent,
          contentInset: contentInset,
          contentOffset: Belt_Option.map(contentOffset, (function (param) {
                  return {
                          x: param[/* x */0],
                          y: param[/* y */1]
                        };
                })),
          decelerationRate: Belt_Option.map(decelerationRate, ScrollViewProps$BsReactNative.decelerationRateToJs),
          directionalLockEnabled: directionalLockEnabled,
          indicatorStyle: Belt_Option.map(indicatorStyle, ScrollViewProps$BsReactNative.indicatorStyleToJs),
          maximumZoomScale: maximumZoomScale,
          minimumZoomScale: minimumZoomScale,
          scrollEventThrottle: scrollEventThrottle,
          scrollIndicatorInsets: scrollIndicatorInsets,
          scrollsToTop: scrollsToTop,
          snapToInterval: snapToInterval,
          snapToAlignment: Belt_Option.map(snapToAlignment, ScrollViewProps$BsReactNative.snapToAlignmentToJs),
          zoomScale: zoomScale
        });
    var partial_arg$1 = Impl[/* view */0];
    return (function (param) {
        return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
      });
  };
  return /* module */[
          /* scrollTo */scrollTo,
          /* scrollToEnd */scrollToEnd,
          /* make */make
        ];
}

var Impl = /* module */[/* ScrollView */ReactNative.ScrollView];

function scrollTo(ref, x, y, animated) {
  ref.scrollTo({
        x: x,
        y: y,
        animated: animated
      });
  return /* () */0;
}

function scrollToEnd(ref, animated) {
  ref.scrollToEnd({
        animated: animated
      });
  return /* () */0;
}

function make(accessibilityLabel, accessible, contentInsetAdjustmentBehavior, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, contentContainerStyle, horizontal, keyboardDismissMode, keyboardShouldPersistTaps, onContentSizeChange, onScroll, onScrollBeginDrag, onScrollEndDrag, onMomentumScrollBegin, onMomentumScrollEnd, pagingEnabled, refreshControl, scrollEnabled, showsHorizontalScrollIndicator, showsVerticalScrollIndicator, stickyHeaderIndices, overScrollMode, scrollPerfTag, alwaysBounceHorizontal, alwaysBounceVertical, automaticallyAdjustContentInsets, bounces, canCancelContentTouches, centerContent, contentInset, contentOffset, decelerationRate, directionalLockEnabled, indicatorStyle, maximumZoomScale, minimumZoomScale, scrollEventThrottle, scrollIndicatorInsets, scrollsToTop, snapToInterval, snapToAlignment, zoomScale) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        contentContainerStyle: contentContainerStyle,
        contentInsetAdjustmentBehavior: Belt_Option.map(contentInsetAdjustmentBehavior, ScrollViewProps$BsReactNative.contentInsetAdjustmentBehaviorToJs),
        horizontal: horizontal,
        keyboardDismissMode: Belt_Option.map(keyboardDismissMode, ScrollViewProps$BsReactNative.keyboardDismissModeToJs),
        keyboardShouldPersistTaps: Belt_Option.map(keyboardShouldPersistTaps, ScrollViewProps$BsReactNative.keyboardShouldPersistTapsToJs),
        onContentSizeChange: onContentSizeChange,
        onScroll: onScroll,
        onScrollBeginDrag: onScrollBeginDrag,
        onScrollEndDrag: onScrollEndDrag,
        onMomentumScrollBegin: onMomentumScrollBegin,
        onMomentumScrollEnd: onMomentumScrollEnd,
        pagingEnabled: pagingEnabled,
        refreshControl: refreshControl,
        scrollEnabled: scrollEnabled,
        showsHorizontalScrollIndicator: showsHorizontalScrollIndicator,
        showsVerticalScrollIndicator: showsVerticalScrollIndicator,
        stickyHeaderIndices: Belt_Option.map(stickyHeaderIndices, Belt_List.toArray),
        overScrollMode: Belt_Option.map(overScrollMode, ScrollViewProps$BsReactNative.overScrollModeToJs),
        scrollPerfTag: scrollPerfTag,
        alwaysBounceHorizontal: alwaysBounceHorizontal,
        alwaysBounceVertical: alwaysBounceVertical,
        automaticallyAdjustContentInsets: automaticallyAdjustContentInsets,
        bounces: bounces,
        canCancelContentTouches: canCancelContentTouches,
        centerContent: centerContent,
        contentInset: contentInset,
        contentOffset: Belt_Option.map(contentOffset, (function (param) {
                return {
                        x: param[/* x */0],
                        y: param[/* y */1]
                      };
              })),
        decelerationRate: Belt_Option.map(decelerationRate, ScrollViewProps$BsReactNative.decelerationRateToJs),
        directionalLockEnabled: directionalLockEnabled,
        indicatorStyle: Belt_Option.map(indicatorStyle, ScrollViewProps$BsReactNative.indicatorStyleToJs),
        maximumZoomScale: maximumZoomScale,
        minimumZoomScale: minimumZoomScale,
        scrollEventThrottle: scrollEventThrottle,
        scrollIndicatorInsets: scrollIndicatorInsets,
        scrollsToTop: scrollsToTop,
        snapToInterval: snapToInterval,
        snapToAlignment: Belt_Option.map(snapToAlignment, ScrollViewProps$BsReactNative.snapToAlignmentToJs),
        zoomScale: zoomScale
      });
  var partial_arg$1 = Impl[/* view */0];
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  CreateComponent ,
  scrollTo ,
  scrollToEnd ,
  make ,
  
}
/* Impl Not a pure module */
