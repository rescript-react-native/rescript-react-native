[@bs.module "react-native"] external view : ReasonReact.reactClass = "RefreshControl";

let make =
    (
      ~onRefresh: option((unit => unit))=?,
      ~refreshing: option(bool)=?,
      ~colors: option(array(string))=?,
      ~enabled: option(bool)=?,
      ~progressBackgroundColor: option(string)=?,
      ~progressViewReOffset: option(float)=?,
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
            "onRefresh": from_opt(onRefresh),
            "refreshing": from_opt(UtilsRN.optBoolToOptJsBoolean(refreshing)),
            "colors": from_opt(colors),
            "enabled": from_opt(UtilsRN.optBoolToOptJsBoolean(enabled)),
            "progressBackgroundColor": from_opt(progressBackgroundColor),
            "progressViewReOffset": from_opt(progressViewReOffset),
            "tintColor": from_opt(tintColor),
            "title": from_opt(title),
            "titleColor": from_opt(titleColor)
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
