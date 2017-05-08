type section 'item =
  Js.t {
    .
    data : array 'item, key : Js.Undefined.t string, renderItem : Js.Undefined.t (renderItem 'item)
  }
and renderItem 'item =
  Js.t {
    .
    item : 'item,
    index : int,
    section : section 'item,
    separators :
      Js.t {
        .
        highlight : unit => unit,
        unhighlight : unit => unit,
        updateProps : string => Js.t {.} => unit
      }
  } =>
  ReactRe.reactElement
and separatorProps 'item =
  Js.t {
    .
    highlighted : Js.boolean,
    leadingItem : Js.Undefined.t 'item,
    leadingSection : Js.Undefined.t (section 'item),
    section : section 'item,
    trailingItem : Js.Undefined.t 'item,
    trailingSection : Js.Undefined.t (section 'item)
  }
and viewToken 'item =
  Js.t {
    .
    item : 'item,
    key : string,
    index : Js.undefined int,
    isViewable : Js.boolean,
    section : section 'item
  };

let section:
  data::array 'item => key::string? => renderItem::renderItem 'item? => unit => section 'item;

let createElement:
  sections::array (section 'item) =>
  renderItem::renderItem 'item =>
  itemSeparatorComponent::(separatorProps 'item => ReactRe.reactElement)? =>
  listEmptyComponent::(unit => ReactRe.reactElement)? =>
  listFooterComponent::ReactRe.reactElement? =>
  listHeaderComponent::ReactRe.reactElement? =>
  sectionSeparatorComponent::(separatorProps 'item => ReactRe.reactElement)? =>
  extraData::'extraData? =>
  initialNumToRender::int? =>
  keyExtractor::('item => int => string)? =>
  onEndReached::Js.t {. distanceFromEnd : float}? =>
  onEndReachedThreshold::float? =>
  onViewableItemsChanged::
    Js.t {. viewableItems : array (viewToken 'item), changed : array (viewToken 'item)}? =>
  onRefresh::(unit => unit)? =>
  refreshing::bool? =>
  renderSectionHeader::(Js.t {. section : section 'item} => ReactRe.reactElement)? =>
  renderSectionFooter::(Js.t {. section : section 'item} => ReactRe.reactElement)? =>
  stickySectionHeadersEnabled::bool? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;