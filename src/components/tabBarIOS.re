module Item = {
  [@bs.scope "TabBarIOS"] [@bs.module "react-native"]
  external tabBarItemIOS : ReasonReact.reactClass = "Item";
  let make =
      (
        ~title: option(string)=?,
        ~badgeColor: option(string)=?,
        ~badge=?,
        ~icon=?,
        ~onPress=?,
        ~renderAsOriginal=?,
        ~style=?,
        ~selected=?,
        ~selectedIcon=?,
        ~isTVSelectable=?,
        ~accessibilityLabel=?,
        ~accessible=?,
        ~hitSlop=?,
        ~onAccessibilityTap=?,
        ~onLayout=?,
        ~onMagicTap=?,
        ~responderHandlers=?,
        ~pointerEvents=?,
        ~removeClippedSubviews=?,
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
      ~reactClass=tabBarItemIOS,
      ~props=
        Props.extendView(
          {
            "badgeColor": badgeColor,
            "title": title,
            "badge": badge,
            "icon": icon,
            "onPress": onPress,
            "renderAsOriginal": renderAsOriginal,
            "selected": selected,
            "selectedIcon": selectedIcon,
            "style": style,
            "isTVSelectable": isTVSelectable,
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
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
        ),
    );
};

[@bs.module "react-native"]
external tabBarIOS : ReasonReact.reactClass = "TabBarIOS";

let make =
    (
      ~barTintColor=?,
      ~itemPositioning=?,
      ~style=?,
      ~tintColor=?,
      ~translucent=?,
      ~unselectedItemTintColor=?,
      ~unselectedTintColor=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
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
    ~reactClass=tabBarIOS,
    ~props=
      Props.extendView(
        {
          "barTintColor": barTintColor,
          "itemPositioning":
            UtilsRN.option_map(
              x =>
                switch (x) {
                | `fill => "fill"
                | `center => "center"
                | `auto => "auto"
                },
              itemPositioning,
            ),
          "tintColor": tintColor,
          "translucent": translucent,
          "unselectedItemTintColor": unselectedItemTintColor,
          "unselectedTintColor": unselectedTintColor,
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
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
