---
id: components/ToolbarAndroid
title: ToolbarAndroid
wip: true
---

```reason
type element;
type ref = React.Ref.t(Js.nullable(element));

type action;
[@bs.obj]
external action:
  (
    ~title: string,
    ~icon: Image.Source.t=?,
    ~show: [@bs.string] [ | `always | `ifRoom | `never]=?,
    ~showWithText: bool=?,
    unit
  ) =>
  action =
  "";

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    ~overflowIcon: Image.Source.t=?,
    ~actions: array(action)=?,
    ~contentInsetStart: float=?,
    ~logo: Image.Source.t=?,
    ~navIcon: Image.Source.t=?,
    ~onActionSelected: int => unit=?,
    ~onIconClicked: unit => unit=?,
    ~contentInsetEnd: float=?,
    ~rtl: bool=?,
    ~subtitle: string=?,
    ~subtitleColor: Style.color=?,
    ~title: string=?,
    ~titleColor: Style.color=?,
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
  "ToolbarAndroid";

```
