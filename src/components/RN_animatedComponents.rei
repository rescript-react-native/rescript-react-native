module View: RN_view.ViewComponent;

module Image: RN_image.ImageComponent;

module Text: RN_text.TextComponent;

module FlatList: RN_flatList.FlatListComponent;

module ScrollView: {
  let onScrollUpdater:
    (
      ~x: 'a=?,
      ~y: 'b=?,
      ~native: bool=?,
      unit,
      RN_Event.NativeScrollEvent.t
    ) =>
    unit;
  type point = {
    x: float,
    y: float,
  };
  let scrollTo:
    (ReasonReact.reactRef, ~x: int, ~y: int, ~animated: bool) => unit;
  let scrollToEnd: (ReasonReact.reactRef, ~animated: bool) => unit;
  let make:
    (
      ~accessibilityLabel: ReasonReact.reactElement=?,
      ~accessible: bool=?,
      ~hitSlop: RN_types.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: RN_types.touchResponderHandlers=?,
      ~pointerEvents: [ | `auto | `boxNone | `boxOnly | `none]=?,
      ~removeClippedSubviews: bool=?,
      ~style: RN_style.t=?,
      ~testID: string=?,
      ~accessibilityComponentType: [
                                     | `button
                                     | `none
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityLiveRegion: [ | `assertive | `none | `polite]=?,
      ~collapsable: bool=?,
      ~importantForAccessibility: [ | `auto | `no | `noHideDescendants | `yes]
                                    =?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~accessibilityTraits: list(
                              [
                                | `adjustable
                                | `allowsDirectInteraction
                                | `button
                                | `disabled
                                | `frequentUpdates
                                | `header
                                | `image
                                | `key
                                | `link
                                | `none
                                | `pageTurn
                                | `plays
                                | `search
                                | `selected
                                | `startsMedia
                                | `summary
                                | `text
                              ],
                            )
                              =?,
      ~accessibilityViewIsModal: bool=?,
      ~shouldRasterizeIOS: bool=?,
      ~contentContainerStyle: RN_style.t=?,
      ~horizontal: bool=?,
      ~keyboardDismissMode: [ | `interactive | `none | `onDrag]=?,
      ~keyboardShouldPersistTaps: [ | `always | `handled | `never]=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onScroll: RN_Event.NativeScrollEvent.t => unit=?,
      ~pagingEnabled: bool=?,
      ~refreshControl: ReasonReact.reactElement=?,
      ~scrollEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~stickyHeaderIndices: list(int)=?,
      ~overScrollMode: [ | `always | `auto | `never]=?,
      ~scrollPerfTag: string=?,
      ~alwaysBounceHorizontal: bool=?,
      ~alwaysBounceVertical: bool=?,
      ~automaticallyAdjustContentInsets: bool=?,
      ~bounces: bool=?,
      ~canCancelContentTouches: bool=?,
      ~centerContent: bool=?,
      ~contentInset: RN_types.insets=?,
      ~contentOffset: point=?,
      ~decelerationRate: [ | `fast | `normal]=?,
      ~directionalLockEnabled: bool=?,
      ~indicatorStyle: [ | `black | `default | `white]=?,
      ~maximumZoomScale: float=?,
      ~minimumZoomScale: float=?,
      ~onScrollAnimationEnd: unit => unit=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: RN_types.insets=?,
      ~scrollsToTop: bool=?,
      ~snapToAlignment: [ | `center | `end_ | `start]=?,
      ~zoomScale: float=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};