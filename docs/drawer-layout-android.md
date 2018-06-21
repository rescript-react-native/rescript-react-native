---
id: drawer-layout-android
title: DrawerLayoutAndroid
sidebar_label: DrawerLayoutAndroid
---

## Example of use

React component that wraps the platform `DrawerLayout` (Android only). The Drawer (typically used for navigation) is rendered with `renderNavigationView` prop and direct children are the main view (where your content goes).

### default

```reason
let component = ReasonReact.statelessComponent("MyComponent");

let make = _children => {
  ...component,
  render: _self =>
    <DrawerLayoutAndroid
      renderNavigationView=(
        () => <Text> (ReasonReact.string("Drawer!")) </Text>
      )>
      <Text> (ReasonReact.string("Drawer!")) </Text>
    </DrawerLayoutAndroid>,
};
```

## Props

### renderNavigationView
The navigation view that will be rendered inside Drawer.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#rendernavigationview)

```reason
renderNavigationView: unit => ReasonReact.reactElement
```

### drawerPosition
Specifies the side of the screen from which the drawer will slide in.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#drawerposition)

```reason
drawerPosition: [ | `left | `right]=?,
```

### onDrawerClose
Function called on drawer close

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#ondrawerclose)

```reason
onDrawerClose: unit => unit=?
```

### drawerWidth
Specifies the width of the drawer.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#drawerwidth)

```reason
drawerWidth: int=?
```

### keyboardDismissMode
Specifies the width of the drawer. I accepts 2 variants:
 - `` `none`` *(default)* - drags do not dismiss the keyboard
 - `` `onDrag`` - the keyboard is dismissed when a drag begins

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#keyboarddismissmode)

```reason
keyboardDismissMode: [ | `none | `onDrag]=?
```

### drawerLockMode
Specifies the lock mode of the drawer. Drawer can be in 3 states:
 - `` `unlocked`` *(default)* - drawer will respond normally to touch gestures
 - `` `lockedClosed`` - drawer will stay closed and not respond to gestures
 - `` `lockedOpen`` - drawer will stay opened and not respond to gestures

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#drawerlockmode)

```reason
drawerLockMode: [ | `unlocked | `lockedClosed | `lockedOpen]=?
```

### onDrawerOpen
Function called on drawer open.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#ondraweropen)

```reason
onDrawerOpen: unit => unit=?
```

### onDrawerSlide
Function called whenever there is an interaction with the navigation view.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#ondrawerslide)

```reason
onDrawerSlide: unit => unit=?
```

### onDrawerStateChanged
Function called when the drawer state has changed.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#ondrawerstatechanged)

```reason
onDrawerStateChanged: string => unit=?
```

### drawerBackgroundColor
Background color of the Drawer.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#drawerbackgroundcolor)

```reason
drawerBackgroundColor: string=?
```

### statusBarBackgroundColor
Make the drawer take the entire screen and draw the background of the status bar to allow it to open over the status bar.

[RN docs](https://facebook.github.io/react-native/docs/drawerlayoutandroid.html#statusbarbackgroundcolor)

```reason
statusBarBackgroundColor: string=?
```

## Methods
### openDrawer()
Opens the drawer.

### closeDrawer()
Closes the drawer.

### Example with methods
To use `openDrawer` and `closeDrawer` methods you have to call them on `DrawerLayoutAndroid` `ref`.  See [ReasonReact docs](https://reasonml.github.io/reason-react/docs/en/react-ref.html) to learn more about using `ref`s.

```reason
type action;

type state = {drawerRef: ref(option(ReasonReact.reactRef))};

let setDrawerRef = (theRef, {ReasonReact.state}) =>
  state.drawerRef := Js.Nullable.toOption(theRef);

let component = ReasonReact.reducerComponent("ExampleContent");

let handleOpenPress = (_, {ReasonReact.state}) =>
  switch (state.drawerRef^) {
  | None => ()
  | Some(r) => ReasonReact.refToJsObj(r)##openDrawer()
  };

let handleClosePress = (_, {ReasonReact.state}) =>
  switch (state.drawerRef^) {
  | None => ()
  | Some(r) => ReasonReact.refToJsObj(r)##closeDrawer()
  };

let make = _children => {
  ...component,
  initialState: () => {drawerRef: ref(None)},
  reducer: (_action: action, _state: state) => ReasonReact.NoUpdate,
  render: self =>
    <DrawerLayoutAndroid
      renderNavigationView=(
        () =>
          <Button title="CLOSE" onPress=(self.handle(handleClosePress)) />
      )
      ref=(self.handle(setDrawerRef))>
      <Button title="OPEN" onPress=(self.handle(handleOpenPress)) />
    </DrawerLayoutAndroid>,
};
```


