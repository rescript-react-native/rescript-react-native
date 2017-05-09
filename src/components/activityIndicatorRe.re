external view : ReactRe.reactClass = "ActivityIndicator" [@@bs.module "react-native"];

let createElement
    ::animating=?
    ::color=?
    ::size=?
    ::hidesWhenStopped=?
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
            "animating": from_opt (Utils.optBoolToOptJsBoolean animating),
            "color": from_opt color,
            "size":
              from_opt (
                Utils.option_map
                  (
                    fun size =>
                      switch size {
                      | `small => Encode.string "small"
                      | `large => Encode.string "large"
                      | `exact x => Encode.int x
                      }
                  )
                  size
              ),
            "hidesWhenStopped": from_opt (Utils.optBoolToOptJsBoolean hidesWhenStopped)
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
