include VirtualizedSectionListElement;

type renderItemProps('item, 'sectionData) = {
  item: 'item,
  index: int,
  section: section('item, 'sectionData),
  separators,
}
and section('item, 'sectionData) = {
  data: array('item),
  key: option(string),
  renderItem: option(renderItemCallback('item, 'sectionData)),
  [@bs.as "ItemSeparatorComponent"]
  itemSeparatorComponent: option(unit => React.element),
  keyExtractor: option(('item, int) => string),
  sectionData: option('sectionData),
}
and separators = {
  highlight: unit => unit,
  unhighlight: unit => unit,
}
and renderItemCallback('item, 'sectionData) =
  renderItemProps('item, 'sectionData) => React.element;

type renderSectionHeaderCallback('item, 'sectionData) =
  renderSectionHeaderProps('item, 'sectionData) => React.element
and renderSectionHeaderProps('item, 'sectionData) = {
  section: section('item, 'sectionData),
};

type separatorProps('item, 'sectionData) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item, 'sectionData)),
  section: section('item, 'sectionData),
  trailingItem: option('item),
  trailingSection: option(section('item, 'sectionData)),
};

[@bs.obj]
external section:
  (
    ~data: array('item),
    ~key: string=?,
    ~renderItem: renderItemCallback('item, 'sectionData)=?,
    ~_ItemSeparatorComponent: unit => React.element=?,
    ~keyExtractor: ('item, int) => string=?,
    ~sectionData: 'sectionData=?,
    unit
  ) =>
  section('item, 'sectionData);

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // VirtualizedSectionList props
    ~_ItemSeparatorComponent: separatorProps('item, 'sectionData) =>
                              React.element
                                =?,
    ~_SectionSeparatorComponent: separatorProps('item, 'sectionData) =>
                                 React.element
                                   =?,
    ~renderItem: renderItemCallback('item, 'sectionData),
    ~renderSectionFooter: renderSectionHeaderCallback('item, 'sectionData)=?,
    ~renderSectionHeader: renderSectionHeaderCallback('item, 'sectionData)=?,
    ~sections: array(section('item, 'sectionData)),
    ~stickySectionHeadersEnabled: bool=?,
    // VirtualizedList props
    ~_CellRendererComponent: VirtualizedList.cellRendererComponent('item)=?,
    ~_ListEmptyComponent: unit => React.element=?,
    ~_ListFooterComponent: unit => React.element=?,
    ~_ListFooterComponentStyle: Style.t=?,
    ~_ListHeaderComponent: unit => React.element=?,
    ~_ListHeaderComponentStyle: Style.t=?,
    ~debug: bool=?,
    // ~enableVirtualization: bool=?, // not working, disableVirtualization?
    // ~data: 'data, // any collection of 'item
    ~disableVirtualization: bool=?, // deprecated
    ~extraData: 'extraData=?,
    ~getItem: ('data, int) => 'item=?,
    ~getItemCount: 'data => int=?,
    ~getItemLayout: ('data, int) => VirtualizedList.itemLayout=?,
    ~initialNumToRender: int=?,
    ~initialScrollIndex: int=?,
    ~inverted: bool=?,
    ~keyExtractor: ('item, int) => string,
    ~maxToRenderPerBatch: int=?,
    ~onEndReached: VirtualizedList.onEndReachedParams => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onRefresh: unit => unit=?,
    ~onScrollToIndexFailed: VirtualizedList.onScrollToIndexFailedParams => unit
                              =?,
    ~onViewableItemsChanged: VirtualizedList.viewableItemsChanged('item) =>
                             unit
                               =?,
    ~progressViewOffset: float=?,
    ~refreshing: bool=?,
    // ~renderItem: VirtualizedList.renderItemCallback('item),
    ~renderScrollComponent: unit => React.element=?, // TODO: params?
    ~updateCellsBatchingPeriod: float=?,
    ~viewabilityConfig: VirtualizedList.viewabilityConfig=?,
    ~viewabilityConfigCallbackPairs: VirtualizedList.viewabilityConfigCallbackPairs(
                                       'item,
                                     )
                                       =?,
    ~windowSize: int=?,
    // ScrollView props
    ~alwaysBounceHorizontal: bool=?,
    ~alwaysBounceVertical: bool=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~bounces: bool=?,
    ~bouncesZoom: bool=?,
    ~canCancelContentTouches: bool=?,
    ~centerContent: bool=?,
    ~contentContainerStyle: Style.t=?,
    ~contentInset: View.edgeInsets=?,
    ~contentInsetAdjustmentBehavior: [@bs.string] [
                                       | `automatic
                                       | `scrollableAxes
                                       | `never
                                       | `always
                                     ]
                                       =?,
    ~contentOffset: ScrollView.contentOffset=?,
    ~decelerationRate: [@bs.string] [ | `fast | `normal]=?,
    ~directionalLockEnabled: bool=?,
    ~endFillColor: Color.t=?,
    ~fadingEdgeLength: float=?,
    ~horizontal: bool=?,
    ~indicatorStyle: [@bs.string] [ | `default | `black | `white]=?,
    ~keyboardDismissMode: [@bs.string] [
                            | `none
                            | `interactive
                            | [@bs.as "on-drag"] `onDrag
                          ]
                            =?,
    ~keyboardShouldPersistTaps: [@bs.string] [ | `always | `never | `handled]=?,
    ~maximumZoomScale: float=?,
    ~minimumZoomScale: float=?,
    ~nestedScrollEnabled: bool=?,
    ~onContentSizeChange: ((float, float)) => unit=?,
    ~onMomentumScrollBegin: Event.scrollEvent => unit=?,
    ~onMomentumScrollEnd: Event.scrollEvent => unit=?,
    ~onScroll: Event.scrollEvent => unit=?,
    ~onScrollBeginDrag: Event.scrollEvent => unit=?,
    ~onScrollEndDrag: Event.scrollEvent => unit=?,
    ~overScrollMode: [@bs.string] [ | `always | `never | `auto]=?,
    ~pagingEnabled: bool=?,
    ~pinchGestureEnabled: bool=?,
    ~refreshControl: React.element=?,
    ~scrollEnabled: bool=?,
    ~scrollEventThrottle: int=?,
    ~scrollIndicatorInsets: View.edgeInsets=?,
    ~scrollPerfTag: string=?,
    ~scrollsToTop: bool=?,
    ~scrollToOverflowEnabled: bool=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~snapToAlignment: [@bs.string] [ | `start | `center | `end_]=?,
    ~snapToEnd: bool=?,
    ~snapToInterval: float=?,
    ~snapToOffsets: array(float)=?,
    ~snapToStart: bool=?,
    ~stickyHeaderIndices: array(int)=?,
    ~zoomScale: float=?,
    // View props 0.62.0
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
                          | `article
                          | `banner
                          | `complementary
                          | `contentinfo
                          | `form
                          | `list
                          | `listitem
                          | `main
                          | `navigation
                          | `region
                        ]
                          =?,
    ~accessibilityState: Accessibility.state=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~accessibilityValue: Accessibility.value=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: View.edgeInsets=?,
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
    ~onAccessibilityEscape: unit => unit=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderEnd: Event.pressEvent => unit=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderStart: Event.pressEvent => unit=?,
    ~onResponderTerminate: Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: Event.pressEvent => bool=?,
    ~onStartShouldSetResponder: Event.pressEvent => bool=?,
    ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
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
    ~children: React.element=?,
    // React Native Web Props
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseMove: ReactEvent.Mouse.t => unit=?,
    ~onMouseOver: ReactEvent.Mouse.t => unit=?,
    ~onMouseOut: ReactEvent.Mouse.t => unit=?,
    ~onMouseUp: ReactEvent.Mouse.t => unit=?
  ) =>
  React.element =
  "VirtualizedSectionList";
