---
id: components/DrawerLayoutAndroid
title: DrawerLayoutAndroid
wip: true
---

```reason
type element;
type ref = React.Ref.t(Js.nullable(element));

type drawerPosition;

[@bs.module "react-native"] [@bs.scope ("DrawerConsts", "DrawerPosition")]
external left: drawerPosition = "Left";

[@bs.module "react-native"] [@bs.scope ("DrawerConsts", "DrawerPosition")]
external right: drawerPosition = "Right";

type drawerSlideEvent = Event.syntheticEvent({. "offset": float});

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    ~renderNavigationView: unit => React.element,
    ~onDrawerClose: unit => unit=?,
    ~drawerPosition: drawerPosition=?,
    ~drawerWidth: float=?,
    ~keyboardDismissMode: [@bs.string] [ | `none | [@bs.as "on-drag"] `onDrag]
                            =?,
    ~drawerLockMode: [@bs.string] [
                       | [@bs.as "unlocked"] `unlocked
                       | [@bs.as "locked-closed"] `lockedClosed
                       | [@bs.as "locked-open"] `lockedOpen
                     ]
                       =?,
    ~onDrawerOpen: unit => unit=?,
    ~onDrawerSlide: drawerSlideEvent => unit=?,
    ~onDrawerStateChanged: AndroidInteractionState.t => unit=?,
    ~drawerBackgroundColor: Style.color=?,
    ~statusBarBackgroundColor: Style.color=?,
    // View props
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]=?,
    ~accessibilityRole: [@bs.string] [
                          | `none
                          | `button
                          | `link
                          | `search
                          | `image
                          | `keyboardkey
                          | `text
                          | `adjustable
                          | `header
                          | `summary
                          | `imagebutton
                        ]
                          =?,
    ~accessibilityStates: array(AccessibilityState.t)=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: Types.edgeInsets=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~nativeID: string=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderTerminate: Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: Event.pressEvent => unit=?,
    ~onStartShouldSetResponder: Event.pressEvent => bool=?,
    ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~pointerEvents: [@bs.string] [
                      | `auto
                      | `none
                      | [@bs.as "box-none"] `boxNone
                      | [@bs.as "box-only"] `boxOnly
                    ]
                      =?,
    ~removeClippedSubviews: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "DrawerLayoutAndroid";

[@bs.send] external openDrawer: (element, unit) => unit = "";

[@bs.send] external closeDrawer: (element, unit) => unit = "";

```
