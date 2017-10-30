[@bs.module "react-native"] external view : ReasonReact.reactClass = "SectionList";

type jsSection('item) = {
  .
  "data": array('item),
  "key": Js.Undefined.t(string),
  "renderItem": Js.Undefined.t((jsRenderBag('item) => ReasonReact.reactElement))
}
and jsRenderBag('item) = {
  .
  "item": 'item,
  "index": int,
  "section": jsSection('item),
  "separators": {. "highlight": unit => unit, "unhighlight": unit => unit}
};

type jsSeparatorProps('item) = {
  .
  "highlighted": Js.boolean,
  "leadingItem": Js.Undefined.t('item),
  "leadingSection": Js.Undefined.t(jsSection('item)),
  "section": jsSection('item),
  "trailingItem": Js.Undefined.t('item),
  "trailingSection": Js.Undefined.t(jsSection('item))
};

type renderBag('item) = {
  item: 'item,
  index: int,
  section: section('item),
  separators: {. "highlight": unit => unit, "unhighlight": unit => unit}
}
and section('item) = {
  data: array('item),
  key: option(string),
  renderItem: option((renderBag('item) => ReasonReact.reactElement))
};

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item)),
  section: section('item),
  trailingItem: option('item),
  trailingSection: option(section('item))
};

type renderItem('item) = jsRenderBag('item) => ReasonReact.reactElement;

let jsSectionToSection = (jsSection) => {
  data: jsSection##data,
  key: Js.Undefined.to_opt(jsSection##key),
  /*** We set renderItem to None to avoid an infinite conversion loop */
  renderItem: None
};

type sections('item) = array(jsSection('item));

let renderItem = (reRenderItem: renderBag('item) => ReasonReact.reactElement) : renderItem('item) =>
  (jsRenderBag: jsRenderBag('item)) =>
    reRenderItem({
      item: jsRenderBag##item,
      index: jsRenderBag##index,
      section: jsSectionToSection(jsRenderBag##section),
      separators: jsRenderBag##separators
    });

let section = (~data, ~key=?, ~renderItem=?, ()) => {data, key, renderItem};

let sections = (reSections) : sections('item) =>
  Array.map(
    (reSection) => {
      "data": reSection.data,
      "key": Js.Undefined.from_opt(reSection.key),
      "renderItem": Js.Undefined.from_opt(UtilsRN.option_map(renderItem, reSection.renderItem))
    },
    reSections
  );

type separatorComponent('item) = jsSeparatorProps('item) => ReasonReact.reactElement;

let separatorComponent =
    (reSeparatorComponent: separatorProps('item) => ReasonReact.reactElement)
    : separatorComponent('item) =>
  (jsSeparatorProps: jsSeparatorProps('item)) =>
    reSeparatorComponent({
      highlighted: Js.to_bool(jsSeparatorProps##highlighted),
      leadingItem: Js.Undefined.to_opt(jsSeparatorProps##leadingItem),
      leadingSection:
        Js.Undefined.to_opt(jsSeparatorProps##leadingSection)
        |> UtilsRN.option_map(jsSectionToSection),
      section: jsSectionToSection(jsSeparatorProps##section),
      trailingItem: Js.Undefined.to_opt(jsSeparatorProps##trailingItem),
      trailingSection:
        Js.Undefined.to_opt(jsSeparatorProps##trailingSection)
        |> UtilsRN.option_map(jsSectionToSection)
    });

type viewToken('item) = {
  .
  "item": 'item,
  "key": string,
  "index": Js.undefined(int),
  "isViewable": Js.boolean,
  "section": section('item)
};

let make:
  (
    ~sections: sections('item),
    ~renderItem: renderItem('item),
    ~keyExtractor: ('item, int) => string,
    ~itemSeparatorComponent: separatorComponent('item)=?,
    ~listEmptyComponent: unit => ReasonReact.reactElement=?,
    ~listFooterComponent: ReasonReact.reactElement=?,
    ~listHeaderComponent: ReasonReact.reactElement=?,
    ~sectionSeparatorComponent: separatorComponent('item)=?,
    ~extraData: 'extraData=?,
    ~initialNumToRender: int=?,
    ~onEndReached: {. "distanceFromEnd": float}=?,
    ~onEndReachedThreshold: float=?,
    ~onViewableItemsChanged: {
                               .
                               "viewableItems": array(viewToken('item)),
                               "changed": array(viewToken('item))
                             }
                               =?,
    ~onRefresh: unit => unit=?,
    ~refreshing: bool=?,
    ~renderSectionHeader: {. "section": section('item)} => ReasonReact.reactElement=?,
    ~renderSectionFooter: {. "section": section('item)} => ReasonReact.reactElement=?,
    ~stickySectionHeadersEnabled: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit) =
  (
    ~sections,
    ~renderItem,
    ~keyExtractor,
    ~itemSeparatorComponent=?,
    ~listEmptyComponent=?,
    ~listFooterComponent=?,
    ~listHeaderComponent=?,
    ~sectionSeparatorComponent=?,
    ~extraData=?,
    ~initialNumToRender=?,
    ~onEndReached=?,
    ~onEndReachedThreshold=?,
    ~onViewableItemsChanged=?,
    ~onRefresh=?,
    ~refreshing=?,
    ~renderSectionHeader=?,
    ~renderSectionFooter=?,
    ~stickySectionHeadersEnabled=?,
    _children
  ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=view,
      ~props=
        Js.Undefined.(
          {
            "sections": sections,
            "renderItem": renderItem,
            "keyExtractor": keyExtractor,
            "ItemSeparatorComponent": from_opt(itemSeparatorComponent),
            "ListEmptyComponent": from_opt(listEmptyComponent),
            "ListFooterComponent": from_opt(listFooterComponent),
            "ListHeaderComponent": from_opt(listHeaderComponent),
            "SectionSeparatorComponent": from_opt(sectionSeparatorComponent),
            "extraData": from_opt(extraData),
            "initialNumToRender": from_opt(initialNumToRender),
            "onEndReached": from_opt(onEndReached),
            "onEndReachedThreshold": from_opt(onEndReachedThreshold),
            "onRefresh": from_opt(onRefresh),
            "onViewableItemsChanged": from_opt(onViewableItemsChanged),
            "refreshing": from_opt(UtilsRN.optBoolToOptJsBoolean(refreshing)),
            "renderSectionHeader": from_opt(renderSectionHeader),
            "renderSectionFooter": from_opt(renderSectionFooter),
            "stickySectionHeadersEnabled":
              from_opt(UtilsRN.optBoolToOptJsBoolean(stickySectionHeadersEnabled))
          }
        ),
      _children
    );
