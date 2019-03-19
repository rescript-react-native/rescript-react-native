[@bs.module "react-native"]
external view: ReasonReact.reactClass = "ViewPagerAndroid";

[@bs.send] external setPage: (ReasonReact.reactRef, int) => unit = "";

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
      ~accessibilityRole=?,
      ~accessibilityStates=?,
      ~accessibilityHint=?,
      ~accessibilityIgnoresInvertColors=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      ViewProps.extend(
        {
          "initialPage": initialPage,
          "onPageScroll": onPageScroll,
          "onPageScrollStateChanged": onPageScrollStateChanged,
          "onPageSelected": onPageSelected,
          "pageMargin": pageMargin,
          "keyboardDismissMode":
            keyboardDismissMode->Belt.Option.map(
              fun
              | `none => "none"
              | `onDrag => "on-drag",
            ),
          "peekEnabled": peekEnabled,
          "scrollEnabled": scrollEnabled,
        },
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
        ~accessibilityRole?,
        ~accessibilityStates?,
        ~accessibilityHint?,
        ~accessibilityIgnoresInvertColors?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
