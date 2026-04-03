include VirtualizedListElement

module Separators = {
  type t

  type select = [#leading | #trailing]

  @send external highlight: t => unit = "highlight"
  @send external unhighlight: t => unit = "unhighlight"
  @send external updateProps: (t, select, {..}) => unit = "updateProps"
}

type renderItemProps<'item> = {
  item: 'item,
  index: int,
  separators: Separators.t,
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

type onStartReachedParams = {distanceFromStart: float}
type onEndReachedParams = {distanceFromEnd: float}

type onScrollToIndexFailedParams = {
  index: int,
  highestMeasuredFrameIndex: int,
  averageItemLength: float,
}

type separatorComponentProps<'item> = {highlighted: bool, leadingItem: option<'item>}

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

type virtualizedListProps<'data, 'item, 'extraData> = {
  ...ScrollView.scrollViewProps,
  \"CellRendererComponent"?: cellRendererComponent<'item>,
  \"ListEmptyComponent"?: unit => React.element,
  \"ListFooterComponent"?: unit => React.element,
  \"ListFooterComponentStyle"?: Style.t,
  \"ListHeaderComponent"?: unit => React.element,
  \"ListHeaderComponentStyle"?: Style.t,
  debug?: bool,
  disableVirtualization?: bool, // deprecated
  extraData?: 'extraData,
  getItemLayout?: ('data, int) => itemLayout,
  initialNumToRender?: int,
  initialScrollIndex?: int,
  inverted?: bool,
  keyExtractor?: ('item, int) => string,
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
  renderScrollComponent?: ScrollView.scrollViewProps => React.element,
  updateCellsBatchingPeriod?: float,
  viewabilityConfig?: viewabilityConfig,
  viewabilityConfigCallbackPairs?: viewabilityConfigCallbackPairs<'item>,
  windowSize?: int,
}

type coreProps<'data, 'item, 'extraData> = {
  data: 'data, // any collection of 'item
  renderItem: renderItemCallback<'item>,
  \"ItemSeparatorComponent"?: React.component<separatorComponentProps<'item>>,
  ...virtualizedListProps<'data, 'item, 'extraData>,
}

type props<'data, 'item, 'extraData> = {
  ref?: ref,
  ...coreProps<'data, 'item, 'extraData>,
  getItem: ('data, int) => 'item,
  getItemCount: 'data => int,
}

@module("react-native")
external make: React.component<props<'data, 'item, 'extraData>> = "VirtualizedList"
