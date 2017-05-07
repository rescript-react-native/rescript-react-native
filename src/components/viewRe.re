module type ViewComponent = {
  let createElement:
    accessibleLeft::ReactRe.reactElement? =>
    accessible::bool? =>
    hitSlop::Types.insets? =>
    onAccessibilityTap::(unit => unit)? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onMagicTap::(unit => unit)? =>
    responderHandlers::Props.touchResponderHandlers? =>
    pointerEvents::[ | `auto | `none | `boxNone | `boxOnly]? =>
    removeClippedSubviews::bool? =>
    style::StyleRe.t? =>
    testID::string? =>
    accessibilityComponentType::
      [ | `none | `button | `radiobutton_checked | `radiobutton_unchecked]? =>
    accessibilityLiveRegion::[ | `none | `polite | `assertive]? =>
    collapsable::bool? =>
    importantForAccessibility::[ | `auto | `yes | `no | `noHideDescendants]? =>
    needsOffscreenAlphaCompositing::bool? =>
    renderToHardwareTextureAndroid::bool? =>
    accessibilityTraits::
      list [
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
      ]? =>
    accessibilityViewIsModal::bool? =>
    shouldRasterizeIOS::bool? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

module type Impl = {let view: ReactRe.reactClass;};

module CreateComponent (Impl: Impl) :ViewComponent => {
  let createElement
      ::accessibleLeft=?
      ::accessible=?
      ::hitSlop=?
      ::onAccessibilityTap=?
      ::onLayout=?
      ::onMagicTap=?
      ::responderHandlers=?
      ::pointerEvents=?
      ::removeClippedSubviews=?
      ::style=?
      ::testID=?
      ::accessibilityComponentType=?
      ::accessibilityLiveRegion=?
      ::collapsable=?
      ::importantForAccessibility=?
      ::needsOffscreenAlphaCompositing=?
      ::renderToHardwareTextureAndroid=?
      ::accessibilityTraits=?
      ::accessibilityViewIsModal=?
      ::shouldRasterizeIOS=? =>
    ReactRe.wrapPropsShamelessly
      Impl.view
      (
        Props.extendView
          ::accessibleLeft
          ::accessible
          ::hitSlop
          ::onAccessibilityTap
          ::onLayout
          ::onMagicTap
          ::responderHandlers
          ::pointerEvents
          ::removeClippedSubviews
          ::style
          ::testID
          ::accessibilityComponentType
          ::accessibilityLiveRegion
          ::collapsable
          ::importantForAccessibility
          ::needsOffscreenAlphaCompositing
          ::renderToHardwareTextureAndroid
          ::accessibilityTraits
          ::accessibilityViewIsModal
          ::shouldRasterizeIOS
          (Js.Obj.empty ())
      );
};

module View =
  CreateComponent {
    external view : ReactRe.reactClass = "View" [@@bs.module "react-native"];
  };
