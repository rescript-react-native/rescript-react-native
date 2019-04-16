---
id: components/ScrollView
title: ScrollView
wip: true
---

```reason
type element;
type ref = React.Ref.t(Js.nullable(element));

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // ScrollView props
    ~alwaysBounceHorizontal: bool=?,
    ~alwaysBounceVertical: bool=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~bounces: bool=?,
    ~bouncesZoom: bool=?,
    ~canCancelContentTouches: bool=?,
    ~centerContent: bool=?,
    ~contentContainerStyle: Style.t=?,
    ~contentInset: Types.insets=?,
    ~contentInsetAdjustmentBehavior: [@bs.string] [
                                       | `automatic
                                       | `scrollableAxes
                                       | `never
                                       | `always
                                     ]
                                       =?,
    ~contentOffset: Types.point=?,
    ~decelerationRate: [@bs.string] [ | `fast | `normal]=?,
    ~directionalLockEnabled: bool=?,
    ~endFillColor: Style.color=?,
    ~horizontal: bool=?,
    ~indicatorStyle: [@bs.string] [ | `default | `black | `white]=?,
    ~keyboardDismissMode: [@bs.string] [ | `none | `interactive | `onDrag]=?,
    ~keyboardShouldPersistTaps: [@bs.string] [ | `always | `never | `handled]=?,
    ~maximumZoomScale: float=?,
    ~minimumZoomScale: float=?,
    ~nestedScrollEnabled: bool=?,
    ~onContentSizeChange: ((float, float)) => unit=?,
    ~onMomentumScrollBegin: Event.NativeScrollEvent.t => unit=?,
    ~onMomentumScrollEnd: Event.NativeScrollEvent.t => unit=?,
    ~onScroll: Event.NativeScrollEvent.t => unit=?,
    ~onScrollBeginDrag: Event.NativeScrollEvent.t => unit=?,
    ~onScrollEndDrag: Event.NativeScrollEvent.t => unit=?,
    ~overScrollMode: [@bs.string] [ | `always | `never | `auto]=?,
    ~pagingEnabled: bool=?,
    ~refreshControl: React.element=?,
    ~scrollEnabled: bool=?,
    ~scrollEventThrottle: int=?,
    ~scrollIndicatorInsets: Types.insets=?,
    ~scrollPerfTag: string=?,
    ~scrollsToTop: bool=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~snapToAlignment: [@bs.string] [ | `start | `center | `end_]=?,
    ~snapToEnd: bool=?,
    ~snapToInterval: float=?,
    ~snapToOffsets: array(float)=?,
    ~snapToStart: bool=?,
    ~stickyHeaderIndices: list(int)=?,
    ~zoomScale: float=?,
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
    ~hitSlop: Types.insets=?,
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
    ~onLayout: Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.t => bool=?,
    ~onMoveShouldSetResponderCapture: Event.t => bool=?,
    ~onResponderGrant: Event.t => unit=?,
    ~onResponderMove: Event.t => unit=?,
    ~onResponderReject: Event.t => unit=?,
    ~onResponderRelease: Event.t => unit=?,
    ~onResponderTerminate: Event.t => unit=?,
    ~onResponderTerminationRequest: Event.t => unit=?,
    ~onStartShouldSetResponder: Event.t => bool=?,
    ~onStartShouldSetResponderCapture: Event.t => bool=?,
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
    ~testID: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "ScrollView";

type scrollToParams;
[@bs.obj]
external scrollToParams:
  (~x: float, ~y: float, ~animated: bool=?, ~duration: float=?, unit) =>
  scrollToParams =
  "";
[@bs.send] external scrollTo: scrollToParams => unit = "";

type scrollToEndOptions;
[@bs.obj]
external scrollToEndOptions:
  (~animated: bool=?, ~duration: float=?, unit) => scrollToEndOptions =
  "";
[@bs.send] external scrollToEnd: ref => unit = "scrollToEnd";
[@bs.send]
external scrollToEndWithOptions: (ref, scrollToEndOptions) => unit =
  "scrollToEnd";

[@bs.send] external flashScrollIndicators: ref => unit = "";
```
