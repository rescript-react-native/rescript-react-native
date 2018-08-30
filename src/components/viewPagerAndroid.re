[@bs.module "react-native"]
external view : ReasonReact.reactClass = "ViewPagerAndroid";

[@bs.send] external setPage : (ReasonReact.reactRef, int) => unit = "";

let make =
    (
      ~initialPage=?,
      ~keyboardDismissMode=?,
      ~onPageScroll=?,
      ~onPageScrollStateChanged=?,
      ~onPageSelected=?,
      ~pageMargin=?,
      ~peekEnabled=?,
      ~scrollEnabled=?,
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
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "initialPage": fromOption(initialPage),
            "onPageScroll": fromOption(onPageScroll),
            "onPageScrollStateChanged": fromOption(onPageScrollStateChanged),
            "onPageSelected": fromOption(onPageSelected),
            "pageMargin": fromOption(pageMargin),
            "keyboardDismissMode":
              fromOption(
                UtilsRN.option_map(
                  fun
                  | `none => "none"
                  | `onDrag => "on-drag",
                  keyboardDismissMode,
                ),
              ),
            "peekEnabled": fromOption(peekEnabled),
            "scrollEnabled": fromOption(scrollEnabled),
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
        ~shouldRasterizeIOS?,
      ),
  );