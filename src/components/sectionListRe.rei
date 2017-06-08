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
      renderItem: option (renderBag => ReasonReact.reactElement)
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
        renderItem::(renderBag => ReasonReact.reactElement)? =>
        unit =>
        section;
      let make:
        sections::array section =>
        renderItem::(renderBag => ReasonReact.reactElement) =>
        keyExtractor::(Item.item => int => string) =>
        itemSeparatorComponent::(separatorProps => ReasonReact.reactElement)? =>
        listEmptyComponent::(unit => ReasonReact.reactElement)? =>
        listFooterComponent::ReasonReact.reactElement? =>
        listHeaderComponent::ReasonReact.reactElement? =>
        sectionSeparatorComponent::(separatorProps => ReasonReact.reactElement)? =>
        extraData::'extraData? =>
        initialNumToRender::int? =>
        onEndReached::Js.t {. distanceFromEnd : float}? =>
        onEndReachedThreshold::float? =>
        onViewableItemsChanged::Js.t {. changed : array viewToken, viewableItems : array viewToken}? =>
        onRefresh::(unit => unit)? =>
        refreshing::bool? =>
        renderSectionHeader::(Js.t {. section : section} => ReasonReact.reactElement)? =>
        renderSectionFooter::(Js.t {. section : section} => ReasonReact.reactElement)? =>
        stickySectionHeadersEnabled::bool? =>
        array ReasonReact.reactElement =>
        ReasonReact.component ReasonReact.stateless;
    };
  };