external view : ReactRe.reactClass = "DatePickerIOS" [@@bs.module "react-native"];

let createElement
    ::date=?
    ::onDateChange=?
    ::maximumDate=?
    ::minimumDate=?
    ::mode=?
    ::minuteInterval=?
    ::timeZoneOffsetInMinutes=?
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
    ::shouldRasterizeIOS=? =>
  ReactRe.wrapPropsShamelessly
    view
    (
      Props.extendView
        Js.Undefined.(
          {
            "date": from_opt date,
            "onDateChange": from_opt onDateChange,
            "maximumDate": from_opt maximumDate,
            "minimumDate": from_opt minimumDate,
            "mode": from_opt (
                  Utils.option_map
                    (
                      fun prop =>
                        switch prop {
                        | `date => "date"
                        | `time => "time"
                        | `datetime => "datetime"
                        }
                    )
                    mode
                ),
            "minuteInterval": from_opt minuteInterval,
            "timeZoneOffsetInMinutes": from_opt timeZoneOffsetInMinutes,
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