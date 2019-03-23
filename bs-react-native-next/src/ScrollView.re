[@react.component] [@bs.module "react-native"]
external make:
  (
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
    ~accessibilityLabel: React.element=?,
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
    ~accessibilityStates: array(Types.AccessibilityState.t)=?,
    ~accessibilityTraits: array(Types.AccessibilityTrait.t)=?,
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
    ~onMoveShouldSetResponder: Event.NativeEvent.t => bool=?,
    ~onMoveShouldSetResponderCapture: Event.NativeEvent.t => bool=?,
    ~onResponderGrant: Event.NativeEvent.t => unit=?,
    ~onResponderMove: Event.NativeEvent.t => unit=?,
    ~onResponderReject: Event.NativeEvent.t => unit=?,
    ~onResponderRelease: Event.NativeEvent.t => unit=?,
    ~onResponderTerminate: Event.NativeEvent.t => unit=?,
    ~onResponderTerminationRequest: Event.NativeEvent.t => unit=?,
    ~onStartShouldSetResponder: Event.NativeEvent.t => bool=?,
    ~onStartShouldSetResponderCapture: Event.NativeEvent.t => bool=?,
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
[@bs.send] external scrollToEnd: React.Ref.domRef => unit = "scrollToEnd";
[@bs.send]
external scrollToEndWithOptions: (React.Ref.domRef, scrollToEndOptions) => unit =
  "scrollToEnd";

[@bs.send] external flashScrollIndicators: React.Ref.domRef => unit = "";
