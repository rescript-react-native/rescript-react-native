module Item = {
  [@bs.scope "TabBarIOS"] [@bs.module "react-native"]
  external tabBarItemIOS : ReasonReact.reactClass =
    "Item";
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
        ~shouldRasterizeIOS=?
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=tabBarItemIOS,
      ~props=
        Props.extendView(
          Js.Undefined.(
            {
              "badgeColor": from_opt(badgeColor),
              "title": from_opt(title),
              "badge": from_opt(badge),
              "icon": from_opt(icon),
              "onPress": from_opt(onPress),
              "renderAsOriginal": from_opt(UtilsRN.optBoolToOptJsBoolean(renderAsOriginal)),
              "selected": from_opt(UtilsRN.optBoolToOptJsBoolean(selected)),
              "selectedIcon": from_opt(selectedIcon),
              "style": from_opt(style),
              "isTVSelectable": from_opt(UtilsRN.optBoolToOptJsBoolean(isTVSelectable))
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
};

[@bs.module "react-native"] external tabBarIOS : ReasonReact.reactClass = "TabBarIOS";

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
      ~shouldRasterizeIOS=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=tabBarIOS,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "barTintColor": from_opt(barTintColor),
            "itemPositioning":
              from_opt(
                UtilsRN.option_map(
                  (x) =>
                    switch x {
                    | `fill => "fill"
                    | `center => "center"
                    | `auto => "auto"
                    },
                  itemPositioning
                )
              ),
            "tintColor": from_opt(tintColor),
            "translucent": from_opt(UtilsRN.optBoolToOptJsBoolean(translucent)),
            "unselectedItemTintColor": from_opt(unselectedItemTintColor),
            "unselectedTintColor": from_opt(unselectedTintColor)
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
