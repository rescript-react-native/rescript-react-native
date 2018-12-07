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
        ~accessibilityViewIsModal=?,
        ~shouldRasterizeIOS=?,
      ) =>
      
    ReasonReact.wrapJsForReason(
      ~reactClass=tabBarItemIOS,
      ~props=
        Props.extendView(
          {
            "selected": selected,
            "badge": badge,
            "icon": icon,
            "onPress": onPress,
            "renderAsOriginal": renderAsOriginal,
            "badgeColor": badgeColor,
            "selectedIcon": selectedIcon,
            "style": style,
            "systemIcon": UtilsRN.option_map(
              x =>
                switch (x) {                  
                | `bookmarks => "fill"
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
                | `topRated => "top-rated"
              },
              systemIcon,
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
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=tabBarIOS,
    ~props=
      Props.extendView(
        {
          "barStyle": UtilsRN.option_map(
              x =>
                switch (x) {
                | `default => "default"
                | `black => "black"
                },
              barStyle,
          ),
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
