[@bs.module "react-native"] external view : ReasonReact.reactClass = "DatePickerIOS";

let encodeMode = (prop) =>
  switch prop {
  | `date => "date"
  | `time => "time"
  | `datetime => "datetime"
  };

let make =
    (
      ~date=?,
      ~onDateChange=?,
      ~maximumDate=?,
      ~minimumDate=?,
      ~mode=?,
      ~minuteInterval=?,
      ~timeZoneOffsetInMinutes=?,
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
      ~shouldRasterizeIOS=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "date": from_opt(date),
            "onDateChange": from_opt(onDateChange),
            "maximumDate": from_opt(maximumDate),
            "minimumDate": from_opt(minimumDate),
            "mode": from_opt(UtilsRN.option_map(encodeMode, mode)),
            "minuteInterval": from_opt(minuteInterval),
            "timeZoneOffsetInMinutes": from_opt(timeZoneOffsetInMinutes)
          }
        ),
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
        ~shouldRasterizeIOS?
      )
  );
