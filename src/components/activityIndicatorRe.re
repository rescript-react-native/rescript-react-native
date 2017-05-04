external view : ReactRe.reactClass = "ActivityIndicator" [@@bs.module "react-native"];

let createElement
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::onMoveShouldSetResponder=?
    ::onMoveShouldSetResponderCapture=?
    ::onResponderGrant=?
    ::onResponderMove=?
    ::onResponderReject=?
    ::onResponderRelease=?
    ::onResponderTerminate=?
    ::onResponderTerminationRequest=?
    ::onStartShouldSetResponder=?
    ::onStartShouldSetResponderCapture=?
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
    ::shouldRasterizeIOS=?
    ::animating=?
    ::color=?
    ::size=?
    ::sizeNumber=?
    ::hidesWhenStopped=? =>
  ReactRe.wrapPropsShamelessly
    view
    (
      Props.extendView
        Js.Undefined.(
          {
            "animating": from_opt (Utils.optBoolToOptJsBoolean animating),
            "color": from_opt color,
            "size":
              switch (size, sizeNumber) {
              | (Some _, _) =>
                from_opt (
                  Utils.option_map
                    (
                      fun prop =>
                        switch prop {
                        | `small => Utils.Encode.string "small"
                        | `large => Utils.Encode.string "large"
                        }
                    )
                    size
                )
              | (None, _) => from_opt (Utils.option_map Utils.Encode.int sizeNumber)
              },
            "hidesWhenStopped": from_opt (Utils.optBoolToOptJsBoolean hidesWhenStopped)
          }
        )
        ::accessibleLeft
        ::accessible
        ::hitSlop
        ::onAccessibilityTap
        ::onLayout
        ::onMagicTap
        ::onMoveShouldSetResponder
        ::onMoveShouldSetResponderCapture
        ::onResponderGrant
        ::onResponderMove
        ::onResponderReject
        ::onResponderRelease
        ::onResponderTerminate
        ::onResponderTerminationRequest
        ::onStartShouldSetResponder
        ::onStartShouldSetResponderCapture
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