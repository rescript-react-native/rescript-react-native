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

let make:
  data::array 'item =>
  renderItem::(Js.t {. item : 'item, index : int} => ReasonReact.reactElement) =>
  itemSeparatorComponent::ReasonReact.reactClass? =>
  listFooterComponent::ReasonReact.reactElement? =>
  listHeaderComponent::ReasonReact.reactElement? =>
  columnWrapperStyle::StyleRe.t? =>
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
  refreshing::bool? =>
  removeClippedSubviews::bool? =>
  viewabilityConfig::Js.t {.}? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless;