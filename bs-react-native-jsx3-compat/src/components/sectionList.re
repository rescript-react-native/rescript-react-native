type jsSeparatorProps('item) =
  ReactNative.VirtualizedSectionList.separatorProps('item);

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
  renderItem: option(renderBag('item) => React.element),
};

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item)),
  section: section('item),
  trailingItem: option('item),
  trailingSection: option(section('item)),
};

type renderItem('item) =
  ReactNative.VirtualizedSectionList.renderItemProps('item) => React.element;

let jsSectionToSection = jsSection => {
  data: jsSection##data,
  key: jsSection##key,
  /*** We set renderItem to None to avoid an infinite conversion loop */
  renderItem: None,
};

type sections('item) =
  array(ReactNative.VirtualizedSectionList.section('item));

let renderItem =
    (reRenderItem: renderBag('item) => React.element): renderItem('item) =>
  (jsRenderBag: ReactNative.VirtualizedSectionList.renderItemProps('item)) =>
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
        "key": reSection.key,
        "renderItem": reSection.renderItem->Belt.Option.map(renderItem),
        "ItemSeparatorComponent": None,
        "keyExtractor": None,
      },
    reSections,
  );

type separatorComponent('item) = jsSeparatorProps('item) => React.element;

let separatorComponent =
    (reSeparatorComponent: separatorProps('item) => React.element)
    : separatorComponent('item) =>
  (jsSeparatorProps: jsSeparatorProps('item)) =>
    reSeparatorComponent({
      highlighted: jsSeparatorProps##highlighted,
      leadingItem: jsSeparatorProps##leadingItem,
      leadingSection:
        jsSeparatorProps##leadingSection->Belt.Option.map(jsSectionToSection),
      section: jsSectionToSection(jsSeparatorProps##section),
      trailingItem: jsSeparatorProps##trailingItem,
      trailingSection:
        jsSeparatorProps##trailingSection
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

type jsRenderAccessory('item) = {
  .
  "section": ReactNative.VirtualizedSectionList.section('item),
};

type renderAccessory('item) = {section: section('item)};

type renderAccessoryView('item) = jsRenderAccessory('item) => React.element;

let renderAccessoryView =
    (reRenderAccessory: renderAccessory('item) => React.element)
    : renderAccessoryView('item) =>
  (jsRenderAccessory: jsRenderAccessory('item)) =>
    reRenderAccessory({
      section: jsSectionToSection(jsRenderAccessory##section),
    });

[@react.component]
let make =
    (
      ~sections: array(ReactNative.VirtualizedSectionList.section('item)),
      ~renderItem:
         ReactNative.VirtualizedSectionList.renderItemCallback('item),
      ~keyExtractor: ('item, int) => string,
      ~itemSeparatorComponent: option(separatorComponent('item))=?,
      ~listEmptyComponent: option(React.element)=?,
      ~listFooterComponent: option(React.element)=?,
      ~listHeaderComponent: option(React.element)=?,
      ~sectionSeparatorComponent: option(separatorComponent('item))=?,
      ~inverted: option(bool)=?,
      ~extraData: option('extraData)=?,
      ~initialNumToRender: option(int)=?,
      ~onEndReached:
         option(ReactNative.VirtualizedList.onEndReachedParams => unit)=?,
      ~onEndReachedThreshold: option(float)=?,
      ~onViewableItemsChanged:
         option(
           ReactNative.VirtualizedList.viewableItemsChanged('item) => unit,
         )=?,
      ~onRefresh: option(unit => unit)=?,
      ~refreshing: option(bool)=?,
      ~renderSectionHeader:
         option(
           ReactNative.VirtualizedSectionList.renderSectionHeaderCallback(
             'item,
           ),
         )=?,
      ~renderSectionFooter:
         option(
           ReactNative.VirtualizedSectionList.renderSectionHeaderCallback(
             'item,
           ),
         )=?,
      ~stickySectionHeadersEnabled: option(bool)=?,
      ~keyboardDismissMode: option([ | `none | `interactive | `onDrag])=?,
      ~keyboardShouldPersistTaps: option([ | `always | `never | `handled])=?,
      ~showsHorizontalScrollIndicator: option(bool)=?,
      ~showsVerticalScrollIndicator: option(bool)=?,
      ~getItemLayout:
         option(
           (array('item), int) => ReactNative.VirtualizedList.itemLayout,
         )=?,
      _,
    ) =>
  <ReactNative.SectionList
    sections
    renderItem
    keyExtractor
    _ItemSeparatorComponent=?itemSeparatorComponent
    _ListEmptyComponent=?{listEmptyComponent->Belt.Option.map((x, ()) => x)}
    _ListFooterComponent=?{listFooterComponent->Belt.Option.map((x, ()) => x)}
    _ListHeaderComponent=?{listHeaderComponent->Belt.Option.map((x, ()) => x)}
    _SectionSeparatorComponent=?sectionSeparatorComponent
    ?inverted
    ?extraData
    ?initialNumToRender
    ?onEndReached
    ?onEndReachedThreshold
    ?onRefresh
    ?onViewableItemsChanged
    ?refreshing
    ?renderSectionHeader
    ?renderSectionFooter
    ?stickySectionHeadersEnabled
    ?keyboardDismissMode
    ?keyboardShouldPersistTaps
    ?showsHorizontalScrollIndicator
    ?showsVerticalScrollIndicator
    getItemLayout=?{
      getItemLayout->Belt.Option.map((f, data, index) => f(data, index))
    }
  />;
