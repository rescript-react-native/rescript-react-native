module type ScrollViewComponent = {
  type point = {
    x: float,
    y: float
  };
  let scrollTo: (ReasonReact.reactRef, ~x: int, ~y: int, ~animated: bool) => unit;
  let scrollToEnd: (ReasonReact.reactRef, ~animated: bool) => unit;
  let make:
    (
      ~accessibilityLabel: ReasonReact.reactElement=?,
      ~accessible: bool=?,
      ~hitSlop: TypesRN.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: Props.touchResponderHandlers=?,
      ~pointerEvents: [ | `auto | `boxNone | `boxOnly | `none]=?,
      ~removeClippedSubviews: bool=?,
      ~style: Style.t=?,
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
      ~importantForAccessibility: [ | `auto | `no | `noHideDescendants | `yes]=?,
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
                              ]
                            )
                              =?,
      ~accessibilityViewIsModal: bool=?,
      ~shouldRasterizeIOS: bool=?,
      ~contentContainerStyle: Style.t=?,
      ~horizontal: bool=?,
      ~keyboardDismissMode: [ | `interactive | `none | `onDrag]=?,
      ~keyboardShouldPersistTaps: [ | `always | `handled | `never]=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
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
      ~contentInset: TypesRN.insets=?,
      ~contentOffset: point=?,
      ~decelerationRate: [ | `fast | `normal]=?,
      ~directionalLockEnabled: bool=?,
      ~indicatorStyle: [ | `black | `default | `white]=?,
      ~maximumZoomScale: float=?,
      ~mimimumZoomScale: float=?,
      ~onScrollAnimationEnd: unit => unit=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: TypesRN.insets=?,
      ~scrollsToTop: bool=?,
      ~snapToAlignment: [ | `center | `end_ | `start]=?,
      ~zoomScale: float=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);
};

module CreateComponent: (Impl: ViewRe.Impl) => ScrollViewComponent;

module ScrollView: ScrollViewComponent;
