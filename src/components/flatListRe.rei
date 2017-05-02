let scrollToEnd: ReactRe.reactRef => animated::bool => unit;

let scrollToIndex:
  ReactRe.reactRef =>
  index::int =>
  animated::Js.boolean? =>
  viewOffset::int? =>
  viewPosition::int? =>
  unit =>
  unit;

let scrollToItem:
  ReactRe.reactRef => item::'item => animated::Js.boolean? => viewPosition::int? => unit => unit;

let scrollToOffset: ReactRe.reactRef => offset::int? => animated::Js.boolean? => unit => unit;

external recordInteraction : ReactRe.reactRef => unit = "" [@@bs.send];

let createElement:
  itemSeparatorComponent::ReactRe.reactClass? =>
  listFooterComponent::ReactRe.reactElement? =>
  listHeaderComponent::ReactRe.reactElement? =>
  columnWrapperStyle::Style.t? =>
  data::array 'item? =>
  extraData::'any? =>
  getItemLayout::(option (array 'item) => int => Js.t {. length : int, offset : int, index : int})? =>
  horizontal::bool? =>
  initialNumToRender::int? =>
  initialScrollIndex::int? =>
  keyExtractor::('item => int => string)? =>
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
            item : Js.t {.},
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
            item : Js.t {.},
            key : string,
            index : Js.undefined int,
            isViewable : Js.boolean,
            section : Js.t {.}
          }
        )
    }? =>
  refreshing::bool? =>
  removeClippedSubviews::bool? =>
  viewabilityConfig::Js.t {.}? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;