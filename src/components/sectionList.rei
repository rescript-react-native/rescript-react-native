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

let section:
  (
    ~data: array('item),
    ~key: string=?,
    ~renderItem: renderBag('item) => ReasonReact.reactElement=?,
    unit
  ) =>
  section('item);

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item)),
  section: section('item),
  trailingItem: option('item),
  trailingSection: option(section('item)),
};

type sections('item);

let sections: array(section('item)) => sections('item);

type renderItem('item);

let renderItem:
  (renderBag('item) => ReasonReact.reactElement) => renderItem('item);

type separatorComponent('item);

let separatorComponent:
  (separatorProps('item) => ReasonReact.reactElement) =>
  separatorComponent('item);

type renderAccessory('item) = {section: section('item)};

type renderAccessoryView('item);

let renderAccessoryView:
  (renderAccessory('item) => ReasonReact.reactElement) =>
  renderAccessoryView('item);

type viewToken('item) = {
  .
  "index": Js.undefined(int),
  "isViewable": Js.boolean,
  "item": 'item,
  "key": string,
  "section": section('item),
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
    ~onEndReached: {. "distanceFromEnd": float} => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onViewableItemsChanged: {
                               .
                               "changed": array(viewToken('item)),
                               "viewableItems": array(viewToken('item)),
                             }
                               =?,
    ~onRefresh: unit => unit=?,
    ~refreshing: bool=?,
    ~renderSectionHeader: renderAccessoryView('item)=?,
    ~renderSectionFooter: renderAccessoryView('item)=?,
    ~stickySectionHeadersEnabled: bool=?,
    ~keyboardDismissMode: [ | `none | `interactive | `onDrag]=?,
    ~keyboardShouldPersistTaps: [ | `always | `never | `handled]=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );