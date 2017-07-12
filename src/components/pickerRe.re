external view : ReasonReact.reactClass = "Picker" [@@bs.module "react-native"];

module Item = {
  external item : ReasonReact.reactClass =
    "Item" [@@bs.scope "Picker"] [@@bs.module "react-native"];
  let make ::color=? ::label=? ::value=? ::testID=? =>
    ReasonReact.wrapJsForReason
      reactClass::item
      props::
        Js.Undefined.(
          {
            "label": from_opt label,
            "value": from_opt value,
            "color": from_opt color,
            "testID": from_opt testID
          }
        );
};

let encodeMode x =>
  switch x {
  | `dialog => "dialog"
  | `dropdown => "dropdown"
  };

let make
    ::onValueChange=?
    ::selectedValue=?
    ::enabled=?
    ::mode=?
    ::prompt=?
    ::itemStyle=?
    ::accessibilityLabel=?
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
  ReasonReact.wrapJsForReason
    reactClass::view
    props::(
      Props.extendView
        Js.Undefined.(
          {
            "enabled": from_opt (UtilsRN.optBoolToOptJsBoolean enabled),
            "onValueChange": from_opt onValueChange,
            "selectedValue": from_opt selectedValue,
            "itemStyle": from_opt itemStyle,
            "prompt": from_opt prompt,
            "mode": from_opt (UtilsRN.option_map encodeMode mode)
          }
        )
        ::?accessibilityLabel
        ::?accessible
        ::?hitSlop
        ::?onAccessibilityTap
        ::?onLayout
        ::?onMagicTap
        ::?responderHandlers
        ::?pointerEvents
        ::?removeClippedSubviews
        ::?style
        ::?testID
        ::?accessibilityComponentType
        ::?accessibilityLiveRegion
        ::?collapsable
        ::?importantForAccessibility
        ::?needsOffscreenAlphaCompositing
        ::?renderToHardwareTextureAndroid
        ::?accessibilityTraits
        ::?accessibilityViewIsModal
        ::?shouldRasterizeIOS
    );
