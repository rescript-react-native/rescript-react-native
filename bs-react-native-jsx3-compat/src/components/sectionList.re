[@bs.module "react-native"]
external view: ReasonReact.reactClass = "SectionList";

type jsSection('item) = {
  .
  "data": array('item),
  "key": Js.Undefined.t(string),
  "renderItem":
    Js.Undefined.t(jsRenderBag('item) => ReasonReact.reactElement),
}
and jsRenderBag('item) = {
  .
  "item": 'item,
  "index": int,
  "section": jsSection('item),
  "separators": {
    .
    "highlight": unit => unit,
    "unhighlight": unit => unit,
  },
};

type jsSeparatorProps('item) = {
  .
  "highlighted": bool,
  "leadingItem": Js.Undefined.t('item),
  "leadingSection": Js.Undefined.t(jsSection('item)),
  "section": jsSection('item),
  "trailingItem": Js.Undefined.t('item),
  "trailingSection": Js.Undefined.t(jsSection('item)),
};

type renderBag('item) = {
  item: 'item,
  index: int,
  section: section('item),
  separators: {
    .
    "highlight": unit => unit,
    "unhighlight": unit => unit,
  },
}
and section('item) = {
  data: array('item),
  key: option(string),
  renderItem: option(renderBag('item) => ReasonReact.reactElement),
};

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item)),
  section: section('item),
  trailingItem: option('item),
  trailingSection: option(section('item)),
};

type renderItem('item) = jsRenderBag('item) => ReasonReact.reactElement;

let jsSectionToSection = jsSection => {
  data: jsSection##data,
  key: Js.Undefined.toOption(jsSection##key),
  /*** We set renderItem to None to avoid an infinite conversion loop */
  renderItem: None,
};

type sections('item) = array(jsSection('item));

let renderItem =
    (reRenderItem: renderBag('item) => ReasonReact.reactElement)
    : renderItem('item) =>
  (jsRenderBag: jsRenderBag('item)) =>
    reRenderItem({
      item: jsRenderBag##item,
      index: jsRenderBag##index,
      section: jsSectionToSection(jsRenderBag##section),
      separators: jsRenderBag##separators,
    });

let section = (~data, ~key=?, ~renderItem=?, ()) => {data, key, renderItem};

let sections = (reSections): sections('item) =>
  Array.map(
    reSection =>
      {
        "data": reSection.data,
        "key": Js.Undefined.fromOption(reSection.key),
        "renderItem":
          reSection.renderItem
          ->Belt.Option.map(renderItem)
          ->Js.Undefined.fromOption,
      },
    reSections,
  );

type separatorComponent('item) =
  jsSeparatorProps('item) => ReasonReact.reactElement;

let separatorComponent =
    (reSeparatorComponent: separatorProps('item) => ReasonReact.reactElement)
    : separatorComponent('item) =>
  (jsSeparatorProps: jsSeparatorProps('item)) =>
    reSeparatorComponent({
      highlighted: jsSeparatorProps##highlighted,
      leadingItem: Js.Undefined.toOption(jsSeparatorProps##leadingItem),
      leadingSection:
        Js.Undefined.toOption(jsSeparatorProps##leadingSection)
        ->Belt.Option.map(jsSectionToSection),
      section: jsSectionToSection(jsSeparatorProps##section),
      trailingItem: Js.Undefined.toOption(jsSeparatorProps##trailingItem),
      trailingSection:
        Js.Undefined.toOption(jsSeparatorProps##trailingSection)
        ->Belt.Option.map(jsSectionToSection),
    });

type viewToken('item) = {
  .
  "item": 'item,
  "key": string,
  "index": Js.undefined(int),
  "isViewable": bool,
  "section": section('item),
};

type jsRenderAccessory('item) = {. "section": jsSection('item)};

type renderAccessory('item) = {section: section('item)};

type renderAccessoryView('item) =
  jsRenderAccessory('item) => ReasonReact.reactElement;

let renderAccessoryView =
    (reRenderAccessory: renderAccessory('item) => ReasonReact.reactElement)
    : renderAccessoryView('item) =>
  (jsRenderAccessory: jsRenderAccessory('item)) =>
    reRenderAccessory({
      section: jsSectionToSection(jsRenderAccessory##section),
    });

[@bs.deriving jsConverter]
type keyboardDismissMode = [ | `none | `interactive | `onDrag];

[@bs.deriving jsConverter]
type keyboardShouldPersistTaps = [ | `always | `never | `handled];

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
    ~inverted: bool=?,
    ~extraData: 'extraData=?,
    ~initialNumToRender: int=?,
    ~onEndReached: {. "distanceFromEnd": float} => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onViewableItemsChanged: {
                               .
                               "viewableItems": array(viewToken('item)),
                               "changed": array(viewToken('item)),
                             }
                               =?,
    ~onRefresh: unit => unit=?,
    ~refreshing: bool=?,
    ~renderSectionHeader: renderAccessoryView('item)=?,
    ~renderSectionFooter: renderAccessoryView('item)=?,
    ~stickySectionHeadersEnabled: bool=?,
    ~keyboardDismissMode: keyboardDismissMode=?,
    ~keyboardShouldPersistTaps: keyboardShouldPersistTaps=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~getItemLayout: (option(array('item)), int) =>
                    {
                      .
                      "length": int,
                      "offset": int,
                      "index": int,
                    }
                      =?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  ) =
  (
    ~sections,
    ~renderItem,
    ~keyExtractor,
    ~itemSeparatorComponent=?,
    ~listEmptyComponent=?,
    ~listFooterComponent=?,
    ~listHeaderComponent=?,
    ~sectionSeparatorComponent=?,
    ~inverted=?,
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
    ~keyboardDismissMode=?,
    ~keyboardShouldPersistTaps=?,
    ~showsHorizontalScrollIndicator=?,
    ~showsVerticalScrollIndicator=?,
    ~getItemLayout=?,
    _children,
  ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=view,
      ~props={
        "sections": sections,
        "renderItem": renderItem,
        "keyExtractor": keyExtractor,
        "ItemSeparatorComponent": itemSeparatorComponent,
        "ListEmptyComponent": listEmptyComponent,
        "ListFooterComponent": listFooterComponent,
        "ListHeaderComponent": listHeaderComponent,
        "SectionSeparatorComponent": sectionSeparatorComponent,
        "inverted": inverted,
        "extraData": extraData,
        "initialNumToRender": initialNumToRender,
        "onEndReached": onEndReached,
        "onEndReachedThreshold": onEndReachedThreshold,
        "onRefresh": onRefresh,
        "onViewableItemsChanged": onViewableItemsChanged,
        "refreshing": refreshing,
        "renderSectionHeader": renderSectionHeader,
        "renderSectionFooter": renderSectionFooter,
        "stickySectionHeadersEnabled": stickySectionHeadersEnabled,
        "keyboardDismissMode":
          keyboardDismissMode->Belt.Option.map(keyboardDismissModeToJs),
        "keyboardShouldPersistTaps":
          keyboardShouldPersistTaps->Belt.Option.map(
            keyboardShouldPersistTapsToJs,
          ),
        "showsHorizontalScrollIndicator": showsHorizontalScrollIndicator,
        "showsVerticalScrollIndicator": showsVerticalScrollIndicator,
        "getItemLayout":
          getItemLayout->Belt.Option.map((f, data, index) =>
            f(Js.Undefined.toOption(data), index)
          ),
      },
      _children,
    );
