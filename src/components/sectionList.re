[@bs.module "react-native"] external view : ReasonReact.reactClass = "SectionList";

type jsSection('item) = {
  .
  "data": array('item),
  "key": Js.Undefined.t(string),
  "renderItem": Js.Undefined.t(jsRenderBag('item) => ReasonReact.reactElement)
}
and jsRenderBag('item) = {
  .
  "item": 'item,
  "index": int,
  "section": jsSection('item),
  "separators": {
    .
    "highlight": unit => unit,
    "unhighlight": unit => unit
  }
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
  separators: {
    .
    "highlight": unit => unit,
    "unhighlight": unit => unit
  }
}
and section('item) = {
  data: array('item),
  key: option(string),
  renderItem: option(renderBag('item) => ReasonReact.reactElement)
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

let jsSectionToSection = jsSection => {
  data: jsSection##data,
  key: Js.Undefined.toOption(jsSection##key),
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

let sections = reSections : sections('item) =>
  Array.map(
    reSection => {
      "data": reSection.data,
      "key": Js.Undefined.fromOption(reSection.key),
      "renderItem": Js.Undefined.fromOption(UtilsRN.option_map(renderItem, reSection.renderItem))
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
      leadingItem: Js.Undefined.toOption(jsSeparatorProps##leadingItem),
      leadingSection: Js.Undefined.toOption(jsSeparatorProps##leadingSection) |> UtilsRN.option_map(jsSectionToSection),
      section: jsSectionToSection(jsSeparatorProps##section),
      trailingItem: Js.Undefined.toOption(jsSeparatorProps##trailingItem),
      trailingSection:
        Js.Undefined.toOption(jsSeparatorProps##trailingSection) |> UtilsRN.option_map(jsSectionToSection)
    });

type viewToken('item) = {
  .
  "item": 'item,
  "key": string,
  "index": Js.undefined(int),
  "isViewable": Js.boolean,
  "section": section('item)
};

type jsRenderAccessory('item) = {. "section": jsSection('item)};

type renderAccessory('item) = {section: section('item)};

type renderAccessoryView('item) = jsRenderAccessory('item) => ReasonReact.reactElement;

let renderAccessoryView =
    (reRenderAccessory: renderAccessory('item) => ReasonReact.reactElement)
    : renderAccessoryView('item) =>
  (jsRenderAccessory: jsRenderAccessory('item)) =>
    reRenderAccessory({section: jsSectionToSection(jsRenderAccessory##section)});

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
    ~onEndReached: {. "distanceFromEnd": float} => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onViewableItemsChanged: {
                               .
                               "viewableItems": array(viewToken('item)),
                               "changed": array(viewToken('item))
                             }
                               =?,
    ~onRefresh: unit => unit=?,
    ~refreshing: bool=?,
    ~renderSectionHeader: renderAccessoryView('item)=?,
    ~renderSectionFooter: renderAccessoryView('item)=?,
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
            "ItemSeparatorComponent": fromOption(itemSeparatorComponent),
            "ListEmptyComponent": fromOption(listEmptyComponent),
            "ListFooterComponent": fromOption(listFooterComponent),
            "ListHeaderComponent": fromOption(listHeaderComponent),
            "SectionSeparatorComponent": fromOption(sectionSeparatorComponent),
            "extraData": fromOption(extraData),
            "initialNumToRender": fromOption(initialNumToRender),
            "onEndReached": fromOption(onEndReached),
            "onEndReachedThreshold": fromOption(onEndReachedThreshold),
            "onRefresh": fromOption(onRefresh),
            "onViewableItemsChanged": fromOption(onViewableItemsChanged),
            "refreshing": fromOption(UtilsRN.optBoolToOptJsBoolean(refreshing)),
            "renderSectionHeader": fromOption(renderSectionHeader),
            "renderSectionFooter": fromOption(renderSectionFooter),
            "stickySectionHeadersEnabled": fromOption(UtilsRN.optBoolToOptJsBoolean(stickySectionHeadersEnabled))
          }
        ),
      _children
    );