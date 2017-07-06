module type ViewComponent = {
  let make:
    accessibilityLabel::ReasonReact.reactElement? =>
    accessible::bool? =>
    hitSlop::TypesRN.insets? =>
    onAccessibilityTap::(unit => unit)? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onMagicTap::(unit => unit)? =>
    responderHandlers::Props.touchResponderHandlers? =>
    pointerEvents::[ | `auto | `boxNone | `boxOnly | `none]? =>
    removeClippedSubviews::bool? =>
    style::StyleRe.t? =>
    testID::string? =>
    accessibilityComponentType::
      [ | `button | `none | `radiobutton_checked | `radiobutton_unchecked]? =>
    accessibilityLiveRegion::[ | `assertive | `none | `polite]? =>
    collapsable::bool? =>
    importantForAccessibility::[ | `auto | `no | `noHideDescendants | `yes]? =>
    needsOffscreenAlphaCompositing::bool? =>
    renderToHardwareTextureAndroid::bool? =>
    accessibilityTraits::
      list [
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
      ]? =>
    accessibilityViewIsModal::bool? =>
    shouldRasterizeIOS::bool? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
};

module type Impl = {let view: ReasonReact.reactClass;};

module CreateComponent: (Impl: Impl) => ViewComponent;

module View: ViewComponent;
