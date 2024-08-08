include DrawerLayoutAndroidElement

module DrawerSlideEvent = {
  type payload = {offset: float}

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type drawerSlideEvent = DrawerSlideEvent.t

type t

type androidInteractionState = [#idle | #dragging | #settling]

type drawerLockMode = [
  | #unlocked
  | #"locked-closed"
  | #"locked-open"
]

type drawerPosition = [#left | #right]

type keyboardDismissMode = [#none | #"on-drag"]

type drawerLayoutAndroidProps = {
  ref?: ref,
  ...View.viewProps,
  renderNavigationView?: unit => React.element,
  onDrawerClose?: unit => unit,
  drawerLockMode?: drawerLockMode,
  drawerPosition?: drawerPosition,
  drawerWidth?: float,
  keyboardDismissMode?: keyboardDismissMode,
  onDrawerOpen?: unit => unit,
  onDrawerSlide?: drawerSlideEvent => unit,
  onDrawerStateChanged?: androidInteractionState => unit,
  drawerBackgroundColor?: Color.t,
  statusBarBackgroundColor?: Color.t,
}

@react.component(: drawerLayoutAndroidProps) @module("react-native")
external make: drawerLayoutAndroidProps => React.element = "DrawerLayoutAndroid"
