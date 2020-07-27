---
id: components/ScrollView
title: ScrollView
wip: true
---

## Methods

### `scrollTo`

Scrolls to a given `x`, `y` offset, either immediately, with a smooth animation,
or, for Android only, a custom animation duration time.

```reason
let scrollParams = (~x: float, ~y: float, ~animated: bool=?, ~duration: float=?, unit) => unit;

let scrollTo = (scrollView, scrollParams) => unit;
```

#### `scrollTo` Example

```reason
open ReactNative;

[@react.component]
let make = () => {
  let scrollViewRef = React.useRef(Js.Nullable.null);
  <ScrollView ref={scrollViewRef->Ref.value}>
    <TouchableOpacity
      onPress={_ =>
        switch (scrollViewRef.current->Js.Nullable.toOption) {
        | Some(scrollView) =>
          scrollView->ScrollView.scrollTo(
            ScrollView.scrollToParams(~x=0., ~y=0., ~animated=true, ()),
          )
        | _ => ()
        }
      }>
      <Text> "ScrollTo 0, 0"->React.string </Text>
    </TouchableOpacity>
  </ScrollView>;
};
```

### `scrollToEnd`

Scrolls to the end of the `ScrollView` with an animation. If this is a vertical
`ScrollView` scrolls to the bottom. If this is a horizontal `ScrollView` scrolls
to the right.

```reason
let scrollToEnd = (scrollView) => unit;
```

### `scrollToEndWithOptions`

Similar to `scrollToEnd`, with options for animation or, for Android only
duration.

```reason
let scrollToEndOptions = (~animated: bool=?, ~duration: float=?, unit) => unit;

let scrollToEndWithOptions = (scrollView, scrollParams) => unit;
```
