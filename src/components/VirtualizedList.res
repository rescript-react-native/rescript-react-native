include VirtualizedListElement

type renderItemProps<'item> = {
  item: 'item,
  index: int,
  // separators: TODO
}

type renderItemCallback<'item> = renderItemProps<'item> => React.element

// TODO
type cellRendererComponentProps<'item> = {.}
type cellRendererComponent<'item> = React.component<cellRendererComponentProps<'item>>

type viewableItem<'item> = {
  item: 'item,
  key: string,
  index: Js.undefined<int>,
  isViewable: bool,
  section: {.},
}

type viewableItemsChanged<'item> = {
  viewableItems: array<viewableItem<'item>>,
  changed: array<viewableItem<'item>>,
}

type itemLayout = {
  length: float,
  offset: float,
  index: int,
}

type onStartReachedParams = {distanceFromEnd: float}
type onEndReachedParams = {distanceFromEnd: float}

type onScrollToIndexFailedInfo = {
  index: int,
  highestMeasuredFrameIndex: int,
  averageItemLength: float,
}

type onScrollToIndexFailedParams = {info: onScrollToIndexFailedInfo}

type viewabilityConfig = {
  minimumViewTime?: float,
  viewAreaCoveragePercentThreshold?: float,
  itemVisiblePercentThreshold?: float,
  waitForInteraction?: bool,
}

type viewabilityConfigCallbackPair<'item> = {
  viewabilityConfig: viewabilityConfig,
  onViewableItemsChanged: viewableItemsChanged<'item> => unit,
}

type viewabilityConfigCallbackPairs<'item> = array<viewabilityConfigCallbackPair<'item>>

type virtualizedListCoreProps<'data, 'item, 'extraData> = {
  ...ScrollView.scrollViewProps,
  \"CellRendererComponent"?: cellRendererComponent<'item>,
  \"ListEmptyComponent"?: unit => React.element,
  \"ListFooterComponent"?: unit => React.element,
  \"ListFooterComponentStyle"?: Style.t,
  \"ListHeaderComponent"?: unit => React.element,
  \"ListHeaderComponentStyle"?: Style.t,
  debug?: bool,
  //data: 'data, // any collection of 'item
  disableVirtualization?: bool, // deprecated
  extraData?: 'extraData,
  getItem: ('data, int) => 'item,
  getItemCount: 'data => int,
  getItemLayout?: ('data, int) => itemLayout,
  initialNumToRender?: int,
  initialScrollIndex?: int,
  inverted?: bool,
  keyExtractor: ('item, int) => string,
  maxToRenderPerBatch?: int,
  onStartReached?: onStartReachedParams => unit,
  onStartReachedThreshold?: float,
  onEndReached?: onEndReachedParams => unit,
  onEndReachedThreshold?: float,
  onRefresh?: unit => unit,
  onScrollToIndexFailed?: onScrollToIndexFailedParams => unit,
  onViewableItemsChanged?: viewableItemsChanged<'item> => unit,
  progressViewOffset?: float,
  refreshing?: bool,
  //renderItem: renderItemCallback<'item>,
  renderScrollComponent?: unit => React.element, // TODO?: params?
  updateCellsBatchingPeriod?: float,
  viewabilityConfig?: viewabilityConfig,
  viewabilityConfigCallbackPairs?: viewabilityConfigCallbackPairs<'item>,
  windowSize?: int,
}

type virtualizedListProps<'data, 'item, 'extraData> = {
  ...virtualizedListCoreProps<'data, 'item, 'extraData>,
  data: 'data, // any collection of 'item
  renderItem: renderItemCallback<'item>,
}

@react.component(: virtualizedListProps<'data, 'item, 'extraData>) @module("react-native")
external make: virtualizedListProps<'data, 'item, 'extraData> => React.element = "VirtualizedList"
