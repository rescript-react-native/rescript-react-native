---
title: SectionList
---

## Props

### sections

```reason
sections: sections('item)
```

### renderItem

```reason
renderItem: renderItem('item)
```

### keyExtractor

```reason
keyExtractor: ('item, int) => string
```

### itemSeparatorComponent

```reason
itemSeparatorComponent: separatorComponent('item)=?
```

_reference:_

```reason
let separatorComponent:
  (separatorProps('item) => ReasonReact.reactElement) =>
  separatorComponent('item);
```

```reason
type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item)),
  section: section('item),
  trailingItem: option('item),
  trailingSection: option(section('item)),
};
```

```reason
type section('item) = {
  data: array('item),
  key: option(string),
  renderItem: option(renderBag('item) => ReasonReact.reactElement),
};
```

```reason
type renderBag('item) = {
  item: 'item,
  index: int,
  section: section('item),
  separators: {
    .
    "highlight": unit => unit,
    "unhighlight": unit => unit,
  },
};
```

### listEmptyComponent

```reason
listEmptyComponent: unit => ReasonReact.reactElement=?
```

### listFooterComponent

```reason
listFooterComponent: ReasonReact.reactElement=?
```

### listHeaderComponent

```reason
listHeaderComponent: ReasonReact.reactElement=?
```

### sectionSeparatorComponent

```reason
sectionSeparatorComponent: separatorComponent('item)=?
```

_reference:_

```reason
let separatorComponent:
  (separatorProps('item) => ReasonReact.reactElement) =>
  separatorComponent('item);
```

```reason
type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item)),
  section: section('item),
  trailingItem: option('item),
  trailingSection: option(section('item)),
};
```

```reason
type section('item) = {
  data: array('item),
  key: option(string),
  renderItem: option(renderBag('item) => ReasonReact.reactElement),
};
```

```reason
type renderBag('item) = {
  item: 'item,
  index: int,
  section: section('item),
  separators: {
    .
    "highlight": unit => unit,
    "unhighlight": unit => unit,
  },
};
```

### inverted

```reason
inverted: bool=?
```

### extraData

```reason
extraData: 'extraData=?
```

### initialNumToRender

```reason
initialNumToRender: int=?
```

### onEndReached

```reason
onEndReached: {. "distanceFromEnd": float} => unit=?
```

### onEndReachedThreshold

```reason
onEndReachedThreshold: float=?
```

### onViewableItemsChanged

```reason
onViewableItemsChanged: {
  .
  "changed": array(viewToken('item)),
  "viewableItems": array(viewToken('item)),
}=?
```

_reference:_

```reason
type viewToken('item) = {
  .
  "index": Js.undefined(int),
  "isViewable": bool,
  "item": 'item,
  "key": string,
  "section": section('item),
};
```

### onRefresh

```reason
onRefresh: unit => unit=?
```

### refreshing

```reason
refreshing: bool=?
```

### renderSectionHeader

```reason
renderSectionHeader: renderAccessoryView('item)=?
```

_reference:_

```reason
let renderAccessoryView:
  (renderAccessory('item) => ReasonReact.reactElement) =>
  renderAccessoryView('item);
```

```reason
type renderAccessory('item) = {section: section('item)};
```

```reason
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
```

### renderSectionFooter

```reason
renderSectionFooter: renderAccessoryView('item)=?
```

_reference:_

```reason
let renderAccessoryView:
  (renderAccessory('item) => ReasonReact.reactElement) =>
  renderAccessoryView('item);
```

```reason
type renderAccessory('item) = {section: section('item)};
```

```reason
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
```

### stickySectionHeadersEnabled

```reason
stickySectionHeadersEnabled: bool=?
```

### keyboardDismissMode

```reason
keyboardDismissMode: [
  | `none
  | `interactive
  | `onDrag
]=?
```

### keyboardShouldPersistTaps

```reason
keyboardShouldPersistTaps: [
  | `always
  | `never
  | `handled
]=?
```

### showsHorizontalScrollIndicator

```reason
showsHorizontalScrollIndicator: bool=?
```

### showsVerticalScrollIndicator

```reason
showsVerticalScrollIndicator: bool=?
```

### getItemLayout

```reason
getItemLayout: (option(array('item)), int) => {
  .
  "length": int,
  "offset": int,
  "index": int
}=?
```
