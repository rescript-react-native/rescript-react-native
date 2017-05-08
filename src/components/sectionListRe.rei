module Make:
  (Item: {type item;}) =>
  {
    type section =
      Js.t {
        .
        data : array Item.item,
        key : Js.Undefined.t string,
        renderItem :
          Js.Undefined.t (
            Js.t {
              .
              index : int,
              item : Item.item,
              section : section,
              separators : Js.t {. highlight : unit => unit, unhighlight : unit => unit}
            } =>
            ReactRe.reactElement
          )
      };
    type viewToken =
      Js.t {
        .
        index : Js.undefined int,
        isViewable : Js.boolean,
        item : Item.item,
        key : string,
        section : section
      };
    type renderBag = {
      item: Item.item,
      index: int,
      section,
      separators: Js.t {. highlight : unit => unit, unhighlight : unit => unit}
    };
    type separatorProps = {
      highlighted: bool,
      leadingItem: option Item.item,
      leadingSection: option section,
      section,
      trailingItem: option Item.item,
      trailingSection: option section
    };
    module SectionList: {
      let section:
        data::'a =>
        key::'b? =>
        renderItem::'c? =>
        unit =>
        Js.t {. data : 'a, key : Js.Undefined.t 'b, renderItem : Js.Undefined.t 'c};
      let createElement:
        sections::array section =>
        renderItem::(renderBag => ReactRe.reactElement) =>
        keyExtractor::(Item.item => int => string) =>
        itemSeparatorComponent::(separatorProps => ReactRe.reactElement)? =>
        listEmptyComponent::(unit => ReactRe.reactElement)? =>
        listFooterComponent::ReactRe.reactElement? =>
        listHeaderComponent::ReactRe.reactElement? =>
        sectionSeparatorComponent::(separatorProps => ReactRe.reactElement)? =>
        extraData::'extraData? =>
        initialNumToRender::int? =>
        onEndReached::Js.t {. distanceFromEnd : float}? =>
        onEndReachedThreshold::float? =>
        onViewableItemsChanged::Js.t {. changed : array viewToken, viewableItems : array viewToken}? =>
        onRefresh::(unit => unit)? =>
        refreshing::bool? =>
        renderSectionHeader::(Js.t {. section : section} => ReactRe.reactElement)? =>
        renderSectionFooter::(Js.t {. section : section} => ReactRe.reactElement)? =>
        stickySectionHeadersEnabled::bool? =>
        children::list ReactRe.reactElement =>
        ref::(ReactRe.reactRef => unit)? =>
        key::string? =>
        unit =>
        ReactRe.reactElement;
    };
  };