let openDrawer: ReasonReact.reactRef => unit;
let closeDrawer: ReasonReact.reactRef => unit;

let make:
  (
    ~renderNavigationView: unit => ReasonReact.reactElement,
    ~onDrawerClose: unit => unit=?,
    ~onDrawerOpen: unit => unit=?,
    ~onDrawerSlide: unit => unit=?,
    ~onDrawerStateChanged: string => unit=?,
    ~drawerWidth: int=?,
    ~drawerPosition: [ | `left | `right]=?,
    ~keyboardDismissMode: [ | `none | `onDrag]=?,
    ~drawerLockMode: [ | `unlocked | `lockedClosed | `lockedOpen]=?,
    ~drawerBackgroundColor: string=?,
    ~statusBarBackgroundColor: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );