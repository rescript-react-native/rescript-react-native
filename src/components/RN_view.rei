module type ViewComponent = {
  let make:
    (
      ~accessibilityLabel: string=?,
      ~accessible: bool=?,
      ~hitSlop: RN_types.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: RN_types.touchResponderHandlers=?,
      ~pointerEvents: [ | `auto | `boxNone | `boxOnly | `none]=?,
      ~removeClippedSubviews: bool=?,
      ~style: RN_style.t=?,
      ~testID: string=?,
      ~accessibilityComponentType: [
                                     | `button
                                     | `none
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityLiveRegion: [ | `assertive | `none | `polite]=?,
      ~collapsable: bool=?,
      ~importantForAccessibility: [ | `auto | `no | `noHideDescendants | `yes]
                                    =?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~accessibilityTraits: list(
                              [
                                | `adjustable
                                | `allowsDirectInteraction
                                | `button
                                | `disabled
                                | `frequentUpdates
                                | `header
                                | `image
                                | `key
                                | `link
                                | `none
                                | `pageTurn
                                | `plays
                                | `search
                                | `selected
                                | `startsMedia
                                | `summary
                                | `text
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

module type Impl = {let view: ReasonReact.reactClass;};

module CreateComponent: (Impl: Impl) => ViewComponent;

include ViewComponent;