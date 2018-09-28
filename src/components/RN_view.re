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
      ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
      ~removeClippedSubviews: bool=?,
      ~style: RN_style.t=?,
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

module type Impl = {let view: ReasonReact.reactClass;};

module CreateComponent = (Impl: Impl) : ViewComponent => {
  let make =
      (
        ~accessibilityLabel=?,
        ~accessible=?,
        ~hitSlop=?,
        ~onAccessibilityTap=?,
        ~onLayout=?,
        ~onMagicTap=?,
        ~responderHandlers=?,
        ~pointerEvents=?,
        ~removeClippedSubviews=?,
        ~style=?,
        ~testID=?,
        ~accessibilityComponentType=?,
        ~accessibilityLiveRegion=?,
        ~collapsable=?,
        ~importantForAccessibility=?,
        ~needsOffscreenAlphaCompositing=?,
        ~renderToHardwareTextureAndroid=?,
        ~accessibilityTraits=?,
        ~accessibilityViewIsModal=?,
        ~shouldRasterizeIOS=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        Props.extendView(
          ~accessibilityLabel?,
          ~accessible?,
          ~hitSlop?,
          ~onAccessibilityTap?,
          ~onLayout?,
          ~onMagicTap?,
          ~responderHandlers?,
          ~pointerEvents?,
          ~removeClippedSubviews?,
          ~style?,
          ~testID?,
          ~accessibilityComponentType?,
          ~accessibilityLiveRegion?,
          ~collapsable?,
          ~importantForAccessibility?,
          ~needsOffscreenAlphaCompositing?,
          ~renderToHardwareTextureAndroid?,
          ~accessibilityTraits?,
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
          Js.Obj.empty(),
        ),
    );
};

include CreateComponent({
  [@bs.module "react-native"] external view: ReasonReact.reactClass = "View";
});

include ResponderUtils;