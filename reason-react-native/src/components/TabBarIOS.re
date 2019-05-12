include NativeElement;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // TabBarIOS props
    ~barStyle: [@bs.string] [ | `default | `black]=?,
    ~barTintColor: Color.t=?,
    ~itemPositioning: [@bs.string] [ | `fill | `center | `auto]=?,
    ~tintColor: Color.t=?,
    ~translucent: bool=?,
    ~unselectedItemTintColor: Color.t=?,
    ~unselectedTintColor: Color.t=?,
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
    ~hitSlop: View.edgeInsets=?,
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
    ~onAccessibilityEscape: unit => unit=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderEnd: Event.pressEvent => unit=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderStart: Event.pressEvent => unit=?,
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
  "TabBarIOS";

module Item = {
  include NativeElement;

  [@react.component] [@bs.module "react-native"] [@bs.scope "TabBarIOS"]
  external make:
    (
      ~ref: ref=?,
      // TabBarIOS item props
      ~selected: bool=?,
      ~badge: string=?,
      ~icon: Image.Source.t=?,
      ~onPress: unit => unit=?,
      ~renderAsOriginal: bool=?,
      ~badgeColor: string=?,
      ~selectedIcon: Image.Source.t=?,
      ~systemIcon: [@bs.string] [
                     | `bookmarks
                     | `contacts
                     | `downloads
                     | `favourites
                     | `featured
                     | `history
                     | `more
                     | `mostRecent
                     | `mostViewed
                     | `recents
                     | `search
                     | `topRated
                   ]
                     =?,
      ~title: string=?,
      ~isTVSelectable: bool=?,
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
      ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]
                                  =?,
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
      ~hitSlop: View.edgeInsets=?,
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
      ~onAccessibilityEscape: unit => unit=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: Event.layoutEvent => unit=?,
      ~onMagicTap: unit => unit=?,
      // Gesture Responder props
      ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
      ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
      ~onResponderEnd: Event.pressEvent => unit=?,
      ~onResponderGrant: Event.pressEvent => unit=?,
      ~onResponderMove: Event.pressEvent => unit=?,
      ~onResponderReject: Event.pressEvent => unit=?,
      ~onResponderRelease: Event.pressEvent => unit=?,
      ~onResponderStart: Event.pressEvent => unit=?,
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
      ~testID: string=?
    ) =>
    React.element =
    "Item";
};
