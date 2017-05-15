external view : ReactRe.reactClass = "Picker" [@@bs.module "react-native"];

module Item = {
  external item : ReactRe.reactClass = "Item" [@@bs.scope "Picker"] [@@bs.module "react-native"];
  let createElement ::color=? ::label=? ::value=? ::testID=? =>
    ReactRe.wrapPropsShamelessly
      item
      Js.Undefined.(
        {
          "label": from_opt label,
          "value": from_opt value,
          "color": from_opt color,
          "testID": from_opt testID
        }
      );
};

let createElement
    ::onValueChange=?
    ::selectedValue=?
    ::enabled=?
    ::mode=?
    ::prompt=?
    ::itemStyle=?
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::responderHandlers
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
    view
    (
      Props.extendView
        Js.Undefined.(
          {
            "enabled": from_opt (UtilsRN.optBoolToOptJsBoolean enabled),
            "onValueChange": from_opt onValueChange,
            "selectedValue": from_opt selectedValue,
            "itemStyle": from_opt itemStyle,
            "prompt": from_opt prompt,
            "mode":
              from_opt (
                UtilsRN.option_map
                  (
                    fun x =>
                      switch x {
                      | `dialog => "dialog"
                      | `dropdown => "dropdown"
                      }
                  )
                  mode
              )
          }
        )
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
    );
