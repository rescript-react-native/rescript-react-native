[@bs.module "react-native"]
external view : ReasonReact.reactClass = "RefreshControl";

let make =
    (
      ~onRefresh: option(unit => unit)=?,
      ~refreshing: option(bool)=?,
      ~colors: option(array(string))=?,
      ~enabled: option(bool)=?,
      ~progressBackgroundColor: option(string)=?,
      ~progressViewOffset: option(float)=?,
      ~tintColor: option(string)=?,
      ~title: option(string)=?,
      ~titleColor: option(string)=?,
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
            "onRefresh": fromOption(onRefresh),
            "refreshing": fromOption(UtilsRN.optBoolToOptJsBoolean(refreshing)),
            "colors": fromOption(colors),
            "enabled": fromOption(UtilsRN.optBoolToOptJsBoolean(enabled)),
            "progressBackgroundColor": fromOption(progressBackgroundColor),
            "progressViewOffset": fromOption(progressViewOffset),
            "tintColor": fromOption(tintColor),
            "title": fromOption(title),
            "titleColor": fromOption(titleColor)
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
