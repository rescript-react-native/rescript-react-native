external view : ReactRe.reactClass = "SectionList" [@@bs.module "react-native"];

module Make (Item: {type item;}) => {
  type section =
    Js.t {
      .
      data : array Item.item,
      key : Js.Undefined.t string,
      renderItem :
        Js.Undefined.t (
          Js.t {
            .
            item : Item.item,
            index : int,
            section : section,
            separators : Js.t {. highlight : unit => unit, unhighlight : unit => unit}
          } =>
          ReactRe.reactElement
        )
    };
  type viewToken =
    Js.t {
      .
      item : Item.item,
      key : string,
      index : Js.undefined int,
      isViewable : Js.boolean,
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
  let createRenderBag ::item ::index ::section ::separators => {item, index, section, separators};
  let createSeparatorProps
      ::highlighted
      ::leadingItem
      ::leadingSection
      ::section
      ::trailingItem
      ::trailingSection => {
    highlighted,
    leadingItem,
    leadingSection,
    section,
    trailingItem,
    trailingSection
  };
  module SectionList = {
    let section ::data ::key=? ::renderItem=? () =>
      Js.Undefined.({"data": data, "key": from_opt key, "renderItem": from_opt renderItem});
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
      onViewableItemsChanged::Js.t {. viewableItems : array viewToken, changed : array viewToken}? =>
      onRefresh::(unit => unit)? =>
      refreshing::bool? =>
      renderSectionHeader::(Js.t {. section : section} => ReactRe.reactElement)? =>
      renderSectionFooter::(Js.t {. section : section} => ReactRe.reactElement)? =>
      stickySectionHeadersEnabled::bool? =>
      children::list ReactRe.reactElement =>
      ref::(ReactRe.reactRef => unit)? =>
      key::string? =>
      unit =>
      ReactRe.reactElement =
      fun ::sections
          ::renderItem
          ::keyExtractor
          ::itemSeparatorComponent=?
          ::listEmptyComponent=?
          ::listFooterComponent=?
          ::listHeaderComponent=?
          ::sectionSeparatorComponent=?
          ::extraData=?
          ::initialNumToRender=?
          ::onEndReached=?
          ::onEndReachedThreshold=?
          ::onViewableItemsChanged=?
          ::onRefresh=?
          ::refreshing=?
          ::renderSectionHeader=?
          ::renderSectionFooter=?
          ::stickySectionHeadersEnabled=? =>
        ReactRe.wrapPropsShamelessly
          view
          Js.Undefined.(
            {
              "sections": sections,
              "renderItem": fun jsItems =>
                renderItem (
                  createRenderBag
                    item::jsItems##item
                    index::jsItems##index
                    section::jsItems##section
                    separators::jsItems##separators
                ),
              "keyExtractor": keyExtractor,
              "itemSeparatorComponent":
                from_opt (
                  Utils.option_map
                    (
                      fun itemSeparatorComponent jsItems =>
                        itemSeparatorComponent (
                          createSeparatorProps
                            highlighted::jsItems##highlighted
                            leadingItem::jsItems##leadingItem
                            leadingSection::jsItems##leadingSection
                            section::jsItems##section
                            trailingItem::jsItems##trailingItem
                            trailingSection::jsItems##trailingSection
                        )
                    )
                    itemSeparatorComponent
                ),
              "listEmptyComponent": from_opt listEmptyComponent,
              "listFooterComponent": from_opt listFooterComponent,
              "listHeaderComponent": from_opt listHeaderComponent,
              "sectionSeparatorComponent": from_opt sectionSeparatorComponent,
              "extraData": from_opt extraData,
              "initialNumToRender": from_opt initialNumToRender,
              "onEndReached": from_opt onEndReached,
              "onEndReachedThreshold": from_opt onEndReachedThreshold,
              "onRefresh": from_opt onRefresh,
              "onViewableItemsChanged": from_opt onViewableItemsChanged,
              "refreshing": from_opt (Utils.optBoolToOptJsBoolean refreshing),
              "renderSectionHeader": from_opt renderSectionHeader,
              "renderSectionFooter": from_opt renderSectionFooter,
              "stickySectionHeadersEnabled":
                from_opt (Utils.optBoolToOptJsBoolean stickySectionHeadersEnabled)
            }
          );
  };
};