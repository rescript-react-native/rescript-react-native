/**
  A performant interface for rendering sectioned lists, supporting the most handy features:
  You can read more on [SectionList] component usage in official docs: {{:https://facebook.github.io/react-native/docs/sectionlist}}

  {3 Props}
  {4 sections}
  The actual data to render, akin to the data prop in FlatList.
  {[
    ~sections: sections('item),
  ]}
 reference:
  {[
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
  ]}
  */

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

type sections('item);

/**
{4 renderItem}
  {[
    ~renderItem: renderItem('item),
  ]}
*/

let sections: array(section('item)) => sections('item);

type renderItem('item);

/**
  {4 keyExtractor}
  {[
    ~keyExtractor: ('item, int) => string,
  ]}
  {4 itemSeparatorComponent}
  {[
    ~itemSeparatorComponent: separatorComponent('item)=?,
  ]}
  reference:
*/

let renderItem:
  (renderBag('item) => ReasonReact.reactElement) => renderItem('item);

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item)),
  section: section('item),
  trailingItem: option('item),
  trailingSection: option(section('item)),
};

type separatorComponent('item);

/**
  {4 listEmptyComponent}
  {[
    ~listEmptyComponent: unit => ReasonReact.reactElement=?,
  ]}
  {4 listFooterComponent}
  {[
    ~listFooterComponent: ReasonReact.reactElement=?,
  ]}
  {4 listHeaderComponent}
  {[
    ~listHeaderComponent: ReasonReact.reactElement=?,
  ]}
  {4 sectionSeparatorComponent}
  {[
    ~sectionSeparatorComponent: separatorComponent('item)=?,
  ]}
  {4 inverted}
  {[
    ~inverted: bool=?,
  ]}
  {4 extraData}
  {[
    ~extraData: 'extraData=?,
  ]}
  {4 initialNumToRender}
  {[
    ~initialNumToRender: int=?,
  ]}
  {4 onEndReached}
  {[
    ~onEndReached: {
      . "distanceFromEnd": float
    } => unit=?,
  ]}
  {4 onEndReachedThreshold}
  {[
    ~onEndReachedThreshold: float=?,
  ]}
  {4 onViewableItemsChanged}
  {[
    onViewableItemsChanged: {
      .
      "changed": array(viewToken('item)),
      "viewableItems": array(viewToken('item)),
    }=?
  ]}
  reference:
  {[
    type viewToken('item) = {
      .
      "index": Js.undefined(int),
      "isViewable": bool,
      "item": 'item,
      "key": string,
      "section": section('item),
    };
  ]}
   */

let separatorComponent:
  (separatorProps('item) => ReasonReact.reactElement) =>
  separatorComponent('item);

type viewToken('item) = {
  .
  "index": Js.undefined(int),
  "isViewable": bool,
  "item": 'item,
  "key": string,
  "section": section('item),
};

/**
{4 onRefresh}
{[
  onRefresh: unit => unit=?
]}
{4 refreshing}
{[
  refreshing: bool=?
]}
{4 renderSectionHeaader}
{[
  renderSectionHeader: renderAccessoryView('item)=?
]}
reference:
{[
  type renderAccessory('item) = {
    section: section('item),
  };
]}
 */

type renderAccessory('item) = {section: section('item)};

type renderAccessoryView('item);

/**
  {4 renderSectionFooter}
  {[
    ~renderSectionFooter: renderAccessoryView('item)=?,
  ]}
  {4 stickySectionHeadersEnabled}
  {[
    ~stickySectionHeadersEnabled: bool=?,
  ]}
  {4 keyboardDismissMode}
  {[
    keyboardDismissMode: [
      | `none
      | `interactive
      | `onDrag
    ]=?
  ]}
  {4 keyboardShouldPersistTaps}
  {[
    keyboardShouldPersistTaps: [
      | `always
      | `never
      | `handled
    ]=?
  ]}
  {4 showsHorizontalScrollIndicator}
  {[
    ~showsHorizontalScrollIndicator: bool=?,
  ]}
  {4 showsVerticalScrollIndicator}
  {[
    ~showsVerticalScrollIndicator: bool=?,
  ]}
  {4 getItemLayout}
  {[
    ~getItemLayout: (option(array('item)), int) => {
      .
      "length": int,
      "offset": int,
      "index": int,
    }
      =?,
  ]}
*/

let renderAccessoryView:
  (renderAccessory('item) => ReasonReact.reactElement) =>
  renderAccessoryView('item);

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
  );
