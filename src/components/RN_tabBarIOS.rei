module Item: {
  let make:
    (
      ~title: string=?,
      ~badgeColor: string=?,
      ~badge: string=?,
      ~icon: RN_image.imageSource=?,
      ~onPress: unit => unit=?,
      ~renderAsOriginal: bool=?,
      ~style: RN_style.t=?,
      ~selected: bool=?,
      ~selectedIcon: RN_image.imageSource=?,
      ~isTVSelectable: bool=?,
      ~accessibilityLabel: ReasonReact.reactElement=?,
      ~accessible: bool=?,
      ~hitSlop: RN_types.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: RN_types.touchResponderHandlers=?,
      ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
      ~removeClippedSubviews: bool=?,
      ~testID: string=?,
      ~accessibilityComponentType: [
                                     | `none
                                     | `button
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
      ~collapsable: bool=?,
      ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]
                                    =?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~accessibilityTraits: list(
                              [
                                | `none
                                | `button
                                | `link
                                | `header
                                | `search
                                | `image
                                | `selected
                                | `plays
                                | `key
                                | `text
                                | `summary
                                | `disabled
                                | `frequentUpdates
                                | `startsMedia
                                | `adjustable
                                | `allowsDirectInteraction
                                | `pageTurn
                              ],
                            )
                              =?,
      ~accessibilityViewIsModal: bool=?,
      ~shouldRasterizeIOS: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

let make:
  (
    ~barTintColor: string=?,
    ~itemPositioning: [ | `fill | `center | `auto]=?,
    ~style: RN_style.t=?,
    ~tintColor: string=?,
    ~translucent: bool=?,
    ~unselectedItemTintColor: string=?,
    ~unselectedTintColor: string=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: RN_types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: RN_types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
                            [
                              | `none
                              | `button
                              | `link
                              | `header
                              | `search
                              | `image
                              | `selected
                              | `plays
                              | `key
                              | `text
                              | `summary
                              | `disabled
                              | `frequentUpdates
                              | `startsMedia
                              | `adjustable
                              | `allowsDirectInteraction
                              | `pageTurn
                            ],
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );