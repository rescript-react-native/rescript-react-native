---
title: ViewPagerAndroid
---

## Example of use

Container that allows to flip left and right between child views. Each child view of the `ViewPagerAndroid` will be treated as a separate page and will be stretched to fill the `ViewPagerAndroid`.

It is important all children are `<View>`s and not composite components. You can set style properties like `padding` or `backgroundColor` for each child. It is also important that each child have a `key` prop.

### default

```reason
let styles =
  StyleSheet.create(
    Style.(
      {
        "pageStyle": style([flex(1.), flexGrow(1.)]),
        "viewPager":
          style([
            alignItems(Center),
            padding(Pt(20.)),
            backgroundColor(String("red")),
          ]),
      }
    ),
  );

let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <ViewPagerAndroid
        initialPage=0
        style=styles##viewPager
        <View style=styles##pageStyle key="1">
          <Text> (ReasonReact.string("First page")) </Text>
        </View>
        <View style=styles##pageStyle key="2">
          <Text> (ReasonReact.string("Second page")) </Text>
        </View>
      </ViewPagerAndroid>,
};
```

## Props

### initialPage

Index of initial page that should be selected.

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#initialpage)

```reason
initialPage: int=?
```

### keyboardDismissMode

Determines whether the keyboard gets dismissed in response to a drag. Possible values:

- `` `none `` _(default)_ - drags do not dismiss the keyboard.
- `` `onDrag `` - the keyboard is dismissed when a drag begins.

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#keyboarddismissmode)

```reason
keyboardDismissMode: [ | `none | `onDrag]=?
```

### onPageScroll

Executed when transitioning between pages (either because of animation for the requested page change or when user is swiping/dragging between pages). The `event##nativeEvent` object for this callback will carry following data:

- `position` - index of first page from the left that is currently visible
- `offset` - value from range [0,1) describing stage between page transitions. Value x means that (1 - x) fraction of the page at "position" index is visible, and x fraction of the next page is visible.

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#onpagescroll)

```reason
onPageScroll: {
               .
               "nativeEvent": {
                 .
                 "position": int,
                 "offset": int,
               },
             } =>
             unit
               =?
```

### onPageScrollStateChanged

Called when the page scrolling state has changed. The page scrolling state can be in 3 states:

- `idle` - there is no interaction with the page scroller happening at the time
- `dragging` - there is currently an interaction with the page scroller
- `settling`- there was an interaction with the page scroller, and the page scroller is now finishing it's closing or opening animation

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#onpagescrollstatechanged)

```reason
onPageScrollStateChanged: string => unit=?
```

### onPageSelected

This callback will be called once ViewPager finishes navigating to selected page (when user swipes between pages). The `event.nativeEvent` object passed to this callback will have following fields:

- `position` - index of page that has been selected

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#onpageselected)

```reason
onPageSelected: {. "nativeEvent": {. "position": int}} => unit=?
```

### pageMargin

Blank space to show between pages. This is only visible while scrolling, pages are still edge-to-edge.

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#pagemargin)

```reason
pageMargin: int=?
```

### peekEnabled

Whether enable showing peekFraction or not. If this is true, the preview of last and next page will show in current screen.

**default:** `false`

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#peekenabled)

```reason
peekEnabled: bool=?
```

### scrollEnabled

When false, the content does not scroll.

**default:** `true`

[RN docs](https://facebook.github.io/react-native/docs/viewpagerandroid.html#scrollenabled)

```reason
peekEnabled: bool=?
```

## Methods

### setPage: (int) => unit

You can use this method to manually set page at given index.

### Example with methods

To use `setPage` method you have to call them on `DrawerLayoutAndroid` `ref`. See [ReasonReact docs](https://reasonml.github.io/reason-react/docs/en/react-ref.html) to learn more about using `ref`s.
