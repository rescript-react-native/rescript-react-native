module CreateComponent:
  (Item: {type item;}) =>
  {
    type renderBag = {
      item: Item.item,
      index: int,
      section,
      separators: Js.t {. highlight : unit => unit, unhighlight : unit => unit}
    }
    and section = {
      data: array Item.item,
      key: option string,
      renderItem: option (renderBag => ReactRe.reactElement)
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
        data::array Item.item =>
        key::string? =>
        renderItem::(renderBag => ReactRe.reactElement)? =>
        unit =>
        section;
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