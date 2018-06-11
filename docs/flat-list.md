---
id: flat-list
title: FlatList
sidebar_label: FlatList
---

# Props

## data

```reason
data: array('item)
```

## renderItem

```reason
renderItem: renderItem('item)
```

## keyExtractor

```reason
keyExtractor: ('item, int) => string
```

## itemSeparatorComponent

```reason
itemSeparatorComponent: separatorComponent('item)=?
```

_reference:_

```reason
let separatorComponent:
  (separatorProps('item) => ReasonReact.reactElement) =>
  separatorComponent('item);
```

## bounces

```reason
bounces: bool=?
```

## listFooterComponent

```reason
listFooterComponent: ReasonReact.reactElement=?
```

## listHeaderComponent

```reason
listHeaderComponent: ReasonReact.reactElement=?
```

## columnWrapperStyle

```reason
columnWrapperStyle: Style.t=?
```

## extraData

```reason
extraData: 'any=?
```

## getItemLayout

```reason
getItemLayout: (option(array('item)), int) => {
  .
  "length": int,
  "offset": int,
  "index": int,
}=?
```

## horizontal

```reason
horizontal: bool=?
```

## initialNumToRender

```reason
initialNumToRender: int=?
```

## initialScrollIndex

```reason
initialScrollIndex: int=?
```

## inverted

```reason
inverted: bool=?
```

## numColumns

```reason
numColumns: 'int=?
```

## onEndReached

```reason
onEndReached: {. "distanceFromEnd": float} => unit=?
```

## onEndReachedThreshold

```reason
onEndReachedThreshold: float=?
```

## onRefresh

```reason
onRefresh: unit => unit=?
```

## onViewableItemsChanged

```reason
onViewableItemsChanged: {
  .
  "viewableItems":
    array(
      {
        .
        "item": 'item,
        "key": string,
        "index": Js.undefined(int),
        "isViewable": bool,
        "section": Js.t({.}),
      },
    ),
  "changed":
    array(
      {
        .
        "item": 'item,
        "key": string,
        "index": Js.undefined(int),
        "isViewable": bool,
        "section": Js.t({.}),
      },
    ),
}=?
```

## overScrollMode

```reason
overScrollMode: [
  | `auto
  | `always
  | `never
]=?
```

## pagingEnabled

```reason
pagingEnabled: bool=?
```

## refreshing

```reason
refreshing: bool=?
```

## removeClippedSubviews

```reason
removeClippedSubviews: bool=?
```

## scrollEnabled

```reason
scrollEnabled: bool=?
```

## showsHorizontalScrollIndicator

```reason
showsHorizontalScrollIndicator: bool=?
```

## showsVerticalScrollIndicator

```reason
showsVerticalScrollIndicator: bool=?
```

## windowSize

```reason
windowSize: int=?
```

## maxToRenderPerBatch

```reason
maxToRenderPerBatch: int=?
```

## viewabilityConfig

```reason
viewabilityConfig: Js.t({.})=?
```

## onScroll

```reason
onScroll: RNEvent.NativeScrollEvent.t => unit=?
```

_reference:_

**RNEvent.rei**

```reason
module NativeScrollEvent: {
  type t;
  type point = {
    x: float,
    y: float
  };
  type size = {
    width: float,
    height: float
  };
  type contentInset = {
    bottom: float,
    top: float,
    left: float,
    right: float
  };
  let contentOffset: t => point;
  let contentSize: t => size;
  let contentInset: t => contentInset;
  let layoutMeasurement: t => size;
};
```

## style

```reason
style: Style.t=?
```
