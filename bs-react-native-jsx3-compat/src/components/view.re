module type ViewComponent = {
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
        ~accessibilityRole=?,
        ~accessibilityStates=?,
        ~accessibilityHint=?,
        ~accessibilityIgnoresInvertColors=?,
        ~accessibilityViewIsModal=?,
        ~shouldRasterizeIOS=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        ViewProps.extend(
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
          ~accessibilityRole?,
          ~accessibilityStates?,
          ~accessibilityHint?,
          ~accessibilityIgnoresInvertColors?,
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
          Js.Obj.empty(),
        ),
    );
};

include CreateComponent({
  [@bs.module "react-native"] external view: ReasonReact.reactClass = "View";
});
