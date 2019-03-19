module type ViewComponent = {
  /**
    The most fundamental component for building a UI,
    You can read more on [View] component usage in official docs: {{:https://facebook.github.io/react-native/docs/view}}

    {2 Props}

    {3 accessibilityLabel}

    {[
      ~accessibilityLabel: ReasonReact.reactElement=?,
    ]}

    {3 accessible}

    {[
      ~accessible: bool=?,
    ]}

    {3 hitSlop}

    {[
      ~hitSlop: Types.insets=?,
    ]}

    {3 onAccessibilityTap}

    {[
      ~onAccessibilityTap: unit => unit=?,
    ]}

    {3 onLayout}

    {[
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ]}

    {3 onMagicTap}

    {[
      ~onMagicTap: unit => unit=?,
    ]}

    {3 responderHandlers}

    {[
      ~responderHandlers: Types.touchResponderHandlers=?,
    ]}

    {3 pointerEvents}

    {[
      ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ]}

    {3 removeClippedSubviews}

    {[
      ~removeClippedSubviews: bool=?,
    ]}

    {3 style}

    {[
      ~style: Style.t=?,
    ]}

    {3 testID}

    {[
      ~testID: string=?,
    ]}

    {3 accessibilityComponentType}

    {[
      ~accessibilityComponentType: [
                                      | `none
                                      | `button
                                      | `radiobutton_checked
                                      | `radiobutton_unchecked
                                    ]
                                      =?
    ]}

    {3 accessibilityLiveRegion}

    {[
      ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ]}

    {3 collapsable}

    {[
      ~collapsable: bool=?
    ]}

    {3 importantForAccessibility}

    {[
      ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?
    ]}

    {3 needsOffscreenAlphaCompositing}

    {[
      ~needsOffscreenAlphaCompositing: bool=?
    ]}

    {3 renderToHardwareTextureAndroid}

    {[
      ~renderToHardwareTextureAndroid: bool=?
    ]}

    {3 accessibilityTraits}

    {[
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
    ]}

    {3 accessibilityViewIsModal}

    {[
      ~accessibilityViewIsModal: bool=?,
    ]}

    {3 shouldRasterizeIOS}

    {[
      ~shouldRasterizeIOS: bool=?,
    ]}
   */
  let make:
    (
      ~accessibilityLabel: string=?,
      ~accessible: bool=?,
      ~hitSlop: Types.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: Types.touchResponderHandlers=?,
      ~pointerEvents: Types.pointerEvents=?,
      ~removeClippedSubviews: bool=?,
      ~style: Style.t=?,
      ~testID: string=?,
      ~accessibilityComponentType: Types.accessibilityComponentType=?,
      ~accessibilityLiveRegion: Types.accessibilityLiveRegion=?,
      ~collapsable: bool=?,
      ~importantForAccessibility: Types.importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~accessibilityTraits: list(Types.accessibilityTrait)=?,
      ~accessibilityRole: Types.accessibilityRole=?,
      ~accessibilityStates: list(Types.accessibilityState)=?,
      ~accessibilityHint: string=?,
      ~accessibilityIgnoresInvertColors: bool=?,
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