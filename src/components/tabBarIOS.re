module Item = {
  [@bs.scope "TabBarIOS"] [@bs.module "react-native"]
  external tabBarItemIOS: ReasonReact.reactClass = "Item";
  let make =
      (
        ~selected=?,
        ~badge=?,
        ~icon=?,
        ~onPress=?,
        ~renderAsOriginal=?,
        ~badgeColor: option(string)=?,
        ~selectedIcon=?,
        ~style=?,
        ~systemIcon=?,
        ~title: option(string)=?,
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
        ~accessibilityRole=?,
        ~accessibilityStates=?,
        ~accessibilityHint=?,
        ~accessibilityIgnoresInvertColors=?,
        ~accessibilityViewIsModal=?,
        ~shouldRasterizeIOS=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=tabBarItemIOS,
      ~props=
        ViewProps.extend(
          {
            "selected": selected,
            "badge": badge,
            "icon": icon,
            "onPress": onPress,
            "renderAsOriginal": renderAsOriginal,
            "badgeColor": badgeColor,
            "selectedIcon": selectedIcon,
            "style": style,
            "systemIcon":
              systemIcon->Belt.Option.map(
                fun
                | `bookmarks => "bookmarks"
                | `contacts => "contacts"
                | `downloads => "downloads"
                | `favourites => "favourites"
                | `featured => "featured"
                | `history => "history"
                | `more => "more"
                | `mostRecent => "most-recent"
                | `mostViewed => "most-viewed"
                | `recents => "recents"
                | `search => "search"
                | `topRated => "top-rated",
              ),
            "title": title,
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
          ~accessibilityRole?,
          ~accessibilityStates?,
          ~accessibilityHint?,
          ~accessibilityIgnoresInvertColors?,
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
        ),
    );
};

[@bs.module "react-native"]
external tabBarIOS: ReasonReact.reactClass = "TabBarIOS";

let make =
    (
      ~barStyle=?,
      ~barTintColor=?,
      ~itemPositioning=?,
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
      ~style=?,
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
    ~reactClass=tabBarIOS,
    ~props=
      ViewProps.extend(
        {
          "barStyle":
            barStyle->Belt.Option.map(
              fun
              | `default => "default"
              | `black => "black",
            ),
          "barTintColor": barTintColor,
          "itemPositioning":
            itemPositioning->Belt.Option.map(
              fun
              | `fill => "fill"
              | `center => "center"
              | `auto => "auto",
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
        ~accessibilityRole?,
        ~accessibilityStates?,
        ~accessibilityHint?,
        ~accessibilityIgnoresInvertColors?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
