external view : ReactRe.reactClass = "SectionList" [@@bs.module "react-native"];

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
let createElement
    ::sections
    ::renderItem
    ::itemSeparatorComponent=?
    ::listEmptyComponent=?
    ::listFooterComponent=?
    ::listHeaderComponent=?
    ::sectionSeparatorComponent=?
    ::extraData=?
    ::initialNumToRender=?
    ::keyExtractor=?
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
        "renderItem": renderItem,
        "itemSeparatorComponent": from_opt itemSeparatorComponent,
        "listEmptyComponent": from_opt listEmptyComponent,
        "listFooterComponent": from_opt listFooterComponent,
        "listHeaderComponent": from_opt listHeaderComponent,
        "sectionSeparatorComponent": from_opt sectionSeparatorComponent,
        "extraData": from_opt extraData,
        "initialNumToRender": from_opt initialNumToRender,
        "keyExtractor": from_opt keyExtractor,
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