external view : ReasonReact.reactClass = "SectionList" [@@bs.module "react-native"];

module CreateComponent (Item: {type item;}) => {
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
      item : Item.item,
      key : string,
      index : Js.undefined int,
      isViewable : Js.boolean,
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
    let renderItemFromJS renderItem jsItems =>
      renderItem (
        createRenderBag
          item::jsItems##item
          index::jsItems##index
          section::jsItems##section
          separators::jsItems##separators
      );
    let section ::data ::key=? ::renderItem=? () => {data, key, renderItem};
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
      onViewableItemsChanged::Js.t {. viewableItems : array viewToken, changed : array viewToken}? =>
      onRefresh::(unit => unit)? =>
      refreshing::bool? =>
      renderSectionHeader::(Js.t {. section : section} => ReasonReact.reactElement)? =>
      renderSectionFooter::(Js.t {. section : section} => ReasonReact.reactElement)? =>
      stickySectionHeadersEnabled::bool? =>
      array ReasonReact.reactElement =>
      ReasonReact.component ReasonReact.stateless =
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
        ReasonReact.wrapJsForReason
          reactClass::view
          props::
            Js.Undefined.(
              {
                "sections":
                  Array.map
                    (
                      fun {data, key, renderItem} => {
                        "data": data,
                        "key": from_opt key,
                        "renderItem": from_opt (UtilsRN.option_map renderItemFromJS renderItem)
                      }
                    )
                    sections,
                "renderItem": renderItemFromJS renderItem,
                "keyExtractor": keyExtractor,
                "ItemSeparatorComponent":
                  from_opt (
                    UtilsRN.option_map
                      (
                        fun itemSeparatorComponent => {
                          let comp jsItems =>
                            itemSeparatorComponent (
                              createSeparatorProps
                                highlighted::(Js.to_bool jsItems##highlighted)
                                leadingItem::jsItems##leadingItem
                                leadingSection::jsItems##leadingSection
                                section::jsItems##section
                                trailingItem::jsItems##trailingItem
                                trailingSection::jsItems##trailingSection
                            );
                          comp
                        }
                      )
                      itemSeparatorComponent
                  ),
                "ListEmptyComponent": from_opt listEmptyComponent,
                "ListFooterComponent": from_opt listFooterComponent,
                "ListHeaderComponent": from_opt listHeaderComponent,
                "SectionSeparatorComponent": from_opt sectionSeparatorComponent,
                "extraData": from_opt extraData,
                "initialNumToRender": from_opt initialNumToRender,
                "onEndReached": from_opt onEndReached,
                "onEndReachedThreshold": from_opt onEndReachedThreshold,
                "onRefresh": from_opt onRefresh,
                "onViewableItemsChanged": from_opt onViewableItemsChanged,
                "refreshing": from_opt (UtilsRN.optBoolToOptJsBoolean refreshing),
                "renderSectionHeader": from_opt renderSectionHeader,
                "renderSectionFooter": from_opt renderSectionFooter,
                "stickySectionHeadersEnabled":
                  from_opt (UtilsRN.optBoolToOptJsBoolean stickySectionHeadersEnabled)
              }
            );
  };
};