let scrollToEnd: ReasonReact.reactRef => animated::bool => unit;

let scrollToIndex:
  ReasonReact.reactRef =>
  index::int =>
  animated::Js.boolean? =>
  viewOffset::int? =>
  viewPosition::int? =>
  unit =>
  unit;

let scrollToItem:
  ReasonReact.reactRef =>
  item::'item =>
  animated::Js.boolean? =>
  viewPosition::int? =>
  unit =>
  unit;

let scrollToOffset: ReasonReact.reactRef => offset::int? => animated::Js.boolean? => unit => unit;

external recordInteraction : ReasonReact.reactRef => unit = "" [@@bs.send];

type renderBag 'item = {
  item: 'item,
  index: int
};

type renderItem 'item;

let renderItem: (renderBag 'item => ReasonReact.reactElement) => renderItem 'item;

type separatorComponent 'item;

type separatorProps 'item = {
  highlighted: bool,
  leadingItem: option 'item
};

let separatorComponent:
  (separatorProps 'item => ReasonReact.reactElement) => separatorComponent 'item;

let make:
  data::array 'item =>
  renderItem::renderItem 'item =>
  keyExtractor::('item => int => string) =>
  itemSeparatorComponent::separatorComponent 'item? =>
  bounces::bool? =>
  listFooterComponent::ReasonReact.reactElement? =>
  listHeaderComponent::ReasonReact.reactElement? =>
  columnWrapperStyle::StyleRe.t? =>
  extraData::'any? =>
  getItemLayout::(option (array 'item) => int => Js.t {. length : int, offset : int, index : int})? =>
  horizontal::bool? =>
  initialNumToRender::int? =>
  initialScrollIndex::int? =>
  numColumns::'int? =>
  onEndReached::Js.t {. distanceFromEnd : float}? =>
  onEndReachedThreshold::float? =>
  onRefresh::(unit => unit)? =>
  onViewableItemsChanged::
    Js.t {
      .
      viewableItems :
        array (
          Js.t {
            .
            item : 'item,
            key : string,
            index : Js.undefined int,
            isViewable : Js.boolean,
            section : Js.t {.}
          }
        ),
      changed :
        array (
          Js.t {
            .
            item : 'item,
            key : string,
            index : Js.undefined int,
            isViewable : Js.boolean,
            section : Js.t {.}
          }
        )
    }? =>
  overScrollMode::[ | `auto | `always | `never]? =>
  pagingEnabled::bool? =>
  refreshing::bool? =>
  removeClippedSubviews::bool? =>
  scrollEnabled::bool? =>
  showsHorizontalScrollIndicator::bool? =>
  showsVerticalScrollIndicator::bool? =>
  viewabilityConfig::Js.t {.}? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps unit;
